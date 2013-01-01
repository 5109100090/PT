/*
rizky ichsan paramamputra 5109100026
rizky noor ichwan 5109100090
stario gita nugraha 5109100097
claracia dinasty 5109100109
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define TRUE 1

typedef struct LIST
{
	int data;
	LIST *next;
};
//fungsi memasukkan data
void push(LIST **top,int p)
{
	LIST *link=(LIST *)malloc(sizeof(LIST));
	
	link->data=p;
	link->next=*top;
	*top=link;
}
//fungsi mencetak data
void print(LIST *top)
{
	if(top==NULL)
	puts("");
	else
	{
		printf("%d ",top->data);
		print(top->next);
	}
}
//fungsi reverse
void reverse(LIST *top1,LIST **top2)
{
	LIST *link;
	for(top1;top1!=NULL;top1=top1->next)
	{
		link=(LIST *)malloc(sizeof(LIST));
		link->data=top1->data;
		link->next=*top2;
		*top2=link;
	}
}
int main()
{
	LIST *top1 = NULL;
    LIST *top2 = NULL;
	int p;
	//input data
	printf("masukkan data dan akhiri dengan 0: ");
	while(TRUE)
	{
		scanf("%d",&p);
		if(p==0)
        break;
		else
		push(&top1,p);
	}
	//me reveverse data
	print(top1);
	reverse(top1,&top2);
	print(top2);
	getch();
}
