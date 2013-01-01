#include <stdio.h>
#include <string.h>

main()
{
      int i,j,k,n,e,f;
      char a[1000],b[1000],g[1000];
      int c[1000],d[1000],h[1000];
      
      gets(a);
      gets(b);
      
      e=strlen(a);
      f=strlen(b);
      
      if(e>f)
      k=e;
      else
      k=f;
      
      for(i=0,j=e-1; i<e; i++,j--)
      g[i]=a[j];
      j=i;
      if(e<k)
      for(j=i; j<k; j++)
      g[j]='0';
      
      g[j]='\0';
      
      strcpy(a,g);
      
      for(i=0,j=f-1; i<f; i++,j--)
      g[i]=b[j];
      j=i;
      if(f<k)
      for(j=i; j<k; j++)
      g[j]='0';
      
      g[j]='\0';
      
      strcpy(b,g);
      
      for(i=0; i<e; i++)
      c[i]=a[i]-'0';
      
      for(i=0; i<f; i++)
      d[i]=b[i]-'0';
      
      h[0]=0;
      for(i=0; i<k; i++)
      {
           h[i]=h[i]+c[i]+d[i];
           
           if(h[i]>9 && i!=k-1)
           { h[i]=h[i]-10; h[i+1]=1; }
      }

      for(i=0,j=f-1; i<f; i++,j--)
      c[i]=h[j];
      c[i]='\0';


      for(i=0; i<k; i++)
      printf("%d",c[i]);      
}
