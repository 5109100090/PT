#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main(){
    srand((unsigned)time(NULL));
    int i, j, N, src, opt, temp, lo, mid, hi, f=false, x[100];

    printf("#1 INPUT DATA\nopt 1 : input manual\nopt 2 : input random\nopt :");
    scanf("%d", &opt);
    printf("input N data (0<N<100):");
    scanf("%d", &N);
    if(opt==1){
        for(i=0; i<N; i++){;
            printf("input data %d> ", i+1);
            scanf("%d", &x[i]);
        }
    }
    else
        for(i=0; i<N; i++)
            x[i]=rand()%100;
    
    printf("\n#2 DATA\noriginal data :\n");
    for(i=0; i<N; i++)
        printf("%d ", x[i]);
    
    for(i=0; i<N-1; i++)
        for(j=i+1; j<N; j++)
            if(x[i]>x[j]){
                temp=x[i];
                x[i]=x[j];
                x[j]=temp;
            }
    
    printf("\nafter sorted :\n");
    for(i=0; i<N; i++)
        printf("%d ", x[i]);

    printf("\n\n#3 SEARCH DATA\ndata :");
    scanf("%d", &src);

    clock_t first=clock();
    lo=0;
    hi=N-1;
    while(lo<=hi && !f){
        mid=(lo+hi)/2;
        if(x[mid]<src)
            lo=mid+1;
        else if(x[mid]>src)
            hi=mid-1;
        else
            f=true;
    }
    clock_t last=clock();
    if(f)
        printf("data found");
    else
        printf("data not found");

    printf("\ntime : %lf", (double)(last-first)/CLOCKS_PER_SEC);
}