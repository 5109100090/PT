#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack{
    char data;
    struct stack *next;
};

stack *head=NULL, *ptr;

int isEmpty(){
    if(head==NULL)
        return true;
    else
        return false;
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
        printf("Stack is empty\n");
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
    int i, j=0, N;
    char in[20], pre[20], sym;
    
    printf("input infix : ");
    scanf("%s",in);

    N=strlen(in)-1;
    for(i=N; i>=0; i--){
        sym=in[i];
        
        //jika operand, cetak
        if(!isOperator(sym)){
            pre[j]=sym;
            j++;
        }
        else{
            //jika ')', push
            if(sym==')'){
                push(sym);
                N--;
            }
            //jika '(', pop sampe sebelum ')'
            else if(sym=='('){
                ptr=head;

                while(ptr->data!=')'){
                    pre[j]=pop();
                    j++;
                    ptr=ptr->next;
                }
                pop();
                N--;
            }
            else{
                //jika kosong, push
                if(isEmpty())
                    push(sym);
                //jika sym lebih gede, push sym
                else if(prcd(sym)>prcd(head->data))
                    push(sym);
                //jika sym lebih kecil, pop, push sym
                else if(prcd(sym)<=prcd(head->data)){
                    pre[j]=pop();
                    j++;
                    push(sym);
                }
            }
        }
    }
    ptr=head;
    while(ptr!=NULL){
        pre[j]=pop();
        j++;
        ptr=ptr->next;
    }

    for(i=N; i>=0; i--)
        printf("%c",pre[i]);

    print();
}
