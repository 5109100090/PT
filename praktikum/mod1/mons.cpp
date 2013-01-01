#include <stdio.h>
#include <ctype.h>
#include <string.h>

main()
{
      int i,j,k,n;
      
      char x[100][100],y[100],z[100];
      
      scanf("%d\n",&n);
      
      for(i=0; i<n; i++)
      gets(x[i]);
      
      for(i=0; i<n; i++)
      {

               for(j=0,k=0; x[i][j]!='\0'; j++)
               {
                        x[i][j]=tolower(x[i][j]);
                        if(x[i][j]>='a' && x[i][j]<='z')
                        {   
                            y[k]=x[i][j];
                            k++;
                        }
               }
               
               y[k]='\0';
               
               for(j=0,k=k-1; x[i][j]!='\0'; j++,k--)
               z[j]=y[k];
               
               z[j]='\0';
               
               if(strcmp(y,z)==0)
               printf("Ok dah kalau begitu..\n");
               else
               printf("Preettt...\n");
      }
      
      return 0;
}
