//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
//	TRAVEL   AGENCY
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
//	INCLUDED HEADER FILES
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

#include <fstream.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <dos.h>


//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
// THIS CLASS DRAW LINES, BOXES, ETC.
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

class DRAW
{
	public :
			void LINE_HOR(int, int, int, char) ;
			void LINE_VER(int, int, int, char) ;
			void BOX(int,int,int,int,char) ;
} ;


//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
// THIS CLASS CONTROL ALL THE FUNCTIONS RELATED TO TICKETS
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

class TICKET
{
	public :

			void ADDITION(void) ;
			void DELETE(int) ;
			void DELETE_FLTNO() ;
			void ENQUIRY(void) ;
			void modify_flight() ;
			int  FLIGHTNO(int) ;
	private :
			int  last_code() ;
			int  recordno(int) ;
			void modify_record(int) ;
			void ADD_RECORD(int, char[15], char[15], int, int) ;
	protected :
			char from[15], to[15] ;
			int  fltno, ecofair, exefair ;
} ;


//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
// THIS CLASS CONTROL ALL THE FUNCTIONS RELATED TO PASSENGERS
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

class PASSANGER
{
	public :
			void ADD_RECORD(int, int, char[26], char[36], int, char, char) ;
			void DELETE_TICKET(int) ;
			int  DELETE_FLIGHT(int) ;
			void LIST(void) ;
			int  LAST_TICKETNO(void) ;
			int  SEATS(int) ;
			int  FOUND(int) ;
			char *NAME(int) ;
	protected :
			char Class, name[26], address[36], sex ;
			int  slno, age, ticketno ;
} ;


//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
// THIS IS DERIVED CLASS WHICH CONTROL ALL THE FUNCTIONS
// RELATED TO RESERVATION, CANCELLATION, ETC.
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

class RESERVE : public TICKET, public PASSANGER
{
	public :
			void RESERVATION(void) ;
			void CANCELLATION(void) ;
			void DISPLAY_TICKET(void) ;
			void DELETE_ALL(void) ;
} ;


//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
// FUNCTION TO DRAW HORIZONTAL LINE
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void DRAW :: LINE_HOR(int column1, int column2, int row, char c)
{
	for ( column1; column1<=column2; column1++ )
	{
		gotoxy(column1,row) ;
		cout <<c ;
	}
}


//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
// FUNCTION TO DRAW VERTICAL LINE
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void DRAW :: LINE_VER(int row1, int row2, int column, char c)
{
	for ( row1; row1<=row2; row1++ )
	{
		gotoxy(column,row1) ;
		cout <<c ;
	}
}


//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
// FUNCTION TO DRAW BOX
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void DRAW :: BOX(int column1, int row1, int column2, int row2, char c)
{
	char ch=218 ;
	char c1, c2, c3, c4 ;
	char l1=196, l2=179 ;
	if (c == ch)
	{
		c1=218 ;
		c2=191 ;
		c3=192 ;
		c4=217 ;
		l1 = 196 ;
		l2 = 179 ;
	}
	else
	{
		c1=c ;
		c2=c ;
		c3=c ;
		c4=c ;
		l1 = c ;
		l2 = c ;
	}
	gotoxy(column1,row1) ;
	cout <<c1 ;
	gotoxy(column2,row1) ;
	cout <<c2 ;
	gotoxy(column1,row2) ;
	cout <<c3 ;
	gotoxy(column2,row2) ;
	cout <<c4 ;
	column1++ ;
	column2--;
	LINE_HOR(column1,column2,row1,l1) ;
	LINE_HOR(column1,column2,row2,l1) ;
	column1-- ;
	column2++ ;
	row1++ ;
	row2-- ;
	LINE_VER(row1,row2,column1,l2) ;
	LINE_VER(row1,row2,column2,l2) ;
}


//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
// THIS FUNCTION DELETES THE RECORD FOR THE GIVEN CODE FROM
// THE TICKET FILE (TICKET.DAT)
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void TICKET :: DELETE(int tcode)
{
	fstream file ;
	file.open("TICKET.DAT", ios::in) ;
	fstream temp ;
	temp.open("temp.dat", ios::out) ;
	file.seekg(0,ios::beg) ;
	while ( !file.eof() )
	{
		file.read((char *) this, sizeof(TICKET)) ;
		if ( file.eof() )
			break ;
		if ( fltno != tcode )
			temp.write((char *) this, sizeof(TICKET)) ;
	}
	file.close() ;
	temp.close() ;
	file.open("TICKET.DAT", ios::out) ;
	temp.open("temp.dat", ios::in) ;
	temp.seekg(0,ios::beg) ;
	while ( !temp.eof() )
	{
		temp.read((char *) this, sizeof(TICKET)) ;
		if ( temp.eof() )
			break ;
		file.write((char *) this, sizeof(TICKET)) ;
	}
	file.close() ;
	temp.close() ;
}


//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
// THIS FUNCTION GIVES THE CODE NO. TO DELETE RECORD FROM
// THE TICKET FILE (TICKET.DAT)
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void TICKET :: DELETE_FLTNO(void)
{
	clrscr() ;
	int tcode ;
	char ch ;
	gotoxy(5,3) ;
	cout <<"Enter Fltno Code of the Flight to be deleted : " ;
	cin>>tcode;
	clrscr() ;
	do
	{
		gotoxy(1,8) ; clreol() ;
		gotoxy(5,8) ;
		cout <<"Do you want to delete this record (y/n) : " ;
		ch = getche() ;
		ch = toupper(ch) ;
	} while (ch != 'N' && ch != 'Y') ;
	if (ch == 'N')
		return ;
	DELETE(tcode) ;
	gotoxy(5,15) ;
	cout <<"\7Record Deleted" ;
	getch() ;
}

