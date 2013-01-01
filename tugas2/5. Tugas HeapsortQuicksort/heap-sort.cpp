#include <stdio.h>
#include <conio.h>

void createHeap(int X[], int n){
     int i, x, s, f;
     
     for(i=1; i<=n-1; i++){
         x=X[i];
         s=i;
         f=(s-1)/2;
         
         while(s>0 && X[f]<x){
             X[s]=X[f];
             s=f;
             f=(s-1)/2;
         }
         X[s]=x;
     }
}

void sortHeap(int X[], int n){
     int i, x, s, f;
     for(i=n-1; i>=1; i--){
                x=X[i];
                X[i]=X[0];
                f=0;
                
                if(i==1)
                  s=-1;
                else
                  s=1;
                  
                if(i>2 && X[2]>X[1])
                  s=2;
                  
                while(s>-0 && x<X[s]){
                           X[f]=X[s];
                           f=s;
                           s=2*f +1;
                           
                           if(s+1 < i-i && X[s]<X[s+1])
                             s=s+1;
                           if(s>i-1)
                             s=-1;
                }
                X[f]=x;
     }
}

void print(int X[], int n){
     for(int i=0; i<=n-1; i++)
         printf("%d ", X[i]);   
     printf("\n");  
}

main()
{
    int X[9], n;
    printf("enter N :\n");
    scanf("%d", &n);
    printf("enter %d data :\n", n);
    for(int i=0; i<n; i++){
      printf("%d> ",i+1);
      scanf("%d", &X[i]);
    }
    
    printf("Data         : ");
    print(X, n);
    createHeap(X, n);
    
    printf("Heap Tree    : ");
    print(X, n);
    sortHeap(X, n);
    
    printf("Sorted Heap  : ");
    print(X, n);
    
    getch();
}
