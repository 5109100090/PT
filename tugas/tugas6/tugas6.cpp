#include <stdio.h>

main()
{
      char indo[100],malang[100];
      int a,b,c;
      
      printf("kata dalam Bahasa Indonesia : ");
      scanf("%s",indo);
      a=0;
      while(a<100)
      {
                  if(indo[a]=='\0')
                  {
                                 b=a;
                                 break;
                  }
                  a=a+1;
      }
      a=0;
      c=b-1;
      while(a<=b-1)
      {
                   if(indo[c-1]=='n')
                   {
                       if(indo[c]=='g')
                       {
                                       malang[a]=indo[c-1];
                                       malang[a+1]=indo[c];
                                       a=a+2;
                                       c=c-2;
                       }
                       if(indo[c]=='y')
                       {
                                       malang[a]=indo[c-1];
                                       malang[a+1]=indo[c]; 
                                       a=a+2;
                                       c=c-2;
                       }
                       if(indo[c-1]!='g')
                       {
                                       malang[a]=indo[c];
                                       a=a+1;
                                       c=c-1;                       
                       }                       
                   }
                   if(indo[c-1]!='n')
                   {
                       malang[a]=indo[c];
                       a=a+1;
                       c=c-1;                       
                   }                   
      }
      malang[a]='\0';
      printf("kata dalam Bahasa Malang    : %s",malang);
}
