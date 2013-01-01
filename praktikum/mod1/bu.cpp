#include <stdio.h>

char A[50][50];
int x, y, n=0;

void track(int x2, int y2, int count)
{
     int i, j, k, x1, y1;
     
     for(i=1; i<=4; i++)
     {
              x1=x2; y1=y2;
              
              if(i==1) y1--;
              else if(i==2) x1++;
              else if(i==3) y1++;
              else x1--;
              
              if(x1>=0 && x1<x && y1>=0 && y1<y)
              {
                  if(A[x1][y1]=='o')
                  {
                      A[x1][y1]='x';
                      
                      track(x1, y1, count+1);
                      
                      A[x1][y1]='o';
                  }
                  
                  if(A[x1][y1]=='M')
                  {
                     if(n<1)
                     printf("%d\n",count+1);
                     
                     n++;
                  }
              }
     }
}

main()
{
      int i,j,k,n,x1,y1;
      
      scanf("%d%d",&x,&y);
      
      for(i=0; i<y; i++)
        scanf("%s",A[i]);
      
      for(i=0; i<y; i++)
      {
          for(j=0; j<x; j++)
            if(A[i][j]=='T')
            {
                            x1=j;
                            y1=i;
            }
      }
      
      track(x1, y1, 0);
      
      return 0;
}
