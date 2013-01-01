#include <stdio.h>
#include <string.h>

main()
{
      int i,j,k,l;
      char inp[100],y[5]={'a','i','u','e','o'};
      
      while(true)
      {
                 gets(inp);
                 
                 if(strcmp(inp,"aiueo")==0)
                 break;
                 
                 for(j=0,l=0; inp[j]!='\0'; j++)
                 {
                          for(i=0,k=0; i<5; i++)
                          {
                                   if(inp[j]==y[i])
                                   k++;
                          }
                          
                          if(k==0)         
                          l++;
                 }
                 
                 printf("%d\n",l);
      }
      
}
