//*************************************************************************//
//   THIS PROGRAM AUTOMISES A RAILWAY RESERVATION-CUM-INFORMATION SYSTEM   //
//*************************************************************************//

/*  Program constituted by
	   ABHINAV KUSHWAHA */


#include <fstream.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <dos.h>
#include <process.h>
#include <math.h>



//-------------------------------------------//
//-- The following structure stores a Date --//
//-------------------------------------------//


struct Date {

   int da_day;
   int da_mon;
   int da_year;
  };



//----------------------------------------------------------------//
//--The following Structure records the information of a station--//
// ---------------------------------------------------------------//


struct station {
    char name[20];
    char arr_time[5];
    char dep_time[5];
    };




//-------------------------------------------------------------------------//
//--The following class stores and manages the information of a passenger--//
//-------------------------------------------------------------------------//


class passenger_info {

   protected : char name[30];
	       char address[50];
	       char phone[10];
	       unsigned short int age;
	       char sex;

	       };



//-------------------------------------------------------------------------//
//--The following class stores and manipulates the information of a train--//
//-------------------------------------------------------------------------//


class train {

  private   : char train_name[30];
	      station s[5];

  public    : unsigned int train_no;
	      int seats_booked;
	      int capacity;

	      unsigned int difference(char*,char*);
	      void getdata();
	      void modify(unsigned int);
	      void display_train(unsigned int);
	      void display_all(void);
	      void delete_train(unsigned int);
	      };




//------------------------------------------------------------------//
//--The following class has been derived from passenger_info class--//
//--       and holds details about the reservation(s) made        --//
//------------------------------------------------------------------//


class reservation : public passenger_info {

      private : unsigned int train_no;
		int _class;
		 // It holds the information of the travelling class

		int passenger_no;
		int seats;
		char status[9];
		int position;
		float fare;
		struct Date d_o_j, d_o_r;
		  //d_o_j -> Date of journey
		  //d_o_r -> Date of reservation

		char source[20], dest[20];
		  //source -> Starting Station
		  //dest   -> Ending Station

		void calculate(unsigned int, char*, char*);
		int check_train(unsigned int, int);
		void display_ticket(void);
		void set_PNR(void);

      public : static int PNR;
	       static float tot_amt;
		  //this static variable keeps track of the total amount
		  //that has been collected in the form of fare
		  //during current program-run

	       reservation() {

		 train_no = 2001;
		 passenger_no = 0;
		 d_o_j.da_day = 1;
		 d_o_j.da_mon = 1;
		 d_o_j.da_year = 2000;
		 d_o_r.da_day = 1;
		 d_o_r.da_mon = 1;
		 d_o_r.da_year = 2000;
		 fare = 0.0;
		 seats = 500;
		 _class = 7;

		 set_PNR();


	       }
		// Constructor for initialization of values
		// Also sets the PNR No. at Program Run

	       void ticket();
	       void cancel_ticket(int);
	       void display_ticket(int);
	       void display_ticket(char*);
		 // Overloaded Functions
	       void display_all();
	       void modify_ticket(int);

	       };

      int reservation :: PNR = 0;
      float reservation :: tot_amt = 0.0;





//------------------------------------------------------------------//
//--The following class is for program control and Menu Management--//
//--       It displays the MAIN MENU and different Sub-menus      --//
//------------------------------------------------------------------//

//-----------------------------------------------------------------------//
//--            The Class also manages USER ACCESS CONTROL             --//
//--It implements Password-Verification to allow authorized access only--//
// ----------------------------------------------------------------------//


class control {

      private : void train_menu();
		void reservation_menu();
		void verification();
		void box();
		void introduction();

      public  : void main_menu();

	 };




//------------------------------------------------------//
//--STARTING WITH FUNCTION DEFINITIONS FOR CLASS TRAIN--//
//------------------------------------------------------//

//----------------------------------------------------------------------//
//--                This function calculates the difference           --//
//--               between subscripts  of two given stations          --//
//--predominantly to be used by reservation class for fare-calculation--//
//----------------------------------------------------------------------//


unsigned int train :: difference(char* A, char* B) {

      int i = 0, j = 0, k;
      unsigned int diff;

      for(k = 0; k < 5; ++k)
      {  if(!strcmpi(A,s[k].name))
	   i = k+1;
	 if(!strcmpi(B,s[k].name))
	   j = k+1;
       }
       diff = abs(i-j);
	// absolute value function abs() from <math.h>
       if((!(i && j)) || (i == j))
	 { cout << endl << "Invalid Station Name(s) or same stations !!";
	   return 0;
	 }

	return diff;
    }




//----------------------------------------------------//
//--This function gets the information about a train--//
//----------------------------------------------------//



