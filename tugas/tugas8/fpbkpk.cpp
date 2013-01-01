#include <stdio.h>

int fpb(int a, int b)
{
      int c,d,e;
      
      if(a<b)
      {
             d=b;
      }
      if(a>=b)
      {
              d=a;
      }
      
      c=1;      
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
      
      return e;
}

main()
{
      int a,x,y;
      
      printf("masukkan angka pertama :");
      scanf("%d",&x);
      
      printf("masukkan angka kedua   :");
      scanf("%d",&y);
      
      a=fpb(x,y);
      
      printf("FPB dari %d dan %d adalah %d\n",x,y,a);
      printf("KPK dari %d dan %d adalah %d",x,y,x*y/a);      
}
