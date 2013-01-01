#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{
      int batas, x, i;
      
      batas=100;
      i=1;
      
      srand((unsigned)time(NULL));
      
      while(i<=10)
      {
                  x=rand()%batas;
                  
                  printf("%d\n",x);
                  
                  i++;
      }
}
