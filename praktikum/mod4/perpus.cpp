#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

 typedef struct
{
        int id;
        char judul[100];
        char peng[100];
        char pener[100];
        int jml;
}perpus;

int main()
{
    FILE *f;
    int id=0, record=0, pil, nrec = 1, input2, jumlah;
    char input, exit='t', menu;
    perpus per;
    f=fopen("per.dat","rb");
    if(f==NULL){
                f=fopen("per.dat","wb");
                fwrite(&id,sizeof(id),1,f);
                }
    fclose(f);
    
    while(exit!='y'){
    system("cls");
                     
    printf("MENU\n");
    printf("1. Input Data\n");
    printf("2. Tampikan semua data berdasar nomor record\n");
    printf("3. Tampilkan semua data\n");
    printf("4. Edit jumlah buku berdasarkan nomor record\n");
    printf("5. Total Record\n");
    printf("6. Exit\n");
    printf("\n");
    printf("Pilihan Anda: ");
    scanf("%d",&pil);
    fflush (stdin);
    
    menu='y';
    
    while(menu=='y')
    {
        if(pil==1)
        {
             input='y';
             while(input=='y')
             {
                 f = fopen("per.dat","rb+");
                 fread(&nrec,sizeof(nrec),1,f);
                 //printf("banyak data : %d",nrec);
                 fseek(f,sizeof(nrec)+sizeof(per)*nrec,SEEK_SET);
                 // fread(&nrec,sizecd
               
                nrec++;
                per.id=nrec;
                
                printf("judul buku     :"); fflush(stdin);
                gets(per.judul);
                printf("nama pengarang :");
                gets(per.peng);
                printf("nama penerbit  :");
                gets(per.pener);
                printf("jumlah buku    :");
                scanf("%d",&per.jml);
                
                fwrite(&per,sizeof(per),1,f);
                fseek(f,0,SEEK_SET);
                fwrite(&nrec,sizeof(nrec),1,f);
                
                fclose(f);
                
                printf("Input lagi?"); fflush(stdin);
                scanf("%c",&input);
            }
        }
        
        else if(pil==2)
        {
                   input='y';
                   while(input=='y')
                   {
                     printf("nomor record dari data yang ingin anda cari: "); scanf("%d",&input2);
                     
                     f = fopen("per.dat","rb");
                     fread(&nrec,sizeof(nrec),1,f);
                     
                     if(input2>nrec)
                         printf("nomor record tak absah\n");
                     else
                         for(int i=0;i<nrec;i++)
                         {
                                 fread(&per,sizeof(per),1,f);
                                 if(input2==per.id)
                                 {
                                 printf("no record   : %d\n",per.id);
                                 printf("judul buku  : %s\n",per.judul);
                                 printf("pengarang   : %s\n",per.peng); 
                                 printf("penerbit    : %s\n",per.pener);
                                 printf("jumlah buku : %d\n",per.jml);
                                 }
                         }
                     fclose(f);
                     
                     printf("mau mencari lagi(y/t)?");
                     fflush(stdin); scanf("%c",&input);
                 
                   }
        }
        
        else if(pil==3)
        {
             int i;
                 for(i=0; i<79; i++)
                 printf("=");
                 
                 printf("\n");
                 
                 printf("|No Judul\t\tPengarang\t\tPenerbit\t\tJumlah|\n");

                 for(i=0; i<79; i++)
                 printf("=");

                 printf("\n");

                 f = fopen("per.dat","rb");
                 fread(&nrec,sizeof(nrec),1,f);
                 for(i=0;i<nrec;i++)
                 {
                         printf("|");
                         fread(&per,sizeof(per),1,f);
                         printf("%d. ",per.id);
                         printf("%s",per.judul);
                         printf("%19s",per.peng); 
                         printf("%28s",per.pener);
                         printf("%18d   |\n",per.jml);
                 }

                 for(i=0; i<79; i++)
                 printf("=");
                 
                 printf("\n");
                 
                 fclose(f);
        }
        
        else if(pil==4)
        {
                   input='y';
                   while(input=='y')
                   {
                     printf("nomor record dari data yang ingin anda ubah: "); scanf("%d",&input2);
                     
                     f = fopen("per.dat","rb");
                     fread(&nrec,sizeof(nrec),1,f);
                     
                     if(input2>nrec)
                         printf("nomor record tak absah\n");
                     else
                         for(int i=0;i<nrec;i++)
                         {
                                 fread(&per,sizeof(per),1,f);
                                 if(input2==per.id)
                                 {
                                 printf("no record   : %d\n",per.id);
                                 printf("judul buku  : %s\n",per.judul);
                                 printf("pengarang   : %s\n",per.peng); 
                                 printf("penerbit    : %s\n",per.pener);
                                 printf("jumlah buku : %d\n",per.jml);
                                 printf("jumlah buku pengganti: ");
                                 fflush(stdin);
                                 scanf("%d",&per.jml);
                                 
                                 f = fopen("per.dat","rb+");
                                 
                                 fseek(f,sizeof(nrec)+sizeof(per)*(input2-1),SEEK_SET);
                                 fwrite(&per,sizeof(per),1,f);
                                 
                                 fclose(f);
                                 
                                 break;
                                 }
                         }
                     fclose(f);
                     
                     printf("ingin meng-edit lagi(y/t)?");
                     fflush(stdin); scanf("%c",&input);
                 
                   }
        }
        
        else if(pil==5)
        {
                   f = fopen("per.dat","rb+");
                   fread(&nrec,sizeof(nrec),1,f);
                   printf("Total Record : %d\n",nrec);
                   
                   fclose(f);
        }
        
        else
        { exit='y'; menu='t'; }
        
        if(pil!=6)
        {
            printf("back to Menu(Y)/EXIT(T)?");
            fflush(stdin);
            scanf("%c",&menu);
            
            if(menu=='T')
            exit='y';
        }
    
        }//tutup menu
        }//tutup exit
    
}
