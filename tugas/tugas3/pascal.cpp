#include <stdio.h>

main()
{
      int a,b,c,d,e,in;
      int A[100]={0,1};
      int B[100];
      int C[100];      
      
      printf("Masukkan tingi segitiga:");
      scanf("%d",&in);
      
      a=0;
      b=1;
      d=in;
      e=d;
      
      
      while(b<=in)
      {
                  while(d>=1)
                  {
                         printf("  ");
                         d--;
                  }
                                   
                  c=0;   
                  while(c<=a)
                  {
                         B[c]=A[c]+A[c+1];
                         //printf("B[%d]=A[%d]%d+A[%d+1]%d=%d  ",i,i,A[i],i,A[i+1],B[i]);
                         C[c+1]=B[c];
                         printf("%d   ",B[c]);
                         c++;
                  }
                  
                  C[0]=0;
                  C[a+2]=0;
                  
                  
                  
                  
                  c=0;
                  while(c<=a+2)
                  {
                               A[c]=C[c];
                               //printf("%d-",A[i]);
                               c++;
                               
                  }
                  
                  a++;
                  b++;
                  
                  d=e;           
                  d--;
                  e=d;                  
                  
                  //printf("a=%d,b=%d,in=%d,i=%d",a,b,in,i);
                  printf("\n");
      }
}
