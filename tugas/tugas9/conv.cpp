#include <stdio.h>
#include <string.h>

int pangkat(int a)
{
    int b=2, c=2, i;    
    if(a!=0)
    {
        for(i=0; i<a-1; i++)
        {
                 b=b*c;
        }
        return b;
    }
    else
    { return b=1; }
}

main()
{
      int a=0,b,c=0,d,e,i;
      char input[50];
      
      printf("input binner :");
      gets(input);
      
      for(i=0; input[i]!='\0'; i++)
      { b=i; }

      for(; b+1>0; b--, c++)
      {
          if(input[b]=='1')
          { e=1; }
          else
          { e=0; }
          
          d=a;
          a=e*pangkat(c);
                   
          a=d+a;
      }
      printf("the decimal number is :%d",a);
}
