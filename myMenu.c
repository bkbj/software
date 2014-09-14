/**************************************************************************************************/
/* Copyright (C)  Lezg.com, Lezg@USTC, 2014-2015                                                  */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  Lezg                                                                 */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/13                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Lezg, 2014/09/13
 *
 */


#include<stdio.h>
#include<stdlib.h>

#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 10
#define LEN sizeof(mCmdNode)

typedef struct CmdNode
{
	char* cmd;
	char* desc;
	struct CmdNode *next;
}mCmdNode;

char cmdDesc[CMD_NUM][DESC_LEN]=
{
	{"To show more about the function name"},
	{"To show list directory contents"},
	{"To show the calendar"},
	{"To show the date"},
	{"To show the cmd manual"}
};

char cmds[CMD_NUM][DESC_LEN]=
{
	{"help"},
	{"ls"},
	{"cal"},
	{"date"},
	{"man"}
};

void initCmdList(mCmdNode **p)
{
	int i;
	mCmdNode *ptr;
	for(i=0;i<CMD_NUM;++i)
	{
		ptr=(struct CmdNode *)malloc(LEN);
		ptr->cmd=cmds[i];
		ptr->desc=cmdDesc[i];
		ptr->next=(*p);
		(*p)=ptr;
	}
}

void PrintCmdDesc(mCmdNode *node)
{
	if(node->desc!=NULL)
	{
		printf("Menu List:\n");
		printf("%s : %s\n",node->cmd,node->desc);
	}
}

int main()
{
	mCmdNode *head;
	initCmdList(&head);
	while(1)
	{
		char cmd[CMD_MAX_LEN];
		printf("Input a cmd number > ");
		scanf("%s",cmd);
		mCmdNode *p = head;
		while(p!=NULL)
		{
			if(!strcmp(p->cmd,cmd))
			{
				printf("%s : This is %s cmd!\n",p->cmd,p->cmd);
			    PrintCmdDesc(p);
				break;
			}
			p=p->next;
		}
		if(p==NULL)
		{
			printf("This is a wrong cmd!\n");
		}
	}
	return 0;
}



