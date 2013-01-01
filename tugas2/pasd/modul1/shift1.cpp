#include <stdio.h>
#include <stdlib.h>

typedef struct STRUCT
{
	int data;
	STRUCT *next, *prev;
}LIST;

LIST *head=NULL, *tail=NULL, *ptr=NULL;

void add(int x){
    LIST *entry;
    entry=(LIST*)malloc(sizeof(LIST));

    entry -> data = x;

    if(head==NULL){
        head = tail = entry;
        
        head -> prev = NULL;
        tail -> next = NULL;
    }
    else{
        tail -> next = entry;
        entry -> prev = tail;

        tail = entry;

        tail -> next = NULL;
    }
}

void del(int x){
    ptr=head;

    while(ptr->data != x)
        ptr=ptr->next;

    ptr->prev->next=ptr->next;
    ptr->next->prev=ptr->prev;
}

void search(int pos, int lgkh, int N){
    int i, j;

    ptr=head;
    
    while(ptr->data != pos)
        ptr=ptr->next;
    
    for(j=0; j<N; j++){
        if(pos%2==0)
            for(i=0; i<lgkh; i++)
                ptr=ptr->next;
        else
            for(i=0; i<lgkh; i++)
                ptr=ptr->prev;
        

        pos=ptr->data;
        lgkh=pos;
        //printf("posisi bola : %d\n", pos);

        del(pos);
    }
    printf("Node Terakhir   : %d\n", pos);

}

main()
{
    int N, i, pos, langkah;

    printf("Jumlah Node     : ");
    scanf("%d",&N);

    for(i=0; i<N; i++)
        add(i+1);

    tail->next = head;
    head->prev = tail;

    printf("Start Awal      : ");
    scanf("%d",&pos);

    printf("Langkah Pertama : ");
    scanf("%d",&langkah);

    search(pos, langkah, N);
}
