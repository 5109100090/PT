#include <stdio.h>

main()
{
      int a,b,c,d,e;
      
      c=0;
      
      printf("masukkan angka pertama:");
      scanf("%d",&a);
      
      printf("masukkan angka kedua:");
      scanf("%d",&b);
      
      if(a<b)
      {
             d=b;
             goto x;
      }
      
      d=a;
      
x:
      c=c+1;
      
      if(c<=d)
      {
              if(a%c==0)
              {
                        if(b%c==0)
                        {
                                  e=c;
                                  goto x;
                        }
                        
                        goto x;
              }
              
              goto x;
      }
      
      printf("fpb dari %d dan %d adalah:%d",a,b,e);
}
