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
//fungsi memasukkan data dan sorting
void sortpush(LIST **top,LIST **front,int p)
{
	LIST *link = (LIST *)malloc(sizeof(LIST));
	LIST *link2 = (LIST *)malloc(sizeof(LIST));
	LIST *temp = (LIST *)malloc(sizeof(LIST));
	if(*front==NULL)
	{
		link->data=p;
		link->next=NULL;
		if(*top==NULL)
		*front=link;
		else
		(*top)->next=link;
		*top=link;
	}
	else
	{
		for(link= *front; link!=NULL&&link->data<=p; link=link->next)
		link2=link;
		if(link==*front)
		{
			link2->data=p;
			link2->next=link;
			*front=link2;
		}
		else
		{
			temp->data=p;
			temp->next=link;
			link2->next=temp;
		}
	}
}
//fungsi cetak data
void print(LIST *front)
{
	if(front==NULL)
	puts("");
	else
	{
		printf("%d ",front->data);
		print(front->next);
	}
}
int main()
{
	LIST *top = NULL;
    LIST *front = NULL;
	int p;
	
	printf("masukkan data dan akhiri dengan 0: ");
	//memasukkan data
	while(TRUE)
	{
		scanf("%d",&p);
		if(p==0)
        break;
		else
		sortpush(&top,&front,p);
	}
	//cetak data
	print(front);
	getch();
}
