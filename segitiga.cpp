#include <stdio.h>

main()
{
      int b,c,d,e,f,in;

      
      printf("Masukkan tingi segitiga:");
      scanf("%d",&in);
      
      
      b=1;

      
      f=in;
      d=in;
      
      c=in;
      e=c;
      
      
      while(b<=in)
      {
                  while(1<=f)
                  {
                         printf(" ");
                         f--;
                  }
                                   
                  while(c<=in)
                  {
                         printf("*");
                         c++;
                  }
                  
                  
                  f=d;
                  f--;
                  d=f;
                  
                  b++;
                  
                  c=e;
                  c--;
                  e=c;
                  printf("\n");
      }
                  
                  
}
