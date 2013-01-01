#include "fstream.h"
#include "conio.h"
#include "stdio.h"
#include "dos.h"
#include "string.h"
void exit();
class patient
{
public:
char name[30];
char dis[50];
int  age,srn;
char sex[5];
void input();
void showdata();
void ass();
void search();
};
class doctor
{
public:
void show();
void show2();
void newdoctor();
char namedoc[50];
char specia[55];
char unigd[50];
char uniphd[50];
int p1,p2,dob,code;
};
class hospital
{
public:
void intro();
void help();
void classified();
};
void doctor :: show()
{
hospital obj;
obj.intro();
gotoxy(10,5);
cout << "name--";
puts(namedoc);
gotoxy(10,8);
cout << "serial no -->> " << code;
gotoxy(10,10);
cout << "specialization in ";
puts(specia);
getchar();
}
void doctor :: show2()
{
hospital obj;
obj.intro();
gotoxy(10,5);
cout << "name--";
puts(namedoc);
gotoxy(10,8);
cout << "serial no -->> " << code;
gotoxy(10,10);
cout << "specialization in ";
puts(specia);
gotoxy(10,12);
cout << "DOCTOR's QUALIFICATION";
gotoxy(10,14);
cout << "PERCENTAGE IN M.B.B.S / EQUIVALENT GRADUATION --->> ";
cout << p1;
gotoxy(10,16);
cout << "NAME OF M.B.B.S UNIVERSITY --->> ";
puts(unigd);
gotoxy(10,18);
cout << "PERCENTAGE IN POST GRADUATION --->> ";
cout << p2;
gotoxy(10,20);
cout << "NAME OF M.B.B.S UNIVERSITY --->> ";
puts(uniphd);
gotoxy(10,22);
cout << "DATE OF BIRTH(DD\MM\YY) --->> ";
cout << dob;

getchar();
}

