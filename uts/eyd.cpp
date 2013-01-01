#include <stdio.h>
#include <string.h>

main()
{
      int b,n,i,j;
      
      char a[100][100];
      
      scanf("%d\n",&n);
      
      for(i=0; i<n; i++)
      gets(a[i]);
      
      for(i=0; i<n; i++)
      {
               b=strlen(a[i]);
               if(a[i][0]>='a' && a[i][0]<='z')
               a[i][0]=a[i][0]-'a'+'A';
               
               
               for(j=1; j<b; j++)
               {
                        if(a[i][j]>='A' && a[i][j]<='Z')
                        a[i][j]=a[i][j]-'A'+'a';
                        else if(a[i][j]==' ')
                        {
                             if(a[i][j+1]>='a' && a[i][j+1]<='z')
                             a[i][j+1]=a[i][j+1]-'a'+'A';
                             else
                             a[i][j+1]=a[i][j+1];
                             
                             j++;
                        }
                        else
                        a[i][j]=a[i][j];
               }
      }
      
      for(i=0; i<n; i++)
      printf("%s\n",a[i]);
}
