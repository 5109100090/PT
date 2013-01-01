#include <stdio.h>
#include <stdlib.h>

struct link{
       int data;
       link *next;
}

link *head, *tail, *ptr;

void add(int x)
{
     link *entry;
     
     entry=(link*)malloc(sizeof(link));
     
     entry->data=x;
     
     if(head=NULL)
     head=tail=NULL;
     else
     {
         ptr=head;
         if(x < ptr->data && x> ptr->next->data)
     }
}
