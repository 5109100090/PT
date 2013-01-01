#include <stdio.h>

main()
{
      int a, b;
      
      a=0;
x:      
      b=1;
      
      a=a+1;
      
      if(a<11)
      {
y:               
           printf("%d  ",a);
           
           if(a!=b)
           {
                   b=b+1;
                   goto y;
           }
           
           goto x;
      }
}
