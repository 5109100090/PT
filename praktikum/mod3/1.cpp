#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> 

void trans(int **map){
      int a,b,c,d,f,g,h; 
     
        for(int j=0;j<10;j++) 
        { 
           for(int i=0;i<10;i++){            
                 if(map[i][j]==1){
                          a=i; b=j;
                 }          
                 else if(map[i][j]==2){
                          c=i; d=j;
                 }
           } 
         }    
         printf("Map :\n\n"); 
          //a,b start
          //c,d finish
          
          if(a<c)
          //finish di kanan
          for(int j=a;j<=c;j++)
                  map[j][b]=3;
          if(a>c)
          //finish di kiri
          for(int j=c;j<=a;j++)
                  map[j][b]=3; 
          
          
          if(b<d)
          for(int j=b;j<=d;j++)
                  map[c][j]=3;
          //finish di bawah
          if(b>d)
          for(int j=d;j<=b;j++)
                  map[c][j]=3;
          //fnish di atas
                             
           map[a][b]=1;
           map[c][d]=2;        
          for(int j=0;j<10;j++) 
          { 
           for(int i=0;i<10;i++){                            
                   if(map[i][j]==1)           
                   printf("S "); 
                   else if(map[i][j]==2)       
                   printf("F "); 
                   else if(map[i][j]==3)       
                   printf("0 "); 
                   else                      
                   printf("- "); 
             } 
             printf("\n"); 
          } 
     
        printf("\n"); 
     
     
        printf("Horizontal cost per unit =  500\n"); 
        printf("Vertical cost per unit   = 1000\n\n"); 
        g=c-a;
        if(g<0)
        g=g*-1;
         
        h=d-b; 
        if(h<0)
        h=h*-1;
                 
        printf("Your horizontal distance is %d\n",g); 
        printf("Your vertical distance is %d\n",h); 
             
             f=g*500 + h*1000; 
         
        printf("\nYour cost is Rp. %2d \n",f);
}
 
int main(void) 
{ 
      int a,b,c,d,i,j; 
      int **map;
      
      map=(int**)malloc(10*sizeof(int*)); 
                 
      for(i=0; i<10; i++) 
           map[i]=(int*)malloc(10*sizeof(int)); 
            
      for(i=0;i<10;i++) 
      { 
            for(j=0;j<10;j++){  
                    map[i][j] = 0;    
            }                            
      }      
       
      srand((unsigned)time(NULL)); 
      c=rand()%10; 
      d=rand()%10; 
      a=c;
      b=d;             
       
      while(a>=10||b>=10 || a==c && b==d){ 
             printf("Map<[column],[row]>\nMin <0,0>\nMax <9,9> \n"); 
             printf("Your start position  : "); 
             scanf("%d %d",&a,&b); 
             if(a>=10||b>=10 ||     a==c && b==d) printf("Incorrect input. Please, insert it again!\n"); 
      } 
       
      map[a][b]=1; //start 
      map[c][d]=2; //finish 
      trans(map);
      
      for(i=0; i<10; i++) 
      free(map[i]);
      free(map);

      return 0;
} 
 

