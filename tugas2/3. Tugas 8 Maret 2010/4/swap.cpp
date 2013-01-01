/*
rizky ichsan paramamputra 5109100026
rizky noor ichwan 5109100090
stario gita nugraha 5109100097
claracia dinasty 5109100109
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct LIST
{
	int data;
	LIST *next;
};

void enqueue(LIST **front,LIST **back,int x)
{
	LIST *link=(LIST *)malloc(sizeof(LIST));
	
	link->data=x;
	link->next=NULL;
	
	if(*front==NULL)
	  *front=link;
	else
	  (*back)->next=link;
	  
	*back=link;
}
void fill(LIST **front,LIST **back)
{
	int x,n,i;
	
	printf("input jumlah data : ");
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
        printf("input data : ");
		scanf("%d",&x);
        enqueue(front,back,x);
	}
}
void swap(LIST **front)
{
	LIST *link=(LIST *)malloc(sizeof(LIST));
	LIST *link2=(LIST *)malloc(sizeof(LIST));
	int p,q,n,temp;
	
	printf("tukar elemen ke : ");
    scanf("%d",&p);
	printf("dengan elemen ke : ");
    scanf("%d",&q);
	
	n=1;
	for(link=*front; link!=NULL && n<p; link=link->next)
	  n++;
	
	n=1;
	for(link2=*front; link2!=NULL && n<q; link2=link2->next)
	  n++;
	
	temp=link->data;
	link->data=link2->data;
	link2->data=temp;
}
void print(LIST *top)
{
	if(top!=NULL)
	{
		printf("%d\n",top->data);
		print(top->next);
	}
}

main()
{
	LIST *front = NULL;
    LIST *back = NULL;
	
	fill(&front,&back);
	swap(&front);
	print(front);
	puts("");
    getch();	
	return 0;
}
