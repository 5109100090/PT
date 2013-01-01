#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
      int a,b;
      FILE *f = fopen("ndata.dat","rb");
      
      fread(&a, 1, sizeof(a), f);
      //fread(&b, 1, sizeof(a), f);
      
      printf("%d-%d",a,b);
      
      fclose(f);
}
