#include<stdio.h>
#include<string.h> 

char stack[50]; 
int index=0; 

int operand(char symbol) { 
    if(symbol=='(' || symbol==')' || symbol=='#')
      return 1;
    else if(symbol=='+' || symbol=='-')
      return 2;
    else if(symbol=='*' || symbol=='/')
      return 3;
    else if(symbol=='^' || symbol=='$')
      return 4;
} 

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
char a; 
a=stack[index]; 
index--; 
return a; 
}

void convert(char infix[],char postfix[]) { 
int i,j=0; 
char symbol;

stack[index]='#'; 

for(i=0;i<strlen(infix);i++)
{ 
    symbol=infix[i]; 
    if(isoperator(symbol)==0)
    { 
        postfix[j]=symbol; 
        j++; 
    }
    else
    { 
        if(symbol=='(')
          push(symbol); 
        else if(symbol==')')
        { 
            while(stack[index]!='(')
            { 
                postfix[j]=pop(); 
                j++; 
            } 
            pop();
        }
        else
        { 
            if(operand(symbol)>operand(stack[index]))
                push(symbol); 
            else
            { 
                while(operand(symbol)<=operand(stack[index]))
                { 
                    postfix[j]=pop(); 
                    j++; 
                } 
                push(symbol); 
            }
        }
    }
}

while(stack[index]!='#')
{ 
    postfix[j]=pop(); 
    j++; 
} 
postfix[j]='\0';
} 

main()
{
char infix[50],postfix[50];
printf("input infix:\n"); 
gets(infix); 
convert(infix,postfix); 
printf("postfix:\n"); 
printf("%s",postfix); 
}
