#include <stdio.h>

main()
{
      int a[1000],b[20][25],c[25][20],d,e,i,j,k,l;
      
      FILE *fo=fopen("input.txt","r");
      
      for(i=0; i<20; i++)
      {
        fscanf(fo,"%d",&a[i]);
        if(a[i]>25)
        break;
      }
      
      fclose(fo);
      
      l=i;
      d=a[0];
      for(i=1; i<l-1; i++)
        if(d<a[i])
        d=a[i];
      
      //for(i=0; i<l; i++)
      //printf("%d\n",a[i]);
      
      for(i=0; i<l; i++)
      {
        for(j=0; j<a[i]; j++)
        {
                 if(i%2==0)
                 b[i][j]=1;
                 else
                 b[i][j]=0;
        }
        
        for(j=a[i]; j<d; j++)
        b[i][j]=2;
      }  

      for(i=d-1, k=0; i>=0; i--, k++)
      {
        for(j=0; j<l; j++)
        c[k][j]=b[j][i];
      }

      FILE *f=fopen("output.txt","w");
      
      for(i=0, k=d; i<d; i++,k--)
      {
        fprintf(f,"%2d |",k);
        for(j=0; j<l; j++)
        {
                 if(c[i][j]==0)
                 fprintf(f,"## ");
                 else if(c[i][j]==1)
                 fprintf(f,"@@ ");
                 else
                 fprintf(f,"   ");
        }
        
        fprintf(f,"\n");
      }
      for(j=0; j<(l*2)+l+3; j++)
      fprintf(f,"-");
      fprintf(f,"\n");
      
      fprintf(f,"   ");
      
      for(j=0; j<l; j++)
      fprintf(f,"%3d",j+1);

      fclose(f);
}
