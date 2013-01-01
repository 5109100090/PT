#include<stdio.h>
#include<string.h>
#include<math.h>
#include<conio.h>
main()
{
      //for(int i=0; i<100; i++)
        //printf("%d %c\n",i,i);
        
        
        
        char a[5];
        
        int b=0, j;
        
        scanf("%s",a);
        for(int i=0, j=(int)pow(10,strlen(a)-1); i<strlen(a); i++, j/=10){
        b=b+j*((int)a[i]-48);
        }
        
        printf("%d",b);
        
        getch();
}

