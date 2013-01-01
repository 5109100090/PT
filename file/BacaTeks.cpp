#include <stdio.h>

/*typedef struct
{
  int a;
  char b[50];
  int c;
  int d;
} st;*/

int main()
{
  /*FILE *f = fopen("struct.txt", "r");
  
  st arr[10];
  int arr2[10];
  
  int i;
  
  
  for (i=0; i<3; i++)
  {
    fscanf(f, "%d%s%d%d", &arr[i].a, arr[i].b, &arr[i].c, &arr[i].d);
  }
  
  for (i=0; i<3; i++)
  {
    printf("%d-%s-%d-%d\n", arr[i].a, arr[i].b, arr[i].c, arr[i].d);
  }
  fclose(f);*/
  FILE *f = fopen("fileteks.txt", "r");
  
  int arr[50];
  int i;
  
  for (i=0; i<50; i++)
    fscanf(f, "%d", &arr[i]);
  
  for (i=0; i<50; i++)
    printf("%d\n", arr[i]);
    
  return 0;
}
