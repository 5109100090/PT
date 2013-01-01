#include <stdio.h>
      #include <stdlib.h>
      #include <string.h>
      #include <ctype.h>
      #include<conio.h>
  
      static char s[50], i;
   
      static char a[50];
      void push(int data) {
      s[i++] = data;
  
      }
  
      char pop() {
  
      return s[--i];
      }
  
      // prefix -> infix
 
      // prefix -> postfix
  
      void prefix() {
  
      puts("Enter a prefix expression:");
 
      fgets(a, 50, stdin);
  
      int a_size = strlen(a);
 
      puts("Prefix -> Infix:");

      char *token, delim[] = {" \n"}, match[] = {"*+/-"};
 
      int j = 0, m_size = strlen(match);
  
      token = strtok(a, delim);
 
      while (token != NULL) {

      if (isdigit(*token)) {

      printf("%d ", atoi(token));
 
      if (i >= 0) printf("%c ", pop());

      }

      else

      while (j < m_size) {

      if (*token == match[j]) {

      push(*token);
  
      break;

      }

      j++;

      }

      token = strtok(NULL, delim);

      j = 0;

      }
 
      puts("");
 
      puts("Prefix -> Postfix:");

      int k = a_size;
 
      while (k >= 0) {

      if (a[k] == '\0' || a[k] == ' ') k--;
  
      printf("%c ", a[k--]);

      }

      puts("");

      }

      void infix() {
 
      puts("Enter an infix expression:");

      fgets(a, 50, stdin);
 
      }

      void postfix() {

      }

      main() {
 
      int c;
 
      puts("1: Prefix");
 
      puts("2: Infix");
 
      puts("3: Postfix");
  
      scanf("%d", &c);
 
      fflush(stdin);
 
      prefix();

      /*
  78.
      switch(c) {
  79.
      case 1: prefix();
  80.
      break;
  81.
      case 2: infix();
  82.
      break;
  83.
      case 3: postfix();
  84.
      break;
  85.
      }
  86.
      */
      getch();
 
      }
