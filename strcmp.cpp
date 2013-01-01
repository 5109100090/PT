#include <stdio.h>
#include <string.h>
#include <conio.h>

main(){
    char x[10]="aku";
    char y[10]="abah";
    
    printf("x>y %d\n", strcmp(x, y));
    printf("y>x %d\n", strcmp(y, x));
    
    getch();
}
