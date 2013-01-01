/*
  kelompok 12
  implementasi priority queue
*/
#include <stdio.h>
#include <stdlib.h>

struct List{
	int data;
	List *next;
};

void insert(List **head,List **tail,int x){
	List *now = (List *)malloc(sizeof(List));
	now->data = x;
	now->next = NULL;
	
	if(*head==NULL)
		*head = *tail = now;
	else{
		(*tail) -> next = now;
		*tail = now;
	}
}

void enqueue(List **head, List **tail,int x){
	List *now,*prev,*temp;
	
	if(*head==NULL)
		insert(head,tail,x);
	else{
		for(now=*head;now!=NULL && now->data<x;now=now->next)
			prev = now;
		if(now==*head){
			now = (List *)malloc(sizeof(List));
			now -> data = x;
			now -> next = *head;
			*head = now;
		}else if(now==NULL)
			insert(head,tail,x);
		else{
			temp = (List *)malloc(sizeof(List));
			temp -> data = x;
			temp -> next = now;
			prev -> next = temp;
		}
	}
}

int dequeue(List **head,List **tail){
	if(*head==NULL)
        return false;
	else{
		List *now = *head;
		int x = now->data;
		*head = (*head)->next;
		free(now);
		return x;
	}
}

void print(List *head){
	if(head==NULL)
		printf("queue is empty\n");
	else{
		printf("%d ",head->data);
		print(head->next);
	}
}

int main()
{
	List *head = NULL, *tail = NULL;
	int data,opt;
	
	while(true){
		printf("1) push data\n");
		printf("2) pop data\n");
		printf("3) view data\n");
		printf("4) exit\n");
		
		printf("option : ");
        scanf("%d",&opt);
		if(opt==1){
            printf("input data : ");
            scanf("%d",&data);
			enqueue(&head,&tail,data);
        }else if(opt==2){
            data=dequeue(&head,&tail);
			if(data!=0)
			    printf("data : %d\n",data);
        }else if(opt==3){
            printf("queue : ");
            print(head);
        }else
            break;
	}
}
