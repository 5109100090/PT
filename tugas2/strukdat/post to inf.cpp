#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
int top=10;
struct tree
{
  char ch;
  struct tree *next;
  struct tree *prev;
}*stack[11];
typedef struct tree tree;

void push(tree *str)
{
  if(top<=0)
    printf("Stack is Full ");
  else
    {
      stack[top]=str;
      top--;
    }
}

tree* pop()
{
  tree *exp;
  if(top>=10)
    printf("Stack is Empty ");
  else
    exp=stack[++top];
  return exp;
}


void convert(char exp[])
{
  tree *op1,*op2;
  tree *temp;
  int i;
  for(i=0;exp[i]!='\0';i++)
    if(exp[i]>='a'&& exp[i]<='z'||exp[i]>='A'&& exp[i]<='Z')
      {
     temp=(tree*)malloc(sizeof(tree));
     temp->ch=exp[i];
     temp->next=NULL;
     temp->prev=NULL;
     push(temp);
      }
    else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'||exp[i]=='^')
      {
     op1=pop();
     op2=pop();
     temp=(tree*)malloc(sizeof(tree));
     temp->ch=exp[i];
     temp->next=op1;
     temp->prev=op2;
     push(temp); 
      }
}

void display(tree *temp)
{
  if(temp!=NULL)
    {
      display(temp->prev);
      printf("%c",temp->ch);
      display(temp->next);
    }
}

main()
{
  char exp[50];
  printf("Enter the expression :");
  scanf("%s",exp);
  convert(exp);
  printf("\n\n");
  display(pop());
  printf("\n\n");
  getch();
}
