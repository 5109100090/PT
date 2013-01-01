#include <stdio.h>

main()
{
      int a,b,c,d,input;
      
      
      a=5;
      b=1;
      input=5;
      c=input;
      d=a;
      
      while(b<=input)
      {
         printf("a=%d,b=%d,c=%d,d=%d",a,b,c,d);  
      while(a<=c)
      {
                     printf("(%d)  ",a);
                     a++;
      }
      
      a=d;
      a--;
      d=a;
      b++;
      printf("\n");
      }
}
