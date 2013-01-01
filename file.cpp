/* fopen example */
#include <stdio.h>

int main ()
{
  FILE * f = fopen ("file.txt","a");
  if (f!=NULL)
  {
    int i;
    for(i=0; i<50; i++)
    {
             fprintf (f,"%d\n",i+1);
             fprintf (f,"%d\n",(i+1)*2);
             fprintf (f,"%c\n",i);
    }
    
    fclose (f);
  }
  else
  printf("no file!!");
  return 0;
}
