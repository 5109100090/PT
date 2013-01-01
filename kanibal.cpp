#include <stdio.h>
#include <stdlib.h>

main()
{
      int N, opt, p=0, p2, Nboat=0;
      int pulau[2][2], boat[2];
      char m[10];

          pulau[0][0]=3;
          pulau[0][1]=3;
          pulau[1][0]=0;
          pulau[1][1]=0;
          boat[0]=0;
          boat[1]=0;
      while(true)
      {
        //kanibal       =0
        //misionaris    =1
        p=(p%2);
        if(p) p2=0;
        else p2=1;
        printf("pulau                  : %d -> %d\n\n", p+1, p2+1);
        printf("pulau1  ->kanibal      : %d\n", pulau[0][0]);
        printf("pulau1  ->misonaris    : %d\n", pulau[0][1]);
        printf("boat    ->kanibal      : %d\n", boat[0]);
        printf("boat    ->misionaris   : %d\n", boat[1]);
        printf("pulau2  ->kanibal      : %d\n", pulau[1][0]);
        printf("pulau2  ->misonaris    : %d\n\n", pulau[1][1]);
        printf("1. tambah kanibal ke kapal\n2. tambah misionaris ke kapal\n3. pindah kanibal ke pulau\n4. pindah misionaris ke pulau\n5. pindah\noption : ");
        scanf("%d",&opt);
        
        system("cls");
        if(Nboat>2)
          printf("#full#\n");

        if((opt==1 || opt==2) && Nboat<2){
            Nboat++;
            if(opt==1)
            {
                  pulau[p][0]--;
                  boat[0]++;
            }else{
                  pulau[p][1]--;
                  boat[1]++;
            }
        }
        else if((opt==3 || opt==4) && Nboat>0){
            Nboat--;
            if(opt==3){
                  pulau[p][0]++;
                  boat[0]--;
            }else{
                  pulau[p][1]++;
                  boat[1]--;
            }
        }
        else if(opt==5 && Nboat>0 && Nboat<3){
          pulau[p2][0]=pulau[p2][0]+boat[0];
          pulau[p2][1]=pulau[p2][1]+boat[1];

          if((boat[0]!=0 && boat[1]!=0) && boat[0]>boat[1])
              { printf("You LOSE"); break; }
          if((pulau[p][0]!=0 && pulau[p][1]!=0) && pulau[p][0]>pulau[p][1])
              { printf("You LOSE"); break; }
          if((pulau[p2][0]!=0 && pulau[p2][1]!=0) && pulau[p2][0]>pulau[p2][1])
              { printf("You LOSE"); break; }

          boat[0]=0;
          boat[1]=0;
          Nboat=0;

          p++;
        }else if(opt==6)
          break;
        else
          printf("#invalid#\n");
      }
      
}
