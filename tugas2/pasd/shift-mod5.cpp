#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct kota1{
  char nKota1;
  struct kota1 *next, *prev;
  struct kota2 *head2, *tail2;
};

struct kota2{
   char nKota2;
   struct kota2 *next, *prev;
};

struct kota1 *head1=NULL, *tail1=NULL, *ptr1=NULL;
struct kota2 *ptr2=NULL;

//add kota1
void add1(char nKota1){
    
    struct kota1 *entry=(kota1*)malloc(sizeof(kota1));

    entry -> nKota1 = nKota1;

    if(head1==NULL){
        head1=tail1=entry;
        tail1->next=NULL;

        head1->head2=tail1->tail2=NULL;
    }
    else{
        tail1->next=entry;
        entry->prev=tail1;
        tail1=entry;
        tail1->next=NULL;
        
         ptr1=head1;
         while(ptr1->nKota1!=nKota1)
           ptr1=ptr1->next;
         
        ptr1->head2=tail1->tail2=NULL;
    }
}

//add kota2
void add2(char nKota1, char nKota2){

    ptr1=head1;
    while(ptr1->nKota1!=nKota1)
        ptr1=ptr1->next;
     
     struct kota2 *entry=(kota2*)malloc(sizeof(kota2));

     entry -> nKota2 = nKota2;

     if(ptr1->head2==NULL){
       ptr1->head2=ptr1->tail2=entry;
       ptr1->tail2->next=NULL;
     }
     else{
          ptr1->tail2->next=entry;
          entry->prev=ptr1->tail2;
          ptr1->tail2=entry;
          ptr1->tail2->next=NULL;
     }
}

void view(){
     ptr1=head1;
     
     while(ptr1!=NULL){
          printf("%c :", ptr1->nKota1);
          ptr2=ptr1->head2;
          while(ptr2!=NULL){
               printf("%c ", ptr2->nKota2);
               ptr2=ptr2->next;
          }
          printf("\n");
          ptr1=ptr1->next;
     }
}
main(){
       int dist[100][2];
       char x[100][10], kota[100];
       
       int i, j, N;
       scanf("%d", &N);
       /*for(i=0; i<N; i++){
            scanf("%c%d%d", &kota[i], &dist[i][0], &dist[i][1]);
            fflush(stdin);
       }*/

       for(i=0; i<N; i++){
            scanf("%s", x[i]);
            add1(x[i][0]);
            //for(j=1; x[j]!='\0'; j++)
            //     add2(x[0], x[j]);
       }

       for(i=0; i<N; i++){
           for(j=1; x[i][j]!='\0'; j++){
                 add2(x[i][0], x[i][j]);
                 
                 ptr1=head1;
                 while(ptr1->nKota1!=x[i][0])
                     ptr1=ptr1->next;
                     
                 ptr2=ptr1->head2;
                 int y=true;
                 while(ptr2!=NULL){
                     if(ptr2->nKota2==x[i][j]){
                         y=false;
                     }
                     ptr2=ptr2->next;
                 }
                 if(y)
                     add2(x[i][j], x[i][0]);
           }
       }
       
       view();
       
       getch();
}
