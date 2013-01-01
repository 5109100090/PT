#include <stdio.h>

main()
{
      int a,b,c,d;
      
      printf("masukkan angka pertama:");
      scanf("%d",&a);
      
      printf("masukkan angka kedua:");
      scanf("%d",&b);
      
      c=a;
      d=b;
      
x:
      if(a==b)
      {
              goto z;
      }
      
      if(a<b)
      {
             a=a+c;
             
y:
             if(a==b)
             {
                     goto z;
             }
             
             goto x;
      }
      
      b=b+d;
      goto y;
      
z:
      printf("kpk dari %d dan %d adalah:%d",c,d,a);
}
