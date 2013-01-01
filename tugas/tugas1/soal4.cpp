#include <stdio.h>

main()
{
      int a, b, c, d;
      
      a=1;
      b=1;
      c=0;
      d=0;
      
      printf("%d  ",a);
x:
      a=b;
      c=b+d;
      b=c;
      printf("%d  ",b);
      
      d=b;
      c=b+a;
      b=c;
      
      if(b<1000)
      {
                printf("%d  ",b);
                goto x;
      }
}
