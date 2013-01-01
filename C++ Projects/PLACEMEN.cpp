/* **********************************************************************
*************************************************************************
			 PROJECT ON PLACEMENT SERVICES
*************************************************************************
*************************************************************************/


/* **********************************************************************
			HEADER FILES
*********************************************************************** */

#include<iostream.h>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<iomanip.h>
#include<fstream.h>
#include<string.h>
#include<ctype.h>
/* **********************************************************************
			PREDEFINED VARIABLES
*********************************************************************** */

//typedef  char *option[10];
int    GraphDriver;		/* The Graphics device driver		*/
int    GraphMode;		/* The Graphics mode value		*/
double AspectRatio;		/* Aspect ratio of a pixel on the screen*/
int    MaxX, MaxY;		/* The maximum resolution of the screen */
int    MaxColors;		/* The maximum # of colors available	*/
int    ErrorCode;		/* Reports any graphics errors		*/
struct palettetype palette;	/* Used to read palette info 		*/


/* ***********************************************************************
			 FUNCTION PROTOTYPES
************************************************************************ */
char menu();
void mainscreen(); 	       //First screen of kunwer placement services
void logo();		       // Authors menu
//void password();
void load();                   //Loading screen
void Initialize(void);         // Initialize the graphics mode
void SayGoodbye(void);         // Last screen placement services
void MainWindow(char *header); // Display messages of placement services
void StatusLine(char *msg);    // Display prompt message
void DrawBorder(void);	       // Drawing window in screen
void choices();                //menu choices for placement services
void choices4mat();            //menu choices for matromonial services
//char menu3(char *str);         //menu display function
char menu4();                  //menu display function
char menu5();                  //menu display function
void changetextstyle(int font, int direction, int charsize);
			       //Changing the text style using function
void matro_mem(char *);


/* *************************************************************************
			CLASSES USED IN THE PROJECT
************************************************************************** */


/* ************************************************************************
			CLASSES OF PLACEMENT AGENCY
************************************************************************** */



/* ==================== VACANCY CLASS ============================== */
class vacancy
  {
  private:
	char vac_type[14];
	short int vac_code;
	char vac_spec[50];
	char vac_qual[30];
	int vac_req_no;
	int exper;
  public:
	void get_vacancy();   //this function used to get information from user
	void show_vac();      //show information
	void add_vacancy();   // add vacancy file
	void show();          //out put of user input
	void show_vacancy();  //show vacancy in formated way
	void modify_vacancy();//modify vacancy file
	void del_vacancy();   //delete record from vacancy file
	void reports();	      //generate report for vacancy
	void search(); 	      //serch is used for information
	void place_vacancy();
}  vac;


/* ==================== FORM CLASS ================================ */

class form :public vacancy//derived class
   {
	private :
		unsigned long  res_code;
		unsigned long  mem_code;
		char name[20];
		int age;
		int type;
		char address[50];
		long int date;
		long int phone_no;
		char sex;// m forx male , f for female
		char higher_qualif[30];
		char exper[30];
		char uni_name[25];
		char stream[20];
		char marrige;
		char language[20];
		char pref_work; //this is for the preference of work in india of 										aboard
		struct date dat;
	public:
		int form_no;
		char ch;
		void Left_clear(int,int);
		void Right_clear(int,int);
		form()//this constructor is used to initailise the variables
		 {
			form_no=0;
			res_code=0;  phone_no=0;
		 }
		void box(int,int,int,int);
		unsigned long get_rec_no();
		//above function generate record no. automatically
		// this function modify the computer professional file
		void master_rec();
		// function to display all records available
		void deleted_rec();
		// function to display all deleted records
		void show_da(int);
		// this function arrange record summarised way
		void modify_mem(int );
		// this function modify the MBA file
		//  this function show summary of record
		void show_obj(int );
		//this function get a record from the operator for Computer
		int get_data(int);
		//this function get a record from the operator for MBA
		void show_data(int );
		//this function displays data
		void add_object(int );
		//this function show object of Computer professional
		void show_object(int );
		//this function used to modify computer professional record
		void del_object(int );
		//this function is used to del the record
		void gen_form();
		//this form is fill buy every people visited company
		void find();
		//finding the search menu
		void find_object(int );
		//this function used to search computer professional record
		 int last_code(void);
		 //this function used to find last registeration number
		void help_placement();
		//to get help
		void show_gen();
		//this function used to show thw general equires(comp)
		void show_general();
		//this function used to show the general equires(full)
		void del_gen();
		//this function used to delete the general equires
		void search_inform();
		//this function used to search the member from the file
		void place_mem(char *);
		//this function is used to draw member (compact) data format
		void memcard();
		//this function used to design the membership card
		void return_del_mem();
		void deleted_del();
		void deleted_mem();

  }member;


 /* =================== MENU CLASS =============================== */

 class menu : public form
  {
	private:
		char a[22];
		public:
		void  enroll_mnu();
		void  allinf_mnu();
		void  member_avab();
		void  modify_mnu();
		serch_infor();
  }z;



/* *****************************************************************
			CLASS FOR MATROMONIAL AGENCY
****************************************************************** */


/* *********************************************************************
				FUNCTIONS
********************************************************************** */


/* ====================== TO DISPLAY THE VIDEO ======================= */

void normalvideo(int x, int y, char *str)
{
	gotoxy(x, y);
	cprintf("%s", str);
}


/* ====================== FUNCTION TO REVERSE THE VIDEO ==============*/

void reversevideo(int x, int y, char *str)
{
	textcolor(RED);
	textbackground(WHITE);
	gotoxy(x, y);
	cprintf("%s", str);
	textcolor(GREEN);
	textbackground(BLACK);
}

/* =====================  FUNCTION TO FORM RECTANGLE ===============*/

void form:: box(int x1, int y1, int x2, int y2)
{
	 textcolor(WHITE);
	 for (int col = x1; col < x2; col++)
	 {
		gotoxy(col, y1);
		cprintf("%c", 196);
		gotoxy(col, y2);
		cprintf("%c", 196);
		delay(5);
	 }

	 for (int row = y1; row < y2; row++)
	 {
		gotoxy(x1, row);
		cprintf("%c", 179);
		gotoxy(x2, row);
		cprintf("%c", 179);
		delay(5);
	 }

	 gotoxy(x1, y1);
	 cprintf("%c", 218);
	 gotoxy(x1, y2);
	 cprintf("%c", 192);
	 gotoxy(x2, y1);
	 cprintf("%c", 191);
	 gotoxy(x2, y2);
	 cprintf("%c", 217);
}

/* ===================== FUNCTION TO FORM BOX ================*/

void box(int x1, int y1, int x2, int y2)
{
textcolor(WHITE);
	 for (int col = x1; col < x2; col++)
	 {
		gotoxy(col, y1);
		cprintf("%c", 196);
		gotoxy(col, y2);
		cprintf("%c", 196);
		delay(5);
	 }

	 for (int row = y1; row < y2; row++)
	 {
		gotoxy(x1, row);
		cprintf("%c", 179);
		gotoxy(x2, row);
		cprintf("%c", 179);
		delay(5);
	 }

	 gotoxy(x1, y1);
	 cprintf("%c", 218);
	 gotoxy(x1, y2);
	 cprintf("%c", 192);
	 gotoxy(x2, y1);
	 cprintf("%c", 191);
	 gotoxy(x2, y2);
	 cprintf("%c", 217);
}


/*======================= FUNCTION TO DRAW HORIZONTAL LINE==============*/

void line_hor(int column1, int column2, int row, char c)
{
	for ( column1; column1<=column2; column1++ )
	{
		gotoxy(column1,row) ;
		cout <<c ;
	}
}


/* ===================== FUNCTION TO DRAW VERTICAL LINE =============== */

void line_ver(int row1, int row2, int column, char c)
{
textcolor(WHITE);
	for ( row1; row1<=row2; row1++ )
	{
		gotoxy(column,row1) ;
		cprintf("%c",c);
	}
}



/* ===================== MAIN OPENING SCREEN =========================== */


void mainscreen()
{
	int maxx, maxy, in;
	void *l;
	int xradius = 150, yradius = 75;
	// Display the contents of allocated memory on the screen
	putimage(1, 11, l, COPY_PUT);
	int i=0;
	while(!kbhit())
	{
		 if(i==10)
		 i=0;
		 clrscr();
		 setbkcolor(i);
		 int midx = getmaxx() / 2;
		 int midy = getmaxy() / 2;
		 sound(i*300);
		 setfillstyle(0, getmaxcolor());
		 /* draw a filled ellipse */
		 fillellipse(midx, midy, xradius, yradius);
		 settextstyle(4, 0, 5);
		 textcolor(i);
		 // Displaying the output text on main screen
		 outtextxy(90, 40, "G.A.R.V");
		 settextstyle(1, 0, 1);
		 textcolor(i);
		 outtextxy(40,90,"PLACEMENT AGENCY");
		 settextstyle(0, HORIZ_DIR, 1);
		 outtextxy(20, 180, "Press any key to continue...");
		 delay(250);
		 i++;
	}
	nosound();
	// Clear the viewport area
	clearviewport();
	closegraph();
//	load();
}

/* ==================== INTRODUCTION ABOUT THE AUTHER ================== */

void logo()
{
	int maxx, maxy, in;
	void *l;

	// Get maximum x, y coordinates of the screen
	maxx = getmaxx();
	maxy = getmaxy();

	// setbkcolor sets the current background color using the palette
	setbkcolor(5);

	// Draws a rectangle (graphics mode)
	rectangle(0, 0, maxx, maxy);


	// Display the contents of allocated memory on the screen
	putimage(1, 11, l, COPY_PUT);

	// Sets the line style and text justification in screen
	settextstyle(4, HORIZ_DIR, 0);

	// Displaying the output text on main screen
	outtextxy(30, 20, "By :-");
	settextstyle(4,HORIZ_DIR,0);
	outtextxy(10,50,"   Kishen  ");
	outtextxy(30,80,"     Kumar");
	//outtextxy(50,110,"        Dev ");
	settextstyle(7, HORIZ_DIR, 1);
	outtextxy(20, 150, "Press any key to continue...");
	getch();
	// Clear the viewport area
	clearviewport();
}


/* ===================== LOADING SCREEN ===============================*/

