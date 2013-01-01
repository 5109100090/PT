#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct stack{
    char data;
    struct stack *next;
};

stack *head=NULL, *ptr;

int isEmpty(){
    if(head==NULL)
        return 1;
    else
        return 0;
}

void push(int x){
    stack *entry;
    entry=(stack*)malloc(sizeof(stack));

    entry->data=x;

    if(isEmpty()){
        head=entry;
        head->next=NULL;
    }else{
        entry->next=head;
        head=entry;
    }
}

char pop(){
    char temp;

    if(isEmpty())
        //printf("Stack is empty\n");
        return 0;
    else{
        temp=head->data;
        head=head->next;
        return temp;
    }
}

void print(){
    ptr=head;

    while(ptr!=NULL){
        printf("%c\n",ptr->data);
        ptr=ptr->next;
    }
}

int prcd(char symbol) {
    switch(symbol) {
        case '+':
        case '-':
        return 2;
        case '*':
        case '/':
        return 4;
        case '^':
        case '$':
        return 6;
        case '(':
        case ')':
        return 1;
    }
}

int isOperator(char symbol) {
    switch(symbol) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '$':
        case '(':
        case ')':
        return 1;

        default:
        return 0;
    }
}

main(){
    int i=0, j=0, N,a=0,k;
    char in[20], pre[20], sym;

    printf("input prefix : ");
    scanf("%s",pre);

    while(pre[i]!='\0'){
        sym=pre[i];

        if(isOperator(sym)){
            push(sym);
        }else{
            if(isOperator(pre[i-1])){
                  in[j]='(';
                  in[j+1]=sym;
                  j+=2;
                  a++;
             }
             else if(!isOperator(pre[i-1]) && a>0){
                  in[j]=sym;
                  j++;
                  for(k=0; k<a; k++, j++)
                      in[j]=')';
                     
                  a=0;
             }else{
                  in[j]=sym;
                  j++;
             }
             
             in[j]=pop();
             j++;
        }
        i++;
    }
    
    in[j]='\0';
    for(i=0; i<strlen(in); i++)
        printf("%c",in[i]);
        getch();
}
