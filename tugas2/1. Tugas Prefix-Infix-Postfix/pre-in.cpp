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

void convert(char prefix[],char infix[]) { 
int i,j=0; 
char symbol;

stack[index]='#'; 

for(i=0;i<strlen(prefix);i++)
{ 
    symbol=prefix[i]; 
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
} 

main()
{
char infix[50],prefix[50];
printf("input prefix:\n"); 
gets(prefix); 
convert(prefix,infix); 
printf("infix:\n"); 
printf("%s",infix); 
}
