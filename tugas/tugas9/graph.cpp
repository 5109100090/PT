#include <stdio.h>
#include <math.h>

void spasi(int n,int m)
{
             for(; n>0; n--)
             {
                       if(m==0)
                       printf(" ");
                       
                       if(m==1)
                       printf("*");
             }
}

main()
{
      int a,b;
      double j,k,pi = M_PI;
      
      for(k=0; k<=2*pi; k=k+pi/20)
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
      }

}
