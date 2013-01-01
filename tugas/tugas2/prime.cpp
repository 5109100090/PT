#include <stdio.h>

main()
{
      int a,b,c;
      
      a=1;
x:
      b=2;
y:
      a=a+1;
      
      if(a<1000)            
      {
z:
           c=a%b;
           
           if(c==0)
           {
                   if(a==b)
                   {
                           printf("%d  ",a);
                           goto x;
                   }
                   
                   goto y;
           }
           
           b=b+1;
           goto z;
      }
}