void load()
{
	clrscr();
	initgraph( &GraphDriver, &GraphMode, "c:\\tc\\bgi" );
	setbkcolor(4);
	settextstyle(4, 0, 5);
	textcolor(3);
	outtextxy(190, 140, "LOADING....");

	int b=180;
	for(int h=0;h<5;h++)
	{
		for(int a=0;a<290;a++)
		{
			putpixel(b+a,225+h,7);
			putpixel(b+a,250+h,7);

		}
	}
	int d=225;
	for(h=0;h<5;h++)
	{
		for(int c=0;c<25;c++)
		{
			putpixel(180+h,d+c,7);
			putpixel(465+h,d+c,7);
		}
	}
	int x=185;
	int y=215;
	int l=230;

	for(int k=1;k<=19;k++)
	{
		for(int j=0;j<=20;j++)
		{
			for(int i=0;i<=10;i++)
			{
				putpixel(x+i,l+j,14);
			}
		}
	delay(250);
	x=x+15;
	y=y+15;
	}
}


/* ===================================================================
			SOME SOUND FUNCTIONS
=================================================================== */

void m_open()
{
	for(int i=1000;i>0;i=i-7)
	{
	  sound(i);
	  delay(6);
	  nosound();
	}
}
void prompt()
{
   int i;
	for(i=0;i<1000;i=i+6)
	{
	  sound(i);
	  delay(2);
	  nosound();
	}
	for(i=0;i<1000;i=i+7)
	{
	  sound(i);
	  delay(2);
	  nosound();
	}
}
void object_st()
{
	for(int i=0;i<1000;i=i+7)
	{
	  sound(i);
	  delay(2);
	  nosound();
	}
}
void object_ce()
{
	for(int i=0;i<800;i=i+15)
	{
	  sound(i);
	  delay(1);
	  nosound();
	}
}

/* ==================== INITIALIZING FUNCTION ========================= */

void Initialize(void)
{
	int xasp, yasp;			/* Used to read the aspect ratio*/

	GraphDriver = DETECT; 		/* Request auto-detection	*/

	initgraph( &GraphDriver, &GraphMode, "c:\\tc\\bgi" );
	ErrorCode = graphresult();		/* Read result of initialization*/

	if( ErrorCode != grOk )
	{		/* Error occured during init	*/
		printf(" Graphics System Error: %s\n", grapherrormsg( ErrorCode ) );
		exit( 1 );
	}

	getpalette( &palette );		/* Read the palette from board	*/
	MaxColors = getmaxcolor() + 1;	/* Read maximum number of colors*/

	MaxX = getmaxx();
	MaxY = getmaxy();			/* Read size of screen		*/

	getaspectratio( &xasp, &yasp );	/* Read the hardware aspect	*/
	AspectRatio = (double)xasp / (double)yasp; /* Get correction factor	*/
}

/* ==================== GOODBYE CLOSING EACH OTHER ======================*/

void design()
{
	clrscr();
	int gdriver = DETECT, gmode, errorcode;
	initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
	   printf("Graphics error: %s\n", grapherrormsg(errorcode));
	   printf("Press any key to halt:");
	   getch();
	   exit(1);
	}
	textbackground(WHITE);
	for(int i=1;i<=200;i++)
	{
		setcolor(i);
		cleardevice();
		outtextxy(245,i-20,"COPYRIGHT 2003 TO");
		outtextxy(220,i,"GARV SOFTWARE DEVELOPERS");
		sound(10*i);
		delay(20);
	}
	nosound();
	textbackground(BLACK);
	delay(800);
	delay(100);
	for(i=1;i<=200;i++)
	{
		setcolor(7+i);
		cleardevice();
		outtextxy(i,200,"designed by         ");
//		outtextxy(600-i,270,"KISHEN KUMAR");
		sound(100000/2*i);
		delay(10);
	}
	nosound();
	char ab[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' ','.'};
char bp[25]="gagan sharma";
for(i=0;i<strlen(bp);i++)
{
for(int j=0;j<28;j++)
{
textcolor(j+1);
gotoxy(30+i,17);
cprintf("%c",ab[j]);
delay(10);
if(ab[j]==bp[i])
break;
}
}
	int a=320;
	int b=250;
	for(i=0;i<=500;i++)
	{
		putpixel(rand()%(a+=1),rand()%(b+=1),i);
		delay(10);
	}
//	delay(1000);
	getch();
	closegraph();
}


void SayGoodbye(void)
{
	int ai,aq,y,x,y1,y2;
	int i,j;
	textmode(16);
	_setcursortype(_NOCURSOR);
	for(ai=0;ai<18;ai++)
	{
		clrscr();
		textcolor(12+BLINK);
		gotoxy(10,4);
		printf("                                                           ");
		gotoxy(10,23);
		printf("                                                           ");
		for(y=4;y<=23;y++)
		{
			gotoxy(9,y);
			printf(" ");
			gotoxy(8,y);
			printf(" ");
		}
		for(y1=4;y1<=23;y1++)
		{
			gotoxy(70,y1);
			printf(" ");
			gotoxy(69,y1);
			printf(" ");
		}
		gotoxy(ai-1,9);
		cprintf("                   THANKS                      ");
		gotoxy(ai-1,12);
		cprintf("                  for using                    ");
		gotoxy(ai-1,15);
		cprintf("                    this                       ");

		gotoxy(ai-1,18);
		cprintf("                   Project                     ");
	}
	delay(100);
	//sound
	clrscr();
	for(aq=0;aq<18;aq++)
	{
		textcolor(11);
		gotoxy(10,4);
		printf("                                                           ");
		gotoxy(10,23);
		printf("                                                           ");
		for(y=4;y<=23;y++)
		{
			gotoxy(9,y);
			printf(" ");
			gotoxy(8,y);
			printf(" ");
		}
		for(y1=4;y1<=23;y1++)
		{
			gotoxy(70,y1);
			printf(" ");
			gotoxy(69,y1);
			printf(" ");
		}
		for(y2=4;y2<=23;y2++)
		{
			gotoxy(39,y2);
			printf(" ");
			gotoxy(38,y2);
			printf(" ");
		}
		for(x=10;x<=69;x++)
		{
			gotoxy(x,13);
			printf(" ");
			gotoxy(x,13);
			printf(" ");
		}
		gotoxy(ai-1,8);
		printf("                                               ");
		gotoxy(ai-1,9);
		cprintf("                   THANKS                      ");
		gotoxy(ai-1,10);
		printf("                                               ");
		gotoxy(ai-1,11);
		printf("                                               ");
		gotoxy(ai-1,12);
		cprintf("                  for using                    ");
		gotoxy(ai-1,13);
		printf("                                               ");
		gotoxy(ai-1,14);
		printf("                                               ");
		gotoxy(ai-1,15);
		cprintf("                    this                       ");
		gotoxy(ai-1,16);
		printf("                                               ");
		gotoxy(ai-1,17);
		printf("                                               ");
		gotoxy(ai-1,18);
		cprintf("                   Project                     ");
		gotoxy(ai-1,19);
		printf("                                               ");
	}
	delay(1000);
	design();
}


/* ==================== MAINWINDOW FOR THE DEMO AND VIEWPORT =========== */


void MainWindow( char *header )
{
	int height;

	cleardevice();			/* Clear graphics screen	*/
	setcolor( MaxColors - 1 );		/* Set current color to white	*/
	setviewport( 0, 0, MaxX, MaxY, 1 );	/* Open port to full screen	*/

	height = textheight( "H" );           /* Get basic text height        */

	changetextstyle( DEFAULT_FONT, HORIZ_DIR, 1 );
	settextjustify( CENTER_TEXT, TOP_TEXT );

	outtextxy( MaxX/2, 2, header );
	setviewport( 0, height+4, MaxX, MaxY-(height+4), 1 );

	DrawBorder();
	setviewport( 1, height+5, MaxX-1, MaxY-(height+5), 1 );

}
/* ********************** CLER THE TEXT ******************************* */

void clear(int col, int row, int num)
{
	for (int j = 1; j <= num; j++)
	{
		gotoxy(col+j, row);
		cout << " ";
	}
}

/* ==================== STATUSLINE: LINE AT THE BOTTOM OF SCREEN =======*/

void StatusLine( char *msg )
{
	int height;

	setviewport( 0, 0, MaxX, MaxY, 1 );	/* Open port to full screen	*/
	setcolor( MaxColors - 1 );		/* Set current color to white	*/

	changetextstyle( DEFAULT_FONT, HORIZ_DIR, 1 );
	settextjustify( CENTER_TEXT, TOP_TEXT );
	setlinestyle( SOLID_LINE, 0, NORM_WIDTH );
	setfillstyle( EMPTY_FILL, 0 );

	height = textheight( "H" );           /* Detemine current height      */
	bar( 0, MaxY-(height+4), MaxX, MaxY );
	rectangle( 0, MaxY-(height+4), MaxX, MaxY );
	outtextxy( MaxX/2, MaxY-(height+2), msg );
	setviewport( 1, height+5, MaxX-1, MaxY-(height+5), 1 );

}

/* ===================== FUNCTION TO DRAW BORDER =======================*/


void DrawBorder(void)
{
	struct viewporttype vp;

	setcolor( MaxColors - 1 );		/* Set current color to white	*/

	setlinestyle( SOLID_LINE, 0, NORM_WIDTH );

	getviewsettings( &vp );
	rectangle( 0, 0, vp.right-vp.left, vp.bottom-vp.top );

}

/* ===================== FUNCTION TO CHANGE TEXT STYLE==================*/

void changetextstyle(int font, int direction, int charsize)
{
	int ErrorCode;

	graphresult();			/*Clear error code		*/
	settextstyle(font, direction, charsize);
	ErrorCode = graphresult();		/* Check result 		*/

	if ( ErrorCode != grOk )
	{						/* If error occured		*/
		closegraph();
		printf(" Graphics System Error: %s\n", grapherrormsg( ErrorCode ) );
		exit( 1 );
	}
}

/* ===================== PLACEMENT HELP FUNCTION ======================= */