void train :: getdata() {

      clrscr();
      fstream file;
      file.open("TRAIN.DAT", ios::app | ios::binary);
      cout << endl << "Enter Information for the train !!"<<endl;
      cout << endl << "Train No. : ";
      cin  >> train_no;
      cout << endl << "Name of Train : ";
      gets(train_name);
      clrscr();
      cout << "Enter Information of five stations en route the train :"
	   << endl;
      getch();

      for (int i = 0; i < 5; ++i)
       {
	 clrscr();
	 cout << endl << "Enter Info for Station : " << i+1;
	 cout << endl << "Name of Station : ";
	 gets(s[i].name);
	 cout << "Enter Arrival time   (hh:mm) : ";
	 gets(s[i].arr_time);
	 cout << "Enter Departure time (hh:mm) : ";
	 gets(s[i].dep_time);
	 getch();
       }

      clrscr();
      cout << endl << "Enter the capacity of the train : ";
      cin  >> capacity;
      seats_booked = 0;

      file.write((char*)this , sizeof(train));
      file. close();

      cout << endl << "TRAIN HAS BEEN ADDED TO RECORDS !!";
      getch();
   }




//---------------------------------------------------------------------//
//--This function modifies the data of a train according to train no.--//
//---------------------------------------------------------------------//


void train :: modify(unsigned int t_no) {

      clrscr();
      int flag = 0;
      fstream file;
      file.open("TRAIN.DAT",ios::in | ios::out | ios::ate | ios::binary);
      file.seekg(0,ios::beg);

      file.read((char*)this, sizeof(train));
      for(int j = 0; !file.eof(); ++j)
       {
	  if (t_no == train_no)
	  { flag = 1;
	    cout << endl << "DISPLAYING CURRENT TRAIN INFORMATION !!"<<endl;
	    cout << endl << "Train No. : ";
	    cout << train_no;
	    cout << endl << "Name of Train : ";
	    puts(train_name);
	    getch();
	    clrscr();

	    cout << " Information of five stations en route the train :"
		 << endl;
	    getch();

	    for (int i = 0; i < 5; ++i)
	    {
	      clrscr();
	      cout << endl << "Info for Station : " << i+1;
	      cout << endl << endl << "Name of Station : ";
	      puts(s[i].name);
	      cout << "Arrival time   (hh:mm) : ";
	      puts(s[i].arr_time);
	      gotoxy(31,5);
	      clreol();
	      gotoxy(1,6);
	      cout << "Departure time (hh:mm) : ";
	      puts(s[i].dep_time);
	      gotoxy(31,6);
	      clreol();
	      getch();
	    }

	    clrscr();
	    cout << endl << "Capacity of the train : ";
	    cout << capacity;

	    cout << endl << endl;
	    cout << "ENTER NEW INFORMATION !!" << endl;
	    cout << endl << "Train No. : ";
	    cin  >> train_no;
	    cout << endl << "Name of Train : ";
	    gets(train_name);
	    clrscr();

	    cout << "Enter Information of five stations en route the train :"
		 << endl;
	    getch();

	    for ( i = 0; i < 5; ++i)
	    {
	      clrscr();
	      cout << endl << "Enter Info for Station : " << i+1;
	      cout << endl << "Name of Station : ";
	      gets(s[i].name);
	      cout << "Enter Arrival time   (hh:mm) : ";
	      gets(s[i].arr_time);
	      cout << "Enter Departure time (hh:mm) : ";
	      gets(s[i].dep_time);
	    }

	    getch();
	    clrscr();
	    cout << endl << "Enter capacity of the train : ";
	    cin  >> capacity;

	    file.seekp(j*(sizeof(train)),ios::beg);
	    file.write((char*)this, sizeof(train));
	  }
       file.read((char*)this, sizeof(train));
       }

       if (!flag)
	   cout << endl << "NO MATCH FOUND !!";

       file.close();
       getch();
    }




//---------------------------------------------------------------------//
//--This function displays the data of a train according to train no.--//
//---------------------------------------------------------------------//


