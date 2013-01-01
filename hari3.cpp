#include <stdio.h>

main()
{
      int tahun,bulan,tanggal,feb,a,tot;
      int bln[12];
      
      a=0;
      
      scanf("%d-%d-%d",&tahun,&bulan,&tanggal);
      
      if(bulan==0)
      {
                  tot=tanggal;
      }
      else
      {
          
      if(tahun%4==0)
      {
                    feb=29;
      }
      feb=28;
      
      bln[0]=31;
      bln[1]=feb;
      bln[2]=31;
      bln[3]=30;
      bln[4]=31;
      bln[5]=30;
      bln[6]=31;
      bln[7]=31;
      bln[8]=30;
      bln[9]=31;
      bln[10]=30;
      bln[11]=31;
      
      bulan=bulan-2;
      
      while(bulan>=0)
      {
                 a=a+bln[bulan];
                 bulan--;
                 
                 //printf("%d  ",bulan);
                 //bulan=bulan-1;
      }
      
      tot=a+tanggal;

      }

      printf("%d ",tot);
}