void form::help_placement(void)
{
	clrscr() ;
	box(2,1,79,25) ;
	box(23,2,55,4) ;
	line_ver(6,22,7,179) ;
	textcolor(11+143);
	gotoxy(24, 3);
	textbackground(RED);
	cprintf(" WELCOME TO PLACEMENT SERVICES ");
	textbackground(BLACK);
	textcolor(WHITE);
	delay(10) ;
	gotoxy(5,6);
	cprintf("1");
	gotoxy(9,6);  cprintf("In this Project you can keep record of people who  searching for");
	delay(10) ;
	gotoxy(9,7);  cprintf("the jobs ." );
	delay(10) ;
	gotoxy(5,9);
	cprintf("2");
	gotoxy(9,9); cprintf("This  program  is  capable  to   hold  any  number   of  account." );
	delay(10) ;
	gotoxy(5,11);
	cprintf("3");
	gotoxy(9,11); cprintf("In  first option you can register for the general category  by " );
	delay(10) ;
	gotoxy(9,12); cprintf("by giving simply details of that person." );
	delay(10) ;
	gotoxy(5,14);
	cprintf("4");
	gotoxy(9,14); cprintf("In  second option  you can  register in  your  requiered  field" );
	delay(10) ;
	gotoxy(5,16);
	cprintf("5");
	gotoxy(9,16); cprintf("In Third option you can modify or delete allready registered record " );
	delay(10) ;
	gotoxy(5,18);
	cprintf("6");
	gotoxy(9,18); cprintf("In Forth  option  you can  modify  or Delete  any  vacancy  record." );
	delay(10) ;
	gotoxy(5,20);
	cprintf("7");
	gotoxy(9,20); cprintf("Eight option give help related to this menu");
	delay(10);
	gotoxy(5,22);
	cprintf("8");
	gotoxy(9,22); cprintf("Exit to dos");
	delay(10);
	textcolor(BLACK+BLINK) ;
	textbackground(CYAN) ;
	gotoxy(26,25) ;
	cprintf(" Press any key to continue ") ;
	textcolor(LIGHTGRAY) ;
	textbackground(BLUE) ;
	gotoxy(25,2) ;
	getch() ;
	for (int i=25; i>=1; i--)
	{
		delay(20) ;
		gotoxy(1,i) ; clreol() ;
	}
}


void form::memcard()
{
clrscr();
box(15,6,75,21);
gotoxy(25,8);
cout<<"GARV PLACEMENT AGENCY";
gotoxy(30,9);
cout<<"MEMBERSHIP CARD(PLACEMENT)";
gotoxy(25,11);
cout<<"REGISTERATION NO. ------>";
cout<<res_code;
gotoxy(25,11);
cout<<"NAME ------------------->";
puts(name);
gotoxy(25,12);
cout<<"ADDRESS ---------------->";
puts(address);
gotoxy(25,13);
cout<<"PHONE NO. -------------->";
cout<<phone_no;
gotoxy(25,15);
cout<<"MEMBERSHIP DATE -------->";
//cout<<dat.dd<<"-"<<dat.mm<<"-"<<dat.yy;
printf("%d/%d/%d",dat.da_day,dat.da_mon,dat.da_year);
gotoxy(25,16);
cout<<"EXPIRE DATE ------------>";
printf("%d/%d/%d",dat.da_day,dat.da_mon,dat.da_year+1);
//cout<<dat.dd<<"-"<<dat.mm<<"-"<<dat.yy+1;
gotoxy(45,18);
cout<<"MANAGER";
gotoxy(45,19);
cout<<"(KISHEN KUMAR)";
getch();
}



/* *************************************************************************
			FUNCTION FOR THE MENU DISPLAY
************************************************************************** */


char menu(char* str,char *a[],int n)
{
	int i, done;

	clrscr();
	member.box(17, 5, 67, 22);
       member.box(10, 1, 74, 25);
	textcolor(11+143);

	gotoxy(30, 3);
	textbackground(RED);
	cprintf(str);
		textbackground(BLACK);
	textcolor(22);
	struct date d;
		getdate(&d);
	gotoxy(18,6);
	printf("%d/%d/%d",d.da_day,d.da_mon,d.da_year);
	for (i = 1; i <=n ; i++)
		normalvideo(32, i+8, a[i]);

	reversevideo(32, 8, a[0]);
	reversevideo(32, 8, a[0]);
	i = done =0;

	_setcursortype(_NOCURSOR);

	do
	{
		int key = getch();

		switch(key)
		{
			case 00:
				key = getch();

				switch (key)
				{
					case 72:
						normalvideo(32, i+8, a[i]);
						i--;

						if (i == -1)
							i = n;

						reversevideo(32, i+8, a[i]);
						break;

					case 80:
						normalvideo(32, i+8, a[i]);
						i++;

						if (i == n+1)
							i = 0;

						reversevideo(32, i+8, a[i]);
						break;
				}
				break;
			case 13:

				done = 1;
		}
	} while (!done);

	_setcursortype(_NOCURSOR);
	return (i+49);
}

/* ================= FUNCTION FOR THE MAIN CHOICES OF PROJECT =========*/

void mainchoices()
{
char choice;
char *b[]=
		{
	     " PLACEMENT AGENCY ",
	     " EXIT",
		};
	do
	{

		choice = menu("GARV AGENCY",b,2);
		clrscr();

		switch (choice)
		{
		   case '1':
				z.help_placement();
				choices();
				break;

		   case '2':    Initialize();
				setbkcolor(13);
				SayGoodbye();
				closegraph();
				exit(0);
				break;


		}

	} while (choice != 0);
}



void report()
{
char choice;
char *b[] =
		{
	     " VACANCIES AVAILABLE",
	     " ALL REGISTERED MEMBERS",
	     " ALL INTERVIEWING MEMBER",
	     " ALL INFORMATION OF MEMBER",
	     " MEMBER AVAILABLE   ",
	     " SEARCH INFORMATION ABOUT MEMBER",
	     " Quit   "
		};
	do
	{
		choice = menu("REPORT MENU",b,6);
		clrscr();

		switch (choice)
		{

		   case '1': vac.show_vacancy();
			     break;

		   case '2': member.master_rec();
			     break;

		   case '3': member.deleted_mem();
			     break;

		   case '4': z.allinf_mnu();
			     break;

		   case '5': z.member_avab();
			     break;

		   case '6': z.find();//member.search_inform();
			     break;

		   default  : clrscr();
			      choices();
		}

	} while (choice != 0);
}



/* ================== FUNCTION FOR MAIN MENU (PLACEMENT) ============ */

void choices()
{
char choice;
char *b[]={
	     " GENERAL FORM ",
	     " REGESTRATION FORM",
	     " ADD VACANCY FORM",
	     " MODIFY MEMBER FILE",
	     " MODIFY VACANCY FILE",
	     " REPORTS",
	     " HELP",
	     " Quit   "
	  };
	do
	{
		choice = menu("PLACEMENT AGENCY",b,7);
		clrscr();

		switch (choice)
		{
		   case '1': member.gen_form();
			     break;

		   case '2': z.enroll_mnu();
			     break;

		   case '3': vac.add_vacancy();
			     break;

		   case '4': z.modify_mnu();
			     break;

		   case '5': vac.modify_vacancy();
			     break;

		   case '6': report();
			     break;

		   case '7': clrscr();
			      z.help_placement();
			      break;

		   default  : clrscr();
			      mainchoices();
		}

	} while (choice != 0);
}


/* ===================== SEARCH FUNCTION FOR THE PLACEMENT AGENCY ====== */

void form::find()
{
char choice,*str={"SEARCH MENU"};
char *b[]=
		{
	     " COMPUTER PROFESSIONAL ",
	     " MASTER OF BUSSINESS ADMINSTRATOR",
	     " DOCTER",
	     " ENGINEERS",
	     " ACCOUNTANT(B.Com---C.A)",
	     " SCIENCE",
	     " ANY OTHER",
	     " EXIT",
		};
do
{
	choice=menu(str,b,7);
	switch(choice)
	{
	case '1':	clrscr();
			find_object(1);
			break;
	case '2':	clrscr();
			find_object(2);
			break;
	case '3':	clrscr();
			find_object(3);
			break;
	case '4':	clrscr();
			find_object(4);
			break;
	case '5':	clrscr();
			find_object(5);
			break;
	case '6':	clrscr();
			find_object(6);
			break;
	case '7':	clrscr();
			find_object(7);
			break;
	case '8':	clrscr();
			choices();
			break;
	}
}while(choice!=8);
}

/* ********************************************************************
			LAST CODE FUNCTION
********************************************************************** */

 int form::last_code(void)
{
	fstream file;
	file.open("master.dat", ios::in|ios::binary);
	file.seekg(0, ios::beg);
	int count = 0;

	// Founds the last registration no.
	while (file.read((char *)this, sizeof(member)))
		count = res_code;
	file.close();
	return count;
}


/* *********************************************************************
			MAIN PROGRAM
*********************************************************************** */


void main()
{

	int  gm = DETECT, gd = CGA;

	// Initialise the graphics system for using graphics
	initgraph (&gd, &gm, "c:\\tc\\bgi");
	mainscreen();
	closegraph();  // Close the graphics mode
	initgraph (&gd, &gm, "c:\\tc\\bgi");
	logo();
	closegraph();
	mainchoices();

}

/* *********************************************************************
			VACANCY CLASS MEMBER FUNCTION
********************************************************************* */


/* ===================== FUNCTION TO SHOW VACANCY AVAILABLE =========== */

void vacancy:: show()
 {
	 gotoxy(1,3);
	 cout<<" VACANCY CODE  :"<<vac_code;
	 cout<<"\n VACANCY TYPE   :"<<vac_type;
	 cout<<"\n SPECILIST      :"<<vac_spec;
	 cout<<"\n NO. OF PEOPLE REQUIRED :"<<vac_req_no;
	 cout<<"\n EXPERIENCE REQUIRED    :"<<exper;
 }


/* ===================== FUNCTION TO SEARCH VACANCY =================== */

void vacancy::search()
{
 fstream infile;
 char search_choice;
 int code; char name[30]; int experien;
 int counter=0;
 int state;
 char *b[]=
		{
	     " VACANCY CODE ",
	     " VACANCY TYPE",
	     " YEAR'S EXPERIENCE",
	     " EXIT",
		};
 do
	{
			clrscr();

			search_choice=menu("VACANCY SEARCH",b,3);    // get search choice from the user
			switch(search_choice)
			{
				case '1':

					clrscr();
					cout<<"\n ENTER VACANCY CODE TO BE SEARCHED ->";
					cin>>code;
					infile.open("vacancy.dat",ios::in); // open file 					in reading mode
					infile.seekg(0,ios::beg);   // set file pointer to 					the begining of the file
					//infile.read((char*)&vac,sizeof(vac)); // read 					the first record
					while(infile.read((char*)&vac,sizeof(vac))) // search whole file
					{
					clrscr();
					 // read next 					record
						if(vac.vac_code == code) // record found
						{
							counter++;        // increment counter
							vac.show(); // display record
						}

					}
					infile.close(); // close file
					gotoxy(20,24);  // set cursor position
					cout<<" RECORDS FOUND = "<<counter; // display 						counter
					getch();    // wait for keypress
						if(counter==0)
	{
	clrscr();
	prompt();
	textcolor(5+143);
	gotoxy(25,12);
	cprintf("NO RECORD FOUND");
	getch();
	}
	break;

				case '2':
					clrscr();
					cout<<"\n ENTER THE NAME TO BE SEARCHED ---->";
					gets(name);
					infile.open("vacancy.dat",ios::in); // open file 					in reading mode
					infile.seekg(0,ios::beg); // set file pointer to 					the begining of the file

					while(infile.read((char*)&vac,sizeof(vac)))  // search whole file
					{
					clrscr();

						if (strcmpi(vac.vac_type,name) == 0) // 						record found
						{
							counter++;            // increment 						counter
							vac.show();     // display record
						}

					}
					infile.close();   // close file
					gotoxy(20,24);    // set cursor position
					cout<<" RECORDS FOUND = "<<counter; // display 						counter
					getch();     // wait for key press
						if(counter==0)
	{
	clrscr();
	prompt();
	textcolor(5+143);
	gotoxy(25,12);
	cprintf("NO RECORD FOUND");
	getch();
	}
					break;

				case '3':
					clrscr();
					cout<<"\n ENTER THE OF YEAR EXPERIENCE TO BE SEARCHED ---->";
					gets(name);
					infile.open("vacancy.dat",ios::in); // open file 					in reading mode
					infile.seekg(0,ios::beg); // set file pointer to 					the begining of the file
					while(infile.read((char*)&vac,sizeof(vac)))  // search whole file
					{
					clrscr();
							if (vac.exper ==experien) // record found
						{
							counter++;            // increment 							counter
							vac.show();     // display record
						}

					}
					infile.close();   // close file
					gotoxy(20,24);    // set cursor position
					cout<<" RECORDS FOUND = "<<counter; // display 						counter
					getch();     // wait for key press
						if(counter==0)
	{
	clrscr();
	prompt();
	textcolor(5+143);
	gotoxy(25,12);
	cprintf("NO RECORD FOUND");
	getch();
	}
					break;

			       case '4':   clrscr();
			       choices();
					}

					}

					while(search_choice!=4);
					}


