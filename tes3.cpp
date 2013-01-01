#include<stdio.h>
#include<string.h> 

char stack[50]; 
int index=0; 

int isoperator(char symbol) { 
    if(symbol=='+' || symbol=='-' || symbol=='*' || symbol=='/' || symbol=='^' || symbol=='$' || symbol=='(' || symbol==')')
      return 1;
    else
      return 0;
} 

//input operand to stack
void push(char item) { 
index++; 
stack[index]=item; 
} 

//ambil nilai dari stack
char pop() { 
     if(stack[index]=='#')
        return 0;
char a; 
a=stack[index]; 
index--; 
return a; 
}

void convert(char postfix[],char infix[]) { 
int i,j=0; 
char symbol;

postfix=strrev(postfix); 
stack[index]='#'; 

for(i=0;i<strlen(postfix);i++)
{ 
    symbol=postfix[i]; 
    if(isoperator(symbol)==0)
    {
        infix[j]=symbol;
        infix[j+1]=pop(); 
        j+=2;
    }
    else
        push(symbol);
}

infix[j]='\0';
infix=strrev(infix); 
} 

main()
{
char infix[50],postfix[50];
printf("input postfix:\n"); 
gets(postfix); 
convert(postfix,infix); 
printf("infix:\n"); 
printf("%s",infix); 
}
