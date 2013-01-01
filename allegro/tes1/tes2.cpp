#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    srand((unsigned)time(NULL));
	int i,j,k,n,x[100],y[100];
    float a,b;
	n=50;
	
	FILE *f = fopen("text.txt", "w");
	
	fprintf(f, "%d\n",n);
	
	for(i=0; i<n; i++)
	{
       a=rand()%500;
       b=rand()%500;
       
       fprintf(f, "%f %f\n",a,b);
    }
	
	fclose(f);
}
