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
//fungsi menghapus data
void clear(LIST **top)
{
	if(*top!=NULL)
	{
		*top=(*top)->next;
		clear(top);
	}
	free(*top);
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
int main()
{
    //inisialisasi p dan top sebagau pointer
    int p;
	LIST *top=NULL;
	
	printf("masukkan data dan akhiri dengan 0: ");
	//input data
	while(TRUE)
	{
		scanf("%d",&p);
		if(p==0)
        break;
		else
		push(&top,p);
	}
	//memanggil fungsi
	print(top);
	clear(&top);
	print(top);
	getch();
}