void train :: display_train(unsigned int t_no) {

      clrscr();
      int flag = 0;
      fstream file;
      file.open("TRAIN.DAT",ios::in | ios::binary);
      file.seekg(0,ios::beg);

      file.read((char*)this, sizeof(train));
      for(int j = 0; !file.eof(); ++j)
       {
	  if (t_no == train_no)
	  {
	    flag = 1;
	    cout << endl << "DISPLAYING TRAIN INFORMATION !!"<<endl;
	    cout << endl << "Train No. : ";
	    cout << train_no;
	    cout << endl << "Name of Train : ";
	    puts(train_name);
	    getch();
	    clrscr();

	    cout << " Information of five stations en route the train :"
		 << endl;
	    getch();

	    for (int i = 0; i < 5; ++i)
	    {
	      clrscr();
	      cout << endl << "Info for Station : " << i+1;
	      cout << endl << endl << "Name of Station : ";
	      puts(s[i].name);
	      cout << "Arrival time   (hh:mm) : ";
	      puts(s[i].arr_time);
	      gotoxy(30,5);
	      clreol();
	      gotoxy(1,6);
	      cout << "Departure time (hh:mm) : ";
	      puts(s[i].dep_time);
	      gotoxy(30,6);
	      clreol();
	      getch();

	    }

	    clrscr();
	    cout << endl << " Capacity of train : ";
	    cout << capacity;
	    cout << endl << endl <<" No. of Seats booked in the train : ";
	    cout << seats_booked;
	  }

       file.read((char*)this, sizeof(train));
       }

       if (!flag)
	   cout << endl << "NO MATCH FOUND !!";

       file.close();
       getch();
    }




//----------------------------------------------------------------------//
//--This function displays all the currently running trains one-by-one--//
//----------------------------------------------------------------------//



void train :: display_all(void) {

      clrscr();
      ifstream file;
      file.open("TRAIN.DAT", ios::binary);
      file.seekg(0,ios::beg);

      file.read((char*)this, sizeof(train));
      while (!(file.eof()))
      {
	    clrscr();
	    cout << endl << "DISPLAYING TRAIN INFORMATION !!"<<endl;
	    cout << endl << "Train No. : ";
	    cout << train_no;
	    cout << endl << "Name of Train : ";
	    puts(train_name);
	    getch();
	    clrscr();

	    cout << " Information of five stations en route the train :"
		 << endl;
	    getch();

	    for (int i = 0; i < 5; ++i)
	    {
	      clrscr();
	      cout << endl << "Info for Station : " << i+1;
	      cout << endl << endl << "Name of Station : ";
	      puts(s[i].name);
	      cout << "Arrival time   (hh:mm) : ";
	      puts(s[i].arr_time);
	      gotoxy(30,5);
	      clreol();
	      gotoxy(1,6);
	      cout << "Departure time (hh:mm) : ";
	      puts(s[i].dep_time);
	      gotoxy(30,6);
	      clreol();
	      getch();
	    }

	    clrscr();
	    cout << endl << "Capacity of train : ";
	    cout << capacity;
	    cout << endl << endl << "No. of Seats booked in the train : ";
	    cout << seats_booked << endl;

	    getch();

	    file.read((char*)this, sizeof(train));
      }
      file.close();
   }




//-----------------------------------------------------------------------//
//--     This function cancels the ticket according to given PNR No.   --//
//--This function copies all records except the matched one to TEMP.DAT--//
//--        And rewrites the contents of TICKET.DAT from TEMP.DAT      --//
//-----------------------------------------------------------------------//

//-----------------------------------------------------------------//
//--The function deletes data only when the Seats booked are zero--//
//--            Only unreserved trains can be deleted            --//
//-----------------------------------------------------------------//


void train :: delete_train (unsigned int t_no) {

      clrscr();
      int flag = 0;
      fstream fin2;
      fstream fout;

      fin2.open("TRAIN.DAT", ios::in | ios::binary);
      fout.open("TEMP.DAT", ios::out | ios::binary);

      fin2.seekg(0, ios::beg);
      fout.seekp(0, ios::beg);

      fin2.read((char*)this, sizeof(train));

      while(!fin2.eof())
      {
	if (t_no == train_no)
	  flag = 1;
	fin2.read((char*)this, sizeof(train));
      }
      fin2.close();

      if (!flag)
       {
	cout << endl << "No such Record found !!";
	getch();
       }

      else if (seats_booked != 0)
       {
	cout << endl << "Sorry !! Train has reservations. "
	     << endl << "Deletion is not possible."
	     << endl << "First Cancel All Tickets pertaining to this train";
	getch();
	flag = 0;
       }

       else if (flag==1) {
	fstream fin;
	fin.open("TRAIN.DAT", ios::in | ios::binary);
	fin.seekg(0, ios::beg);
	fin.read((char*)this, sizeof(train));

	while(!fin.eof())
	{

	 if (t_no == train_no);

	 else
	  fout.write((char*)this, sizeof(train));

	 fin.read((char*)this, sizeof(train));
	}
	// The above sequence copies the active train records
	// to a temporary file
	}

       fout.close();

       if (flag)
       {
	 fstream f1;
	 fstream f2;

	 f1.open("TEMP.DAT", ios::in | ios::binary);
	 f2.open("TRAIN.DAT", ios::out | ios::binary);

	 f1.seekg(0, ios::beg);
	 f2.seekp(0, ios::beg);

	 f1.read((char*)this, sizeof(train));
	 while(!f1.eof())
	 {
	    f2.write((char*)this, sizeof(train));
	    f1.read((char*)this, sizeof(train));
	 }
	 //This sequence copies the functional records
	 //from temporary file to truncated and rewritten TRAIN.DAT

	 f1.close();
	 f2.close();

	 if (flag)
	 {
	   sound(1000);
	   delay(400);
	   nosound();
	   cout << endl << "TRAIN HAS BEEN DELETED !!";
	 }
	 getch();

       }

   }



