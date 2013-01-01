/*
Game Tree Tic Tac Toe
Nama    : Rizky Noor Ichwan
NRP     : 5109100090
*/

#include <stdio.h>
#include <stdlib.h>

int pos_X[3][3], pos_O[3][3], pos[3][3];
int win = 0, false_X = 0, false_O = 0, chk = 0;
char X[20], O[20];

void board();
void player_X();
void player_O();
void player_win();
void check();

main()
{
	int i, j, opt;
	char ans;
	
	do
	{
         printf("TIC-TAC-TOE\n");
         printf("-----------");
         
         printf("\n1) Play");
         printf("\n2) Exit");
         printf("\nOption : ");
         scanf("%d", &opt);
         
         if(opt==1)
         {
             chk = 0;
             win = 0;
             for(i = 1; i <= 3; i++)
             for(j = 1; j <= 3; j++)
             {
                 pos_X[i][j] = 0;
                 pos_O[i][j] = 0;
                 pos[i][j] = 0;
             }
             printf("\n\n");
             system("CLS");
                             
             printf("\nMasukkan nama pemain !!\n");
             printf("player X : ");
             fflush(stdin);
             gets(X);
             printf("\nplayer O : ");
             fflush(stdin);
             gets(O);
             board();
                             
             while(true)
             {
                 if(win == 1)
                 break;
                 check();
                                    
                 if(chk == 9)
                 {
                     printf("\n\t\t\tMATCH DRAWS!!");
                     system("PAUSE");
                     break;
                 }
                 else
                     chk = 0;
                                   
                 printf("\nTURN FOR %s:", X);
                 player_X();
                                    
                 while(false_X == 1)
                 {
                     if(false_X != 1)
                     break;
                     false_X = 0;
                     printf("\nTURN FOR %s:", X);
                     player_X();
                 }
                                   
                 check();
                 if(chk == 9)
                 {
                     printf("\n\t\t\tMATCH DRAWS");
                     system("PAUSE");
                     break;
                 }
                 else
                     chk = 0;
                 printf("\nTURN FOR %s:", O);
                 player_O();
                                   
                 while(false_O == 1)
                 {
                     if(false_O != 1)
                         break;
                     false_O = 0;
                     printf("\nTURN FOR %s:", O);
                     player_O();
                 }
             }
                             
             board();
             if(win != 1)
             {
                 printf("\n\t\t\tMATCH DRAWS!!");
                 system("PAUSE");
             }
         }          
         else if(opt==2)
             exit(1);
                             
         printf("\nWants to play (Y/N) ? ");
         fflush(stdin);
         scanf("%c", &ans);
    } while(ans == 'y' || ans ==' Y');
}

void board()
{
     int i, j;
     system("CLS");
     
     printf("TIC-TAC-TOE\n");
     printf("-----------");
     printf("\n\t\t\t1\t2\t3");
     
     for(i = 1; i <= 3; i++)
     {
           printf("\n\t\t\t _____________________________");
           printf("\n \t\t\tº\t  º\t   º\t     º");
           printf("\n\t\t%d\t",i);
           
           for(j = 1; j <= 3; j++)
           {
                 if(pos_X[i][j] == 1)
                                printf("    X     ");
                 else if(pos_O[i][j] == 1)
                      printf("    O     ");
                 else
                 {
                     printf("          ");
                     continue;
                 }
           }
           printf("\n\t\t\tº\t  º\t   º\t     º");
     }
	 printf("\n\t\t\t------------------------------");
	 player_win();
}

void player_X()
{
     int row,col;
     
     if(win == 1)
            return;
     printf("\nrow no : ");
     fflush(stdin);
     scanf("%d", &row);
     printf("column no : ");
     fflush(stdin);
     scanf("%d", &col);
     
     if(pos[row][col] == 1 || row < 1 || row > 3 || col < 1 || col > 3)
     {
                             printf("\nWRONG POSITION!!");
                             system("PAUSE");
                             
                             false_X = 1;
                             board();
     }
     else
     {
         pos_X[row][col] = 1;
         pos[row][col] = 1;
         board();
     }
}

void player_O()
{
     int row, col;
     
     if(win == 1)
            return;
     printf("\nEnter the row no. : ");
	 scanf("%d", &row);
	 printf("Enter the column no. : ");
	 scanf("%d", &col);
	
     if(pos[row][col] == 1 || row < 1 || row > 3 || col < 1 || col > 3)
     {
                             printf("\nWRONG POSITION!!");
                             system("PAUSE");
                             false_O = 1;
                             board();
     }
     else
	 {
         pos_O[row][col] = 1;
		 pos[row][col] = 1;
         board();
     }
}

void player_win()
{
     int i;
	 for(i = 1; i <= 3; i++)
	 {
           if(pos_X[i][1] == 1 && pos_X[i][2] == 1 && pos_X[i][3] == 1)
           {
                          win = 1;
                          printf("\n\nRESULT: %s wins!!", X);
                          system("PAUSE");
                          return;
           }
     }
	 for(i = 1; i <= 3; i++)
	 {
           if(pos_X[1][i] == 1 && pos_X[2][i] == 1 && pos_X[3][i]==1)
		   {
                          win = 1;
                          printf("\n\nRESULT: %s wins!!", X);
			              system("PAUSE");
                          return;
           }
	 }
     if(pos_X[1][1] == 1 && pos_X[2][2] == 1 && pos_X[3][3] == 1)
	 {
                    win = 1;
                    printf("\n\nRESULT: %s wins!!", X);
                    system("PAUSE");
                    return;
     }
     else if(pos_X[1][3] == 1 && pos_X[2][2] == 1 && pos_X[3][1] == 1)
	 {
          win = 1;
          printf("\n\nRESULT: %s wins!!",X);
          system("PAUSE");
          return;
	 }
     
     for(i = 1; i <= 3; i++)
	 {
           if(pos_O[i][1] == 1 && pos_O[i][2] == 1 && pos_O[i][3] == 1)
           {
                          win = 1;
                          printf("\n\nRESULT: %s wins!!", O);
                          system("PAUSE");
                          return;
           }
	 }
	 
     for(i = 1; i <= 3; i++)
     {
           if(pos_O[1][i] == 1 && pos_O[2][i] == 1 && pos_O[3][i] == 1)
           {
                          win = 1;
                          printf("\n\nRESULT: %s wins!!", O);
                          system("PAUSE");
			              return;
           }
	 }
	 if(pos_O[1][1] == 1 && pos_O[2][2] == 1 && pos_O[3][3] == 1)
     {
                    win = 1;
                    printf("\n\nRESULT: %s wins!!", O);
                    system("PAUSE");
                    return;
	 }
     else if(pos_O[1][3] == 1 && pos_O[2][2] == 1 && pos_O[3][1] == 1)
	 {
          win = 1;
          printf("\n\nRESULT: %s wins!!", O);
          system("PAUSE");
		  return;
	 }
}

void check()
{
     int i, j;
     
     for(i = 1; i <= 3; i++)
           for(j = 1;j <= 3; j++)
           {
                 if(pos[i][j] == 1)
                   chk++;
                 else
                   continue;
           }
}
