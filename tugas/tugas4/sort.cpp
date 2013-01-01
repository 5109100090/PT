#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{     
      int m,n,f,g,type;//input variable
      int x,y;//randomize variable
      int jmlArr;//number of array
      int A[100];//maximum size of array      
      int a,b,c,d,e;//sorting variable
      int i;//printing variable
      
      e=0;//initial selector
      d=1;//initial checker
      
      printf("+-------------------------+\n");
      printf("|    # sorting number #   |\n");      
      printf("|    input manually = 1   |\n");
      printf("|    input randomly = 2   |\n");      
      printf("+-------------------------+\n");      
      printf("input manually or randomly?");
      scanf("%d",&type);
      
      if(type==1 or type==2)
      {
      
          //input manually
          if(type==1)
          {
              printf("# manually #\ninput N number:");
              scanf("%d",&n);               
              
              f=1;//initialization
              
              //input n number and insert it into array
              while(f<=n)
              {
                         printf("input number #%d:",f);
                         scanf("%d",&m);
                         
                         //insert the number into the array
                         A[f-1]=m;
                         
                         f++;
              }
          }
          
          
          //input randomly
          if(type==2)
          {   
              //make a sequence for random number
              //according to time
              srand((unsigned)time(NULL));
              
              printf("# randomly #\ninput N number:");
              scanf("%d",&n);            
              
              g=0;//initial randomize
              
              //make n random number and insert it into array
              while(g<=n)
              {
                          //set the maximum random number
                          x=rand()%100;
                          
                          //make some negative number
                          y=rand()%2;
                          if(y==0)
                          {
                                    x=x*-1;
                          }
                          
                          //insert the number into the array
                          A[g]=x;
                          
                          g++;
              }      
          }
          
          
          //find the last index of array
          jmlArr=n-1;
          
          
          //print the number before sorting
          printf("the numbers before sorting :\n");
          i=0;//first index of array
          while(i<=jmlArr)
          {
                     printf("%d  ",A[i]);
                     i++;
          }
          
          printf("\n");
          
          
          //sorting
          //---------------------
          while(e<=jmlArr)
          {
              c=d;//set the last checker position
              a=A[e];//set the new selector position
              
              while(c<=n)
              {
                  a=A[e];//set the selector position
                  b=A[c];//set the checker position
                  
                  //check which number is bigger
                  //if the selector number is
                  //bigger than checker number, swap it
                  if(a>b)
                  {
                          A[e]=b;//new selector value from the last cheker value
                          A[c]=a;//new checker value from the last selector value
                  }
                  
                  c++;//move checker
              }
              e++;//move selector
              d++;//move checker
          }
          //---------------------      
          
          
          //print the number after sorting
          printf("the numbers after sorting :\n");
          i=0;//first index of array
          while(i<=jmlArr)
          {
                     printf("%d  ",A[i]);
                     i++;
          }
      
      }
}
