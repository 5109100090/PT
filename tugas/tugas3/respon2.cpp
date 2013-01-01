/*
looping 1= looping pertama
looping 2= looping kelanjutan dari looping 1
looping 3= looping ke bawah
*/

#include <stdio.h>
#include <stdlib.h>

main()
{
      int a,b,c,d,input,batas1;
      a=1;//set angka awal looping 2
      b=1;//set angka awal looping 3
      
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
            
      batas1=input;//pembatas dari looping 2
      c=input+1;//c digunakan untuk inisialisasi dari looping 1
      d=c;//simpan value awal dari c
      
      //looping 3
      while(b<=input)
      {
          //looping 1
          while(c<=input)
          {
                        printf("%d  ",c);
                        c++;
          }
          
          //looping 2
          while(a<=batas1)
          {
                         printf("%d  ",a);
                         a++;
          }
          a=1;//reset angka awal looping 2
          c=d;//ambil value c yg lama
          c--;//decrease c
          d=c;//set value c yg baru
          batas1--;//decrease batas dari looping 2
          printf("\n");
          b++;//increase looping 3
      }
      system("pause");
}
