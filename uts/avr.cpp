/*
sum dengan 3 angka dibelakag koma
*/
#include <stdio.h>

main()
{
      int i,j,k,c,n;
      float b,a[100];
      
      while(true)
      {
                 scanf("%d",&n);

                 if(n==0) break;
                 else
                 {
                                  
                 for(i=0; i<n; i++)
                 scanf("%f",&a[i]);
                 
                 for(i=0,b=0; i<n; i++)
                 b=b+a[i];
                 
                 b=b/n;
                 
                 printf("%1.3f\n",b);
                 }
      }
}
