#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

      int a,b,c,d,e,x,y,in;
      char A[52][4],B[24][4],X[8][4],Y[8][4],Z[8][4];

void cards()
{     
      for(e=0,b=0;e<4;e++)
      {
          for(c=12;c>=0;c--,b++)
          {
              a=(char)c+49;
              d=' ';
              
              if(a=='=')
              { a='K'; }
              if(a=='<')
              { a='Q'; }
              if(a==';')
              { a='J'; }
              if(a==':')
              { d='1'; a='0'; } 
              if(a=='1')
              { a='A'; }
              
              A[b][0]=d;
              A[b][1]=a;          
              A[b][2]=3+e;
              A[b][3]='\0';
          }
      }
}

void copyToXYZ()
{
      for(a=0,b=0;a<24;b++)
      {
                       strcpy(X[b],B[a]); a++;
                       strcpy(Y[b],B[a]); a++;
                       strcpy(Z[b],B[a]); a++;
      }     
}

void randomCard()
{
      srand((unsigned)time(NULL));
      //get 24 randomize card
      for(a=0;a<24;a++)
      {             
                       for(b=0;b<=a;b++)
                       {
                                         x=rand()%52;
                                         y=strcmp(A[x],B[b]);
                                         for(;y==0;)
                                         { x=rand()%52; y=strcmp(A[x],B[b]); }
                       }                                       
                       
                       strcpy(B[a],A[x]);                                              
      }
      
      copyToXYZ();

}

void print()
{
      //print the card in 3x8
      for(a=0,b=0;a<8;a++)
      {
                      for(c=0;c<3;c++,b++)      
                      printf("   %s",B[b]);
                      printf("\n");
      }
}

void selectRow(int c)
{
      if(c==1)
      {
              for(b=0;b<3;b++)
              { strcpy(A[b],X[b]); }
              
              for(b=0;b<24;)
              {
               for(a=0;a<8;a++,b++){ strcpy(B[b],X[a]); }
               for(a=0;a<8;a++,b++){ strcpy(B[b],Y[a]); }
               for(a=0;a<8;a++,b++){ strcpy(B[b],Z[a]); } 
              }            
      }
      if(c==2)
      {
              for(b=0;b<3;b++)
              { strcpy(A[b],Y[b]); }
                            
              for(b=0;b<24;)
              {
               for(a=0;a<8;a++,b++){ strcpy(B[b],Y[a]); }
               for(a=0;a<8;a++,b++){ strcpy(B[b],X[a]); }
               for(a=0;a<8;a++,b++){ strcpy(B[b],Z[a]); } 
              }            
      }
      if(c==3)
      {
              for(b=0;b<3;b++)
              { strcpy(A[b],Z[b]); }
                            
              for(b=0;b<24;)
              {
               for(a=0;a<8;a++,b++){ strcpy(B[b],Z[a]); }
               for(a=0;a<8;a++,b++){ strcpy(B[b],X[a]); }
               for(a=0;a<8;a++,b++){ strcpy(B[b],Y[a]); } 
              }            
      }                 
}

void ins(int a)
{
     if(a==0)
     { printf("[choose a card]"); }
     else
     { printf("[find your card in column]"); }
     
     printf("\n\n");
}

void game()
{
      //set 52 cards
      cards();
      
      //get 24 random card
      randomCard();
      
      for(e=0;e<3;e++)
      {   
          system("cls");
          ins(e);
          print();
          for(a=1;a<4;a++)
          { printf("   [%d]",a); }

          printf("\n\n");
          
          printf("column number:");
          scanf("%d",&in);
                      
          if(e<2)
          { selectRow(in); copyToXYZ(); }
      }
      
      printf("your card is :%s",A[in-1]);
}

main()
{      
      game();
}
