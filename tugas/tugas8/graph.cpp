#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void spasi(int n,int m)
{
             while(n>0)
             {
                       if(m==0)
                       printf(" ");
                       
                       if(m==1)
                       printf("*");
                       n--;
             }
}

main()
{
      int a,b;
      double j,k,pi = M_PI;
      
      k=0;
      while(k<=2*pi)
      {               
              j=39+38*sin(k);
              b=(int)j;
              
              if(b>=39)
              {
                       spasi(39,0);
                       
                       if(b!=39)
                       printf("|");
                       
                       spasi(b-39,1);
                       printf("*\n");
              }
              if(b<39)
              {
                      spasi(b,0);
                      printf("*");
                      spasi(38-b,1);
                      printf("|\n");
              }
              spasi(39,0);
              printf("|\n");
              
              k=k+pi/20;
      }

}
