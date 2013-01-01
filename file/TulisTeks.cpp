#include <stdio.h>

int main()
{
  FILE *ft;
  ft = fopen("fileteks.txt", "w");
//  ft = freopen("fileteks.txt", "w", stdout);
  int arr[50];
  int i;
  
  for (i=0; i<50; i++)
  {
    arr[i] = i+1;
    fprintf(ft, "%d\n", arr[i]);
  }
    
  
  //fprintf(ft, "halo 3\n");
  //printf("sudah ditulis ke file\n");
  fclose(ft);
  
  return 0;
}
