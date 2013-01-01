#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct ruang{
  int r;
  int s;
  struct ruang *next, *prev;
};

struct lantai{
   int l;
   struct lantai *next, *prev;
   ruang *head1, *tail1;
};

lantai *head2=NULL, *tail2=NULL, *ptr2=NULL;
ruang *ptr1=NULL;

void addR(int nLantai){

    int nRuang, i;

    ptr2=head2;
    while(ptr2->l!=nLantai)
        ptr2=ptr2->next;

    ptr1=ptr2->head1;
    for(i=0; ptr1!=NULL; i++)
        ptr1=ptr1->next;

     ruang *entry;

     entry=(ruang*)malloc(sizeof(ruang));

     nRuang=(nLantai*100)+(i+1);

     entry -> r = nRuang;
     entry -> s = 0;

     if(ptr2->head1==NULL){
       ptr2->head1=ptr2->tail1=entry;
       ptr2->tail1->next=NULL;
     }
     else{
          ptr2->tail1->next=entry;
          entry->prev=ptr2->tail1;
          ptr2->tail1=entry;
          ptr2->tail1->next=NULL;
     }
}

void delR(int nLantai)
{
    ptr2=head2;

    while(ptr2->l!=nLantai)
        ptr2=ptr2->next;

    if(ptr2->head1==ptr2->tail1 || ptr2->head1==NULL){
        ptr2->head1=NULL;
        return;
    }

    ptr2->tail1=ptr2->tail1->prev;
    ptr2->tail1->next=NULL;
}

void delL()
{
    if(head2==tail2 || head2==NULL){
        head2=NULL;
        return;
    }

    tail2=tail2->prev;
    tail2->next=NULL;
}

void status(int nLantai, int nRuang, int stat){

    ptr2=head2;
    while(ptr2->l!=nLantai)
        ptr2=ptr2->next;

    ptr1=ptr2->head1;
    while(ptr1->r!=nRuang)
        ptr1=ptr1->next;

    ptr1->s=stat;
}

void addL(int nLantai){

    lantai *entry;
    entry=(lantai*)malloc(sizeof(lantai));

    entry -> l = nLantai;

    if(head2==NULL){
        head2=tail2=entry;
        tail2->next=NULL;
    }
    else{
         tail2->next=entry;
         entry->prev=tail2;
         tail2=entry;
         tail2->next=NULL;
    }
}

void viewL(int x)
{
     ptr2=head2;
     printf("Daftar Fasilitas Ruangan TC\n");
     printf("---------------------------\n");
     printf("Lantai Ruangan                 Jumlah Ruangan\n");

     while(ptr2!=NULL)
     {
         int i=0;
         printf("%6d ",ptr2->l);

         ptr1=ptr2->head1;
         while(ptr1!=NULL){
             //view all rooms
             if(x){
                     printf("%d,",ptr1->r);
                     i++;
             }
             //view booked rooms
             else
                 if(ptr1->s==1){
                     printf("%d,",ptr1->r);
                     i++;

                 }

             ptr1=ptr1->next;
         }

         if(i==0)
             printf("(belum ada ruangan)");
         printf("%6d",i);
         printf("\n");
                 
         ptr2=ptr2->next;
     }
}

main(){
       int i, j, opt, opt2, opt3, nRuang, nLantai=3;

       for(i=0; i<nLantai; i++){

           addL(i+1);
           if(i==0)
               nRuang=5;
           else if(i==1)
               nRuang=2;
           else
               nRuang=3;
           
           for(j=0; j<nRuang; j++)
               addR(i+1);
       }

       while(true){
           printf("Menu:\n1. tambah ruang\n2. hapus ruang\n3. pinjam ruang\n4. kembalikan ruang\n5. lihat ruang\n6. lihat ruang yang dipinjam\n7. tambah lantai\n8. hapus lantai\n9. exit\noption : ");
           scanf("%d",&opt);

           if(opt==1)
           {
               printf("tambah ke lantai : ");
               scanf("%d",&opt2);

               nRuang++;
               addR(opt2);
               viewL(true);
           }
           else if(opt==2){
               printf("delete ruang terakhir pada lantai : ");
               scanf("%d",&opt2);
               delR(opt2);
               viewL(true);
           }
           else if(opt==3 || opt==4){
               printf("Pilih lantai : ");
               scanf("%d",&opt2);

               printf("Pilih ruang : ");
               scanf("%d",&opt3);

               if(opt==3)
                   status(opt2, opt3, 1);
               else
                   status(opt2, opt3, 0);

               viewL(false);
           }
           else if(opt==5)
               viewL(true);
           else if(opt==6)
               viewL(false);
           else if(opt==7){
               nLantai++;
               addL(nLantai);
               viewL(true);
           }
           else if(opt==8){
               nLantai--;
               delL();
               viewL(true);
           }
           else
               break;

       }
       
       getch();
}
