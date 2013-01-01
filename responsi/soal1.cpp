#include <stdio.h>

main()
{
      int a,tengah,i,batas;
      i=1;
      printf("masukkan angka ganjil:");
      scanf("%d",&a);
      
      if(a%2!=0)
      {
                batas=i;
                while(a>=i)
                {
                          printf("%d  ",a);
                          a-=1;
                }
      }
      
      //printf("masukkan angka ganjil");
}