//------------------------------------------------------------//
//--STARTING WITH FUNCTION DEFINITIONS FOR CLASS RESERVATION--//
//------------------------------------------------------------//


//------------------------------------------------------------------//
//--    The following function resets the PNR on Program Re-run   --//
//------------------------------------------------------------------//


void reservation :: set_PNR(void)  {

      int savePNR = 0;
      fstream fx;
      fx.open("TICKET.DAT", ios::in | ios::binary);

      if(fx) {

      fx.read((char*) this, sizeof(reservation));
      while(!fx.eof()) {

      savePNR = passenger_no ;
      fx.read((char*) this, sizeof(reservation));

	}
      }

      fx.close();

      PNR = savePNR ;
}



//-------------------------------------------------------------------//
//--This function accesses the records of file TRAIN.DAT and checks--//
//--       if the train no. for the journey is valid or not        --//
//--     ascertains the position and decrements the no. of seats   --//
//-------------------------------------------------------------------//

//----------------------------------------------------------------//
//--            This function implements containership          --//
//--This function has an object of class train for record-access--//
//----------------------------------------------------------------//


int reservation :: check_train(unsigned int t_no, int persons) {

      train t;
      int flag = 0;
      int pos;

      fstream f;
      f.open("TRAIN.DAT",ios::in | ios::out | ios::ate | ios::binary);
      f.seekg(0,ios::beg);

      f.read((char*)&t, sizeof(train));
      for ( int j = 0; (!f.eof()); ++j)
      {
	if (t_no == t.train_no)
	    { flag = 1;
	      if(t.capacity < t.seats_booked)
	      { pos = t.seats_booked - t.capacity + 1;
		strcpy(status,"WAIT_LIST ");
		}
	      else
	      { pos = t.seats_booked + 1;
		strcpy(status,"CONFIRMED ");
		}

	      t.seats_booked += persons;
	      f.seekp(j * sizeof(train));
	      f.write((char*)&t,sizeof(train));
	     }
      f.read((char*)&t, sizeof(train));
      }

      f.close();

      position = pos;

      return flag;
   }




//----------------------------------------------------------------------//
//--This function calculates fare as according to the journey stations--//
//--            And the travelling class and No. of persons           --//
//--                This also implements containership                --//
//----------------------------------------------------------------------//



void reservation :: calculate(unsigned int t_no, char* A, char* B)
  {
      train t;
      unsigned int distance;

      fstream f("TRAIN.DAT",ios::in | ios::binary);
      f.seekg(0,ios::beg);

      f.read((char*)&t, sizeof(train));
      while (!f.eof()) {

	 if (t_no == t.train_no)
	 {
	   distance = 100 * t.difference(A,B);
	   break;
	 }
	 f.read((char*)&t, sizeof(train));
       }

	 fare = 3 * (8 - _class) * distance;
	 f.close();
  }




//--------------------------------------------------------------------------//
//--This function extracts all info necessary for a reservation and ticket--//
//--------------------------------------------------------------------------//


