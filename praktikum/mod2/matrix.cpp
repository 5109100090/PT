#include <stdio.h> 

int hasil [100][100]; 
int pil, baris, kolom, limb, limk; 
    
    //menginisialisasikan kedua matrix dengan variabel global
    int A [100][100]; 
    int B [100][100];
    
void penjumlahan () 
{ 
    printf ("\n Hasil Penjumlahan Matriks A+B adalah : \n"); 
    for (baris=0;baris<limb;baris++) 
    { 
        for (kolom=0;kolom<limk;kolom++) 
        { 
            hasil[baris][kolom] = A[baris][kolom] + B[baris][kolom]; 
            printf ("%3d\t",hasil[baris][kolom]) ;
        } 
        printf ("\n"); 
    } 
} 
 
void antar () 
{ 
    int a; 
    printf ("\n Hasil Perkalian antara Matriks A*B adalah : \n"); 
    for (baris=0;baris<limb;baris++) 
    { 
        for (kolom=0;kolom<limb;kolom++) 
        { 
            for (a=0; a<limb;a++) 
                hasil[baris][kolom]= hasil[baris][kolom]+A[baris][a]*B[a][kolom]; 
            
            printf ("%3d\t",hasil[baris][kolom]); 
        } 
        printf ("\n"); 
    } 
}

void pengurangan () 
{ 
    printf ("\n Hasil Pengurangan Matriks A-B adalah : \n"); 
    for (baris=0;baris<limb;baris++) 
    { 
        for (kolom=0;kolom<limk;kolom++) 
        { 
            hasil [baris][kolom]= A[baris][kolom] - B[baris][kolom]; 
            printf ("%3d\t",hasil[baris][kolom]); 
        } 
        printf ("\n"); 
    } 
}  
   
void skalar (int skalar) 
{
    int iter;
    printf ("\n Hasil Perkalian Matriks dengan %d adalah : \n", skalar); 
    for(iter = 0; iter < 2; iter++)
    { 
        for (baris=0;baris<limb;baris++) 
        { 
            for (kolom=0;kolom<limk;kolom++) 
            { 
                if (iter==0) 
                hasil [baris][kolom]= A[baris][kolom]*skalar; 
                else 
                hasil [baris][kolom]= B[baris][kolom]*skalar; 
                
                printf ("%3d\t",hasil[baris][kolom]); 
            } 
            printf ("\n"); 
        } 
        printf("\n"); 
}    
}  

int main () 
{    
    scanf ("%d",&limb); 
    scanf ("%d",&limk); 

    for (baris=0;baris<limb;baris++) 
        for (kolom=0;kolom<limk;kolom++) 
        { 
            printf ("Matriks A elemen [%d,%d]: ",baris+1,kolom+1); 
            scanf ("%d",&A[baris][kolom]); 
            fflush(stdin); 
        } 
    printf ("\n"); 
    for (baris=0;baris<limb;baris++)         
        for (kolom=0;kolom<limk;kolom++) 
        { 
            printf ("Matriks B elemen [%d,%d]: ",baris+1,kolom+1); 
            scanf ("%d",&B[baris][kolom]); 
            fflush(stdin); 
        } 
        
    int someInt; 
    
    printf("Masukkan angka pengali skalar: "); 
    scanf ("%d",&someInt); 
     
    penjumlahan (); 
    pengurangan (); 
    skalar (someInt); 
    if (limb==limk) antar(); 
    return 0; 
}     
