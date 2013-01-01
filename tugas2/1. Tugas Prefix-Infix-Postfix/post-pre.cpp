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
     if(stack[index]=='#')
        return 0;
char a; 
a=stack[index]; 
index--; 
return a; 
}

void convert(char postfix[],char prefix[]) { 
int i,j=0; 
char symbol, infix[50];

postfix=strrev(postfix); 
stack[index]='#'; 

//convert to infix
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

j=0;

//convert to prefix

for(i=0;i<strlen(infix);i++)
{ 
    symbol=infix[i]; 
    if(isoperator(symbol)==0)
    { 
        prefix[j]=symbol; 
        j++; 
    }
    else
    { 
        if(symbol==')')
          push(symbol); 
        else if(symbol=='(')
        { 
            while(stack[index]!=')')
            { 
                prefix[j]=pop(); 
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
                    prefix[j]=pop(); 
                    j++; 
                } 
                push(symbol); 
            }
        }
    }
}

while(stack[index]!='#')
{ 
    prefix[j]=pop(); 
    j++; 
} 
prefix[j]='\0';
prefix=strrev(prefix); 
} 

main()
{
char prefix[50],postfix[50];
printf("input postfix:\n"); 
gets(postfix); 
convert(postfix,prefix); 
printf("prefix:\n"); 
printf("%s",prefix); 
}
