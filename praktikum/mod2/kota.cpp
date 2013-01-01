#include <stdio.h>   
#include <math.h>
   
float lokasi[100][2]; 
char kota[100];
int hasil[100]; 

double phy(float x,float y)
{
double a;
a=sqrt(x*x+y*y);
return a;
}

void cetak(int length)
{   
  int dist=0, x;     
  for(x=0; hasil[x]<length; x++)
  {   
      if(x>0)   
      dist+=(int)phy(lokasi[hasil[x]][0]-lokasi[hasil[x-1]][0],lokasi[hasil[x]][1]-lokasi[hasil[x-1]][1]);  
  }   
  printf("%.2f\n",dist);   
}   
    
void MasukkanPosisi(int length)
{
    int x;   
    for(x=0;x<length;x++)
    {   
    scanf("%f %f",&lokasi[x][0], &lokasi[x][1]);   
    fflush(stdin); 
    }  
}   
   
double jum_Kombinasi(int faktor)
{   
  if(faktor == 0)   
    return 1;   
  else   
    return faktor*jum_Kombinasi(faktor-1);
}   
   
void kota_kombinasi(int a, int kombinasi,int index,int length)
{   
  for(int b=a; b+kombinasi<=length; b++)
  {   
      hasil[index]=b;
      if(kombinasi==1)  
        cetak(length);
      else
        kota_kombinasi(b+1,kombinasi-1,index+1, length);
  }   
}   
       
int main()
{     
  int a=0,length,kombinasi;   
  scanf("%s", kota);   
  for(length=0;kota[length]!='\0';)
  length++;
  
  MasukkanPosisi(length);   
     
  do
    scanf("%d",&kombinasi);
  while(kombinasi>length && kombinasi<=1);

  printf("%.0f\n",jum_Kombinasi(length)/jum_Kombinasi(kombinasi)/jum_Kombinasi(length-kombinasi));   
  
  kota_kombinasi(a, kombinasi,0,length);   
  return 0;   
}    
