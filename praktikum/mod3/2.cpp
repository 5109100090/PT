#include <stdio.h> 
#include <stdlib.h>  
#include <time.h>    
 
int a, b, sum = 0; 
void randPosition(int **array, int x, int y); 
void checkFriend(int **array, int x, int y); 
void display(int *array, int a, int b); 
 
int main() 
{ 
    //2D array with 12 row and col 
     int **array;           
 
     array=(int**)malloc(12*sizeof(int*));
     for(int i=0; i<12; i++)         
     array[i]=(int*)malloc(12*sizeof(int));
           
     randPosition(array,a,b);  
      
     if(sum==0) printf("You weren't connected"); 
     else       printf("You were connected with %d friends",sum); 
}

  
void display(int **array, int a, int b){ 
     printf("\n\n"); 
     int x, y; 
      for(x=1; x<11; x++)
      { 
            for(y=1; y<11; y++)
            { 
             if(x==a&&y==b)    
             printf("%4c", 1);           
              else if (array[x][y]==1)
              printf("%4c", 2); 
             else                    
             printf("   -"); 
            } 
        printf("\n\n"); 
      } 
      printf("\n"); 
} 
 
void randPosition(int **array, int x, int y){ 
      
      srand((unsigned)time(NULL)); 
      int i,j; 
      for(i=1;i<11;i++) 
      { 
            for(j=1;j<11;j++){  
                    array[i][j] = rand()%2;    
            }                            
      } 
      
      display(array,-1,-1); 
          
      do { 
             printf("\nYour position : \n "); 
             printf ("  x (1-10)= "); 
             scanf("%d",&a); 
             printf ("   y (1-10)= ");            
             scanf("%d",&b); 
             if(array[a][b]==0)
             printf("Are you sure? Correct your position,please..\n"); 
      }  while(array[a][b]==0); 
          
      system("cls"); 
       
      display(array,a,b);       
            
      checkFriend(array,a,b);  
       
} 
 
void checkFriend(int **array, int x, int y)
{      
      //array[x][y] = 0; 
      int i,j,f,g; 
      for(i=-1;i<=1;i++) 
            for(j=-1;j<=1;j++)
            { 
                  if(array[x+i][y+j] == 1)
                  { 
                    sum++; 
                    f=x+i;
                    g=y+j;
                    checkFriend(array,f,g); 
                  } 
            } 
}
