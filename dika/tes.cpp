    #include <stdio.h>
    
    main()
    {
          int a,b,c,d,e,input;
          
          
          a=1;
          b=1;
          input=5;
          c=input;
          e=input;
          d=e;
          
          while(b<=input)
          {
                         
              //------------------           
              while(e<=input-1)
              {
                             printf("%d  ",e+1);
                             e++;
              }
              
              e=d;
              e--;
              d=e;
              //------------------              
              
          while(a<=c)
          {
                         printf("%d  ",a);
                         a++;
          }
          
          c-=1;
          a=1;
          b++;
          printf("\n");
          }
    }
