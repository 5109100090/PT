#include <stdio.h>
#include <dos.h>
#include <string.h>
#include <assert.h>
#include <conio.h>
 
char teks[3][20]={"1. Dengan Tabel","2. Tanpa Tabel ","3. Keluar      "};
int j;
 
class Stack
{
  private :
    int top;
    int size;
    char *data_x;
    char *data;
    char *kal;
  public :
    void buat_menu();
    void print_isi_stack();
    void print_karakter();
    void buat_arsir(int p);
    void buat_batas();
    void GetInfix();
    void buat_tabel();
    void push(char a);
    void konversi();
    void konversi2();
    char TopValue();
    char pop();
    int GetTop();
    int GetNilai(char simbol);
    Stack(int sz);
    ~Stack();
};
void Stack::print_karakter()
{
  int i;
  for (i=0; i<j; i++)
   printf("%c",data_x[i]);
}
 
void Stack::print_isi_stack()
{
  int z;
  for (z=0; z<GetTop();z++)
   printf("%c",data[z]);
}
void Stack::buat_tabel()
{
   gotoxy(6,3);
   cputs("???????????????????????????????????????????????????????????????");
   gotoxy(6,4);
   cputs("?  No ?   Input   ?     Isi Stack     ?      Notasi Postfix    ?");
   gotoxy(6,5);
   cputs("???????????????????????????????????????????????????????????????");
 
}
void Stack::buat_batas()
{
  int i;
  textcolor(15);
  gotoxy(24,3);
  cputs("PROGRAM KONVERSI INFIX KE POSTFIX");
  gotoxy(23,5);
  cputs("DIBUAT  OLEH KELOMPOK");
  gotoxy(46,5);
  textattr(132);
  cputs("STRUKTUR DATA");
  textcolor(10);
  gotoxy(1,1);
  cputs("?");
  gotoxy(79,1);
  cputs("?");
  gotoxy(1,25);
  cputs("?");
  gotoxy(79,25);
  cputs("?");
  for (i=2; i<79; i++)
   {
     gotoxy(i,1);
     cputs("?");
   }
  for (i=2; i<25; i++)
   {
     gotoxy(1,i);
     cputs("?");
   }
  for (i=2; i<25; i++)
   {
     gotoxy(79,i);
     cputs("?");
   }
  for (i=2; i<79; i++)
   {
     gotoxy(i,25);
     cputs("?");
   }
}
 
void Stack::buat_arsir(int p)
{
  int i;
  for (i=0; i<3; i++)
   {
     if (i==p)
       {
	 textattr(79);
	 gotoxy(33,11+i);
	 cprintf(teks[i]);
       }
     else
       {
	 textattr(14);
	 gotoxy(33,11+i);
	 cprintf(teks[i]);
       }
   }
}
 
 
 
int Stack::GetNilai(char simbol)
{
  int value;
  if (simbol=='^')
   value=3;
  else if (simbol=='*' || simbol=='/')
   value=2;
  else if (simbol=='+' || simbol=='-')
   value=1;
  else
   value=0;
  return value;
 
}
 
int Stack::GetTop()
{
   int x;
   x=top;
   return x;
}
char Stack::TopValue()
{
  return (data[top-1]);
}
 
void Stack::GetInfix()
{
  printf("Masukkan ungkapan Infix : ");
  gets(kal);
}
 
void Stack::konversi()
{
  int i;
  j=0;
  for (i=0; i<strlen(kal); i++)
   {
     if (kal[i]=='(')
       push(kal[i]);
     else if (kal[i]==')')
       {
	 while(TopValue()!='(')
	     printf("%c",pop());
	 pop();
       }
     else if (kal[i]=='^'||kal[i]=='*'||kal[i]=='+'||kal[i]=='-'||kal[i]=='/'||kal[i]=='(')
       {
	 while ((GetTop()!=0) && (GetNilai(kal[i])<=GetNilai(TopValue())))
	 {
	   printf("%c",pop());
	 }
	 push(kal[i]);
       }
     else if (kal[i]!=' ')
       printf("%c",kal[i]);
   }
 
  while (GetTop()!=0)
      printf("%c",pop());
  delete [] data;
}
 
