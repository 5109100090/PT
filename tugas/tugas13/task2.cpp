#include <stdio.h>
#include <stdlib.h>

main()
{
      int a,b,i,j,n,*m;
      
      printf("input n :"); scanf("%d",&n);
      
      m=(int*)malloc(n*sizeof(int));
      
      for(i=0; i<n; i++) m[i]=1;
      
      for(a=0; a<n ;)
      {
               for(i=0,a=0; i<n; i++)
               if(m[i]==n) a++;
                              
               for(i=0; i<n; i++) printf("%d",m[i]);
               
               printf("\n");

               m[n-1]++;

               for(i=1; i<=n; i++)
               if(m[n-i]>n)
               {
                           b=0; b++;
                           for(j=1; j<n; j++)
                           if(m[n-j]==n) b++;
                           
                           m[n-i-1]++;
                           
                           if(b==n-1)
                           {
                                     if(n!=2) m[0]++;
                                     for(j=1; j<n; j++) m[n-j]=m[0];
                           }
                           else
                           for(j=1; j<=i; j++) m[n-j]=m[n-i-1];
               }
      }
      
      free(m);
}
