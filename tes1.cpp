#include<stdio.h>
#include<string.h>
#include<math.h>
#include<conio.h> 

int isDigit(char in[20]){
        
    int b=0, i, j;
        
    for(i=0, j=(int)pow(10,strlen(in)-1); i<strlen(in); i++, j/=10)
    b=b+j*((int)in[i]-48);
    
    return b;
}

main(){
       char a[5]="1994";
       
       printf("%d", isDigit(a));
       
       getch();
}
