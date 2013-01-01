#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{
      srand((unsigned)time(NULL));
      
      int a[15],avr,i,j,x;
      
      scanf("%d",&x);
      
      for(i=0; i<x; i++)
      scanf("%d",&a[i]);
      
      for(i=0,avr=0; i<x; i++)
      avr=avr+a[i];
      
      avr=avr/x;
      
      for(i=0,j=0; i<x; i++)
      if(a[i]>avr) j++;
      
      printf("%d\n",j);
      
      return 0;
}
