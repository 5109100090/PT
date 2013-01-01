#include <stdio.h>

int main()
{
  FILE *fin = fopen("input.txt","r");
  FILE *fout = fopen("output.txt", "w");
  
  int N;
  int i, j, k;
  
  fscanf(fin, "%d", &N);
  
  for (i=1; i<=N; i++)
  {
    int X;
    fscanf(fin, "%d", &X);
    
    for (j=1; j<=X; j++)
    {
      for (k=1; k<=j; k++)
        fprintf(fout, "* ");
      fprintf(fout, "\n");
    }
  }
  
  fclose(fin);
  fclose(fout);
  return 0;
}
