#include <stdio.h>

main()
{
      int a,b,c,d,e;
      
      c=1;
      
      printf("masukkan angka pertama    :");
      scanf("%d",&a);
      
      printf("masukkan angka kedua      :");
      scanf("%d",&b);
      
      if(a<b)
      {
             d=b;
      }
      
      d=a;
      
      while(c<=d)
      {
              if(a%c==0)
              {
                        if(b%c==0)
                        {
                                  e=c;
                        }
              } 
              
              c++;               
      }



      
     
      printf("fpb dari %d dan %d adalah :%d",a,b,e);
}
