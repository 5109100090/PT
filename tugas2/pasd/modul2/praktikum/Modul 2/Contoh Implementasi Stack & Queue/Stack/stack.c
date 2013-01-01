#include<stdio.h>
#include<stdlib.h>

#include"fungsi.h"

int main()
{
 struct Stack stack;
 init(&stack);
 push(&stack, 1);   
 push(&stack, 2);
 push(&stack, 3);
 
 printf("Isi stack = ");
 print(&stack);  
 
 printf("\n\nMelakukan Pop.\nIsi stack yang dihapus adalah = %d\n", pop(&stack)->data); 
 printf("\nIsi stack = ");
 print(&stack);
 
 printf("\n\nTop of stack = %d", peek(&stack)->data);
 getch();
 return 0;   
}
