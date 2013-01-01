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
  FILE *fin = fopen("FileBiner.dat", "rb");
  
  st arr[50];
  
  fread(arr, 1, sizeof(arr), fin);
  int i,x=1;
  
  for (i=0; true; i++)
  {
    if(arr[i].a!=i+1)
    break;
    
    printf("%d\n", arr[i].a);
    printf("%s\n", arr[i].b);
    printf("%d\n", arr[i].c);
    printf("%d\n", arr[i].d);
    printf("\n");
  }
  
  return 0;
}