void reservation :: ticket () {

      clrscr();
      fstream f;
      f.open("TICKET.DAT", ios::app | ios::binary);

      cout << endl << "ENTER INFORMATION !!";
      cout << endl
	   << endl << "P.N.R. No.                 :      " << PNR+1 << endl;
      cout << endl << "Train No. 		  :      ";
      cin  >> train_no;
      cout << endl << "No. of persons             :      ";
      cin  >> seats;
      cout << endl << "Travelling Class           :      ";
      cin  >> _class;
      cout << endl << "Starting Station           :      ";
      gets(source);
      cout <<         "Terminating Station        :      ";
      gets(dest);

      calculate(train_no,source,dest);
	//calculation of fare

      if(!fare);

      else if(!check_train(train_no,seats))
      cout << endl << endl << "Sorry!! The train no. is invalid."
	   << endl << "Exiting........";



      else {

      getch();
      clrscr();

      ++PNR;
      passenger_no = PNR;

      cout << endl << "Name                       :      ";
      gets(name);
      cout <<         "Address                    :      ";
      gets(address);
      cout <<         "Phone No.                  :      ";
      gets(phone);
      cout <<         "Age                        :      ";
      cin  >> age;
      cout <<         "Sex                        :      ";
      cin  >> sex;
      cout << endl
	   << endl << "Date of Journey :" ;
      cout << endl << "Day       :   ";
      cin  >> d_o_j.da_day;
      cout <<         "Month     :   ";
      cin  >> d_o_j.da_mon;
      cout <<         "Year      :   ";
      cin  >> d_o_j.da_year;

      cout << endl << "Date of Reservation :" ;
      cout << endl << "Day       :   ";
      cin  >> d_o_r.da_day;
      cout <<         "Month     :   ";
      cin  >> d_o_r.da_mon;
      cout <<         "Year      :   ";
      cin  >> d_o_r.da_year;

      tot_amt += fare;
       //incrementing total fare collected till now

      f.write((char*)this , sizeof(reservation));
     }

     getch();
     f.close();
   }



//------------------------------------------------------------//
//-- The following function definitions of display_ticket() --//
//--implement Polymorphism in C++ using Function Overloading--//
//------------------------------------------------------------//

//--------------------------------------------------------------------//
//--The following version of display_ticket is for displaying ticket--//
//--                      <Search Key> = None                       --//
//--  (This private function is for internal use by class members)  --//
//--------------------------------------------------------------------//


void reservation :: display_ticket(void) {

      clrscr();
      cout << endl << "DISPLAYING INFORMATION !!" << endl;
      cout << endl << "P.N.R. No.                 :      " << passenger_no;
      cout << endl
	   << endl << "Train No.                  :      ";
      cout << train_no;
      cout << endl << "No. of persons             :      ";
      cout << seats;
      cout << endl << "Travelling Class           :      ";
      cout << _class;
      cout << endl << "Starting Station           :      ";
      puts(source);
      cout <<         "Terminating Station        :      ";
      puts(dest);
      cout << endl << "Position                   :      "
	   << position << " ";
      puts(status);
      gotoxy(46,12);
      clreol();

      getch();
      clrscr();
      cout << endl << "DISPLAYING INFORMATION !!" << endl;
      cout << endl << "Name                       :      ";
      puts(name);
      cout <<         "Address                    :      ";
      puts(address);
      cout <<         "Phone No.                  :      ";
      puts(phone);
      cout <<         "Age                        :      ";
      cout << age;
      cout << endl << "Sex                        :      ";
      cout << sex;
      cout << endl << "Date of Reservation        :      ";
      cout << d_o_r.da_day << "-";
      cout << d_o_r.da_mon << "-";
      cout << d_o_r.da_year;
      cout << endl << "Date of Journey            :      " ;
      cout << d_o_j.da_day << "-";
      cout << d_o_j.da_mon << "-";
      cout << d_o_j.da_year;
      cout << endl
	   << endl << "FARE                       :      Rs. " << fare << " only";
      cout << endl;
      getch();

   }




//----------------------------------------------------------//
//--The following function displays the ticket particulars--//
//--                <Search Key> = PNR No.                --//
//----------------------------------------------------------//


void reservation ::display_ticket(int num) {

      int flag = 0;
      fstream f;
      f.open("TICKET.DAT",ios::in | ios::binary);
      f.seekg(0,ios::beg);

      f.read((char*)this, sizeof(reservation));
      while (!f.eof())
      {
	 if (num == passenger_no)
	 {
	    flag = 1;
	    display_ticket();
	 }

      f.read((char*)this, sizeof(reservation));
      }

      if(!flag)
       { cout << endl << "NO MATCH FOUND !!";
	 getch();
       }
    f.close();
  }




//------------------------------------------------------------------//
//--This function displays ticket details on name of ticket-holder--//
//--                     <Search Key> = name                      --//
//------------------------------------------------------------------//


void reservation :: display_ticket(char* s) {

      int flag = 0;
      fstream f;
      f.open("TICKET.DAT", ios::in | ios::binary);
      f.seekg(0,ios::beg);

      f.read((char*)this, sizeof(reservation));
      while (!f.eof())
      {
	 if (!(strcmpi(s,name)))
	 {
	    flag = 1;
	    display_ticket();
	 }

      f.read((char*)this, sizeof(reservation));
      }

      if(!flag)
       { cout << endl << "NO MATCH FOUND !!";
	 getch();
       }
    f.close();
  }




//-------------------------------------------------------------------------//
//--This function provides a listing of all the tickets reserved till now--//
//-------------------------------------------------------------------------//


