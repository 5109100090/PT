#include <stdio.h>

main()
{
      int tahun,bulan,bulan2,tanggal,feb,a,sum;
      
      a=0;
      
      printf("masukkan tanggal(yyyy-mm-dd):");
      scanf("%d-%d-%d",&tahun,&bulan,&tanggal);
      
      bulan2=bulan;
      
      if(tahun%4==0)
      {
          feb=29;
      }
      if(tahun%4!=0)
      {
          feb=28;
      }    
      
      int arrbln[12]={31,feb,31,30,31,30,31,31,30,31,30,31};
      
      bulan-=2;
      
      while(bulan>=0)
      {
                 a+=arrbln[bulan];
                 bulan--;
      }
      
      sum=a+tanggal;
      
      printf("tanggal %d-%d-%d adalah hari ke-%d di tahun %d",tanggal,bulan2,tahun,sum,tahun);

}
