#include <stdio.h>
#include <string.h>

main()
{
      int a,b,c,d,h,j;
      char B[1][20],A[10][20];
      
      j=11;
      while(j>10)
      {
          printf("input number of words (max 10): ");
          scanf("%d",&j);
      }
      
      printf("input %d words\n",j);
      
      d=0;
      while(d<j)
      {
                 printf("word #%d :",d+1);
                 scanf("%s",A[d]);
                 d++;
      }
    
    printf("before sorting : ");
    d=0;
    while(d<j)
    {
              printf("%s  ",A[d]);
              d++;
    }
    printf("\n");      
      
    a=0;
    b=0;
    c=1;

    while(b<j)
    {
          c=b+1;
          //cek per 2 kata 
          while(c<j)
          {
                  h=0;
                  a=0;
                  //cek per huruf
                  while(h==0)
                  {
                          if(A[b][a]<A[c][a])
                          {
                                             h=1;
                          }
                          if(A[b][a]>A[c][a])
                          {
                                                //tukar
                                                strcpy(B[0],A[b]);
                                                strcpy(A[b],A[c]);
                                                strcpy(A[c],B[0]);
                                                h=1;
            
                          }
                          a++;
                  }
                  c++;
          }
          b++;

    }

          printf("after sorting  : ");
          d=0;
          while(d<j)
          {
                    printf("%s  ",A[d]);
                    d++;
          }
          
}
