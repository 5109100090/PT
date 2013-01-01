#include <stdio.h>

main()
{
    int c;
    c=2;
r:
    printf("%d   ",c);
    
    if(c!=50)
    {
        c=c+2;
        goto r;
    }
    
    c=49;
t:
    printf("%d  ",c);
    
    if(c!=1)
    {
        c=c-2;
        goto t;
    }
}