void hospital :: help()
{
hospital obj;
gotoxy(10,5);
cout << "THE KUSHWAHA HOSPITAL WAS FORMED IN 1964,THREE YEARS AFTER THE";
gotoxy(10,7);
cout << "HOSPITAL WAS FORMALLY INAGURATED BY THE PRESIDENT OF ASSOCIATION";
gotoxy(10,9);
cout << "OF DOCTORS IN 1961.SINCE THEN THE HOSPITAL  HAS BEEN PROVIDING ITS";
gotoxy(10,11);
cout << "PATIENTS WITH THE BEST OF FACILITIES.THE HOSPITAL HAS RISEN TO";
gotoxy(10,13);
cout << "BECOME ONE OF THE BEST HOSPITAL IN THE COUNTRY.THE HOSPITAL HAS A";
gotoxy(10,15);
cout << "VERY DEDICATED,PROFESIONAL AND EXPERIENCED STAFF.THE HOSPITAL PROVIDES";
gotoxy(10,17);
cout << "SPECIAL CONCESSION TO THE FAMILIES OF SERVICE CLASSES & ALSO TO THE";
gotoxy(10,19);
cout << "DISABLED AND ELDERLY PEOPLE.";
gotoxy(10,22);
cout << "Press any key to return";
gotoxy(55,3);
getchar();
}
void patient :: ass()
  {
  hospital obj;

  obj.intro();
  gotoxy(30,2);
  cout << "PATIENT ASSISTANCE";
  gotoxy(30,3);
  cout << "==================";
  gotoxy(10,5);
  cout << "THE HOSPITAL OFFERS YOU WITH THE BET OF FACILITIES IN THE FIELD";
  gotoxy(10,6);
  cout << "OF MEDICINE 24 HOURS A DAY,7 DAYS A WEEK...THE HOSPITAL IS WELL";
  gotoxy(10,7);
  cout << "FURNISHED WITH THE BEST EQUIPPMENT AND HAS THE BEST STAFF AVAIL";
  gotoxy(10,8);
  cout << "-ABLE IN THE  COUNTRY. THE LIST OF VARIOUS DEPARTMENTS OF THIS";
  gotoxy(10,9);
  cout << "HOSPITAL AND THEIR HEADS IS AS FOLLOWS::::::::";
  gotoxy(10,12);
  cout << "  NAME OF DEPARTMENT                              H.O.D";
  gotoxy(10,13);
  cout << "  ==================                              =====";
  gotoxy(13,14);
  cout << "Pathology   Dept.                           Dr R Sharma,MBBS";
  gotoxy(13,15);
  cout << "Heart research Dept.                        Dr K D Prasad,MBBS";
  gotoxy(13,16);
  cout << "E.N.T Dept.                                 Dr(mrs)Preeti Sud";
  gotoxy(13,17);
  cout << "Dental Dept.                                Dr  P S Moorthy";
  gotoxy(13,18);
  cout << "Eye  Dept                                   Dr(mrs)P Chowdhary";
  gotoxy(13,19);
  cout << "Gynic Dept                                  DR(mrs)R Garg.";
  gotoxy(13,20);
  cout << "O.P.D Dept                                  Dr P K Sharma.";
  gotoxy(20,22);
  cout << "Press any key to go to next page";
  getchar();
  obj.intro();
  gotoxy(25,3);
  cout << "PATIENT ASSISTANCE PAGE-2";
  gotoxy(25,4);
  cout << "=========================";
  gotoxy(5,6);
  cout << "THIS PAGE PROVIDES THE PATIENTS WITH THE TIMINGS TO VISIT THE H.O.D";
  gotoxy(10,8);
  cout << "NAME OF DOCTOR         DEPT          TIMINGS         PROCEDURE";
  gotoxy(10,9);
  cout << "--------------         ----          -------         ---------";
  gotoxy(10,10);
  cout << "Dr R Sharma,MBBS      Pathology     7:am--5:pm         Appt.";
  gotoxy(10,11);
  cout << "Dr K D Prasad,MBBS    Heart          ---do---          Appt.";
  gotoxy(10,12);
  cout << "Dr(mrs)Preeti Sud     E.N.T          ---do---          Appt.";
  gotoxy(10,13);
  cout << "Dr  P S Moorthy       Dental        7:am--3:pm       on same day";
  gotoxy(10,14);
  cout << "Dr(mrs)P Chowdhary    Eye           8:am--5:pm       on same day";
  gotoxy(10,15);
  cout << "DR(mrs)R Garg         Gynic         7:am--6:pm       on same day";
  gotoxy(10,16);
  cout << "Dr P K Sharma         O.P.D          ---do---          Appt.    ";
  gotoxy(3,18);
  cout << "Secondary staff is availiable at all times at all Depts for emergency cases";
  gotoxy(3,19);
  cout << "Emergency & Maternity ward is open 24 hours a day.";
  gotoxy(25,21);
  cout << "Press any key to return.";
  getch();
}
void patient :: input()
{
hospital obj;
obj.intro();
gotoxy(30,8);
cout << "SR.no :-> ";
cin >> srn;
gotoxy(30,10);
cout << "NAME OF PATIENT :-> ";
gets(name);
gotoxy(30,12);
cout << "AGE :-> ";
cin >> age;
gotoxy(30,14);
cout << "DISEASE OF PATIENT :-> ";
gets(dis);
gotoxy(30,16);
cout << "SEX :-> ";
cin >> sex;
}
void patient :: showdata()
{
hospital obj;
obj.intro();
gotoxy(30,5);
cout << "SR.no :-> ";
cout << srn ;
gotoxy(30,7);
cout << "NAME OF PATIENT :-> ";
puts(name);
gotoxy(30,9);
cout << "AGE :-> ";
cout << age;
gotoxy(30,11);
cout << "DISEASE OF PATIENT :-> ";
puts(dis);
gotoxy(30,13);
cout << "SEX :-> ";
cout << sex;
getchar();
}
void patient :: search()
{
hospital obj;
obj.intro();
gotoxy(25,5);
cout << "WELCOME TO KUSHWAHA HOSPITAL SEARCH DEPT.";
gotoxy(12,8);
cout << "INTIALIZING RECORDS .PLEASE WAIT............... ";delay(1000);cout<<"done";
clrscr();
//,MENU FOR SEARCHING
 obj.intro();
 gotoxy(10,11);
 cout<<"SEARCHING BY:-";
 gotoxy(34,8);
 cout << "SEARCHING  CHOICES";
 gotoxy(34,9);
 cout << "******************";
 gotoxy(15,13);
 cout << "1.SR.NO";
 gotoxy(15,15);
 cout << "2.NAME";
 gotoxy(10,17);
 cout << "3.EXIT TO PATIENT MENU";
 gotoxy(10,19);
 cout << "4.EXIT TO MAIN HOSPITAL MENU";
 gotoxy(5,21);
 cout << "INPUT YOUR CHOICE( 1-5) ";
}
void  exit()
   {

     int i,j;
     _setcursortype(_NOCURSOR);

     for(i=4;i<12;i++)
	 {
	    gotoxy(35,i);
	    cout << "THANKS";
	    gotoxy(35,i-1);
	    for(j=35;j<55;j++) cout<<" ";
	    delay(50);

	 }


     gotoxy(55,17);
     cout << "Made by:-";
     gotoxy(60,19);
     cout << "ABHINAV";
     gotoxy(64,20);
     cout<<  "KUSHWAHA";
     getchar();
   }

