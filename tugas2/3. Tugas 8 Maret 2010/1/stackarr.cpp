/*
rizky ichsan paramamputra 5109100026
rizky noor ichwan 5109100090
stario gita nugraha 5109100097
claracia dinasty 5109100109
*/
#include <stdio.h>
#include <conio.h>

#define MAKS 10

//membuat stack dengan nama STACK
typedef struct STACK
{
	int data[MAKS];
	int top;
};

void push(STACK *array,int p)
{
	if(array->top<MAKS-1)
	  array->data[++array->top] = p;
}
void pop(STACK *array,int *q)
{
	*q=array->data[array->top--];
}
void poptest(STACK *array,int *q,int *loop)
{
	if(array->top==-1)
	  *loop=1;
	else
	  pop(array,q);	
}
void print(STACK array)
{	
	for(array.top; array.top>-1; array.top--)
	printf("%d ",array.data[array.top]);
}

main()
{
    int p,q;
    int loop,input;
	STACK array;
	array.top = -1;
	
	printf("1. Fungsi Push\n");
	printf("2. Fungsi Pop\n");
	printf("3. EXIT\n");
	while(input!=3)
	{
		loop=0;
		printf("masukkan pilihan: ");
        scanf("%d",&input);
        
        //input 1 panggil fungsi push
        if(input==1)
        {
           printf("input : ");
           scanf("%d",&p);
           push(&array,p);
           
           printf("isi stack sekarang :");
           print(array);
           printf("\n");
        }
        //input 2 panggil fungsi pop
        else if(input==2)
        {
           poptest(&array,&q,&loop);
           if(loop==1)
             printf("stack is underflow\n");
           else
           { 
             printf("pop : %d \nisi stack sekarang : ",q);
             print(array);
             printf("\n");
           }
        }  
	}
	return 0;
}