/* ===================== FUNCTION TO GET THE VACANCY DETAILS =========== */


void vacancy::get_vacancy()
{

	cout<<"\n ENTER THE CODE FOR THIS VACANCY------------>";
	cin>>vac_code;
	cout<<"\n ENTER THE VACANCY FIELD TO BE ADDED ------------->";
	gets(vac_type);
	strupr(vac_type);
	cout<<"\n ENTER THE QUALIFICATION REQUIRED ------------->";
	gets(vac_qual);
	strupr(vac_qual);
	cout<<"\n ENTER THE SPECIALITION REQUIRED ------------->";
	gets(vac_spec);
	strupr(vac_spec);
	cout<<"\n ENTER THE NO.YEAR'S EXPERIENCE REQUIRED---->";
	cin>>exper;
	cout<<"\n ENTER THE NO OF EMPLOYEE'S REQUIRED ------->";
	cin>>vac_req_no;
}

/* ==================== FUNCTIO TO SHOW VACANCY AVAILABLE ============== */


void vacancy ::show_vac()
{
	cout<<"\n";
	cout<<setiosflags(ios::left)
	<<setw(8)<<""
	<<setw(15)<<vac_code
	<<setw(20)<<vac_type
	<<setw(27)<<vac_spec
	<<setw(30)<<vac_req_no;
}

/* ==================== FUNCTION TO ADD NEW VACANCY =================== */

void vacancy::add_vacancy()
{
	fstream outfile;
	char choice ='y';
	outfile.open("vacancy.dat",ios::app);
	//above line is used to open file in append mode
	while(choice=='y'||choice=='Y')
	{
		vac.get_vacancy(); //get new vacancy
		outfile.write((char*)&vac,sizeof(vac));//write in the file
		cout<<"\n ANY MORE FACILITY TO BE ADDED <<Y/N>>?------->";
		cin>>choice;
	}
}

/* ==================== FUNCTION TO SHOW VACANCY FILE ================== */



 void vacancy ::show_vacancy()
{
	clrscr();
	fstream infile;
	int count=0,state=0;
	infile.open("vacancy.dat",ios::in);
	//above line is used to open file in  input mode
	infile.seekg(0,ios::beg);
	//above line is used to set file pointer to the begububg if the file
	for(int i=0;i<20;i++)
		  cout<<"====";

	cout<<" <-VACANCY CODE-><-  VACANCY TYPE  -><-    SPECIALIST IN  -><-REQ.NO.OF.PEOPLE->";
	for(i=0;i<20;i++)
		 cout<<"====";
       while(infile.read((char*)&vac,sizeof(vac)))
	{
	state++;
	count++;
	if(count==10)
	{
		cout<<"press any key to conyinue";
		getch();
		clrscr();
		cout<<"================================================================================";
		cout<<" <-VACANCY CODE-><-  VACANCY TYPE  -><-    SPECIALIST IN  -><-REQ.NO.OF.PEOPLE->";
		cout<<"================================================================================";
		count=0;
	 }

	 vac.show_vac();
//	 infile.read((char*)&vac,sizeof(vac));//read next vacancy

	 //infile.read((char*)&vac,sizeof(vac)); // read next recor
	}
	if(state==0)
	{
	clrscr();
	prompt();
	textcolor(5+143);
	gotoxy(25,12);
	cprintf("NO RECORD FOUND");
	getch();
	}
	infile.close();
	gotoxy(20,24);
	cout<<"press any key to conyinue";
	getch();

}

/* ===================== FUNCTION TO MODIFY VACANCY FILE =============== */


 void vacancy :: modify_vacancy()
 {


	char choice,i;
	char *str="MODIFY VACANCY FILE";
	char *b[]=
		{
	     " ADD RECORD ",
	     " DELETE RECORD",
	     " SEARCH VACANCY",
	     " SEE THE MEMBER AVAILABALE",
	     " EXIT",
		};
	do
	{
		clrscr();
		choice=menu(str,b,4);
		switch(choice)
			{
			case '1' : clrscr();
				   vac.add_vacancy();
				   break;
			case '2': clrscr();
				  vac.del_vacancy();
				  break;
			case '3': clrscr();
				  vac.search();
				  break;
			case '4': clrscr();
				  vac.show_vacancy();
				  break;
			case '5': clrscr();
				  choices();
				  break;

	     }
     }while(choice!=4);

 }

/* ============== FUNCTION TO DRAW TABLE(PLACEMENT) ================*/

void form :: place_mem(char * str)
{
	clrscr();
	textcolor(WHITE);
	box(1,1,77,25);
	for(int x=2;x<76;x++)
	{
		gotoxy(x,3);
		cprintf("%c",196);
	}
	for(x=4;x<25;x++)
	{
		gotoxy(15,x);
		cprintf("%c",179);
		gotoxy(37,x);
		cprintf("%c",179);
		gotoxy(60,x);
		cprintf("%c",179);
	}
	textcolor(11+143);

	gotoxy(30, 2);
	textbackground(RED);
	cprintf(str);
	textbackground(BLACK);
	textcolor(11);
	gotoxy(3,4);
	cprintf("MEMBER CODE");


	gotoxy(23,4);
	cprintf("NAME");


		gotoxy(39,4);
	cprintf("HIGER QUALIFICATION");
	gotoxy(62,4);
	cprintf("EXPERIENCE");
	textcolor(BLUE);
 }



 void vacancy :: place_vacancy()
{
	clrscr();
	char *str="VACANCY AVILABLE";
	textcolor(WHITE);
	box(1,1,77,25);
	for(int x=2;x<76;x++)
	{
		gotoxy(x,3);
		cprintf("%c",196);
	}
	for(x=4;x<25;x++)
	{
		gotoxy(15,x);
		cprintf("%c",179);
		gotoxy(37,x);
		cprintf("%c",179);
		gotoxy(60,x);
		cprintf("%c",179);
	}
	textcolor(11+143);

	gotoxy(30, 2);
	textbackground(RED);
	cprintf(str);
	textbackground(BLACK);
	textcolor(11);
	gotoxy(3,4);
	cprintf("VACANCY CODE");


	gotoxy(23,4);
	cprintf("VACANCY TYPE");


		gotoxy(39,4);
	cprintf("SPECIALIST");
	gotoxy(62,4);
	cprintf("NO OF VACANCY");
	textcolor(BLUE);
 }


     void form ::show_da(int y)
 {
	textcolor(BLUE);
	gotoxy(7,y);
	cout<<res_code;
	gotoxy(18,y);
	cout<<name;
	gotoxy(40,y);
	cout<<higher_qualif;
	gotoxy(63,y);
	cout<<exper<<" years";
 }


/* ======== FUNCTION TO DISPLAY ALL THE MEMBER REGISTERED ======== */

  void form ::master_rec()
 {
	clrscr();
	int i,y=5,state=0;;
	char str[]="MASTER RECORD FILE";
	fstream infile;
	infile.open("master.dat",ios::in);
	//above line is used to open file in  input mode
	infile.seekg(0,ios::beg);
	//above line is used to set file pointer to the begububg if the file
	place_mem(str);
	//infile.read((char*)&member,sizeof(member));
	//read first object

	while(infile.read((char*)&member,sizeof(member)))
	{
		state++;
		member.show_da(y);

		y++;
		if(y>20)
		{
			textcolor(11+143);
			gotoxy(20,24);
			cprintf("PRESS ANY KEY TO CONTINUE");
			getch();
			place_mem(str);
			y=5;
		}
	}
	if(state==0)
	{
	clrscr();
	prompt();
	textcolor(5+143);
	gotoxy(25,12);
	cprintf("NO RECORD FOUND");
	getch();
	}
	infile.close();
	gotoxy(20,24);
	cout<<"press any key to continue";
	getch();

  }
