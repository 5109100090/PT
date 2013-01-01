#include <stdio.h>

main()
{
      int a;
      int b;
      a=1;
      b=100;
x:
      printf("%d   ",a);
      b=b-1;
      
      a=a+b;
      
      if(b>0)
      {
              printf("%d   ",a);
              b=b-1;
              
              a=a-b;
              
              if(b>0)
              {
                  goto x;
              }
              
      }
      
      b=0;
          
y:
      printf("%d   ",a);
      b=b+1;
              
      a=a-b;
              
      if(b!=100)
      {
             printf("%d   ",a);
             b=b+1;
           
             a=a+b;
              
             if(b!=100)
             {
                   goto y;
             }
       }
     
}