//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
// FUNCTION TO ADD GIVEN DATA IN THE TICKET FILE(TICKET.DAT)
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void TICKET :: ADD_RECORD(int t_fltno, char t_from[15], char t_to[15], int t_ecofair, int t_exefair)
{
	fstream file ;
	file.open("TICKET.DAT", ios::app) ;
	fltno = t_fltno ;
	strcpy(from,t_from) ;
	strcpy(to,t_to) ;
	ecofair = t_ecofair ;
	exefair = t_exefair ;
	file.write((char *) this, sizeof(TICKET)) ;
	file.close() ;
}


//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
// THIS FUNCTION MODIFY THE RECORD FOR THE GIVEN CODE FROM
// THE TICKET FILE (TICKET.DAT)
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void TICKET :: modify_record(int tcode)
{
	int recno ;
	recno = recordno(tcode) ;
	int valid, t_code ;
	char ch, t_ecofair[10], t_exefair[10] ;
	gotoxy(71,2) ;
	cout <<"<0>=Exit" ;
	gotoxy(5,12) ;
	cout <<"Flight Code      : "<<tcode ;
	gotoxy(5,14) ;
	cout <<"Source Name      : " ;
	gotoxy(5,16) ;
	cout <<"Destination Name : " ;
	gotoxy(5,18) ;
	cout <<"Economic Fare    : " ;
	gotoxy(5,20) ;
	cout <<"Executive Fare   : " ;
	do
	{
		gotoxy(26,14) ; clreol() ;
		cout <<"Change (y/n) : " ;
		ch = getche() ;
		ch = toupper(ch) ;
		if (ch == '0')
			return ;
	} while (ch != 'N' && ch != 'Y') ;
	valid = 0 ;
	while (ch == 'Y' && !valid)
	{
		valid = 1 ;
		gotoxy(1,14) ; clreol() ;
		gotoxy(1,24) ; clreol() ;
		gotoxy(1,25) ; clreol() ;
		gotoxy(3,25) ;
		cout <<"ENTER SOURCE NAME TO ADD IN THE MENU" ;
		gotoxy(5,14) ;
		cout <<"Source Name      : " ;
		gets(from) ;
		if (from[0] == '0')
			return ;
		if ((strlen(from) < 1) || (strlen(from) > 20))
		{
			valid = 0 ;
			gotoxy(3,24) ;
			cout <<"\7 Range = 1..20" ;
			getch() ;
		}
	}
	do
	{
		gotoxy(26,16) ; clreol() ;
		cout <<"Change (y/n) : " ;
		ch = getche() ;
		ch = toupper(ch) ;
		if (ch == '0')
			return ;
	} while (ch != 'N' && ch != 'Y') ;
	valid = 0 ;
	while (ch == 'Y' && !valid)
	{
		valid = 1 ;
		gotoxy(1,16) ; clreol() ;
		gotoxy(1,24) ; clreol() ;
		gotoxy(1,25) ; clreol() ;
		gotoxy(3,25) ;
		cout <<"ENTER DESTINATION NAME TO ADD IN THE MENU" ;
		gotoxy(5,16) ;
		cout <<"Destination Name : " ;
		gets(to) ;
		if (to[0] == '0')
			return ;
		if ((strlen(to) < 1) || (strlen(to) > 20))
		{
			valid = 0 ;
			gotoxy(3,24) ;
			cout <<"\7 Range = 1..20" ;
			getch() ;
		}
	}
	do
	{
		gotoxy(26,18) ; clreol() ;
		cout <<"Change (y/n) : " ;
		ch = getche() ;
		ch = toupper(ch) ;
		if (ch == '0')
			return ;
	} while (ch != 'N' && ch != 'Y') ;
	valid = 0;
	while (ch == 'Y' && !valid)
	{
		valid = 1 ;
		gotoxy(1,18) ; clreol() ;
		gotoxy(1,24) ; clreol() ;
		gotoxy(1,25) ; clreol() ;
		gotoxy(3,25) ;
		cout <<"ENTER ECONOMIC FARE TO ADD IN THE MENU" ;
		gotoxy(5,18) ;
		cout <<"Economic Fare    : " ;
		gets(t_ecofair) ;
		ecofair = atof(t_ecofair) ;
		if (t_ecofair[0] == '0')
			return ;
		if (ecofair < 1 || ecofair > 5000)
		{
			valid = 0 ;
			gotoxy(3,24) ;
			cout <<"\7 Range = 1..5000" ;
			getch() ;
		}
	}
	do
	{
		gotoxy(26,20) ; clreol() ;
		cout <<"Change (y/n) : " ;
		ch = getche() ;
		ch = toupper(ch) ;
		if (ch == '0')
			return ;
	} while (ch != 'N' && ch != 'Y') ;
	valid = 0;
	while (ch == 'Y' && !valid)
	{
		valid = 1 ;
		gotoxy(1,20) ; clreol() ;
		gotoxy(1,24) ; clreol() ;
		gotoxy(1,25) ; clreol() ;
		gotoxy(3,25) ;
		cout <<"ENTER EXECUTIVE FARE TO ADD IN THE MENU" ;
		gotoxy(5,20) ;
		cout <<"Executive Fare   : " ;
		gets(t_exefair) ;
		exefair = atof(t_exefair) ;
		if (t_exefair[0] == '0')
			return ;
		if (exefair < 1 || exefair > 6000)
		{
			valid = 0 ;
			gotoxy(3,24) ;
			cout <<"\7 Range = 1..6000" ;
			getch() ;
		}
	}
	do
	{
		gotoxy(1,22) ; clreol() ;
		gotoxy(1,24) ; clreol() ;
		gotoxy(1,25) ; clreol() ;
		gotoxy(5,22) ;
		cout <<"Do you want to save this record (y/n) : " ;
		ch = getche() ;
		ch = toupper(ch) ;
		if (ch == '0')
			return ;
	} while (ch != 'N' && ch != 'Y') ;
	if (ch == 'N')
		return ;
	cout <<"\n" <<from ;
	cout <<" ,"<<to ;
	cout <<" ,"<<ecofair ;
	cout <<" ,"<<exefair ;
	getch() ;
	fstream file ;
	file.open("TICKET.DAT", ios::out | ios::ate) ;
	int location ;
	location = (recno-1) * sizeof(TICKET) ;
	file.seekp(location) ;
	file.write((char *) this, sizeof(TICKET)) ;
	file.close() ;
	clrscr() ;
	gotoxy(5,15) ;
	cout <<"\7Record Modified" ;
	getch() ;
}


