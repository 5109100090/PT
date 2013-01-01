#include <stdio.h>


typedef struct
{
        char jdl[100];
        char peng[100];
        char pen[100];
        int jml;
}st;

main()
{
      st arr[50];
    int input,a,jml;
    char buku[100],peng[100],pen[100],inp='y';
    
    printf("MENU\n");
    printf("1. Input data\n");
    printf("2. Tampilkan data berdasar nomor record\n");
    printf("3. Tampilkan semua data\n");
    printf("4. Edit jumlah buku berdasar nomor record\n");
    printf("5. Total record\n");
    printf("6. Exit\n\n");
    
    printf("Pilihan Anda : ");
    scanf("%d",&a);
    if(a==1)
    {
            FILE *fb=fopen("input.dat","rb");
            
            while(inp=='y')
            {
            printf("judul buku : ");
            scanf("%s",arr[0].jdl);
            printf("pengarang : ");
            scanf("%s",arr[0].peng);
            printf("penerbit : ");
            scanf("%s",arr[0].pen);
            printf("jumlah buku : ");
            scanf("%d",&arr[0].jml);
            
            fwrite(arr, 1, sizeof(arr), fb);
            
            printf("Input lagi?");
            scanf("%c",&inp);
            }
            
            fclose(fb);
    }
    
}
