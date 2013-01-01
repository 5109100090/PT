#include<stdio.h>
#include<conio.h>
main()

{
      int input,a,b,c;
      a=0;
      b=0;
      
      do
      {
                       printf("masukan input: ");
                       scanf("%d", &input);
      }while(input%2==0);
     
     
      c=(input+1)/2;
      while(b<(input+2)/2)
      {
                          //looping naek
                          while(a<c)
                          {
                                              a=a+1;  
                                              printf("%d ",a);                  
                          }
                          //looping turun
                          while(a>b+1)
                          {
                                    a=a-1;
                                    printf("%d ",a);
                          }
      printf("\n");

      b=b+1;
      a=b;
      c=c+1;
      }
      
      while(b<input)
      {
                    a=a-1;
                    c=c-1;
                //looping naek
                while(a<c)
                {
                          printf("%d ",a);
                          a=a+1;
                }
                //looping turun
                a=a-1;
                while(a<c)
                {
                          a=a-1;
                          printf("%d ",a);
                          c--;
                }
                printf("\n"); 
                 
                b++; 
                                              
      
      }
      getch();
      return 0;
      
}
