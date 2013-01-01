#include<stdio.h>
#include<stdlib.h>
#include<time.h>

main()
{
      //inisialisasi array
      int j;
      int A[10000];         
      j=0;
      
      srand((unsigned)time(NULL));
      int a,b,input,c,d,batas,i,x,y,z,k,l,temp;
      
      //inisialisasi untuk batas angka yang dirandom
      batas=100;
      i=1;
      //inisialisasi untuk input manual
      c=0;
      
      printf("pilih 1 atau 2: ");
      scanf("%d", &a);
      
      //pilihan untuk manual
      if(a==1)
      {
              printf("masukkan input anda: ");
              scanf("%d", &input);
              //looping menentukan bilangan yg diinginkan sampai bilangan itu sama dengan jumlah input
              while(c<input)
              {
                        c++;
                        printf("masukan bilangan ke %d : ", c);
                        scanf("%d", &d);
                        A[j]=d;
                        j++;
              }
              j=0; 
              //looping untuk menyortir bilangan yang paling kecil ditaruh sebelah kiri sendiri
              while(j<input)
              {
                       k=input-1;     
                       while(k>=(j+1))
                       {
                                      if(A[k] < A[k-1])
                                      {
                                              temp=A[k];
                                              A[k]=A[k-1];
                                              A[k-1]=temp;
                                      }
                                      k--;
                       }
                       printf("%d  ", A[k]);
                       j++;
              }
      }
      
      //pilihan untuk random
      if(a==2)
      {
              printf("masukkan input anda: ");
              scanf("%d", &input);
              
              //looping mengeluarkan angka random sampai batas nilai 100
              do
              {
                        x=rand()%batas;
                        y=rand()%2;
                        if(y==0)
                        {
                                x=x*(-1);
                        }
                        printf("Bilangan ke %d : %d\n", i, x);
                        A[j]=x;
                        j++;
                        i++;
              }while(i<=input);
               
               
               j=0;
               //looping untuk menyortir bilangan yang paling kecil ditaruh sebelah kiri sendiri
               while(j<input)
               {
                       k=input-1;           
                       while(k>=(j+1))
                       {
                                      if(A[k] < A[k-1])
                                      {
                                              temp=A[k];
                                              A[k]=A[k-1];
                                              A[k-1]=temp;
                                      }
                                      k--;
                       }
                       printf("%d  ", A[k]);
                       j++;
              }
      }
              
                         
}       
