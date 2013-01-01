#include <stdlib.h>
#include <time.h>
#include <stdio.h>

main()
{
      int a,c,PjgStr,random;
      char B[15],C[15],x,
      A[10][15]={"purwodadi","pekalongan","magelang","rembang","blora","cilacap","karanganyar","purwokerto","jepara","brebes"};
      
      srand((unsigned)time(NULL));
      random=rand()%10;

      //length of string
      PjgStr=0;
      while(A[random][PjgStr]!='\0')
      {
                       PjgStr=PjgStr+1;
      }
      
      
      a=0;
      while(a<PjgStr)
      {
            B[a]=' ';
            a=a+1;
      }      

      c=0;
      while(c<=PjgStr)
      {
                 system("cls");                

                  printf("+---------------------------+\n");
                  printf("|        HANGMAN GAME       |\n");
                  printf("| Name of Central Java City |\n");
                  printf("+---------------------------+\n");
      
                 a=0;
                 while(a<PjgStr)
                 {
                           printf("%c",B[a]);
                           a=a+1;
                 }
                 
                 printf("\n");
                 
                 a=0;
                 while(a<PjgStr)
                 {
                           printf("-");
                           a=a+1;
                 }
                 
                 printf("\n");
                 
                 if(c==PjgStr)
                 {
                              printf("you win!!");
                 }
                 if(c!=PjgStr)
                 {
                              printf("guess letter : ");
                              scanf("%c",&x);
                 }

                 
                 a=0;
                 while(a<PjgStr)
                 {
                           if(x==A[random][a])
                           {
                                      B[a]=A[random][a];
                                      c=c+1;
                           }
                           a=a+1;
                 }
      }
}
