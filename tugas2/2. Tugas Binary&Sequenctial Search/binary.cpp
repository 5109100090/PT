#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main(){
    srand((unsigned)time(NULL));
    int i, j, N, src, opt, x[100];

    printf("#1 INPUT DATA\nopt 1 : input manual\nopt 2 : input random\nopt :");
    scanf("%d", &opt);
    printf("input N data :");
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

    printf("\n#2 DATA\n");
    for(i=0; i<N; i++)
        printf("%d ", x[i]);

    printf("\n\n#3 SEARCH DATA\ndata :");
    scanf("%d", &src);

    for(i=0; i<N; i++)
        if(x[i]==src){
            printf("data found on number %d\n", i+1);
            break;
        }

}