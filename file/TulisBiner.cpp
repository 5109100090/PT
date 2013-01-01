#include <stdio.h>
#include <string.h>

typedef struct
{
  int a;
  char b[50];
  int c;
  int d;
} st;

int main()
{
  FILE *fb = fopen("FileBiner.dat", "wb");
  
  st arr[50];
  int i;
  
  for (i=0; i<7; i++)
  {
    arr[i].a = i+1;
    strcpy(arr[i].b, "tes");
    arr[i].c = i*2;
    arr[i].d = i*2+4;
  }
  
//  fwrite(arr, 
  fwrite(arr, sizeof(st), 50, fb);
  fwrite(arr, 1, sizeof(arr), fb);
  fclose(fb);
  
  return 0;
}
