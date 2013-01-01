#include <stdio.h>
#include <string.h>

main()
{
      int i,j,k,c,n;
      char x[100],y[100];
      
      while(true)
      {
                 gets(x);
                 
                 if(strcmp(x,"sindrom palindrom")==0)
                 break;
                 
                 for(j=0; x[j]!='\0'; )
                 j++;
                 
                 for(i=0; x[i]!='\0'; i++,j--)
                 y[i]=x[j-1];
                 
                 y[i]='\0';
                 
                 printf("%s%s\n",x,y);
      }
}