//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
// THIS FUNCTION GIVES THE CODE NO. TO MODIFY RECORD FROM
// THE TICKET FILE (TICKET.DAT)
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void TICKET :: modify_flight(void)
{
	clrscr() ;
	char t_code[5], ch ;
	int t, tcode ;
	gotoxy(5,3) ;
	cout <<"Enter Flight Code of the Flight to be Modify : " ;
	gets(t_code) ;
	t = atoi(t_code) ;
	tcode = t ;
	if (t_code[0] == '0')
		return ;
	if (tcode == 0)
	{
		ENQUIRY() ;
		gotoxy(1,25) ; clreol() ;
		gotoxy(3,25) ;
		cout <<"Press <ENTER> to Exit" ;
		gotoxy(5,24) ;
		cout <<"Enter Flight Code of the Flight to be Modify : " ;
		gets(t_code) ;
		t = atoi(t_code) ;
		tcode = t ;
		if (tcode == 0)
			return ;
	}
	clrscr() ;
	do
	{
		gotoxy(5,8) ;
		cout <<"Do you want to Modify this record (y/n) : " ;
		ch = getche() ;
		ch = toupper(ch) ;
	} while (ch != 'N' && ch != 'Y') ;
	if (ch == 'N')
		return ;
	modify_record(tcode) ;
}




//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
// FUNCTION TO RETURNS FLIGHT NO. FOR THE GIVEN S.NO
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

int TICKET :: FLIGHTNO(int sno)
{
	fstream file ;
	file.open("TICKET.DAT", ios::in) ;
	int count=1 ;
	while (file.read((char *) this, sizeof(TICKET)))
	{
		if (sno == count)
			break ;
		count++ ;
	}
	file.close() ;
	return fltno ;
}


//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
// FUNCTION TO RETURNS FLIGHT NO. FOR THE GIVEN S.NO
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

int TICKET :: recordno(int tcode)
{
	fstream file ;
	file.open("TICKET.DAT", ios::in) ;
	int count=0 ;
	while (file.read((char *) this, sizeof(TICKET)))
	{
		count++ ;
		if (tcode==fltno)
		break;
	}
	file.close() ;
	return count ;
}


//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
// THIS FUNCTION RETURNS THE CODE OF THE LAST RECORD IN THE
// TICKET FILE (TICKET.DAT).
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

