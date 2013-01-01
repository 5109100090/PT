#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct LIST
{
	int data;
	LIST *next;
};

void push(LIST **top,LIST **head,int x)
{
	LIST *now = (LIST *)malloc(sizeof(LIST));
	
	//set data
	now->data = x;
	//set next link
	now->next = NULL;
	
	if(*top==NULL)
	  *head = now;
	else
	  (*top)->next = now;
	  
	*top = now;
}

void print(LIST *top)
{
    //cetak data selama belum NULL
	if(top==NULL)
	  puts("");
	else
	{
		printf("%d ",top->data);
		print(top->next);//jalankan rekursif samapai akhir data
	}
}

void del(LIST **top,LIST **head,int m)
{
	LIST *now = (LIST *)malloc(sizeof(LIST));
	LIST *prev = (LIST *)malloc(sizeof(LIST));
	int i=1;
	
	//mencari posisi data
	for(now=*head; now!=*top && i<m; now=now->next)
	{
		prev = now;
		i++;
	}
	
	//delete data dari hasil mencari lokasi dengan free()
	if(now==*head)	
	{
		prev = now;
		now = now->next;
		*head = now;
		free(prev);
	}
	else if(now==*top)
	{
		*top = prev;
		(*top)->next = NULL;
		free(now);
	}
	else
	{
		prev->next = now->next;
		free(now);
	}
}

int main()
{
	LIST *top = NULL,*head = NULL;
	int x,m,i,n;
	
	printf("banyak data : ");
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
        printf("input data : ");
		scanf("%d",&x);
		push(&top,&head,x);
	}
	
    print(head);
	
    printf("hapus elemen ke: ");
    scanf("%d",&m);
	
    del(&top,&head,m);
	
    print(head);
	
	getch();
	
    return 0;
}
