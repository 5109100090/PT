#include <stdio.h>

main()
{
      int i,j,k,c,n;
      char a[1000],b[1000];
      int c[1000],d[1000];
      
      gets(a);
      gets(b);
      
      for(i=0; a[i]!='\0'; i++)
      c[i]=a[i]+'0';

      for(i=0; b[i]!='\0'; i++)
      d[i]=b[i]+'0';
      
      for(i=0; a[i]!='\0'; i++)
      printf("%s\n",a);
      
      for(i=0; b[i]!='\0'; i++)
      printf("%s\n",b);
}
