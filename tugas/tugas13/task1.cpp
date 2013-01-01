#include <stdio.h>
#include <stdlib.h>

int pow(int n,int m)
{
    int a=n,i;
    for(i=0; i<m-1; i++) a=a*n;
    return a;
}

main()
{
      int a,i,j,n,*m;
      
      printf("input n :"); scanf("%d",&n);
      
      m=(int*)malloc(n*sizeof(int));
      
      for(i=0; i<n; i++) m[i]=1;
      
      for(i=0; i<pow(n,n); i++)
      {
               for(j=0; j<n; j++) printf("%d",m[j]);
               printf("\n");
               
               m[n-1]++;
               
               for(j=1; j<=n; j++)
               if(m[n-j]>n)
               {
                        m[n-j-1]++;                           
                        m[n-j]=1;
               }
      }
      
      free(m);
}
