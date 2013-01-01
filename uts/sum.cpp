/*
jumlah dari tiap digit
*/
#include <stdio.h>
#include <string.h>

main()
{
      int n,i,j,k,sum;
      
      char a[100][100];
      int b[100];
      
      scanf("%d",&n);
      
      for(i=0; i<n; i++)
      scanf("%s",a[i]);
      
      for(i=0; i<n; i++)
      {
               /*sum=10;
               while(sum>9)
               {*/
                   j=0;
                   while(a[i][j]!='\0')
                   {
                                       b[j]=a[i][j]-'0';
                                       j++;
                   }
                   
                   sum=0;
                   for(k=0; k<j; k++)
                   sum=sum+b[k];
                   
                   strcpy(a[i],sum);
              // }
               printf("%d\n",sum);
      }
      
      //for(i=0; i<n; i++)
      //printf("%s\n",a[i]);
}