void reservation :: display_all() {

      fstream f;
      f.open("TICKET.DAT", ios::in | ios::binary);
      f.seekg(0,ios::beg);

      f.read((char*)this, sizeof(reservation));
      for (int i = 1; (!(f.eof())); ++i)
       {
	  display_ticket();
	  f.read((char*)this, sizeof(reservation));
       }
       cout << endl
	    << endl <<"TOTAL AMOUNT COLLECTED BY NOW : Rs. " << tot_amt;
       cout << endl;
       getch();

       f.close();
   }




//----------------------------------------------------//
//-- This function modifies the data of a passenger --//
//--           according to provided PNR No.        --//
//--Journey details are not accessible for deletion --//
//----------------------------------------------------//


void reservation :: modify_ticket(int num) {

      int flag = 0;
      fstream f;
      f.open("TICKET.DAT", ios::in | ios::out | ios::ate | ios::binary);
      f.seekg(0,ios::beg);

      f.read((char*)this, sizeof(reservation));
      for (int k = 0; (!(f.eof())); ++k)
      {
	 if (num == passenger_no)
	 {
	    flag = 1;
	    display_ticket();
	    clrscr();
	    cout << endl << "ENTER NEW INFORMATION  !!";
	    cout << endl << endl << "Name : ";
	    gets(name);
	    cout << endl << "Address : ";
	    gets(address);
	    cout << endl << "Phone No. : ";
	    gets(phone);
	    cout << endl << "Age : ";
	    cin  >> age;
	    cout << "Sex : ";
	    cin  >> sex;

	    f.seekp(k * sizeof(reservation), ios::beg);
	    f.write((char*)this, sizeof(reservation));
	 }

      f.read((char*)this, sizeof(reservation));
      }

      if (!flag)
	cout << endl << "No Record matches !!";

      getch();
      f.close();
  }




//-----------------------------------------------------------------------//
//--      This function cancels the ticket according to given PNR No.  --//
//--This function copies all records except the matched one to TEMP.DAT--//
//--         And rewrites the contents of TICKET.DAT from TEMP.DAT     --//
//-----------------------------------------------------------------------//


void reservation :: cancel_ticket(int num) {

      clrscr();
      int flag = 0;
      fstream fin;
      fstream fout;

      fin.open("TICKET.DAT", ios::in | ios::binary);
      fout.open("TEMP2.DAT", ios::out | ios::binary);

      fin.seekg(0, ios::beg);
      fout.seekp(0, ios::beg);

      fin.read((char*)this, sizeof(reservation));
      while(!fin.eof())
      {
	if (num == passenger_no)
	  flag = 1;

       fin.read((char*)this, sizeof(reservation));
      }

      fin.close();

      if (!flag)
	cout << endl << "No such Record found !!";
      else
       {  getch();
	train t;
	fstream file;
	file.open("TRAIN.DAT",ios::in | ios::out | ios::ate | ios::binary);
	file.seekg(0,ios::beg);

	file.read((char*)&t, sizeof(train));
	for (int rec = 0; !file.eof(); ++rec)
	{
	   if (t.train_no == train_no)
	    {
	       file.seekp((rec * sizeof(train)),ios::beg);
	       t.seats_booked = t.seats_booked - seats;
	       tot_amt = tot_amt - fare;

	       file.write((char*)&t, sizeof(train));
	    }
	 file.read((char*)&t, sizeof(train));
	 }
	 file.close();

	 // The above sequence decrements the number of seats booked
	 // in the train whose ticket is being cancelled and
	 // the total amount collected in this program run

	fstream fin2;
	fin2.open("TICKET.DAT", ios::in | ios::binary);

	fin2.seekg(0, ios::beg);
	fin2.read((char*)this, sizeof(reservation));
	while (!fin2.eof())
	{
	 if (num == passenger_no);

	 else
	  fout.write((char*)this, sizeof(reservation));

	fin2.read((char*)this, sizeof(reservation));
	}
	// The above sequence copies the functional ticket records
	// to a temporary file

	fin2.close();
      }

       fout.close();

       if (flag)
       {
	 fstream f1;
	 fstream f2;

	 f1.open("TEMP2.DAT", ios::in | ios::binary);
	 f2.open("TICKET.DAT", ios::out | ios::binary);

	 f1.seekg(0, ios::beg);
	 f2.seekp(0, ios::beg);

	 f1.read((char*)this, sizeof(reservation));
	 while(!f1.eof())
	 {
	    f2.write((char*)this, sizeof(reservation));
	    f1.read((char*)this, sizeof(reservation));
	 }
	 //This sequence copies the functional records
	 //from temporary file to truncated and rewritten TICKET.DAT

	 f1.close();
	 f2.close();
	 sound(1000);
	 delay(400);
	 nosound();
	 cout << endl << "TICKET HAS BEEN CANCELLED !!";
       }

      getch();
   }




