#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct kota1{
  int nKota1;
  struct kota1 *next, *prev;
  struct kota2 *head2, *tail2;
};

struct kota2{
   int nKota2;
   struct kota2 *next, *prev;
};

struct kota1 *head1=NULL, *tail1=NULL, *ptr1=NULL;
struct kota2 *ptr2=NULL;

//add kota1
void add1(int nKota1){
    
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
void add2(int nKota1, int nKota2){

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
          printf("%d :", ptr1->nKota1);
          ptr2=ptr1->head2;
          while(ptr2!=NULL){
               printf("%d ", ptr2->nKota2);
               ptr2=ptr2->next;
          }
          printf("\n");
          ptr1=ptr1->next;
     }
}

main(){
    char k[100], m[100][3], q[100][3];
    int N, M, K, Q, i, j;
    
    scanf("%d %d %d", &N, &M, &K);

    //kota yg memiliki bandara
    gets(k);
    
    //rute
    for(i=0; i<M; i++)
        gets(m[i]);

    scanf("%d", &Q);
    //req    
    fflush(stdin);
    for(i=0; i<Q; i++){
        gets(q[i]);
    }
 
    for(i=0; i<N; i++)
        add1(i+1);
    
    for(i=0; i<M; i++)
        printf("%s\n", m[i]);
    for(i=0; i<M; i++)
        add2(m[i][0]-48, m[i][2]-48);
        
    view();
    
    getch();        
}
