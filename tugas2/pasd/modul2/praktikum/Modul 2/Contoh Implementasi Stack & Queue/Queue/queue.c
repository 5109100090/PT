#include<stdio.h>
#include<stdlib.h>

#include"fungsi.h"

int main()
{
 struct Queue queue;
 init(&queue);
 enQueue(&queue, 1);   
 enQueue(&queue, 2);
 enQueue(&queue, 3);
 
 printf("Isi stack = ");
 print(&queue);  
 
 printf("\n\nMelakukan deQueue.\nIsi stack yang dihapus adalah = %d\n", deQueue(&queue)->data); 
 printf("\nIsi stack = ");
 print(&queue);
 
 printf("\n\nTop of stack = %d", peek(&queue)->data);
 getch();
 return 0;   
}