int TICKET :: last_code()
{
	fstream file ;
	file.open("TICKET.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	int t=0 ;
	while (file.read((char *) this, sizeof(TICKET)))
		t = fltno ;
	file.close() ;
	return t ;
}


//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
// FUNCTION TO GIVES DATA TO ADD RECORDS IN TICEKT FILE
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void TICKET :: ADDITION(void)
{
	int tcode, valid ;
	char ch;
	int t_ecofair,t_exefair;
	tcode = last_code() ;
	tcode++ ;
	do
	{
		clrscr() ;
		gotoxy(71,2) ;
		cout <<"<0>=Exit" ;
		gotoxy(27,3) ;
		cout <<"ADDITION OF FLIGHT RECORDS" ;
		gotoxy(26,4) ;
		cout <<"ออออออออออออออออออออออออออ" ;
		gotoxy(5,6) ;
		cout <<"Flight Code        : " <<tcode ;
		gotoxy(5,8) ;
		cout <<"Starting Point     : " ;
		gotoxy(5,10) ;
		cout <<"Destination Point  : " ;
		gotoxy(5,12) ;
		cout <<"Economic Price     : " ;
		gotoxy(5,14) ;
		cout <<"Executive Price    : " ;
		do
		{
			valid = 1 ;
			gotoxy(1,8) ; clreol() ;
			gotoxy(1,24) ; clreol() ;
			gotoxy(1,25) ; clreol() ;
			gotoxy(3,25) ;
			cout <<"ENTER STARTING POINT OF THE FLIGHT IN THE MENU" ;
			gotoxy(5,8) ;
			cout <<"Starting Point     : " ;
			gets(from) ;
			strupr(from) ;
			if (from[0] == '0')
				return ;
			if ((strlen(from) < 1) || (strlen(from) > 20))
			{
				valid = 0 ;
				gotoxy(3,24) ;
				cout <<"\7 Range = 1..20" ;
				getch() ;
			}
		} while (!valid) ;
		do
		{
			valid = 1 ;
			gotoxy(1,10) ; clreol() ;
			gotoxy(1,24) ; clreol() ;
			gotoxy(1,25) ; clreol() ;
			gotoxy(3,25) ;
			cout <<"ENTER DESTINATION POINT OF THE FLIGHT IN THE MENU" ;
			gotoxy(5,10) ;
			cout <<"Destination Point  : " ;
			gets(to) ;
			strupr(to) ;
			if (to[0] == '0')
				return ;
			if ((strlen(to) < 1) || (strlen(to) > 20))
			{
				valid = 0 ;
				gotoxy(3,24) ;
				cout <<"\7 Range = 1..20" ;
				getch() ;
			}
		} while (!valid) ;
		do
		{
			valid = 1 ;
			gotoxy(1,12) ; clreol() ;
			gotoxy(1,24) ; clreol() ;
			gotoxy(1,25) ; clreol() ;
			gotoxy(3,25) ;
			cout <<"ENTER ECONOMIC FARE TO ADD IN THE MENU" ;
			gotoxy(5,12) ;
			cout <<"Economic Price     : " ;
			cin>>ecofair ;
			if (ecofair == 0)
				return ;
			if (ecofair < 0 || ecofair > 5000)
			{
				valid = 0 ;
				gotoxy(3,24) ;
				cout <<"\7 Range 0..5000" ;
				getch() ;
			}
		} while (!valid) ;
		do
		{
			valid = 1 ;
			gotoxy(1,14) ; clreol() ;
			gotoxy(1,24) ; clreol() ;
			gotoxy(1,25) ; clreol() ;
			gotoxy(3,25) ;
			cout <<"ENTER EXECUTIVE FARE TO ADD IN THE MENU" ;
			gotoxy(5,14) ;
			cout <<"Executive Price    : " ;
			cin>>exefair ;
			if (exefair == 0)
				return ;
			if (exefair < 0 || exefair > 6000)
			{
				valid = 0 ;
				gotoxy(3,24) ;
				cout <<"\7 Range 0..6000" ;
				getch() ;
			}
		} while (!valid) ;
		do
		{
			gotoxy(1,17) ; clreol() ;
			gotoxy(1,24) ; clreol() ;
			gotoxy(1,25) ; clreol() ;
			gotoxy(5,17) ;
			cout <<"Do you want to save this record (y/n) : " ;
			ch = getche() ;
			ch = toupper(ch) ;
			if (ch == '0')
				return ;
		} while (ch != 'N' && ch != 'Y') ;
		if (ch == 'Y')
		{
			ADD_RECORD(tcode,from,to,ecofair,exefair);
			tcode++ ;
		}
		do
		{
			gotoxy(1,19) ; clreol() ;
			gotoxy(1,24) ; clreol() ;
			gotoxy(1,25) ; clreol() ;
			gotoxy(5,19) ;
			cout <<"Do you want to add more records (y/n) : " ;
			ch = getche() ;
			ch = toupper(ch) ;
			if (ch == '0')
				return ;
		} while (ch != 'N' && ch != 'Y') ;
	} while (ch == 'Y') ;
}


//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
// FUNCTION TO DISPLAY LIST OF FLIGHTS
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void TICKET :: ENQUIRY(void)
{
	clrscr() ;
	fstream file ;
	file.open("TICKET.DAT", ios::in) ;
	DRAW d ;
	d.BOX(1,2,80,24,218) ;
	d.LINE_HOR(2,79,4,196) ;
	d.LINE_HOR(2,79,6,196) ;
	d.LINE_HOR(2,79,22,196) ;
	textcolor(LIGHTGRAY+BLINK) ;
	gotoxy(30,3) ;
	cprintf("LIST OF THE FLIGHTS") ;
	textcolor(LIGHTGRAY) ;
	textcolor(BLACK) ; textbackground(WHITE) ;
	for (int i=2; i<=79; i++)
	{
		gotoxy(i,5) ;
		cprintf(" ") ;
	}
	gotoxy(2,5) ;
	cprintf(" Sno.   FLIGHT NO.  FROM          TO           ECONOMIC FAIR  EXECUTIVE FAIR") ;
	textcolor(LIGHTGRAY) ; textbackground(BLACK) ;
	int row=7, sno=1 ;
	while (file.read((char *) this, sizeof(TICKET)))
	{
		gotoxy(3,row) ;
		cout <<sno<<".)" ;
		gotoxy(10,row) ;
		cout <<fltno<<".)" ;
		gotoxy(22,row) ;
		cout <<from ;
		gotoxy(36,row) ;
		cout <<to ;
		gotoxy(49,row) ;
		cout <<"Rs."<<ecofair ;
		gotoxy(64,row) ;
		cout <<"Rs."<<exefair ;
		row++ ;
		sno++ ;
	}
	file.close() ;
}


//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
// FUNCTION TO RESERVE TICKET FOR THE PASSANGER
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void RESERVE :: RESERVATION(void)
{
	clrscr() ;
	ENQUIRY() ;
	char t1[5], pclass, pname[26], paddress[36], psex ;
	int  t2, valid, page, tno, sno ;
	PASSANGER p ;
	tno = p.LAST_TICKETNO() + 1 ;
	do
	{
		valid = 1 ;
		gotoxy(3,23) ;
		cout <<"                                  " ;
		gotoxy(3,23) ;
		cout <<"PRESS <ENTER> TO EXIT" ;
		gotoxy(3,20) ;
		cout <<"                                  " ;
		gotoxy(3,20) ;
		cout <<"Enter Sno. of the FLIGHT : " ;
		gets(t1) ;
		t2 = atoi(t1) ;
		sno = t2 ;
		if (strlen(t1) == 0)
			return ;
		if (sno < 1 || sno > 12)
		{
			valid = 0 ;
			gotoxy(3,23) ;
			cout <<"                           " ;
			gotoxy(3,23) ;
			cout <<"\7ENTER CORRECTLY" ;
			getch() ;
		}
	} while (!valid) ;
	int i=1 ;
	fstream file ;
	file.open("TICKET.DAT", ios::in) ;
	while (file.read((char *) this, sizeof(TICKET)))
	{
		if (sno == i)
			break ;
		i++ ;
	}
	file.close() ;
	if (p.SEATS(sno) >= 250)
	{
		gotoxy(5,21) ;
		cout <<"\7Sorry! Seats are not available." ;
		getch() ;
		return ;
	}
	gotoxy(3,23) ;
	cout <<"                                                  " ;
	gotoxy(3,23) ;
	cout <<"E=ECONOMIC,  X=EXECUTIVE  or PRESS <ENTER> TO EXIT" ;
	do
	{
		gotoxy(3,21) ;
		cout <<"                                      " ;
		gotoxy(3,21) ;
		cout <<"By which Class you want to travel : " ;
		pclass = getche() ;
		pclass = toupper(pclass) ;
		if (pclass == 13)
			return ;
	} while (pclass != 'E' && pclass != 'X') ;
	clrscr() ;
	gotoxy(72,3) ;
	cout <<"<0>=EXIT" ;
	gotoxy(34,2) ;
	cout <<"RESERVATION" ;
	gotoxy(5,5) ;
	cout <<"NAME    : " ;
	gotoxy(5,6) ;
	cout <<"ADDRESS : " ;
	gotoxy(5,7) ;
	cout <<"SEX M/F : " ;
	gotoxy(5,8) ;
	cout <<"AGE     : " ;
	do
	{
		valid = 1 ;
		gotoxy(5,25) ; clreol() ;
		cout <<"ENTER NAME OF THE PASSANGER" ;
		gotoxy(15,5) ; clreol() ;
		gets(pname) ;
		if (pname[0] == '0')
			return ;
		if (strlen(pname) < 1 || strlen(pname) > 25)
		{
			valid = 0 ;
			gotoxy(5,25) ; clreol() ;
			cout <<"\7Enter Correctly (Range: 1..25)" ;
			getch() ;
		}
	} while (!valid) ;
	do
	{
		valid = 1 ;
		gotoxy(5,25) ; clreol() ;
		cout <<"ENTER ADDRESS OF THE PASSANGER" ;
		gotoxy(15,6) ; clreol() ;
		gets(paddress) ;
		if (paddress[0] == '0')
			return ;
		if (strlen(paddress) < 1 || strlen(paddress) > 35)
		{
			valid = 0 ;
			gotoxy(5,25) ; clreol() ;
			cout <<"\7Enter Correctly (Range: 1..35)" ;
			getch() ;
		}
	} while (!valid) ;
	do
	{
		gotoxy(5,25) ; clreol() ;
		cout <<"ENTER SEX OF THE PASSANGER" ;
		gotoxy(15,7) ; clreol() ;
		psex = getche() ;
		psex = toupper(psex) ;
		if (psex == '0')
			return ;
	} while (psex != 'M' && psex != 'F') ;
	do
	{
		valid = 1 ;
		gotoxy(5,25) ; clreol() ;
		cout <<"ENTER AGE OF THE PASSANGER" ;
		gotoxy(15,8) ; clreol() ;
		gets(t1) ;
		t2 = atoi(t1) ;
		page = t2 ;
		if (t1[0] == '0')
			return ;
		if (page < 1 || page > 100)
		{
			valid = 0 ;
			gotoxy(5,25) ; clreol() ;
			cout <<"\7ENTER CORRECTLY" ;
			getch() ;
		}
	} while (!valid) ;
	clrscr() ;
	DRAW d ;
	d.BOX(15,5,66,21,'*') ;
	d.LINE_HOR(16,65,7,'*') ;
	gotoxy(45,9) ;
	cout <<"Flight no. " <<fltno ;
	gotoxy(20,11) ;
	cout <<"Passanger Name : " <<pname ;
	gotoxy(20,13) ;
	cout <<"Address : " <<paddress ;
	gotoxy(20,15) ;
	cout <<"Sex : " <<psex ;
	gotoxy(20,17) ;
	cout <<"Age : " <<page ;
	gotoxy(45,19) ;
	if (pclass == 'E')
		cout <<"Total Fair: " <<ecofair ;
	else
		cout <<"Total Fair: " <<exefair ;
	p.ADD_RECORD(tno,sno,pname,paddress,page,psex,pclass) ;
	getch() ;
}


//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
// FUNCTION TO ADD THE GIVEN DATA IN THE PASSANGER'S FILE
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void PASSANGER :: ADD_RECORD(int tno, int sno, char pname[26], char paddress[36], int page, char psex, char pclass)
{
	fstream file ;
	file.open("PASS.DAT", ios::app) ;
	ticketno = tno ;
	slno = sno ;
	strcpy(name,pname) ;
	strcpy(address,paddress) ;
	age = page ;
	sex = psex ;
	Class = pclass ;
	file.write((char *) this, sizeof(PASSANGER)) ;
	file.close() ;
}


//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
// THIS FUNCTION RETURN THE LAST TICKET NO. IN THE PASSANGER
// FILE
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

int PASSANGER :: LAST_TICKETNO(void)
{
	fstream file ;
	file.open("PASS.DAT", ios::in) ;
	int count=0 ;
	while (file.read((char *) this, sizeof(PASSANGER)))
		count = ticketno ;
	file.close() ;
	return count ;
}


//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
// THIS FUNCTION RETURN TOTAL NO. OF SEATS IN THE PASSANGER
// FILE
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

int PASSANGER :: SEATS(int sno)
{
	fstream file ;
	file.open("PASS.DAT", ios::in) ;
	int count=0 ;
	while (file.read((char *) this, sizeof(PASSANGER)))
	{
		if (sno == slno)
			count++ ;
	}
	file.close() ;
	return count ;
}


//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
// THIS FUNCTION RETURN 0 IF THE TICKET NO. NOT FOUND IN
// PASSANGER'S FILE
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

int PASSANGER :: FOUND(int tno)
{
	fstream file ;
	file.open("PASS.DAT", ios::in) ;
	int found=0 ;
	while (file.read((char *) this, sizeof(PASSANGER)))
	{
		if (tno == ticketno)
		{
			found = 1 ;
			break ;
		}
	}
	file.close() ;
	return found ;
}


//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
// THIS FUNCTION RETURNS PASSANGER'S NAME FOR THE GIVEN
// TICKET NO.
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

char *PASSANGER :: NAME(int tno)
{
	fstream file ;
	file.open("PASS.DAT", ios::in) ;
	while (file.read((char *) this, sizeof(PASSANGER)))
	{
		if (tno == ticketno)
			break ;
	}
	file.close() ;
	return  name ;
}


//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
// THIS FUNCTION DISPLAY THE LIST OF THE PASSANGERS
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void PASSANGER :: LIST(void)
{
	clrscr() ;
	char t1[10] ;
	int  t2, sno, valid ;
	TICKET ticket ;
	ticket.ENQUIRY() ;
	do
	{
		valid = 1 ;
		gotoxy(3,23) ;
		cout <<"                                  " ;
		gotoxy(3,23) ;
		cout <<"PRESS <ENTER> TO EXIT" ;
		gotoxy(3,20) ;
		cout <<"                                                                       " ;
		gotoxy(3,20) ;
		cout <<"Enter Sno. of the FLIGHT for which you want to see list of passanger " ;
		gets(t1) ;
		t2 = atoi(t1) ;
		sno = t2 ;
		if (strlen(t1) == 0)
			return ;
		if (sno < 1 || sno > 12)
		{
			valid = 0 ;
			gotoxy(3,23) ;
			cout <<"                           " ;
			gotoxy(3,23) ;
			cout <<"\7ENTER CORRECTLY" ;
			getch() ;
		}
	} while (!valid) ;
	clrscr() ;
	int row=7, found=0, flag=0 ;
	char ch ;
	DRAW d ;
	d.BOX(1,2,80,24,218) ;
	d.LINE_HOR(2,79,4,196) ;
	d.LINE_HOR(2,79,6,196) ;
	d.LINE_HOR(2,79,22,196) ;
	gotoxy(3,3) ;
	cout <<"Flight no. " <<ticket.FLIGHTNO(sno) ;
	gotoxy(32,3) ;
	cout <<"LIST OF PASSANGER" ;
	textcolor(BLACK) ; textbackground(WHITE) ;
	gotoxy(2,5) ;
	cprintf(" TICKET NO.    NAME                            CLASS                          ") ;
	textcolor(LIGHTGRAY) ; textbackground(BLACK) ;
	fstream file ;
	file.open("PASS.DAT", ios::in) ;
	file.seekg(0,ios::beg) ;
	while (file.read((char *) this, sizeof(PASSANGER)))
	{
		if (sno == slno)
		{
			flag = 0 ;
			delay(20) ;
			found = 1 ;
			gotoxy(5,row) ;
			cout <<ticketno ;
			gotoxy(17,row) ;
			cout <<name ;
			gotoxy(49,row) ;
			if (Class == 'X')
				cout	<<"Executive" ;
			else
				cout <<"Economic" ;
			if ( row == 21 )
			{
				flag = 1 ;
				row = 7 ;
				gotoxy(5,23) ;
				cout <<"Press any key to continue or Press <ESC> to exit" ;
				ch = getch() ;
				if (ch == 27)
					break ;
				clrscr() ;
				d.BOX(1,2,80,24,218) ;
				d.LINE_HOR(2,79,4,196) ;
				d.LINE_HOR(2,79,6,196) ;
				d.LINE_HOR(2,79,22,196) ;
				gotoxy(32,3) ;
				cout <<"LIST OF PASSANGER" ;
				textcolor(BLACK) ; textbackground(WHITE) ;
				gotoxy(2,5) ;
				cprintf(" TICKET NO.    NAME                     FLIGHT NO.           CLASS            ") ;
				textcolor(LIGHTGRAY) ; textbackground(BLACK) ;
			}
			else
				row++ ;
		}
	}
	if (!found)
	{
		gotoxy(5,10) ;
		cout <<"\7Records not found" ;
	}
	if (!flag)
	{
		gotoxy(5,23) ;
		cout <<"Press any key to continue..." ;
		getch() ;
	}
	file.close() ;
}


//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
// THIS FUNCTION DELETES PASSANGER RECORDS FOR THE GIVEN
// TICKET NO.
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void PASSANGER :: DELETE_TICKET(int tno)
{
	fstream file ;
	file.open("PASS.DAT", ios::in) ;
	fstream temp ;
	temp.open("temp.dat", ios::out) ;
	file.seekg(0,ios::beg) ;
	while (!file.eof())
	{
		file.read((char *) this, sizeof(PASSANGER)) ;
		if (file.eof())
			break ;
		if (tno != ticketno)
			temp.write((char *) this, sizeof(PASSANGER)) ;
	}
	file.close() ;
	temp.close() ;
	file.open("PASS.DAT", ios::out) ;
	temp.open("temp.dat", ios::in) ;
	temp.seekg(0,ios::beg) ;
	while ( !temp.eof() )
	{
		temp.read((char *) this, sizeof(PASSANGER)) ;
		if ( temp.eof() )
			break ;
		file.write((char *) this, sizeof(PASSANGER)) ;
	}
	file.close() ;
	temp.close() ;
}


//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
// THIS FUNCTION DELETES ALL PASSANGER RECORDS FOR THE GIVEN
// FLIGHT NO.
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

int PASSANGER :: DELETE_FLIGHT(int sno)
{
	fstream file ;
	file.open("PASS.DAT", ios::in) ;
	fstream temp ;
	temp.open("temp.dat", ios::out) ;
	file.seekg(0,ios::beg) ;
	int found = 0 ;
	while (!file.eof())
	{
		file.read((char *) this, sizeof(PASSANGER)) ;
		if (file.eof())
			break ;
		if (sno != slno)
			temp.write((char *) this, sizeof(PASSANGER)) ;
		else
			found = 1 ;
	}
	file.close() ;
	temp.close() ;
	file.open("PASS.DAT", ios::out) ;
	temp.open("temp.dat", ios::in) ;
	temp.seekg(0,ios::beg) ;
	while ( !temp.eof() )
	{
		temp.read((char *) this, sizeof(PASSANGER)) ;
		if ( temp.eof() )
			break ;
		file.write((char *) this, sizeof(PASSANGER)) ;
	}
	file.close() ;
	temp.close() ;
	return found ;
}


//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
// THIS FUNCTION CANCELS PASSANGER'S TICKET
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void RESERVE :: CANCELLATION(void)
{
	clrscr() ;
	char t1[10], ch ;
	int  t2, tno, valid ;
	do
	{
		valid = 1 ;
		gotoxy(3,23) ; clreol() ;
		cout <<"PRESS <ENTER> TO SEE LIST or 0 TO EXIT" ;
		gotoxy(3,20) ; clreol() ;
		cout <<"Enter Ticket no. of the Passenger to cancel the Ticket " ;
		gets(t1) ;
		t2 = atoi(t1) ;
		tno = t2 ;
		if (t1[0] == '0')
			return ;
		if (strlen(t1) == 0)
		{
			valid = 0 ;
			LIST() ;
			clrscr() ;
		}
		if (!FOUND(tno) && valid)
		{
			valid = 0 ;
			gotoxy(3,23) ; clreol() ;
			cout <<"\7Record not found" ;
			getch() ;
		}
	} while (!valid) ;
	clrscr() ;
	fstream file ;
	file.open("PASS.DAT", ios::in) ;
	while (file.read((char *) this, sizeof(PASSANGER)))
		if (ticketno == tno)
			break ;
	file.close() ;
	int i=1 ;
	file.open("TICKET.DAT", ios::in) ;
	while (file.read((char *) this, sizeof(TICKET)))
	{
		if (slno == i)
			break ;
		i++ ;
	}
	file.close() ;
	PASSANGER p ;
	DRAW d ;
	d.BOX(15,5,66,21,'*') ;
	d.LINE_HOR(16,65,7,'*') ;
	gotoxy(33,6) ;
	cout <<"Ticket no. " <<tno ;
	gotoxy(17,9) ;
	cout <<from <<" to " <<to ;
	gotoxy(45,9) ;
	cout <<"Flight no. " <<fltno ;
	gotoxy(20,11) ;
	cout <<"Passanger Name : " <<p.NAME(tno);
	gotoxy(20,13) ;
	cout <<"Address : " <<address ;
	gotoxy(20,15) ;
	cout <<"Sex : " <<sex ;
	gotoxy(20,17) ;
	cout <<"Age : " <<age ;
	gotoxy(45,19) ;
	if (Class == 'E')
		cout <<"Total Fair: " <<ecofair ;
	else
		cout <<"Total Fair: " <<exefair ;
	do
	{
		gotoxy(10,23) ; clreol() ;
		cout <<"Cancel this ticket (y/n) : " ;
		ch = getche() ;
		ch = toupper(ch) ;
	} while (ch != 'Y' && ch != 'N') ;
	if (ch == 'N')
		return ;
	DELETE_TICKET(tno) ;
	gotoxy(10,25) ;
	cout <<"\7Ticket Cancelled" ;
	getch() ;
}


//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
// THIS FUNCTION DISPLAY THE PASSANGER'S INFORMATION
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void RESERVE :: DISPLAY_TICKET(void)
{
	clrscr() ;
	char t1[10], ch ;
	int  t2, tno, valid ;
	do
	{
		valid = 1 ;
		gotoxy(3,23) ; clreol() ;
		cout <<"PRESS <ENTER> TO SEE LIST or 0 TO EXIT" ;
		gotoxy(3,20) ; clreol() ;
		cout <<"Enter Ticket no. of the Passanger  " ;
		gets(t1) ;
		t2 = atoi(t1) ;
		tno = t2 ;
		if (t1[0] == '0')
			return ;
		if (strlen(t1) == 0)
		{
			valid = 0 ;
			LIST() ;
			clrscr() ;
		}
		if (!FOUND(tno) && valid)
		{
			valid = 0 ;
			gotoxy(3,23) ; clreol() ;
			cout <<"\7Record not found" ;
			getch() ;
		}
	} while (!valid) ;
	clrscr() ;
	fstream file ;
	file.open("PASS.DAT", ios::in) ;
	while (file.read((char *) this, sizeof(PASSANGER)))
		if (ticketno == tno)
			break ;
	file.close() ;
	int i=1 ;
	file.open("TICKET.DAT", ios::in) ;
	while (file.read((char *) this, sizeof(TICKET)))
	{
		if (slno == i)
			break ;
		i++ ;
	}
	file.close() ;
	PASSANGER p ;
	DRAW d ;
	d.BOX(15,5,66,21,'*') ;
	d.LINE_HOR(16,65,7,'*') ;
	gotoxy(33,6) ;
	cout <<"Ticket no. " <<tno ;
	gotoxy(17,9) ;
	cout <<from <<" to " <<to ;
	gotoxy(45,9) ;
	cout <<"Flight no. " <<fltno ;
	gotoxy(20,11) ;
	cout <<"Passanger Name : " <<p.NAME(tno);
	gotoxy(20,13) ;
	cout <<"Address : " <<address ;
	gotoxy(20,15) ;
	cout <<"Sex : " <<sex ;
	gotoxy(20,17) ;
	cout <<"Age : " <<age ;
	gotoxy(45,19) ;
	if (Class == 'E')
		cout <<"Total Fair: " <<ecofair ;
	else
		cout <<"Total Fair: " <<exefair ;
	gotoxy(10,25) ;
	cout <<"Press any key to continue..." ;
	getch() ;
}


//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
// THIS FUNCTION GIVE FLIGHT NO. TO DELETE ALL PASSANGER
// RECORDS
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void RESERVE :: DELETE_ALL(void)
{
	clrscr() ;
	ENQUIRY() ;
	char t1[5] ;
	int  t2, valid, sno ;
	do
	{
		valid = 1 ;
		gotoxy(3,23) ;
		cout <<"                                  " ;
		gotoxy(3,23) ;
		cout <<"PRESS <ENTER> TO EXIT" ;
		gotoxy(3,20) ;
		cout <<"                                                                            " ;
		gotoxy(3,20) ;
		cout <<"Enter Sno. of the FLIGHT for which all passanger records to be deleted : " ;
		gets(t1) ;
		t2 = atoi(t1) ;
		sno = t2 ;
		if (strlen(t1) == 0)
			return ;
		if (sno < 1 || sno > 12)
		{
			valid = 0 ;
			gotoxy(3,23) ;
			cout <<"                           " ;
			gotoxy(3,23) ;
			cout <<"\7ENTER CORRECTLY" ;
			getch() ;
		}
	} while (!valid) ;
	gotoxy(3,23) ;
	if (!DELETE_FLIGHT(sno))
		cout <<"\7Records not found. Press any key to continue..." ;
	else
		cout <<"\7Records deleted. Press any key to continue..." ;
	getch() ;
}


//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ
// THIS IS MAIN FUNCTION WHICH DISPLAY MENU AND CALLS ALL
// THE MAIN FUNCTIONS
//ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ

void main(void)
{
	DRAW d ;
	PASSANGER p ;
	TICKET ticket ;
	RESERVE r ;
	char ch ;
	while (1)
	{
		clrscr() ;
	    /*	d.BOX(10,2,71,25,219) ;
		d.LINE_VER(3,24,11,219) ;
		d.LINE_VER(3,24,70,219) ;
		d.BOX(12,3,69,24,218) ;
		for (int i=7; i<=19; i++)
			for (int j=20; j<=61; j++)
			{
				gotoxy(j,i) ;
				cprintf(" ") ;
			}*/
		gotoxy(34,6) ;
		cprintf("TRAVEL AGENCY") ;
		gotoxy(29,7) ;
		cprintf("ออออออออออออออออออออออ") ;
		gotoxy(28,9) ;
		cprintf("1) ADDITION   OF  FLIGHTS") ;
		gotoxy(28,10) ;
		cprintf("2) MODIFICATION OF FLIGHT") ;
		gotoxy(28,11) ;
		cprintf("3) DELETION   OF  FLIGHTS") ;
		gotoxy(28,12) ;
		cprintf("4) PASSENGER RESERVATIONS") ;
		gotoxy(28,13) ;
		cprintf("5) PASSENGER CANCELLATION") ;
		gotoxy(28,14) ;
		cprintf("6) ALL PASSENGER  RECORDS") ;
		gotoxy(28,15) ;
		cprintf("7) ALL  FLIGHTS   ENQUIRY") ;
		gotoxy(28,16) ;
		cprintf("8) LIST OF THE PASSENGERS") ;
		gotoxy(28,17) ;
		cprintf("0) END TICKET RESERVATION ") ;
		gotoxy(27,20) ;
		cprintf("Please Enter Your Choice => ") ;
		ch = getche() ;
		clrscr() ;
		if (ch == 27 || ch == '0')
			break ;
		else
		if (ch == '1')
			ticket.ADDITION() ;
		if (ch == '2')
			ticket.modify_flight() ;
		if (ch == '3')
			ticket.DELETE_FLTNO() ;
		if (ch == '4')
			r.RESERVATION() ;
		if (ch == '5')
			r.CANCELLATION() ;
		if (ch == '7')
		{
			ticket.ENQUIRY() ;
			gotoxy(2,23) ;
			cout <<"Press any key to continue..." ;
			getch() ;
		}
		else
		if (ch == '8')
			p.LIST() ;
		else
		if (ch == '6')
		{
			while (1)
			{
				clrscr() ;
				d.BOX(10,2,71,25,219) ;
				d.LINE_VER(3,24,11,219) ;
				d.LINE_VER(3,24,70,219) ;
				d.BOX(12,3,69,24,218) ;
				for (int i=7; i<=19; i++)
					for (int j=20; j<=61; j++)
					{
						gotoxy(j,i) ;
						cprintf(" ") ;
					}
				gotoxy(29,6) ;
				cprintf("EDIT PASSENGER RECORDS") ;
				gotoxy(29,7) ;
				cprintf("ออออออออออออออออออออออ") ;
				gotoxy(28,11) ;
				cprintf("1: PASSANGER   INFORMATION") ;
				gotoxy(28,13) ;
				cprintf("2: DELETE PASSENGER RECORD") ;
				gotoxy(28,15) ;
				cprintf("0: EXIT TO THE  MAIN  MENU") ;
				gotoxy(27,18) ;
				cprintf("Please Enter Your Choice => ") ;
				ch = getche() ;
				clrscr() ;
				if (ch == 27 || ch == '0')
					break ;
				else
				if (ch == '1')
					r.DISPLAY_TICKET() ;
				else
				if (ch == '2')
					r.DELETE_ALL() ;
			}
		}
	}
}



















 




 

 




 





 




 






 




 





