/* ========== FUNCTION TO DISPLAY ALL THE DELETED RECORDS ========== */

    void form ::deleted_rec()
 {
	clrscr();
	int i,y=5,state=0;
	char str[]="DELETED RECORD FILE";
	fstream infile;
	infile.open("deleted.dat",ios::in);
	//above line is used to open file in  input mode
	infile.seekg(0,ios::beg);
	//above line is used to set file pointer to the begububg if the file
	place_mem(str);
//	infile.read((char*)&member,sizeof(member));
	//read first object

	while(infile.read((char*)&member,sizeof(member)))
	{
		state++;
		member.show_da(y);

		y++;
		if(y>20)
		{
			textcolor(11+143);
			gotoxy(20,24);
			cprintf("PRESS ANY KEY TO CONTINUE");
			getch();
			place_mem(str);
			y=5;
		}
	}
	if(state==0)
	{
	clrscr();
	prompt();
	textcolor(5+143);
	gotoxy(25,12);
	cprintf("NO RECORD FOUND");
	getch();
	}
	infile.close();
	gotoxy(20,24);
	cout<<"press any key to continue";
	getch();

  }

  void form::return_del_mem()
  {
	clrscr();
	unsigned long code;
	int state=1;
	fstream infile,infile1,outfile,outfile1;
	cout<<"\n ENTER THE MEMBERSHIP CODE TO BE DELETED ----->";
	cin>>code;
	outfile.open("temp.dat",ios::app);
	infile.open("deleted.dat",ios::in);
	infile1.open("deleted.dat",ios::in);
	infile.seekg(0,ios::beg);
	infile1.seekg(0,ios::beg);
	while(infile1.read((char*)&member,sizeof(member)))
	{
		if(member.res_code==code)
		{
			switch(type)
			{
				case 1 : outfile1.open("computer.dat",ios::app);
				 break;
				case 2:	 outfile1.open("mba.dat",ios::app);
				 break;
				case 3:	 outfile1.open("docter.dat",ios::app);
				 break;
				case 4:	 outfile1.open("engineer.dat",ios::app);
				 break;
				case 5:	 outfile1.open("commerce.dat",ios::app);
				 break;
				case 6:	 outfile1.open("science.dat",ios::app);
				 break;
				case 7:	 outfile1.open("other.dat",ios::app);
				 break;
			}
		outfile1.write((char*)&member,sizeof ( member));
		outfile1.close();
		}
	}
	infile1.close();
	while(infile.read((char*)&member,sizeof(member)))
	{
	       if (member.res_code!=code)
		       outfile.write((char*)&member,sizeof ( member));
	       else
	       {
		       char ch;
		       state=0;
		       clrscr();
		       gotoxy(10,10);
		       cout<<"DO YOU WANT TO DELETE THE RECORD PERMANENT<Y/N> : ";
		       cin>>ch;

	       }
	}

	if(state==1)
	{
	clrscr();
	prompt();
	textcolor(5+143);
	gotoxy(25,12);
	cprintf("RECORD NOT FOUND");
	getch();
	}
	infile.close();
	outfile.close();
	remove("deleted.dat");
	rename("temp.dat","deleted.dat");
}

void form::deleted_mem()
{
char choice;
char *b[]=
		{
	     " LIST OF INTERVIEWING MEMBER",
	     " RETURN MEMBER",
	     " DELETED PERMANENTLY",
	     " EXIT",
		};
	do
	{

		choice = menu("GARV AGENCY",b,3);
		clrscr();

		switch (choice)
		{
		   case '1':
				member.deleted_rec();
				break;

		   case '2':
				member.return_del_mem();
				break;

		   case '3':    member.deleted_del();
				break;

		   case '4':     report();
				break;


		}

	} while (choice != 4);
}



 void form::deleted_del()
 {
	clrscr();
	unsigned long code;
	int state=1;
	fstream infile,outfile;
	cout<<"\n ENTER THE MEMBERSHIP CODE TO BE DELETED ----->";
	cin>>code;
//	tojob(code);
	outfile.open("temp.dat",ios::app);
	infile.open("deleted.dat",ios::in);
	infile.seekg(0,ios::beg);

 while(infile.read((char*)&member,sizeof(member)))
	{
	       if (member.res_code!=code)
		       outfile.write((char*)&member,sizeof ( member));
	       else
	       {
		       char ch;
		       state=0;
		       clrscr();
		       gotoxy(10,10);

	       }

	}

	if(state==1)
	{
	clrscr();
	prompt();
	textcolor(5+143);
	gotoxy(25,12);
	cprintf("RECORD NOT FOUND");
	getch();
	}
	infile.close();
	outfile.close();
	remove("deleted.dat");
	rename("temp.dat","deleted.dat");
 }
 /* ================= FUNTION TO UPDATE FILE(COMPUTER)=============== */


 void form::add_object(int ch)
  {
	fstream outfile, outfile2;
	char choice='y' ;
	int valid=1;
	//update placement services Computer Professional file
		switch(ch)
	{
	case 1 : outfile.open("computer.dat",ios::app);
		 break;
	case 2:	 outfile.open("mba.dat",ios::app);
		 break;
	case 3:	 outfile.open("docter.dat",ios::app);
		 break;
	case 4:	 outfile.open("engineer.dat",ios::app);
		 break;
	case 5:	 outfile.open("commerce.dat",ios::app);
		 break;
	case 6:	 outfile.open("science.dat",ios::app);
		 break;
	case 7:	 outfile.open("other.dat",ios::app);
		 break;
	}
	outfile2.open("master.dat",ios::app);
	while(choice=='y'&& valid==1)
	{
		valid=member.get_data(ch); //get information from the user
		if(valid==1)
		{
		outfile.write((char*)&member,sizeof(member));//write in file
		outfile2.write((char*)&member,sizeof(member));//write in file
		outfile2.flush();
		outfile.flush();
		clrscr();
		member.memcard();
		clrscr();
		textcolor(11+143);
		gotoxy(17,15);
		textbackground(BLUE);
		cprintf("Any more records to be entered<Y/N> ");
//		flushall();
		cin>>choice;//=getch();
		textbackground(BLACK);
		textcolor(22);
		}
	}
	outfile.close(); //close file
	outfile2.close();
  }


 /* ================= FUNTION TO SHOW DATA (COMPUTER)=============== */



  void form::show_object(int ch)
 {
	fstream infile;
	switch(ch)
	{
	case 1 : infile.open("computer.dat",ios::in);
		 break;
	case 2:	 infile.open("mba.dat",ios::in);
		 break;
	case 3:	 infile.open("docter.dat",ios::in);
		 break;
	case 4:	 infile.open("engineer.dat",ios::in);
		 break;
	case 5:	 infile.open("commerce.dat",ios::in);
		 break;
	case 6:	 infile.open("science.dat",ios::in);
		 break;
	case 7:	 infile.open("other.dat",ios::in);
		 break;
	}
	infile.seekg(0,ios::beg); //set file pointer to the begining of the file
	int count=0;
	while(infile.read((char*)&member,sizeof(member)))//!infile.eof())
	{
	      count++;
	      member.show_data(ch);//display record
	}
	if(count==0)
	{
	clrscr();
	prompt();
	gotoxy(25,12);
	textcolor(7+143);
	cprintf("NO RECORD IS FOUND");
	getch();
	textcolor(WHITE);
	}
	infile.close();
  }



 /* ================= FUNTION TO DELETE DATA (COMPUTER)=============== */

  void  form::del_object(int ch)
 {
	clrscr();
	unsigned long code;
	int state=1;
	fstream infile,outfile,outfile2;
	cout<<"\n ENTER THE MEMBERSHIP CODE TO BE DELETED ----->";
	cin>>code;
	outfile.open("temp.dat",ios::app);
	switch(ch)
	{
	case 1 : infile.open("computer.dat",ios::in);
		 break;
	case 2:	 infile.open("mba.dat",ios::in);
		 break;
	case 3:	 infile.open("docter.dat",ios::in);
		 break;
	case 4:	 infile.open("engineer.dat",ios::in);
		 break;
	case 5:	 infile.open("commerce.dat",ios::in);
		 break;
	case 6:	 infile.open("science.dat",ios::in);
		 break;
	case 7:	 infile.open("other.dat",ios::in);
		 break;
	}
	outfile2.open("deleted.dat",ios::app);
	infile.seekg(0,ios::beg);
	infile.read((char*)&member,sizeof(member));


	while(!infile.eof())
	{
	       if (member.res_code!=code)
		       outfile.write((char*)&member,sizeof ( member));
	       else
	       {
		       char ch;
		       state=0;
		       clrscr();
		       gotoxy(10,10);
		       cout<<"DO YOU WANT TO DELETE THE RECORD PERMANENT<Y/N> : ";
		       cin>>ch;
		       if(ch=='n' || ch=='N')
				outfile2.write((char*)&member,sizeof(member));
	       }
		       infile.read((char*)&member,sizeof (member));
	}

	if(state==1)
	{
	clrscr();
	prompt();
	textcolor(5+143);
	gotoxy(25,12);
	cprintf("RECORD NOT FOUND");
	getch();
	}
	infile.close();
	outfile.close();
	outfile2.close();
	switch(ch)
	{
	case 1:	remove("computer.dat");
		rename("temp.dat","computer.dat");
		break;
	case 2:	remove("mba.dat");
		rename("temp.dat","mba.dat");
		break;
	case 3:	remove("docter.dat");
		rename("temp.dat","docter.dat");
		break;
	case 4:	remove("engineer.dat");
		rename("temp.dat","enginerr.dat");
		break;
	case 5:	remove("commerce.dat");
		rename("temp.dat","commerce.dat");
		break;
	case 6:	remove("science.dat");
		rename("temp.dat","science.dat");
		break;
	case 7:	remove("other.dat");
		rename("temp.dat","other.dat");
		break;
	}

 }

 /* ================= FUNTION TO SHOW OBJECT (COMPUTER)=============== */

 void form ::show_obj(int ch)
 {
	clrscr();
	int i,y=5;
	char *str;
	fstream infile;
	switch(ch)
	{
	case 1 : infile.open("computer.dat",ios::in);
		 strcpy(str,"COMPUTER PROFESSIONAL");
		 break;

	case 2 : infile.open("mba.dat",ios::in);
		 strcpy(str,"MASTER OF BUSINESS ADMINISTRATION");
		 break;

	case 3 : infile.open("docter.dat",ios::in);
		 strcpy(str,"DOCTERS");
		 break;

	case 4 : infile.open("engineer.dat",ios::in);
		 strcpy(str,"ENGINNERS");
		 break;

	case 5 : infile.open("commerce.dat",ios::in);
		 strcpy(str,"COMMERCE PROFESSIONAL");
		 break;

	case 6 : infile.open("science.dat",ios::in);
		 strcpy(str,"SCIENCE PROFESSIONAL");
		 break;

	case 7 : infile.open("other.dat",ios::in);
		 strcpy(str,"OTHER PROFESSIONAL");
		 break;
	}
	//above line is used to open file in  input mode
	infile.seekg(0,ios::beg);
	//above line is used to set file pointer to the begububg if the file
	place_mem(str);
	int count=0;
	while(infile.read((char*)&member,sizeof(member)))
	{
		member.show_da(y);
		y++;
		count++;
		if(y>20)
		{
			textcolor(11+143);
			gotoxy(20,24);
			cprintf("PRESS ANY KEY TO CONTINUE");
			getch();
			place_mem(str);
			y=5;
		}
	}
	if(count==0)
	{
	clrscr();
	prompt();
	textcolor(5+143);
	gotoxy(25,12);
	cprintf("RECORD NOT FOUND");
	getch();
	}
	infile.close();
	gotoxy(20,24);
	cout<<"press any key to continue";
	getch();

  }

 /* ================= FUNTION TO MODIFY FILE (COMPUTER)=============== */


  void form ::modify_mem(int ch)
 {
	char choice;
	char *str;
	switch(ch)
	{
	case 1 : strcpy(str,"MODIFY COMPUTER PROFESSIONAL");
		 break;
	case 2:	 strcpy(str,"MODIFY MASTER OF BUSINESS ADMINISTRATION");
		 break;
	case 3:	 strcpy(str,"MODIFY DOCTERS");
		 break;
	case 4:	 strcpy(str,"MODIFY ENGINNERS");
		 break;
	case 5:	 strcpy(str,"MODIFY COMMERCE PROFESSIONAL");
		 break;
	case 6:	 strcpy(str,"MODIFY SCIENCE PROFESSIONAL");
		 break;
	case 7:	 strcpy(str,"MODIFY OTHER PROFESSIONAL");
		 break;
	}
		char *b[] =
		{
	     " ADD RECORD ",
	     " DELETE RECORD",
	     " SEE THE MEMBER AVAILABALE",
	     " EXIT",
		};


	do
	{
		clrscr();
		choice=menu(str,b,3);
		switch(choice)
		{
		      case '1': clrscr();
				member.add_object(ch);
				break;

		      case '2': clrscr();
				member.del_object(ch);
				break;

		      case '3': clrscr();
				member.show_obj(ch);
				break;
		      case '4': clrscr();
				choices();
		}
	}while(choice!=4);
 }

