#include <stdio.h>
#include <stdlib.h>

main()
{
      int a,b,c,input,batastgh,batasawl,batastgh2;
      
      a=1;//inisialisasi looping ke samping
      b=1;//inisialisasi looping ke bawah
      c=1;

      //cek inputan harus ganjil
      //-------------------------------------      
      printf("Masukkan N:");
      scanf("%d",&input);
      
      while(input%2==0)
      {
                       printf("+---------------------------+\n");
                       printf("| N harus bilangan ganjil!! |\n");
                       printf("+---------------------------+\n\n");
                       printf("Masukkan N:");
                       scanf("%d",&input);
      }
      //-------------------------------------      

//BLOK1     
      batastgh=(input/2)+1;//batas tengah buat looping ke samping
      batastgh2=(input/2)+1;//batas tengah buat looping ke bawah      
      batasawl=1;
      
      //looping ke bawah, increase
      while(b<=batastgh2)
      {
          //looping ke kanan, increase
          while(a<=batastgh)
          {
                         printf("%d  ",a);
                         a++;
          }
          a-=2;
          
          //looping ke kanan, decrease
          while(a>=batasawl)
          {
                     printf("%d  ",a);
                     a--;
          }
    
          batastgh+=1;
          c++;//angka awal buat kolom
          a=c;//angka awal buat baris
          batasawl=a;
          printf("\n");
          
          b++;
      }
      
      
      
      //set semua variabel ke 2 angka sebelumnya dari angka sekarang
      //-----------
      a-=2;
      b-=2;
      c-=2;
      batasawl-=2;;
      batastgh-=2;
      //-----------      
      
      
//BLOK2 
      
      //looping kebawah, decrease
      while(b>=1)
      {

          //looping ke kanan, increase         
          while(a<=batastgh)
          {
                         printf("%d  ",a);
                         a++;
          }
          a-=2;
          
          //looping ke kanan, decrease
          while(a>=batasawl)
          {
                     printf("%d  ",a);
                     a--;
          }
    
          batastgh--;
          c--;//angka awal buat kolom
          a=c;//angka awal buat baris
          batasawl=a;
          printf("\n");
         
          
          b--;
      }
      
      
      a-=2;
      batasawl=1;
      batastgh-=2;
      system("pause");
}
