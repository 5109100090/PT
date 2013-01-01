#include <stdio.h>

main()
{
      int jumlahhari,jumlah,feb,tanggal,bulan,tahun,harike,total,h;
      int bln[12];
      
      scanf("%d-%d-%d",&tahun,&bulan,&tanggal);
      
   jumlahhari=0;
      if(tahun%4==0)
      {
                    jumlah=366;
                    feb=29;
      }
      jumlah=365;
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
      
      h=bulan;
      
      while(bulan<=11)      
      {
                            jumlahhari=bln[bulan]+jumlahhari;
                            bulan++;
      }
      
      h=h-1;
      harike=bln[h]-tanggal;
      total=jumlah-harike-jumlahhari;
      
      printf("%d",total);
}
