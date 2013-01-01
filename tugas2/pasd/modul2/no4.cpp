/*
  kelompok 12
  konversi bilangan desimal menjadi biner
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct List
{
	int data;
	List *next;
};

int pop(List **top)
{
	int x;
	
	List *now = *top;
	x = now->data;
	*top = (*top)->next;
	free(now);
	
	return x;
}

void push(List **top,int x)
{
	List *now = (List*)malloc(sizeof(List));
	now->data = x;
	now->next = *top;
	*top = now;
}

int main()
{
	List *top = NULL;
	int dec;
	
	printf("input decimal : ");
	scanf("%d",&dec);
	while(true)
	{
		push(&top,dec%2);
		if(dec<2)
            break;
		else
			dec/=2;
	}
	printf("binary        : ");
	while(top!=NULL)
		printf("%d",pop(&top));
	
	getch();
}
