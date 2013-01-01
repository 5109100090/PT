#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include "stack.h"
#include "queue.h"

int isDigit(char in[20]){
        
    int b=0, i, j;
        
    for(i=0, j=(int)pow(10,strlen(in)-1); i<strlen(in); i++, j/=10)
    b=b+j*((int)in[i]-48);
    
    return b;
}

void read(struct Stack *stack, struct Queue *queue, char in[20]){
     
     int i, j;
     char com1[20], com2[20];
     
     if(isDigit(in)<11 && !isEmptyQ(queue))
       strcpy(in, seek(queue, isDigit(in))->data);
     
     for(i=0; in[i]!=' '; i++){
       if(in[i]=='\0')
         break;
       com1[i]=in[i];
     }
     com1[i]='\0';
     
     i++;
     for(j=0; in[i]!='\0'; i++, j++)
       com2[j]=in[i];
     com2[j]='\0';

     if(!strcmp(com1,"PUSH")){
       if(strlen(in)==4)
         printf("missing parameter\n");
       else{
         pushS(stack, com2);
         enQueue(queue, in);
       }
     }
     else if(!strcmp(com1,"POP")){
       if(strlen(in)>3)
         printf("too many parameter\n");
       else{
         popS(stack);
         enQueue(queue, in);
       }
     }
     else if(!strcmp(com1,"SHOW")){
       if(strlen(in)>4)
         printf("too many parameter\n");
       else{
         printf("===Stack content===\n");
         printS(stack);
         enQueue(queue, in);
       }
     }
     else if(!strcmp(com1,"EMPTY")){
       if(strlen(in)>5)
         printf("too many parameter\n");
       else{
         emptyS(stack);
         enQueue(queue, in);
       }
     }
     else if(!strcmp(com1,"HELP")){
       if(strlen(in)>4)
         printf("too many parameter\n");
       else{
       }
     }
     else if(!strcmp(com1,"HISTORY"))
     {
       if(strlen(in)>7)
         printf("too many parameter\n");
       else
         printQ(queue);
     }
     else if(!strcmp(com1,"CLEARHISTORY")){
       if(strlen(in)>12)
         printf("too many parameter\n");
       else
         emptyQ(queue);
     }
     else
       printf("invalid command\n");
}

main()
{
      char com[20];
      struct Stack stack;
      initS(&stack);
      
      struct Queue queue;
      initQ(&queue);
      
      while(true){                      
        printf("comline>> ");
        gets(com);
        
        if(!strcmp("EXIT",com))
          break;

        read(&stack, &queue, com);
      }
}
