#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int id;
  char subject[100];
  char date[100];
  char event[100];
} data;

int nData(int i)
{
  int n, end;
  FILE *fn = fopen("ndata.dat", "rb");
  
  if(fn==NULL)
  {
              FILE *f = fopen("ndata.dat", "wb");
              fprintf(f, "0 0");
              fclose(f);
  }
  fscanf(fn, "%d %d", &n, &end);
  fclose(fn);
  
  if(i==1)
    return n;
  else
    return end;
}

void viewMenu()
{
  data arr[100];
  int i, ndata;
  
  ndata=nData(1);
  
  //read data.dat
  FILE *f = fopen("data.dat", "rb");
  
  if(f==NULL)
      printf("#-NO EVENT-#\n");
  else
  {
      for (i=0; i<ndata; i++)
      fscanf(f, "%d%s%s%s", &arr[i].id, arr[i].subject, arr[i].date, arr[i].event);
      
      for (i=0; i<ndata; i++)
      {
          printf("#%d\n", arr[i].id);
          printf("subject\t\t: %s\n", arr[i].subject);
          printf("date&time\t: %s\n", arr[i].date);
          printf("event\t\t: %s\n", arr[i].event);
          printf("-----------\n");
      }
  }
  
  fclose(f);
}

void writeMenu()
{
  data *arr;
  int i,n,ndata,edata;
  
  printf("number of event :");
  scanf("%d",&n);
  
  arr=(data*)malloc(n*sizeof(data));
  
  for(i=0; i<n; i++)
  {
      printf("#%d\n",i+1);
      printf("subject\t\t: ");gets(arr[i].subject);
      if(i==0)gets(arr[i].subject);
      printf("date&time\t: "); gets(arr[i].date);
      printf("event\t\t: "); gets(arr[i].event);
      printf("-----------\n");
  }
   
    //write to data.dat
    FILE *f = fopen ("data.dat","ab");
    ndata=nData(1);
    edata=nData(2)+1;
    for(i=0; i<n; i++, edata++)
    {
        fprintf (f,"%d\n",edata);
        fprintf (f,"%s\n",arr[i].subject);
        fprintf (f,"%s\n",arr[i].date);
        fprintf (f,"%s\n",arr[i].event);
    }
    
    printf("#-SAVED-#\n");
    fclose (f);
    
    //edit ndata.dat
    FILE *fn = fopen("ndata.dat", "wb");
    fprintf(fn, "%d %d", ndata+n, edata-1);
    fclose(fn);
    
    free(arr);

}

void delMenu()
{
     int ndata, edata, n, i, j;
     data *arr;
     
     ndata=nData(1);
     edata=nData(2);
     
     arr=(data*)malloc(ndata*sizeof(data));
     
     printf("delete event :#");
     scanf("%d",&n);
     
     FILE *fr = fopen("data.dat", "rb");
     for(i=0, j=0; i<ndata; i++, j++)
     {
              fscanf(fr, "%d%s%s%s", &arr[j].id, arr[j].subject, arr[j].date, arr[j].event);
              if(arr[j].id==n)
              j--;
     }
     fclose(fr);
     
    //write to data.dat
    FILE *f = fopen ("data.dat","wb");
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
    FILE *fn = fopen("ndata.dat", "wb");
    fprintf(fn, "%d %d", ndata-1, edata);
    fclose(fn);
     
     free(arr);
}

int main ()
{
    int i=1,m;

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
          viewMenu();
        else if(m==2)
          writeMenu();
        else if(m==3)
          delMenu();
        else if(m==4)
          break;
        else
          printf("wrong input\n");
    }
  
  return 0;
}