void hospital::intro()
{
  clrscr();
  int x;
  int y;
  for(y=2;y<24;y++)
   {
    gotoxy(1,y);
    cout<<"º";
    gotoxy(78,y);
    cout<<" º";
   }
   gotoxy(1,1);
   cout<<"É";
   gotoxy(1,24);
   cout<<"È";
   gotoxy(79,1);
   cout<<"»";
   gotoxy(79,24);
   cout<<"¼";

for(x=2;x<79;x++)
   {
    gotoxy(x,1);
    cout<<"Í";
    gotoxy(x,24);
    cout<<"Í";
   }

}
void doctor :: newdoctor()
{
hospital obj;
obj.intro();
gotoxy(25,2);
cout << "NEW DOCTOR'S REGISTRATION";
gotoxy(25,3);
cout << "=======================";
gotoxy(10,4);
cout << "DOCTOR'S CODE NO ";
cin >> code;
gotoxy(10,6);
cout << "Doctor'S Name :: ";
gets(namedoc);
gotoxy(10,8);
cout << "FIELD OF SPECILIZATION --->> ";
gets(specia);
gotoxy(10,10);
cout << "DOCTOR'S QUALIFICATION";
gotoxy(10,12);
cout << "PERCENTAGE IN M.B.B.S / EQUIVALENT GRADUATION --->> ";
cin >> p1;
gotoxy(10,14);
cout << "NAME OF M.B.B.S UNIVERSITY --->> ";
gets(unigd);
gotoxy(10,16);
cout << "PERCENTAGE IN POST GRADUATION --->> ";
cin >>p2;
gotoxy(10,18);
cout << "NAME OF M.B.B.S UNIVERSITY --->> ";
gets(uniphd);
gotoxy(10,20);
cout << "DATE OF BIRTH(DD\MM\YY) --->> ";
cin >> dob;
}
void main()
{

textcolor(WHITE);
textbackground(BLACK);
hospital obj;
patient suck;
doctor doct;
obj.intro();
gotoxy(35,3);
cout << "USER'S VERIFICATION";
gotoxy(35,4);
cout << "=================";
char q[25];
gotoxy(32,12);
cout << "password---->>";
textcolor(BLACK);
gets(q);
textcolor(WHITE);
if (strcmp(q,"pass")==0)
{
}
else
{
clrscr();
obj.intro();
gotoxy(27,7);
cout << "AUTHENTICATION FAILURE";
gotoxy(27,8);
cout << "======================";
gotoxy(25,10);
cout << "THAT WAS A WRONG PASSWORD.";
getchar();
goto p;

}




k:
 obj.intro();
 gotoxy(28,3);
 cout <<"WELCOME TO THE  KUSHWAHA HOSPITAL"<<"\n";
 gotoxy(28,4);
 cout <<"==========================="<<"\n";
 gotoxy(25,6);
 cout <<"*THE HOSPITAL WITH A DIFFERENCE*";
 gotoxy(10,11);
 cout<<"1.HELP";
 gotoxy(34,8);
 cout << "OPENING MENU";
 gotoxy(34,9);
 cout << "============";
 gotoxy(10,13);
 cout << "2.PATIENT'S INFORMATION";
 gotoxy(10,15);
 cout << "3.DOCTOR'S INFORMATION";
 gotoxy(10,17);
 cout << "4.CLASSIFIED HOSPITAL INFO";
 gotoxy(10,19);
 cout << "5.EXIT";
 gotoxy(5,21);
 cout << "INPUT YOUR CHOICE( 1-5) ";
 int ch;
 cin >> ch;
 if ((ch<1) || (ch>5))
   {
    gotoxy(5,22);
    cout << "WRONG ENTRY.";
    getchar();
    goto k;
   }
 switch(ch)
 {
  case 1:
	{
	obj.intro();
	obj.help();
	getchar();
	goto k;
	}
  case 2:
	{
	z:
	obj.intro();
	gotoxy(30,5);
	cout << "PATIENT'S INFORMATION";
	gotoxy(30,6);
	cout << "===================";
	gotoxy(10,8);
	cout << "1.PATIENT'S ASSITANCE";
	gotoxy(10,10);
	cout << "2.PATIENT'S SEARCH";
	gotoxy(10,12);
	cout << "3.PATIENT'S INFO MODIFICATION ";
	gotoxy(10,14);
	cout << "4.PATIENT'S REGISTRATION.";
	gotoxy(10,16);
	cout << "5.PATIENT'S UNREGISTRATION AND BILLING";
	gotoxy(10,18);
	cout << "6.DISPLAY LIST OF ALL PATIENTS.";
	gotoxy(10,20);
	cout << "7.RETURN TO MAIN MENU";
	gotoxy(5,22);
	cout << "INPUT YOUR CHOICE( 1-7) ";
	int o;
	cin >> o;
	if ((o<1) || (o>7))
	 {
	  gotoxy(5,23);
	  cout << "WRONG CHOICE";
	  getchar();
	  goto z;
	 }
	switch(o)
	 {//for internal switch
	      case 1:
		    {
		    suck.ass();
		    getchar();
		    goto z;
		    }
	      case 2:
		    {
		    f:
		    suck.search();
		    int g;
		    cin >> g;
			   if((g<1) || (g>4))
			      {
			      cout << "wrong choice";
			      goto f;
			      }
			   if(g==1)
			     {
			     gotoxy(10,4);
			     obj.intro();
			     gotoxy(10,3);
			     cout << "PLEASE INPUT SR.NO WHOSE DETAILS HAVE TO BE FOUND::";
			     char wes = 'n';
			     int sch;
			     cin >> sch;
			     ifstream fot;
			     fot.open("pa.dat");
			     fot.seekg(0);
			     fot.read((char*)&suck,sizeof(patient));
			     while(fot)
				{

				   if(suck.srn==sch)
				   {suck.showdata();
				    gotoxy(30,2);
				    cout << "SEARCH RESULT";
				    gotoxy(30,3);
				    cout << "==============";
				    wes = 'y';
				   }
				  fot.read((char*)&suck,sizeof(patient));
				}
			     if (wes == 'n')
				{
				gotoxy(10,10);
				cout << "RECORD NOT FOUND ";
				}

			     fot.close();


			     }
			   if (g==2)
			     {
			     gotoxy(10,4);
			     obj.intro();
			     gotoxy(10,3);
			     cout << "PLEASE INPUT NAME WHOSE DETAILS HAVE TO BE FOUND::";
			     char wese = 'n';
			     int ptr;
			     char namee[45];
			     gets(namee);
			     ifstream fot;
			     fot.open("pa.dat");
			     fot.seekg(0);
			     fot.read((char*)&suck,sizeof(patient));

			     while(fot)
				{
				 ptr = strcmp(suck.name,namee);
				 if (ptr== 0)

				   {suck.showdata();
				    gotoxy(30,2);
				    cout<< "SEARCH RESULT";
				    gotoxy(30,3);
				    cout << "==============";
				    wese = 'y';
				    break;
				   }
				  fot.read((char*)&suck,sizeof(patient));
				}
			     if (wese == 'n')
				{
				gotoxy(10,10);
				cout << "RECORD NOT FOUND ";
				}

			     fot.close();


			     }
			   if (g==3)
			     {
			     goto z;
			     }
			   if (g==4)
			     {
			     goto k;
			     }
		    getchar();
		    goto z;
		    }
	      case 3:
		    {
		    // to modify patient record
		    obj.intro();
		    gotoxy(10,2);
		    cout << "INPUT SR.NO OF PATIENT::";


		    int ts;
		    cin >>ts;
		    ifstream fot;
		    ofstream fin;
		    fin.open("temp2.dat");
		    fot.open("pa.dat");
		    fot.seekg(0);
		    fot.read((char*)&suck,sizeof(patient));
		    while(fot)
		      {
			if(suck.srn==ts)
			   {


			    suck.showdata();
			    gotoxy(10,18);
			    cout << "THESE ARE THE OLD DETAILS";
			    gotoxy(10,20);
			    cout << "YOU NEED TO INPUT NEW DETAILS.PRESS A KEY TO PROCEED";
			    getchar();
			    clrscr();
			    obj.intro();
			    suck.input();
			    gotoxy(35,5);
			    cout << "NEW DETAILS";
			    gotoxy(35,6);
			    cout << "-----------";
			    fin.write((char*)&suck,sizeof(patient));
			   }
			else
			   {
			   fin.write((char*)&suck,sizeof(patient));
			   }

			fot.read((char*)&suck,sizeof(patient));
		       }
		    fot.close();
		    fin.close();
		    ofstream foto;
		    ifstream fito;
		    foto.open("pa.dat");
		    fito.open("temp2.dat");
		    fito.read((char*)&suck,sizeof(patient));
		    while(fito)
		      {
		       foto.write((char*)&suck,sizeof(patient));
		       fito.read((char*)&suck,sizeof(patient));
		      }
		    fito.close();
		    foto.close();
		    goto z;
		    }

	      case 4:
		    {
		    ofstream fout;
		    fout.open("pa.dat",ios :: app);
		    char ans='y';
		    while (ans == 'y')
		    {
		    suck.input();
		    fout.write((char*)&suck,sizeof(patient));
		    gotoxy(30,19);
		    cout << "DO YOU WISH TO ADD MORE RECORDS?";
		    cin >> ans;
		    }
		    fout.close();

		    goto z;
		    }
	      case 5:
		    {
		    obj.intro();
		    gotoxy(10,2);
		    cout << "INPUT SR.NO OF PATIENT::";
		    int ta;
		    char qwer='n';
		    cin >>ta;
		    ifstream fot;
		    ofstream fin;
		    fin.open("temp.dat");
		    fot.open("pa.dat");
		    fot.seekg(0);
		    fot.read((char*)&suck,sizeof(patient));
		    while(fot)
		      {
			if(suck.srn==ta)
			   {

			   qwer='y';
			   gotoxy(10,10);
			   cout << "record has been found deletion in progress.........";
			   delay(1000);
			   cout << "done";
			   obj.intro();
			   gotoxy(20,5);
			   cout << "DO YOU WISH TO PREPARE THE BILL.(1-yes,2-no) ";
			   int ter;
			   cin >> ter;
			   char billname[30];
			   int billdu,billty;
			   if (ter==1)
			       {
				obj.intro();
				gotoxy(10,3);
				cout << "INPUT DURATION OF ADMISSION IN THE HOSPITAL::-->> ";
				cin >> billdu;
				gotoxy(10,5);
				cout << "INPUT ROOM TYPE(1->GENERAL WARD,2->PRIVATE,3-ICU,4-LUXURY)";
				cin >> billty;
				int amt;
				gotoxy(35,10);
				cout << "ROOM CHARGES/DAY";
				gotoxy(35,11);
				cout << "-----------------";
				gotoxy(10,14);
				cout << "GENERAL WARD==Rs150 ";
				gotoxy(10,16);
				cout << "PRIVATE WARD==Rs300";
				gotoxy(10,18);
				cout << "I C U=========Rs450";
				gotoxy(10,20);
				cout << "LUXURY========Rs600";
				getchar();
				amt=(billdu*100)+(billty*150*billdu)+(10*billdu)+(billdu*50);
				obj.intro();
				gotoxy(40,2);
				cout << "BILL";
				gotoxy(40,3);
				cout << "====";
				gotoxy(10,4);
				cout << "NAME::";
				cout<< suck.name;
				gotoxy(10,6);
				cout << "AGE::";
				cout << suck.age;
				gotoxy(10,8);
				cout << "SEX::";
				cout << suck.sex;
				gotoxy(10,10);
				cout << "DISEASE::";
				cout << suck.dis;
				gotoxy(10,12);
				cout << "ITEM             COST/DAY           NO.OF DAYS           COST";
				gotoxy(10,14);
				cout << "HOSPITAL CHARGES  Rs100";
				gotoxy(49,14);
				cout << billdu;
				gotoxy(68,14);
				cout << (100*billdu);
				gotoxy(30,19);
				gotoxy(10,16);
				cout << "ROOM CHARGES";
				gotoxy(28,16);
				cout << "Rs" << (billty*150);
				gotoxy(49,16);
				cout << billdu;
				gotoxy(68,16);
				cout << (billty*150*billdu);
				gotoxy(10,18);
				cout << "LAUNNDRY+DINING   Rs60";
				gotoxy(49,18);
				cout << billdu;
				gotoxy(68,18);
				cout << (60*billdu);
				gotoxy(10,20);
				cout << "TOTAL";
				gotoxy(68,20);
				cout <<  amt;
				gotoxy(25,21);
				cout << "*HAVE A NICE DAY*";
				gotoxy(10,23);
				cout << "Press  printsreen  on your keyboard to print the bill";
				getchar();
			       }
			   goto w;
			   }
			else
			   {
			   fin.write((char*)&suck,sizeof(patient));
			   }
			w:
			fot.read((char*)&suck,sizeof(patient));
		       }
		    fot.close();
		    fin.close();
		    if (qwer=='n')
		       {
			gotoxy(10,15);
			cout << "record not found";
			getchar();
			goto z;
			}
		    ofstream foto;
		    ifstream fito;
		    foto.open("pa.dat");
		    fito.open("temp.dat");
		    fito.read((char*)&suck,sizeof(patient));
		    while(fito)
		      {
		       foto.write((char*)&suck,sizeof(patient));
		       fito.read((char*)&suck,sizeof(patient));
		      }
		    fito.close();
		    foto.close();

		    goto z;
		    }

	      case 6:
		    {
		    ifstream fout1;
		    fout1.open("pa.dat");
		    fout1.seekg(0);
		    fout1.read((char*)&suck,sizeof(patient));

	      while(fout1)
		    {
		    suck.showdata();
		    fout1.read((char*)&suck,sizeof(patient));
		    }
		    fout1.close();
		    goto z;
		    }
	      case 7:
		    {
		    }



	 }//for internal switch
	goto k;
	}

     case 3:
	{
	d:
	obj.intro();
	gotoxy(30,5);
	cout << "DOCTOR'S INFORMATION";
	gotoxy(30,6);
	cout << "-------------------";
	gotoxy(10,8);
	cout <<"1.DOCTOR'S RECORD SEARCH";
	gotoxy(10,10);
	cout << "2.DOCTOR'S DETAILED LIST";
	gotoxy(10,12);
	cout << "3.DOCTOR'S INFO MODIFICATION ";
	gotoxy(10,14);
	cout << "4.NEW DOCTOR'S ADDITION";
	gotoxy(10,16);
	cout << "5.REMOVAL OF DOCTOR'S RECORD";
	gotoxy(10,18);
	cout << "6.RETURN TO MAIN MENU";
	gotoxy(5,21);
	cout << "INPUT YOUR CHOICE( 1-6) ";
	int chb;
	cin >> chb;
	if ((chb < 1) || (chb > 6))
	   {
	    gotoxy(5,22);
	    cout << "WRONG CHOICE";
	    getchar();
	   }
	   switch(chb)
	  {
	     case 1:
		   {
		   as:
		    suck.search();
		    int q;
		    cin >> q;
			   if((q<1) || (q>4))
			      {
			      cout << "wrong choice";
			      goto as;
			      }
			   if(q==1)
			     {
			     gotoxy(10,4);
			     obj.intro();
			     gotoxy(10,3);
			     cout << "PLEASE INPUT SR.NO WHOSE DETAILS HAVE TO BE FOUND::";
			     char wes = 'n';
			     int sch2;
			     cin >> sch2;
			     ifstream fot;
			     fot.open("doc.dat");
			     fot.seekg(0);
			     fot.read((char*)&doct,sizeof(doctor));
			     while(fot)
				{

				   if(doct.code==sch2)
				   {
				    doct.show();

				    wes = 'y';
				   }
				  fot.read((char*)&doct,sizeof(doctor));
				}
			     if (wes == 'n')
				{
				gotoxy(10,10);
				cout << "RECORD NOT FOUND ";
				}

			     fot.close();


			     }
			   if (q==2)
			     {
			     gotoxy(10,4);
			     obj.intro();
			     gotoxy(10,3);
			     cout << "PLEASE INPUT NAME WHOSE DETAILS HAVE TO BE FOUND::";
			     char wese2 = 'n';
			     int ptr;
			     char namee2[45];
			     gets(namee2);
			     ifstream fot;
			     fot.open("doc.dat");
			     fot.seekg(0);
			     fot.read((char*)&doct,sizeof(doctor));

			     while(fot)
				{
				 ptr = strcmp(doct.namedoc,namee2);
				 if (ptr== 0)

				   {
				    doct.show();
				    wese2 = 'y';
				    break;
				   }
				  fot.read((char*)&doct,sizeof(doctor));
				}
			     if (wese2 == 'n')
				{
				gotoxy(10,10);
				cout << "RECORD NOT FOUND ";
				}

			     fot.close();


			     }
			   if (q==3)
			     {
			     goto d;
			     }
			   if (q==4)
			     {
			     goto k;
			     }
		    getchar();
		    goto d;

		   }
	     case 2:
		   {
		    ifstream fout1;
		    fout1.open("doc.dat");
		    fout1.seekg(0);
		    fout1.read((char*)&doct,sizeof(doctor));
		    while(fout1)
		    {
		    doct.show();
		    fout1.read((char*)&doct,sizeof(doctor));
		    }
		    fout1.close();
		    goto d;
		   }
	     case 3:
		   {
		    obj.intro();
		    gotoxy(10,2);
		    cout << "INPUT SR.NO OF doctor::";
		    int ts;
		    cin >>ts;
		    ifstream fot;
		    ofstream fin;
		    fin.open("temp2.dat");
		    fot.open("doc.dat");
		    fot.seekg(0);
		    fot.read((char*)&doct,sizeof(doctor));
		    while(fot)
		      {
			if(doct.code==ts)
			   {
			    gotoxy(10,4);
			    doct.show();
			    cout << "OLD DETAILS ARE -----::::";

			    cout << "\n\n YOU NEED TO INPUT NEW DETAILS.PRESS A KEY TO PROCEED";
			    clrscr();
			    obj.intro();


			    doct.newdoctor();
			    gotoxy(35,5);
			    cout << "                         ";			    gotoxy(35,5);
			    cout << "NEW DETAILS";
			    gotoxy(35,6);
			    cout << "-----------";
			    fin.write((char*)&doct,sizeof(doctor));
			   }
			else
			   {
			   fin.write((char*)&doct,sizeof(doctor));
			   }

			fot.read((char*)&doct,sizeof(doctor));
		       }
		    fot.close();
		    fin.close();
		    ofstream foto;
		    ifstream fito;
		    foto.open("doc.dat");
		    fito.open("temp2.dat");
		    fito.read((char*)&doct,sizeof(doctor));
		    while(fito)
		      {
		       foto.write((char*)&doct,sizeof(doctor));
		       fito.read((char*)&doct,sizeof(doctor));
		      }
		    fito.close();
		    foto.close();
		    goto d;
		   }
	     case 4:
		   {
		    ofstream fout;
		    fout.open("doc.dat",ios :: app);
		    char ans='y';
		    while (ans == 'y')
		    {
		    doct.newdoctor();
		    fout.write((char*)&doct,sizeof(doctor));
		    cout << "do you wish to add more";
		    cin >> ans;
		    }
		    fout.close();
		   goto d;

		   }
	     case 5:
		    {
		    obj.intro();
		    gotoxy(10,2);
		    cout << "INPUT SR.NO OF PATIENT::";
		    int tp;
		    char qwer='n';
		    cin >>tp;
		    ifstream fot;
		    ofstream fin;
		    fin.open("temp2.dat");
		    fot.open("doc.dat");
		    fot.seekg(0);
		    fot.read((char*)&doct,sizeof(doctor));
		    while(fot)
		      {
			if(doct.code==tp)

			   {

			   qwer='y';
			   gotoxy(10,10);
			   cout << "record has been found deletion in progress.........";
			   goto j;
			   }
			else
			   {
			   fin.write((char*)&doct,sizeof(doctor));
			   }
			j:
			fot.read((char*)&doct,sizeof(doctor));
		       }
		    fot.close();
		    fin.close();
		    if (qwer=='n')
		       {
			gotoxy(10,15);
			cout << "record not found";
			getchar();
			goto d;
			}
		    ofstream foto;
		    ifstream fito;
		    foto.open("doc.dat");
		    fito.open("temp2.dat");
		    fito.read((char*)&doct,sizeof(doctor));
		    while(fito)
		      {
		       foto.write((char*)&doct,sizeof(doctor));
		       fito.read((char*)&doct,sizeof(doctor));
		      }
		    fito.close();
		    foto.close();

		    goto d;
		    }
	     case 6:
		   {
		   }
	   }
	l:
	goto k;
	}

   case 4:
	{
	 obj.intro();
	 char q[25];
	 gotoxy(10,8);
	 cout << "YOU HAVE OPTED TO ACCESS CLASSIFIED HOSPITAL INFORMATION";
	 gotoxy(10,10);
	 cout << "TO GAIN ACCESS YOU MUST PROVIDE ME WITH THE PASSWORD";
	 gotoxy(10,14);
	 cout << "PASSWORD---->>";
	 gets(q);
	 if (strcmp(q,"f")==0)
	     {
	     obj.intro();
	     gotoxy(25,2);
	     cout << "HOSPITAL INFORMATION";
	     gotoxy(25,3);
	     cout << "====================";
	     gotoxy(10,6);
	     cout << "IN THIS SECTION YOU CAN VIEW COMPLETE INFORMATION OF THE ";
	     gotoxy(10,7);
	     cout << "DOCTORS IN THE HOSPITAL ";
	     gotoxy(10,10);
	     cout << "Press  a  key  to  proceed";
	     getchar();
	     suck.search();
		    int q;
		    cin >> q;
			   if((q<1) || (q>4))
			      {
			      cout << "wrong choice";
			      goto as;
			      }
			   if(q==1)
			     {
			     gotoxy(10,4);
			     obj.intro();
			     gotoxy(10,3);
			     cout << "PLEASE INPUT SR.NO WHOSE DETAILS HAVE TO BE FOUND::";
			     char wes = 'n';
			     int sch2;
			     cin >> sch2;
			     ifstream fot;
			     fot.open("doc.dat");
			     fot.seekg(0);
			     fot.read((char*)&doct,sizeof(doctor));
			     while(fot)
				{

				   if(doct.code==sch2)
				   {
				    doct.show2();

				    wes = 'y';
				   }
				  fot.read((char*)&doct,sizeof(doctor));
				}
			     if (wes == 'n')
				{
				gotoxy(10,10);
				cout << "RECORD NOT FOUND ";
				}

			     fot.close();


			     }
			   if (q==2)
			     {
			     gotoxy(10,4);
			     obj.intro();
			     gotoxy(10,3);
			     cout << "PLEASE INPUT NAME WHOSE DETAILS HAVE TO BE FOUND::";
			     char wese2 = 'n';
			     int ptr;
			     char namee2[45];
			     gets(namee2);
			     ifstream fot;
			     fot.open("doc.dat");
			     fot.seekg(0);
			     fot.read((char*)&doct,sizeof(doctor));

			     while(fot)
				{
				 ptr = strcmp(doct.namedoc,namee2);
				 if (ptr== 0)

				   {
				    doct.show2();
				    wese2 = 'y';
				    break;
				   }
				  fot.read((char*)&doct,sizeof(doctor));
				}
			     if (wese2 == 'n')
				{
				gotoxy(10,10);
				cout << "RECORD NOT FOUND ";
				}

			     fot.close();


			     }
			   if (q==3)
			     {
			     goto d;
			     }
			   if (q==4)
			     {
			     goto k;
			     }
			    goto k;
	     }
	 else
	     {
	      cout << "\a";
	      obj.intro();
	      gotoxy(20,10);
	      cout << "SORRY WRONG PASSWORD";
	      getchar();
	      goto k;
	     }

	 }

   case 5:
	 {
	  obj.intro();
	  exit();
	  break;
	 }


}
p:

}












