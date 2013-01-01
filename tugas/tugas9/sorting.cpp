#include <stdio.h>
#include <string.h>

main()
{
      int a,b,c,d,h,j;
      char B[1][20],A[10][20];
      
      for(j=11; j>10; )
      {
          printf("input number of words (max 10): ");
          scanf("%d",&j);
      }
      
      printf("input %d words\n",j);
      
      for(d=0; d<j; d++)
      {
                 printf("word #%d :",d+1);
                 scanf("%s",A[d]);
      }
    
    printf("before sorting : ");
    for(d=0; d<j; d++)
    {
              printf("%s  ",A[d]);
    }
    printf("\n");      
      
    a=0;
    c=1;

    for(b=0; b<j; b++)
    {
          //cek per 2 kata 
          for(c=b+1; c<j; c++)
          {
                     if(strcmp(A[b],A[c])==1)
                     {
                                  strcpy(B[0],A[b]);
                                  strcpy(A[b],A[c]);
                                  strcpy(A[c],B[0]);             
                     }           
          }
    }

          printf("after sorting  : ");
          for(d=0; d<j; d++)
          {
                    printf("%s  ",A[d]);
          }
          
}