void Stack::konversi2()
{
  int i;
  j=0;
  data_x=new char[250];
  buat_tabel();
  for (i=0; i<strlen(kal); i++)
   {
     if (kal[i]=='(')
       push(kal[i]);
     else if (kal[i]==')')
       {
	 while(TopValue()!='(')
	  {
	     data_x[j]=pop();
	     j++;
	  }
	 pop();
       }
     else if (kal[i]=='^'||kal[i]=='*'||kal[i]=='+'||kal[i]=='-'||kal[i]=='/'||kal[i]=='(')
       {
	 while ((GetTop()!=0) && (GetNilai(kal[i])<=GetNilai(TopValue())))
	 {
	   data_x[j]=pop();
	   j++;
	 }
	 push(kal[i]);
       }
     else if (kal[i]!=' ')
     {
       data_x[j]=kal[i];
       j++;
     }
     gotoxy(6,i+6);
     putch(179);
     gotoxy(12,i+6);
     putch(179);
     gotoxy(24,i+6);
     putch(179);
     gotoxy(44,i+6);
     putch(179);
     gotoxy(69,i+6);
     putch(179);
     gotoxy(9,i+6);
     printf("%d",i+1);
     gotoxy(18,i+6);
     printf("%c",kal[i]);
     gotoxy(27,i+6);
     print_isi_stack();
     gotoxy(47,i+6);
     print_karakter();
   }
 
  while (GetTop()!=0)
    {
      data_x[j]=pop();
      j++;
      gotoxy(9,i+6);
      printf("%d",i+1);
      gotoxy(6,i+6);
      cputs("?     ?           ?                   ?                        ?");
      gotoxy(27,i+6);
      print_isi_stack();
      gotoxy(47,i+6);
      print_karakter();
      i++;
    }
 
  gotoxy(6,i+6);
  cputs("????????????????????????????????????????????????????????????????");
  delete [] data_x;
}
 
char Stack::pop()
{
  assert(!(top==0));
  top--;
  return data[top];
}
 
Stack::~Stack()
{
  delete data;
}
 
Stack::Stack(int sz)
{
  size=sz;
  top=0;
  data=new char [size];
 
}
 
void Stack::push(char a)
{
  assert(top<size);
  data[top]=a;
  top++;
}
 
void main()
{
  Stack Tumpukan(250);
  clrscr();
  int pilihan=0;
  int keluar=0;
  Tumpukan.buat_batas();
  Tumpukan.buat_arsir(0);
  char tombol,pil;
  do
   {
    if (kbhit())
    {
     (tombol=getch());
     if (tombol==0)
      tombol=getch();
 
    switch (tombol)
     {
       case 13:{
		 switch (pilihan)
		 {
		   case 0: {
			     do
			      {
				clrscr();
				Tumpukan.GetInfix();
				Tumpukan.konversi2(); printf("\n");
				//printf("Hasilnya dalam ungkapan Postfix : ");
				printf("\nIngin mencoba lagi ? (Y/T) ");
				pil=getch();
			      }while (pil=='Y'||pil=='y');
			      clrscr();
			      Tumpukan.buat_batas();
			      Tumpukan.buat_arsir(0);
			   };break;
		   case 1: {
			     do
			      {
				clrscr();
				Tumpukan.GetInfix();
				printf("\nHasilnya dalam ungkapan Postfix : ");
				Tumpukan.konversi(); printf("\n");
				printf("\nIngin mencoba lagi ? (Y/T) ");
				pil=getch();
			      }while (pil=='Y'||pil=='y');
			      clrscr();
			      Tumpukan.buat_batas();
			      Tumpukan.buat_arsir(0);
			   };break;
		   case 2: keluar=1;break;
		 }
	       }break;
       case 72:{
		 if (pilihan>0)
		   pilihan--;
		 else pilihan=2;
		 Tumpukan.buat_arsir(pilihan);break;
	       }
       case 80:{
		 if (pilihan<2)
		   pilihan++;
		 else pilihan=0;
		 Tumpukan.buat_arsir(pilihan);break;
	       }
     }
    }
    delay(150);
   }while(keluar!=1);
}

