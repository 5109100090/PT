#include <stdio.h>
main()
{
      int a,b,c;
      a=1;
      b=1;
      while(a<=5)
      {
                 while(b<=5)
                 {
                            printf("%d  ",b);
                            b++;
                 }
      b=1;
      a++;
      printf("\n");
      }
}