/* ================= FUNTION TO SEARCH DATA (COMPUTER)=============== */


  void form::find_object(int ch)
 {
	char choice;
	int ages,age2,counter=0;
	char quali[30],expir[30],sexy,work;
	fstream infile;
	char * b[]=
		{
		"AGE ",
		"QUALIFICATION ",
		"EXPERIENCE",
		"PLACE OF WORKING",
		"SEX",
		"COMBINED",
		"EXIT",
		};
	do
	{
	clrscr();
	choice=menu("SEARCH MENU",b,6);
	switch(ch)
	{
	case 1 : infile.open("computer.dat",ios::in);
		 break;
	case 2:	 infile.open("mba.dat",ios::in);
		 break;
	case 3:	 infile.open("docter.dat",ios::in);
		 break;
	case 4:	 infile.open("engineer.dat",ios::in);
		 break;
	case 5:	 infile.open("commerce.dat",ios::in);
		 break;
	case 6:	 infile.open("science.dat",ios::in);
		 break;
	case 7:	 infile.open("other.dat",ios::in);
		 break;
	}
	infile.seekg(0,ios::beg);
	// set file pointer to the begining of the file
//	infile.read((char*)&member,sizeof(member));
	// read the first record
	switch(choice)
		{
			case '1': clrscr();
				  cout<<"\n ENTER AGE TO BE SEARCHED ->";
				  cin>>ages;
				  counter=0;
				   while(infile.read((char*)&member,sizeof(member)))
				   // search whole file
				   {
					if(member.age == ages) // record found
					{
						 counter++;        // increment counter
						 member.show_data(1); // display record
					}

					// read next record
				  }
				  infile.close(); // close file
				  gotoxy(20,24);  // set cursor position
				  cout<<"                                     ";
				  gotoxy(20,24);  // set cursor position
				  cout<<" RECORDS FOUND = "<<counter; // display counter
				  getch();    // wait for keypress
				  break;

			case '2': clrscr();
				  cout<<"\n ENTER THE QUALIFICATION TO BE SEARCHED ->";
				  gets(quali);
				  counter=0;
				  while(infile.read((char*)&member,sizeof(member)))  // search whole file
				  {
				  if (strcmpi(member.higher_qualif,quali) == 0) // 						record found
				  {
					counter++;            // increment counter
					member.show_data(1);     // display record
				  }
				  }
				  infile.close();   // close file
				    gotoxy(20,24);  // set cursor position
				  cout<<"                                     ";
				  gotoxy(20,24);    // set cursor position
				  cout<<" RECORDS FOUND = "<<counter; // display counter
				  getch();     // wait for key press
				  break;

			case '3': clrscr();
				  cout<<"\n ENTER THE OF EXPERIENCE TO BE SEARCHED -->";
				  gets(expir);
				  counter=0;
				  while(infile.read((char*)&member,sizeof(member)))  // search whole file
				  {
					if (strcmpi(member.exper,expir)==0) // record 						found
					  {
						counter++;            // increment counter
						member.show_data(1);     // display record
					  }
				  }
				  infile.close();   // close file
				    gotoxy(20,24);  // set cursor position
				  cout<<"                                     ";
				  gotoxy(20,24);    // set cursor position
				  cout<<" RECORDS FOUND = "<<counter; // display counter
				  getch();     // wait for key press
				  break;


			case '4': clrscr();
				  counter=0;
				  cout<<"\n ENTER THE  PLACE OF WORKING<I-INDIA/A-ABROAD> TO BE SEARCHED ---->";
				  cin>>work;
				  while(infile.read((char*)&member,sizeof(member)))  // search whole file
				  {
					if(member.pref_work==work) // record found
					{
						counter++;            // increment counter
						member.show_data(1);     // display record
					}
				   }
				  infile.close();   // close file
				    gotoxy(20,24);  // set cursor position
				  cout<<"                                     ";
				  gotoxy(20,24);    // set cursor position
				  cout<<" RECORDS FOUND = "<<counter; // display counter
				  getch();     // wait for key press
				  break;

			case '5': clrscr();
				  counter=0;
				  cout<<"\n ENTER THE  SEX TO BE SEARCHED ---->";
				  cin>>sexy;
				  while(infile.read((char*)&member,sizeof(member)))  // search whole file
				  {
				  if(member.sex==sexy) // record found
				  {
					counter++;            // increment counter
					member.show_data(1);     // display record
				  }
				  }
				  infile.close();   // close file
				   gotoxy(20,24);  // set cursor position
				  cout<<"                                     ";
				  gotoxy(20,24);    // set cursor position

				  cout<<" RECORDS FOUND = "<<counter; // display counter
				  getch();     // wait for key press
				  break;
			case '6': clrscr();
				  cout<<"\n ENTER AGE TO BE SEARCHED (MIN)->";
				  cin>>ages;
				  cout<<"\n ENTER AGE TO BE SEARCHED (MAX)->";
				  cin>>age2;
				  cout<<"\n ENTER THE QUALIFICATION TO BE SEARCHED ->";
				  gets(quali);
				  strupr(quali);
				  cout<<"\n ENTER THE OF EXPERIENCE TO BE SEARCHED -->";
				  gets(expir);
				  cout<<"\n ENTER THE  PLACE OF WORKING<I-INDIA/A-ABROAD> TO BE SEARCHED ---->";
				  cin>>work;
				  toupper(work);
				  cout<<"\n ENTER THE  SEX TO BE SEARCHED ---->";
				  cin>>sexy;
				  toupper(sexy);
				  counter=0;
				   while(infile.read((char*)&member,sizeof(member)))
				   // search whole file
				   {
					if(member.age>=ages && member.age<=age2) // record found
					{
					  if ((strcmpi(member.higher_qualif,quali) == 0) || (strlen(quali)==0))
					  {
						if (strcmpi(member.exper,expir)==0) // record found
						  {
						  if(member.pref_work==work) // record found
							{
							  if(member.sex==sexy) // record found
							  {

						 counter++;        // increment counter
						 member.show_data(1); // display record
							}
						 }
						 }
						 }
						 }


					// read next record
				  }
				  infile.close(); // close file
				  gotoxy(20,24);  // set cursor position
				  cout<<"                                     ";
				  gotoxy(20,24);  // set cursor position
				  cout<<" RECORDS FOUND = "<<counter; // display counter
				  getch();    // wait for keypress
				  break;

		       case '7':  clrscr();
				  find();
				  break;
		 }
	if(counter==0)
	{
	clrscr();
	prompt();
	textcolor(5+143);
	gotoxy(25,12);
	cprintf("NO RECORD FOUND");
	getch();
	}
	 }while(choice!='6');

  }


 /* ================= FUNTION TO INPUT DATA (MBA)=============== */

  int form :: get_data(int ch)
 {
	clrscr();
	box(10,3,70,23);
	box(5,1,74,25);
	gotoxy(60,4);
	cout<<"<0 - EXIT>";
	int valid;
	textcolor(11+143);

	gotoxy(27, 2);
	textbackground(BLUE);
	cprintf("<-REGISTERATION FORM->");
	textbackground(BLACK);
	textcolor(22);
	textcolor(5);
	gotoxy(12 ,5);
	cprintf("Registration No.  -> ");
	gotoxy(35,5);
	res_code=last_code()+1;
	cout<<res_code;
	type=ch;
	 do
	{
		clear(12,7,25);
		textcolor(5);
		gotoxy(12,7);
		cprintf("Enter the name    -> ");
		gets(name);
		valid = 1;
		strupr(name);
		if(strcmp(name,"0")==0)
		return 0;

		if (strlen(name) > 30 )
		{
			valid = 0;
			gotoxy(10, 24);
			prompt();
			cout<<"Name should not greater than 30";
			getch();
			clear(32,7,strlen(name)+1);
			clear(7,24,50);
		}
		for(int i=0;i<strlen(name)-1;i++)
		{
		if(isdigit(name[i]))
		{
			valid = 0;
			gotoxy(10, 24);
			prompt();
			cout<<"Name should not be numric";
			//delay(1000);
			getch();
			clear(32,7,strlen(name)+1);
			clear(7,24,50);
			break;
		}
		}
		textcolor(5);
		gotoxy(12,7);
		cprintf("Enter the name    -> ");
	}while (!valid);

	 do
	{
		clear(12,9,25);
		textcolor(5);
		gotoxy(12,9);
		cprintf("Permanent Address -> ");
		gets(address);
		valid = 1;
		strupr(address);
		if(strcmp(address,"0")==0)
		return 0;

		if (strlen(address) == 0 || strlen(address) > 30 )
		{
			valid = 0;
			gotoxy(10, 24);
			cout<<"Address should not greater than 30";
			prompt();
			//delay(1000);
			getch();
			clear(32,9,strlen(address)+1);
			clear(9,24,50);
		}
		textcolor(5);
		gotoxy(12,9);
		cprintf("Permanent Address -> ");
	}while (!valid);
	 textcolor(5);
	 gotoxy(12,11);
	 cprintf("Age     -> ");
	 cin>>age;
	 if (age == 0)
	 return 0;
	 gotoxy(26,11);
	 cout<<"years";
		 do
	{
		clear(42,11,25);
		textcolor(5);
		gotoxy(42,11);
		cprintf("Phone no. ->");
		cin>>phone_no;
		valid = 1;
		if(phone_no==0)
		return 0;
		if (phone_no>29999999 || phone_no<21000000 )
		{
			valid = 0;
			gotoxy(10, 24);
			prompt();
			cout<<"Phone number should not greater or less than 8 digit";
			//delay(1000);
			getch();
			clear(42,11,25);
			clear(7,24,55);
		}

		textcolor(5);
		gotoxy(42,11);
		cprintf("Phone no. ->");
	}while (!valid);
	 do
	{
	 clear(37,12,25);
	 textcolor(5);
	 gotoxy(12,13);
	 cprintf("Sex(M-male,F-female) -> ");
	 cin>>sex;
	 toupper(sex);
	 valid=1;
	 if(sex=='0')
	 return 0;
	 if(sex!='m' && sex!='M' && sex!='f' && sex!='F')
	 {
			valid = 0;
			gotoxy(10, 24);
			prompt();
			cout<<"WORNG ENTRY FOR THE SEX(M/F)";
			//delay(1000);
			getch();
			clear(37,12,25);
			clear(7,24,55);
	 }
	 else
	 {
	 gotoxy(36,13);
	 if(sex=='m' || sex=='M')
		 cout<<"Male";
	 else
		 cout<<"Female";
	 }
	 }while(!valid);
	do
	 {
	 clear(42,13,2);
	 textcolor(5);
	 gotoxy(10,24);
	 cout<<"M: MARRIED, S: SINGLE ,D: DIWORCED";
	 gotoxy(42,13);
	 cprintf("Marrital Status<M/S/D> -> ");
	 cin>>marrige;
	 toupper(marrige);
	 valid=1;
	 if(marrige=='0')
	 return 0;
	 if(marrige!='m' && marrige!='M' && marrige!='s' && marrige!='S' && marrige!='d' && marrige!='D')
	 {
			valid = 0;
			clear(10,24,38);
			gotoxy(10, 24);
			prompt();
			cout<<"WORNG ENTRY FOR THE MARRIGE STATUS(M/S/D)";
			//delay(1000);
			getch();
			clear(42,13,2);
			clear(7,24,55);
	 }
	 clear(7,24,55);
	 }while(!valid);

	textcolor(5);
	gotoxy(12,15);
	cprintf("Higher Qualifications -> ");
	gets(higher_qualif) ;
	strupr(higher_qualif);
	if(strcmp(higher_qualif,"0")==0)
	return 0;
	textcolor(5);
	gotoxy(12,17);
	flushall();
	cprintf("Expperience -> ");
	cin>>exper;
	gotoxy(30,17);
	cout<<"years";

	textcolor(5);
	gotoxy(42,17);
	if(ch==2 || ch==4)
	cprintf("Branch ->");
	if(ch==3 || ch==7)
	cprintf("Specialist ->");
	if(ch==1||ch==5 || ch==6)
	cprintf("Stream ->");
	gets(stream);
	strupr(stream);
	if(strcmp(stream,"0")==0)
	return 0;
	textcolor(5);
	gotoxy(12,19);
	cprintf("Language Known -> ");
	gets(language);
	strupr(language);
	if(strcmp(language,"0")==0)
	return 0;

	do
	 {
	 clear(62,21,2);
	 textcolor(5);
	 gotoxy(12,21);
	 cprintf("Prefrence place of working(I-INDIA, A-ABOARD) -> ");
	 cin>>pref_work;
	 toupper(pref_work);
	 valid=1;
	 if(pref_work=='0')
	 return 0;
	 if(pref_work!='i' && pref_work!='I' && pref_work!='a' && pref_work!='A')
	 {
			valid = 0;
			clear(10,24,38);
			gotoxy(10, 24);
			prompt();
			cout<<"WORNG ENTRY FOR THE WORK PREFRENCE(I/A)";
			//delay(1000);
			getch();
			clear(62,21,2);
			clear(7,24,55);
	 }
	 else
	 {
	 gotoxy(61,21);
	 if(pref_work=='i' || pref_work=='I')
		 cout<<"India";
	 else
		 cout<<"Abroad";
	 }
	 }while(!valid);
	 getdate(&dat);
	 return 1;

 }


 /* ================= FUNTION TO SHOW DATA (MBA)=============== */


  void form ::show_data(int ch)
  {
	clrscr();
	box(10,3,70,23);
	box(5,1,74,25);
	textcolor(11+143);

	gotoxy(27, 2);
	textbackground(BLUE);
	cprintf("<-MASTER OF BUSSINESS ADMINTRATION->");
	textbackground(BLACK);
	textcolor(22);
	textcolor(5);
	gotoxy(12 ,5);
	cprintf("Registration No.  -> ");
	cout<<res_code ;
	textcolor(5);
	gotoxy(12,7);
	cprintf("Name    -> ");
	puts(name);
	textcolor(5);
	gotoxy(12,9);
	cprintf("Permanent Address -> ");
	puts(address);
	textcolor(5);
	gotoxy(12,11);
	cprintf("Age -> ");
	cout<<age;
	cout<<" years";
	textcolor(5);
	gotoxy(42,11);
	cprintf("Phone No.  -> ");
	cout<<phone_no;
	textcolor(5);
	gotoxy(12,13);
	cprintf("Sex -> ");
	if(sex=='m' || sex=='M')
	     cout<<"Male";
	else
	     cout<<"Female";
	textcolor(5);
	gotoxy(42,13);
	cprintf("Marrital Status -> ");
	cout<<marrige;
	gotoxy(12,15);
	textcolor(5);
	cprintf("Higher Qualifications -> ");
	puts(higher_qualif) ;
	textcolor(5);
	gotoxy(12,17);
	cprintf("Expperience -> ");
	cout<<exper;
	cout<<"years";
	textcolor(5);
	gotoxy(42,17);
	if(ch==2 || ch==4)
	cprintf("Branch ->");
	if(ch==3 || ch==7)
	cprintf("Specialist ->");
	if(ch==1 ||ch==5 || ch==6)
	cprintf("Stream ->");
	puts(stream);

	textcolor(5);
	gotoxy(12,19);
	cprintf("Language Known -> ");
	puts(language);
	textcolor(5);
	gotoxy(12,21);
	cprintf("Prefrence place of working -> ");
	if(pref_work=='i' || pref_work=='I')
	     cout<<"India";
	else
	     cout<<"Abroad";

	textcolor(11+143);
	gotoxy(27,24);
	textbackground(BLUE);
	cprintf("Press any key to continue");
	fflush(stdin);
	getch();
	textbackground(BLACK);
	textcolor(22);
  }




