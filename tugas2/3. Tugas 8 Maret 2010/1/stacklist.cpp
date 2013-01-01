/*
rizky ichsan paramamputra 5109100026
rizky noor ichwan 5109100090
stario gita nugraha 5109100097
claracia dinasty 5109100109
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//membuat stack dengan nama LIST
typedef struct LIST
{
	int data;
	LIST *next;
};

void push(LIST **top,int p)
{
	LIST *link;
	
	link=(LIST *)malloc(sizeof(LIST));
	(link->data) = p;
	(link->next) = *top;
	*top = link;
}
void pop(LIST **top,int *q)
{
	LIST *link;
	link=(LIST *)malloc(sizeof(LIST));
	
	link=*top;
	*q=link->data;
	*top=link->next;
	free(link);
}
void poptest(LIST **top,int *q,int *loop)
{
	if(*top==NULL)
	  *loop = 1;
	else
	  pop(top,q);	
}

void print(LIST *top)
{	
	if(top!=NULL)
	{
		printf("%d ",top->data);
		print(top->next);
	}
}

main()
{
    int p,q;
    int loop,input;
	LIST *top = NULL;
	
	printf("1. Perintah Push\n");
	printf("2. Perintah Pop\n");
	printf("3. EXIT\n");
	
	while(input!=3)
	{
		loop=0;
		printf("masukkan pilihan: ");
        scanf("%d",&input);
		if(input==1)
		{
		   printf("input : ");
           scanf("%d",&p);
	       push(&top,p);
	       printf("isi stack sekarang : ");
	       print(top);
	       printf("\n");
	    }
        else if(input==2)
        {     
           poptest(&top,&q,&loop);
  		   if(loop==1)
  		     printf("link list is underflow\n");
  		   else
  		   {
  		     printf("pop : %d\n",q);
  		     printf("isi stack sekarang : ");
  		     print(top);
  		     printf("\n");
           }
		}
	}
	return 0;
}