//--------------------------------------------------------//
//--STARTING WITH FUNCTION DEFINITIONS FOR CLASS CONTROL--//
//--------------------------------------------------------//


//----------------------------------------------------------------------//
//--The following function displays the menu for train related options--//
//----------------------------------------------------------------------//


void control :: train_menu() {

      train t;
      unsigned int train_no;
      int ch;

      label :

      clrscr();
      box();
      gotoxy(32,8);
      cout << " TRAIN  MENU ";
      gotoxy(32,9);
      cout << "~~~~~~~~~~~~~";
      gotoxy(29,11);
      cout << "1. Add New Train ";
      gotoxy(29,12);
      cout << "2. Modify Train ";
      gotoxy(29,13);
      cout << "3. Display Particular Train ";
      gotoxy(29,14);
      cout << "4. Display All Trains ";
      gotoxy(29,15);
      cout << "5. Delete Train ";
      gotoxy(29,16);
      cout << "6. Return to Main Menu ";
      gotoxy(29,18);
      cout << "ENTER CHOICE : ";

      cin >> ch;

      clrscr();
      train_no = 0;

      switch(ch)
      {
	 case 1 : t.getdata();
		  break;

	 case 2 : clrscr();
		  cout << "Enter Train No. : ";
		  cin  >> train_no;
		  t.modify(train_no);
		  break;

	 case 3 : cout << "Enter Train No. : ";
		  cin  >> train_no;
		  t.display_train(train_no);
		  break;

	 case 4 : t.display_all();
		  break;

	 case 5 : cout << "Enter Train No. : ";
		  cin  >> train_no;
		  t.delete_train(train_no);
		  break;

	 case 6 : return;

	default : gotoxy(29,20);
		  cout << "Wrong Choice !!";
		  getch();

      }

      goto label;
    }




//-------------------------------------------------//
//--   The following function displays the menu  --//
//--for reservation and ticketing related options--//
//-------------------------------------------------//


void control :: reservation_menu() {

      reservation r;
      int getPNR;
      char* name;
      int ch;

      tag :

      clrscr();
      box();
      gotoxy(30,7);
      cout << "  RESERVATION  MENU ";
      gotoxy(30,8);
      cout << " ~~~~~~~~~~~~~~~~~~~";
      gotoxy(30,10);
      cout << "1. Reserve Ticket ";
      gotoxy(30,11);
      cout << "2. Modify Ticket ";
      gotoxy(30,12);
      cout << "3. Display Ticket (by PNR)";
      gotoxy(30,13);
      cout << "4. Display Ticket (by Name)";
      gotoxy(30,14);
      cout << "5. Display All Tickets";
      gotoxy(30,15);
      cout << "6. Cancel Ticket ";
      gotoxy(30,16);
      cout << "7. Return to Main Menu ";
      gotoxy(30,18);
      cout << "ENTER CHOICE : ";

      cin >> ch;

      clrscr();
      getPNR = 0;

      switch(ch)
      {
	 case 1 : r.ticket();
		  break;

	 case 2 : clrscr();
		  cout << "Enter PNR No. : ";
		  cin  >> getPNR;
		  r.modify_ticket(getPNR);
		  break;

	 case 3 : cout << "Enter PNR No. : ";
		  cin  >> getPNR;
		  r.display_ticket(getPNR);
		  break;

	 case 4 : cout << "Enter Name of the Person";
		  gets(name);
		  r.display_ticket(name);
		  break;

	 case 5 : r.display_all();
		  break;

	 case 6 : cout << "Enter PNR No. : ";
		  cin  >> getPNR;
		  r.cancel_ticket(getPNR);
		  break;

	 case 7 : return;

	default : gotoxy(30,20);
		  cout << "Wrong Choice !!";
		  getch();

      }

      goto tag;
    }




//--------------------------------------------------------------//
//The following function displays the textured fill background--//
//--                     for all the menus                    --//
//--------------------------------------------------------------//


void control :: box(void) {

	char c1=178, c2=177, c3=176 ;
	int k=1 ;
	gotoxy(1,2) ;
	for (int i=1; i<=1840; i++)
	{
		if (k == 1)
			cout <<c1 ;
		else
		if (k == 2)
			cout <<c2 ;
		else
		if (k == 3)
			cout <<c3 ;
		k++ ;
		if (k == 4)
			k = 1 ;
	}
	for (i=5; i<=21; i++)
	{
		gotoxy(21,i) ;
		cout <<"                                        " ;
	}
}




