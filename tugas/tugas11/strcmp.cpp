#include<stdio.h>

int strcmp(char *s, char *t)
{       
    for (;*s!='\0';)
    {
        if(*s>*t) return 1;
        else if(*s<*t) return -1;
        else { s++; t++; }
    }
    if(*s=='\0') return 0;
}

main()
{
      char a[10],b[10];
            
      printf("word #1 : "); scanf("%s",&a);
      printf("word #2 : "); scanf("%s",&b);
                  
      printf("%d",strcmp(a,b));
}
