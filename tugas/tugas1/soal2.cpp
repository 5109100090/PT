#include <stdio.h>

main()
{
      int a;
      int b;
      a=1;
      b=-1;
x:
      printf("%d  ",a);
      b=b+1;
      
      a=a+b;
      
      if(a<1000)
      {
                goto x;
      }
}
