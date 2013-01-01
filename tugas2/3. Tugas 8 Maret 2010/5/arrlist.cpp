/*
rizky ichsan paramamputra 5109100026
rizky noor ichwan 5109100090
stario gita nugraha 5109100097
claracia dinasty 5109100109
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define N 5

//define struct
typedef struct LIST
{
	int data;
	LIST *next;
};

//isi semua data dengan NULL
void init(LIST **top,LIST **head)
{
	for(int i=0;i<N;i++)
	{
		top[i] = NULL;
		head[i] = NULL;
	}
}

//buat fungsi cetak untuk mencetak data
void print(LIST *head)
{
    //cetak selama bukan NULL
	if(head==NULL)
	  puts("");
	else
	{
		printf("%d ",head->data);
		print(head->next);//jalankan rekursif sampai akhir data
	}
}

//fungsi input data
void insert(LIST **top,LIST **head,int i,int x)
{
	LIST *now = (LIST *)malloc(sizeof(LIST));
	
	now->data = x;
	now->next = NULL;
	
	if(top[i]==NULL)
	  head[i]=now;
	else
	  top[i]->next = now;
	  
	top[i] = now;
}

//fungsi sorting
void sortnpush(LIST **top,LIST **head,int i,int x)
{
	LIST *now = (LIST *)malloc(sizeof(LIST));
	LIST *now2 = (LIST *)malloc(sizeof(LIST));
	LIST *temp = (LIST *)malloc(sizeof(LIST));
	
	//cek head utama apakah masih kosong atau tidak
	if(head[i]==NULL)
      insert(top,head,i,x);
	else
	{
        //sorting data
		for(now = head[i]; now!=NULL && now->data<=x; now = now->next)
		  now2 = now;
		
        //penukaran data berdasarkan sorting  
		if(now==head[i])
		{
			now2->data = x;
			now2->next = now;
			head[i] = now2;
		}
		else
		{
			temp->data = x;
			temp->next = now;
			now2->next = temp;
		}
	}
}

main()
{
	LIST *top[N],*head[N];
	int i=0,x;
	
	init(top,head);
	
	while(true)
	{
		printf("input indeks dan data : ");
        scanf("%d%d",&i,&x);
        
		if(i<0 || i> N-1)
          break;
		else
		  sortnpush(top,head,i,x);
		i++;
	}
	
	for(i=0;i<N;i++)
	{
		printf("list %d : ",i);
		print(head[i]);
	}
	getch();
	
	return 0;
}