//------------------------------------------------------------------------//
//--The following function allows the user to access the program only on--//
//--                 Providing the Authorization Password               --//
//--              This prevents illegal tapping of the system           --//
//------------------------------------------------------------------------//


void control :: verification() {

      clrscr();
      sound(1000);
      delay(400);
      nosound();
      char* password;

      gotoxy(20,12);

      strcpy(password, getpass(" ENTER VERIFICATION PASSWORD : "));

      if ((!strcmpi(password,"BARBIE")) || (!strcmpi(password,"VINCY")))
      {
	 clrscr();
	 sound(1000);
	 delay(400);
	 nosound();

	 gotoxy(18,12);
	 cout << "PASSWORD CONFIRMED. ACCESSING PROGRAM......";
	 getch();
       }

       else
       {
	  clrscr();
	  sound(2000);
	  delay(400);
	  nosound();

	  gotoxy(26,11);
	  cout << "INCORRECT PASSWORD....";
	  gotoxy(29,13);
	  textcolor(RED + BLINK);
	  cout << "Access--Denied";
	  textcolor(WHITE);
	  delay(3000);

	  exit(0);

       }
   }




//------------------------------------------------------------------//
//--The following function provides a brief introduction about the--//
//--   system to the user for better understanding and efficiency --//
//------------------------------------------------------------------//


void control :: introduction() {

      clrscr();
      textcolor(YELLOW + BLINK);
      gotoxy(4,3);
      cprintf(" ---------------------------------------------------------------------");
      gotoxy(4,4);
      cprintf("           PROJECT RAILWAY RESERVATION-CUM-INFORMATION SYSTEM         ");
      gotoxy (4,5);
      cprintf(" ---------------------------------------------------------------------");
      textcolor(WHITE);
      gotoxy(5,7);
      cout << " *   This  Project  aims at  automizing a Railway Reservation System";
      gotoxy(5,9);
      cout << " *   This  Program  can  maintain  records for  any number of Trains";
      gotoxy(5,10);
      cout << "     along with any number of Wait-listed or  confirmed Reservations";
      gotoxy(5,12);
      cout << " *   The Main Menu has  three major parts which  provide options for";
      gotoxy(5,13);
      cout << "     Train Manipulation -- Reservations -- Introduction  --  Exiting ";
      gotoxy(5,15);
      cout << " *   Train option  allows for  addition, deletion, modification  and";
      gotoxy(5,16);
      cout << "     displaying of trains by giving their Train Nos. ";
      gotoxy(5,18);
      cout << " *   Reservation  Option  inputs  data  of a person and the  journey";
      gotoxy(5,19);
      cout << "     It further allows for searching a particular person and display";
      gotoxy(5,20);
      cout << "     of all tickets or a particular (by PNR No.) ";
      gotoxy(5,22);
      cout << " *   Introduction option gives a brief preview of the Project ";
      gotoxy(5,24);
      cout << " *   Exit Option exits to Windows / DOS........";

      getch();
      clrscr();

   }




//-------------------------------------------------------------//
//--      The following function displays the Opening Menu   --//
//--The function branches the control to other specific menus--//
//-------------------------------------------------------------//


void control :: main_menu() {

      verification();
      introduction();

      int ch;

      do {

       clrscr();
       box();
       gotoxy(27,6);
       cout << " RAILWAY RESERVATION SYSTEM ";
       gotoxy(27,7);
       cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
       gotoxy(32,9);
       cout << " M A I N   M E N U ";
       gotoxy(32,10);
       cout << "~~~~~~~~~~~~~~~~~~~";
       gotoxy(32,12);
       cout << "1. Introduction";
       gotoxy(32,13);
       cout << "2. Train Menu";
       gotoxy(32,14);
       cout << "3. Reservation Menu";
       gotoxy(32,15);
       cout << "4. Exit to Windows";
       gotoxy(32,18);
       cout << "ENTER CHOICE : ";

       cin  >> ch;

       switch(ch) {

	 case 1 : introduction();
		  break;

	 case 2 : train_menu();
		  break;

	 case 3 : reservation_menu();
		  break;

	 case 4 : gotoxy(32,20);
		  cout << "Exiting......";
		  delay(2000);
		  exit(0);

	}
      }
      while (ch != 4);

  }




//------------------------------------------------------------------------------//
//--THE FOLLOWING FUNCTION IS THE MAIN FUNCTION WHICH CONTROLS THE PROGRAM RUN--//
//-- It has an object of class control through which program data is accessed --//
//------------------------------------------------------------------------------//


int main() {

     control c;
     c.main_menu();
     return 0;
   }

