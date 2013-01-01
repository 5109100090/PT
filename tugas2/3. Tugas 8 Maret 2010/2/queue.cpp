/*
rizky ichsan paramamputra 5109100026
rizky noor ichwan 5109100090
stario gita nugraha 5109100097
claracia dinasty 5109100109
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//membuat stack dengan nama LIST
typedef struct LIST
{
	int data;
	LIST *next;
};

//inisialisasi fungsi
void enqueue(LIST **front,LIST **back,int p)
{
	LIST *list=(LIST *)malloc(sizeof(LIST));//menyiapkan tempat untuk list di dalam memori
	
	list->data=p;//memasukkan inputan user kedalam variabel data
	list->next=NULL;//memberi terminator di akhir list
	
	if(*front==NULL)//jika data dalam list hanya satu
        *front=list;
	else//jika data dalam list lebih dari satu
        (*back)->next=list;
    *back=list;
}
void dequeue(LIST **front,LIST **back,int *q)
{
	LIST *list=(LIST *)malloc(sizeof(LIST));
	
	list=*front;//menunjuk ke list yang ditunjuk oleh pointer front
	*q=list->data;//menampung nilai yang dikeluarkan
	*front=list->next;//memundurkan pointer front ke list sebelumnya
	
    if(*front==NULL)//bila data hanya ada satu
	   *back=NULL;//memberi nilai NULL pada pointer front dan back
	
    free(list);
}

void dequeuetest(LIST **front,LIST **back,int *q,int *loop)
{
	if(*front==NULL)//apabila list kosong
	   *loop=1;//memberi kode ke fungsi main
	else
	   dequeue(front,back,q);//mengeluarkan isi list
}

void print(LIST *front)
{	
	if(front!=NULL)//bila list tidak kosong
	{
		printf("%d ",front->data);
		print(front->next);
	}
}

main()
{
    //deklarasi variabel
    int p,q;
    int loop,input;
	LIST *front,*back;
	front = back = NULL;
	
	printf("1. Perintah Enqueue\n");
	printf("2. Perintah Dequeue\n");
	printf("3. EXIT\n");
	
    while(input!=3)//memeriksa pilihan
	{
		loop=0;
		printf("masukkan pilihan: ");
        scanf("%d",&input);
		if(input==1)
		{
			printf("input : ");
            scanf("%d",&p);//menyimpan data dari user yang akan dimasukkan list
		    enqueue(&front,&back,p);
		}    
		else if(input==2)
		{
	        dequeuetest(&front,&back,&q,&loop);
            if(loop==1)//bila list kosong
	        printf("dequeue is underflow\n");
	        else
            printf("%d\n",q);//mencetak data yang dikeluarkan dari list
		}
	}
	print(front);//untuk melihat data yang ada di dalam list
	getch();
}