/* ================== FUNCTON TO CLEAR A ROW (LEFT)================== */


  void form::Left_clear(int col, int row)
 {
	for (int j = col; j <= 39; j++)
	{
		gotoxy(j, row);
		cout << " ";
	}
 }


 /* ================== FUNCTON TO CLEAR A ROW (RIGHT)================== */


  void form::Right_clear(int col, int row)
 {
	for (int j = col; j <= 79; j++)
	{
		gotoxy(j, row);
		cout << " ";
	}
  }



  /* ================== FUNCTON TO FILL GENERAL FORM================== */

 void form :: gen_form()
 {
	int routeno;;
	char ch;
	int i, val;
	clrscr();
	gotoxy(3, 3);
	for (i = 1; i<= 76; i++)
		cprintf(" ");
	textbackground(BLACK);
	textcolor(BLACK+BLINK);
	textbackground(WHITE);
	gotoxy(30, 3);
	cprintf("G.A.R.V Placement General Entry");
	textcolor(LIGHTGRAY);
	textbackground(BLACK);
	gotoxy(65, 3);
	cout << "<0>=Exit";
	fstream fr;
	int rno;
	fr.open("general.dat",ios::in|ios::app);
	fr.seekg(0,ios::end);
	int end=fr.tellg();
	if(end<=0)
	end=0;
	int nr=end;
	int nr1=0;
	if(nr==0)
	{
		rno=0;
		gotoxy(20,25);
		cout<<"NO RECORDS";
	}
	else
	{
		fr.seekg(0,ios::beg);
		while(nr1<nr)
		{
			fr.seekg(nr1*sizeof(member),ios::beg);
			fr.read((char *) this,sizeof(member));
			rno=routeno;
			nr1++;
		}
	}// end of else
	fr.close();
	routeno=rno+1;
	box(9,1,76,25);
	do
	{
		int mem_no;	// form number
		char name[30];        //name of visitor
		char address[30], address2[30];	// address of visitor
		char f_name[30];	// father name of visitor
		long int phone_no;	// Phone no of visitor
		int sdd, smm, syy;	// Date of enquary
		int age;	// Total pages in book
		char s_status;	// merital status of visitor
		char qualif[30];//qualification of visitor
		struct date d;		// For extracting system date
		getdate(&d);
		sdd = d.da_day;
		smm = d.da_mon;
		syy = d.da_year;
		gotoxy(50, 7);
		cout << "Date: " << sdd << '-' << smm << '-' << syy;
		gotoxy(10, 23);
		cout << "Enter the form number";
		gotoxy(13, 7);
		cout << "FORM  NO. ";
//		routeno=last_codegen()+1;
		cout<<routeno;
		Left_clear(10, 23);
		Right_clear(39, 23);
		gotoxy(11, 8);
		for (i = 1; i <= 60; i++)
			cout << "=";
		do
		{
			gotoxy(10, 23);
			cout << "Enter the enquary number";
			gotoxy(13, 9);
			cout << "ENQUARY NO. ";
			gotoxy(28, 9);
			cin >> mem_no;
			Left_clear(10, 23);
			Right_clear(39, 23);
			if ((routeno== 0) || (mem_no== 0))
				return;
			gotoxy(13, 10);
			cout << "NAME : ";
			gotoxy(13, 12);
			cout << "ADDRESS1: ";
			gotoxy(13, 14);
			cout << "FATHER NAME : ";
			gotoxy(13, 15);
			cout << "PHONE NO : ";
			gotoxy(13, 16);
			cout << "AGE : ";
			gotoxy(13, 17);
			cout << "MARITAL STATUS: ";
			gotoxy(13,18);
			cout<<"QUALIFICATION :";
			do
			{
				Left_clear(10, 23);
				gotoxy(10, 23);
				cout << "Enter name of the visitor";
				val = 1;
				gotoxy(34, 10);
				gets(name);
				strupr(name);
				if (name[0] == '0')
					return;
				if (strlen(name) == 0 || strlen(name) > 30)
				{
					val = 0;
					gotoxy(10, 23);
					cout << "\7name should not greater than 30";
					getch();
				}
			} while (!val);
			Left_clear(5, 23);
			Right_clear(39, 23);
			do
			{
				gotoxy(10, 23);
				cout << "enter permanent address of visitor ";
				val = 1;
				gotoxy(34, 12);
				gets(address);
				strupr(address);
				if (name[0] == '0')
					return;
				if (strlen(address) == 0 || strlen(address) > 30)
				{
					val = 0;
					gotoxy(10, 23);
					cout << "\7Address should not greater than 30";
					getch();
				}
			}while (!val);
			Left_clear(10, 23);
			Right_clear(39, 23);
			Left_clear(5, 23);
			Right_clear(39, 23);
			do
			{
				Left_clear(10, 23);
				Right_clear(39, 23);
				gotoxy(10, 23);
				cout << "Enter father name of the visitor";
				val = 1;
				gotoxy(34, 14);
				gets(f_name);
				strupr(f_name);
				if (name[0] == '0')
					return;
				if (strlen(f_name) == 0 || strlen(f_name) > 30)
				{
					val = 0;
					gotoxy(10, 23);
					cout << "\7father name should not greater than 							30";
					getch();
				}
			} while (!val);
			Left_clear(10, 23);
			Right_clear(39, 23);
			gotoxy(10, 23);
			cout << "Enter phone no. of visitor";
			gotoxy(34, 15);
			cin >> phone_no;
			Left_clear(10, 23);
			Right_clear(39, 23);
			gotoxy(10, 23);
			cout << "Enter age of visitor";
			gotoxy(34, 16);
			cin >> age;
			Left_clear(10, 23);
			Right_clear(39, 23);
			gotoxy(10,23);
			cout<<"Enter your marital status";
			gotoxy(34,17);
			cin>>s_status;
			Left_clear(10,23);
			Right_clear(39,23);
			gotoxy(10,23);
			cout<<"enter higher qualification";
			gotoxy(34,18);
			gets(qualif);
			do
			{
				val = 1;
				gotoxy(10, 23);
				cout << "Do you want to save the record <Y/N>: ";
				ch = getche();
				if (ch == '0')
					return;
				ch = toupper(ch);
			}while (ch != 'N' && ch != 'Y');
			if (ch == 'N')
				return;
			Left_clear(10, 23);
			Right_clear(39, 23);

			gotoxy(12, 23);
			cout << "Any Accession <Y/N>: ";
			ch = getche();
			if (ch == '0')
				return;
			Left_clear(12, 23);
			Right_clear(12, 23);
		} while (ch == 'Y');

		gotoxy(12, 23);
		cout << "Any Acquisition <Y/N>: ";
		ch = getche();
		if (ch == '0')
			return;
		Left_clear(12, 23);
		Right_clear(12, 23);
		ch = toupper(ch);
	} while (ch == 'Y');

}


