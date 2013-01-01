#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{     
      int **m,**n,i,j,o,p,a,b,r,jmlTtg,gen;
            
      srand((unsigned)time(NULL));
      
      printf("input width  :"); scanf("%d",&b);
      printf("input height :"); scanf("%d",&a);

      m=(int**)malloc(a*sizeof(int*));
      for(int i=0; i<a; i++) m[i]=(int*)malloc(b*sizeof(int));
      
      
      n=(int**)malloc(a*sizeof(int*));
      for(int i=0; i<a; i++) n[i]=(int*)malloc(b*sizeof(int));
      
      for(i=0; i<a; i++)
      for(j=0; j<b; j++) { r=rand()%2; m[i][j]=r; n[i][j]=r; }
      
      for(gen=1;true;gen++)
      {
              system("cls"); 
              for(i=0; i<a; i++)
              {
                       for(j=0; j<b; j++) printf("%c",m[i][j]);
                       printf("\n");
              }
              
              for(i=0; i<b; i++) printf("-");
              
              printf("\nGenereation %d",gen);
                            
              _sleep(100);
                               
              for(i=0; i<a; i++)
              {
                       for(j=0; j<b; j++)
                       {
                                jmlTtg=0;
                                for(r=1; r<=8; r++)
                                {
                                         o=i; p=j;
                                         
                                         if(r==1) { o--; }//cek_atas
                                         else if(r==2) { o--; p++; }//cek_atas_kanan
                                         else if(r==3) { p++; }//cek_kanan
                                         else if(r==4) { o++; p++; }//cek_kanan_bawah
                                         else if(r==5) { o++; }//cek_bawah
                                         else if(r==6) { o++; p--; }//cek_bawah_kiri
                                         else if(r==7) { p--; }//cek_kiri
                                         else { o--; p--; }//cek_atas
                                         
                                         if(o>=0 && o<a && p>=0 && p<b && m[o][p]==1) jmlTtg++;
                                }
                                if(m[i][j]==0 && jmlTtg==3) n[i][j]=1;
                                else if(jmlTtg<2 || jmlTtg>3) n[i][j]=0;
                       }
              }      
        
              for(i=0; i<a; i++)
              for(j=0; j<b; j++) m[i][j]=n[i][j];
      }

      for(i=a-1; i>=0; i--) { free(n[i]); free(m[i]); }
      free(n); free(m);
}
