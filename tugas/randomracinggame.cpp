#include <stdio.h>
#include <stdlib.h>
#include <time.h>


main()
{
      srand((unsigned)time(NULL));
      
      int a,b,h,w,track,player,time,random,PLAYER[20],WINNER[20];
      player=1;
      track=1;
      
      while(player<2 or player>20)
      {      
          system("cls");
          
          printf("+--------------------+\n");
          printf("| RANDOM RACING GAME |\n");
          printf("+--------------------+\n");      
          printf("Player (2-20) : ");
          scanf("%d",&player);         
      }
      
      while(track<15 or track>75)
      {
          system("cls");
          
          printf("+--------------------+\n");
          printf("| RANDOM RACING GAME |\n");
          printf("+--------------------+\n");
          printf("%d Player\n",player);      
          printf("Track (15-75) : ");
          scanf("%d",&track);      
      }
      
      system("cls");
      printf("\nREADY..");
      _sleep(500);

      system("cls");
      printf("\nSET..");
      _sleep(500);
      
      system("cls");
      printf("\nGO..!!");
      _sleep(500);            
      
      
      //set initial position
      //for all player
      b=1;      
      while(b<=player)
      {
                 PLAYER[b-1]=0;
                 b++;
      }
      
      time=1;
      h=0;      
      while(h<1)
      {
              h=0;
              system("cls");
              
              printf("  ");              
              
              //top track
              for(a=1;a<=track;a++)
              {
                  printf("=");
              } 
             
              printf("\n");             
                            
              //set position
              b=1;
              w=0;
              while(b<=player)
              {
                              
                         printf("%2d-",b);
                         
                         
                         //position from start line
                         a=1;
                         while(a<=PLAYER[b-1])
                         {
                             printf(" ");
                             a++;
                         }
                         
                         
                         //player
                         printf(">");
                         
                         
                         //position from finish line                       
                         a=1;
                         while(a<=track-PLAYER[b-1]-2)
                         {
                                         printf(" ");
                                         a++;
                         }
                         
                         
                         //finish line
                         if(PLAYER[b-1]==track-1)
                         {
                             printf("\n");
                         }
                         else
                         {
                             printf("|\n");
                         }
                         
                         
                         //if reach the finish line
                         //stop this process
                         //and record the winner
                         if(PLAYER[b-1]==track-1)
                         {
                                h=1;//stop the process
                                WINNER[w]=b;//record the winner
                                w++;//number of winner
                         }                                                  
                                                  
                         
                         //set a new position
                         random=rand()%5;
                         if(random==4)
                         {
                                     random=-1;
                         }
                         
                         
                         //add to the last position
                         PLAYER[b-1]=PLAYER[b-1]+random;
                         
                         
                         //set to finish if pass the finish line
                         if(PLAYER[b-1]>track-1)
                         {
                             PLAYER[b-1]=track-1;
                         }
                         
                         
                         //set back to start if the position
                         //less than 0 from start line
                         if(PLAYER[b-1]<0)
                         {
                             PLAYER[b-1]=0;
                         }
                         
                         
                         b++;               
              }
              
              printf("  ");
              
              //bottom track
              a=1;
              while(a<=track)
              {
                  printf("=");
                  a++;
              }              
              
              printf("\nTime : %d",time);
              
              _sleep(800);
              
              time++;              
      }
      
      printf("\n");
      
      //the winner
      if(w-1>0)
      {
          printf("# DRAW!! #");
          a=0;
          while(a<=w-1)
          {
              printf("\n%d. #%d",a+1,WINNER[a]);
              a++;
          }
      }
      else
      {
          printf("The winner is #%d",WINNER[0]);
      }
}