/* ================== FUNCTON TO DELETE GENERAL RECORD================== */


  void  form::del_gen()
 {
	clrscr();
	unsigned long code;
	fstream infile,outfile;
	cout<<"\n ENTER THE FORM CODE TO BE DELETED ----->";
	cin>>code;
	outfile.open("tempgen.dat",ios::app);
	infile.open("general.dat",ios::in);
	infile.seekg(0,ios::beg);
	infile.read((char*)&member,sizeof(member));
	while(!infile.eof())
	{
		if (member.form_no!=form_no)
			outfile.write((char*)&member,sizeof ( member));
		infile.read((char*)&member,sizeof (member));
	}
	infile.close();
	outfile.close();
	remove("general.dat");
	rename("tempgen.dat","general.dat");
 }


 /* ================== FUNCTON TO SEARCH INFORMATION================== */

  void form::search_inform()
 {
	fstream infile;
	char search_choice;
	int i;
	  char *b[]=
		{
	     " VACANCY FILE SEARCH ",
	     " MEMBER FILE SEARCH",
	     " EXIT",
		};
	do
	{	// display search menu
		clrscr();
		search_choice=menu("SEARCH MENU",b,5);    // get search choice from the user
		switch(search_choice)
		{
			case '1': vac.search();
				  break;

			case '2': z.enroll_mnu();
				  break;

			case '3': clrscr();
				  choices();
		}
	}while(search_choice!=3) ;
 }

 /* ================== FUNCTON TO DELETE VACANCY================== */


  void  vacancy::del_vacancy()
 {
	clrscr();
	unsigned long code;
	fstream infile,outfile;
	cout<<"\n ENTER THE VACANCY CODE TO BE DELETED ----->";
	cin>>code;
	outfile.open("tempvac.dat",ios::app);
	infile.open("vacancy.dat",ios::in);
	infile.seekg(0,ios::beg);
	infile.read((char*)&vac,sizeof(vac));
	while(!infile.eof())
	{
		if (vac.vac_code!=code)
			outfile.write((char*)&vac,sizeof ( vac));
		infile.read((char*)&vac,sizeof (vac));
	}
	infile.close();
	outfile.close();
	remove("vacancy.dat");
	rename("tempvac.dat","vacancy.dat");
 }


 /* ================== FUNCTON FOR ENROLLMENT================== */



void menu ::enroll_mnu()
 {
	char choice;
	char *str="ENROLLMENT MENU";
	char *b[]=
		{
	     " COMPUTER PROFESSIONAL ",
	     " MASTER OF BUSSINESS ADMINSTRATOR",
	     " DOCTER",
	     " ENGINEERS",
	     " ACCOUNTANT(B.Com---C.A)",
	     " SCIENCE",
	     " ANY OTHER",
	     " EXIT",
		};
	do
	{
		choice=menu(str,b,7);
		switch(choice)
		{
			case '1': clrscr();
				  member.add_object(1);
				  break;

			case '2': clrscr();
				  member.add_object(2);
				  break;

			case '3': clrscr();
				  member.add_object(3);
				  break;

			case '4': clrscr();
				  member.add_object(4);
				  break;

			case '5': clrscr();
				  member.add_object(5);
				  break;

			case '6': clrscr();
				  member.add_object(6);
				  break;

			case '7': clrscr();
				  member.add_object(7);
				  break;

			case '8': clrscr();
				  gotoxy(22,15);
				  cout<<"YOU ENDED THE SESSION ";
				  choices();
		}
	}while (choice!=8);
 }


 /* ================== FUNCTON TO SHOW INFORMATION ============= */


void menu :: allinf_mnu()
{
	int choice;
	char *str="ALL INFORMATION ABOUT MEMBER";
	char *b[]=
		{
	     " COMPUTER PROFESSIONAL ",
	     " MASTER OF BUSSINESS ADMINSTRATOR",
	     " DOCTER",
	     " ENGINEERS",
	     " ACCOUNTANT(B.Com---C.A)",
	     " SCIENCE",
	     " ANY OTHER",
	     " EXIT",
		};
	do
	{
		choice=menu(str,b,7);
		switch(choice)
		{

			case '1': clrscr();
				  member.show_object(1);
				  break;

			case '2': clrscr();
				  member.show_object(2);
				  break;

			case '3': clrscr();
				  member.show_object(3);
				  break;

			case '4': clrscr();
				  member.show_object(4);
				  break;

			case '5': clrscr();
				  member.show_object(5);
				  break;

			case '6': clrscr();
				  member.show_object(6);
				  break;

			case '7': clrscr();
				  member.show_object(7);
				  break;

			case '8': clrscr();
				  gotoxy(22,15);
				  cout<<"YOU ENDED THE SESSION ";
				  choices();
		}
	}while (choice!=8);
 }


/* ================== FUNCTON TO SHOW MEMBER AVAILABE =========== */


void  menu :: member_avab()
 {
	int choice;
	char *str="MEMBER AVALIABLE";
	char *b[]=
		{
	     " COMPUTER PROFESSIONAL ",
	     " MASTER OF BUSSINESS ADMINSTRATOR",
	     " DOCTER",
	     " ENGINEERS",
	     " ACCOUNTANT(B.Com---C.A)",
	     " SCIENCE",
	     " ANY OTHER",
	     " EXIT",
		};
	do
	{
		choice=menu(str,b,7);
		switch(choice)
		{

			case '1': clrscr();
				  member.show_obj(1);
				  break;

			case '2': clrscr();
				  member.show_obj(2);
				  break;

			case '3': clrscr();
				  member.show_obj(3);
				  break;

			case '4': clrscr();
				  member.show_obj(4);
				  break;

			case '5': clrscr();
				  member.show_obj(5);
				  break;

			case '6': clrscr();
				  member.show_obj(6);
				  break;

			case '7': clrscr();
				  member.show_obj(7);
				  break;

			case '8': clrscr();
				  gotoxy(22,15);
				  cout<<"YOU ENDED THE SESSION ";
				  choices();
		}
	 }while (choice!=8);
 }


 /* ================== FUNCTON TO MODIFY================== */


  void menu ::modify_mnu()
 {
	char choice;
	char *str="MODIFY MEMBER MENU";

	char *b[]=
		{
	     " COMPUTER PROFESSIONAL ",
	     " MASTER OF BUSSINESS ADMINSTRATOR",
	     " DOCTER",
	     " ENGINEERS",
	     " ACCOUNTANT(B.Com---C.A)",
	     " SCIENCE",
	     " ANY OTHER",
	     " EXIT",
		};

	do
	{
		choice=menu(str,b,7);
		switch(choice)
		{

			case '1': clrscr();
				  member.modify_mem(1);
				  break;

			case '2': clrscr();
				  member.modify_mem(2);
				  break;

			case '3': clrscr();
				  member.modify_mem(3);
				  break;

			case '4': clrscr();
				  member.modify_mem(4);
				  break;

			case '5': clrscr();
				  member.modify_mem(5);
				  break;

			case '6': clrscr();
				  member.modify_mem(6);
				  break;

			case '7': clrscr();
				  member.modify_mem(7);
				  break;

			case '8': clrscr();
				  gotoxy(22,15);
				  cout<<"YOU ENDED THE SESSION ";
				  choices();
		}
	}while (choice!=8);
 }



 /* ================== FUNCTON TO SHOW GWNERAL ================== */


  void form ::show_gen()
 {
	cout<<"\n";
	cout<<setiosflags(ios::left)
	<<setw(8)<<""
	<<setw(15)<<form_no
	<<setw(20)<<name
	<<setw(27)<<phone_no
	<<setw(30)<<higher_qualif;
 }


 /* ================== FUNCTON TO SHOW GENERAL DATA ================== */

  void form::show_general()
 {
	clrscr();
	fstream infile;
	infile.open("general.dat",ios::in);
	//above line is used to open file in  input mode
	infile.seekg(0,ios::beg);
	//above line is used to set file pointer to the begububg if the file
	cout<<"\n <-FORM NO-><-   VISITOR NAME   -><-    PHONE NO     -><-HIGHER 	QUALIFICATION ->";
	cout<<"\n-----------------------------------------------------------------	---------------";
	infile.read((char*)&member,sizeof(member));
	//read first object
	while(!infile.eof())
	{
		member.show_gen();
		infile.read((char*)&member,sizeof(member));
				//read next vacancy
	}
	infile.close();
	gotoxy(20,24);
	cout<<"press any key to continue";
	getch();
 }


