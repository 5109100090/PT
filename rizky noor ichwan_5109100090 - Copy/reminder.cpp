#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int id;
  char subject[100];
  char date[100];
  char event[100];
} data;

void delMenu()
{
     int ndata, edata, n, i, j;
     data *arr;
     
     arr=(data*)malloc(ndata*sizeof(data));
     
     printf("delete event :#");
     scanf("%d",&n);
     
     FILE *fr = fopen("data.dat", "r");
     for(i=0, j=0; i<ndata; i++, j++)
     {
              fscanf(fr, "%d%s%s%s", &arr[j].id, arr[j].subject, arr[j].date, arr[j].event);
              if(arr[j].id==n)
              j--;
     }
     fclose(fr);
     
    //write to data.dat
    FILE *f = fopen ("data.dat","w");
    for(i=0; i<ndata-1; i++)
    {
        fprintf (f,"%d\n",arr[i].id);
        fprintf (f,"%s\n",arr[i].subject);
        fprintf (f,"%s\n",arr[i].date);
        fprintf (f,"%s\n",arr[i].event);
    }
    printf("#-DELETED-#\n");
    fclose (f);
    
    //edit ndata.dat
    FILE *fn = fopen("ndata.dat", "w");
    fprintf(fn, "%d %d", ndata-1, edata);
    fclose(fn);
     
     free(arr);
}

int main ()
{
    data arr[100];
    int i,j=0,m,n,ndata;

        printf("+-----REMINDER-----+\n");
        printf("|__________________|\n");
        printf("| (1) view event   |\n");
        printf("| (2) add event    |\n");
        printf("| (3) delete event |\n");
        printf("| (4) exit         |\n");
        printf("+------------------+\n");
    
    while(true)
    {
        printf("#MENU :");
        scanf("%d",&m);
        printf("\n");
        
        if(m==1)
{

  FILE *f = fopen("data.dat","rb");
  fread(&j, sizeof(j), 1, f);
  printf("%d\n",j);
  
  if(f==NULL)
      printf("#-NO EVENT-#\n");
  /*else
  {
      fread(&arr, 1, sizeof(arr), f);
      
      for (i=0; i<j; i++)
      {
          printf("#%d\n", arr[i].id);
          printf("subject\t\t: %s\n", arr[i].subject);
          printf("date&time\t: %s\n", arr[i].date);
          printf("event\t\t: %s\n", arr[i].event);
          printf("-----------\n");
      }
  }*/
  
  fclose(f);
}
        else if(m==2)
{

  FILE *f = fopen("data.dat","ab");
  
  if(f==NULL)
  {
             FILE *f = fopen("data.dat","wb");
             fwrite(&j, sizeof(j), 1, f);
  }

  fread(&j, sizeof(j), 1, f);
  printf("%d\n",j);
  
  printf("number of event :");
  scanf("%d",&n);
  
  for(i=0; i<n; i++)
  {
      printf("#%d\n",i+1); arr[i].id=j;
      printf("subject\t\t: "); gets(arr[i].subject);
      if(i==0)gets(arr[i].subject);
      printf("date&time\t: "); gets(arr[i].date);
      printf("event\t\t: "); gets(arr[i].event);
      printf("-----------\n");
  }
    
    fwrite(&arr, sizeof(arr), 1, f);
    j=j+n;
    fwrite(&j, sizeof(j), 1, f);
    
    printf("#-SAVED-#\n");
    
    fclose(f);
}
        else if(m==3)
          delMenu();
        else if(m==4)
          break;
        else
          printf("wrong input\n");
    }
  
  return 0;
}
