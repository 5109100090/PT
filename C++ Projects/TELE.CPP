#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
		 ///////////////////////////
		 //  GLOBAL DECLARATIONS  //
		 ///////////////////////////
struct tel
{
   char name[20],addr[40],date[15],phone[10];
   int sno;
}trin;

struct record
{
   int call,gross,charges,rent,amount;
   char name[20],addr[40],date[15],phone[10];
}bill;

FILE  *fp,*fp1;

char l[60],ch;

void member();
void query();
void billy1();
void info();
void add();
void mod();
void del();
void disp();
void name();
void telephone();
void hosp();
void cine();
void rest();
void rail();
void air();
int dat(int dd,int mm,int yy);

void am(char zz[])
{
  int i;
  textcolor(2);
  textbackground(5);
  gotoxy(20,2);
  cprintf("%s",zz);
  textbackground(0);
  textcolor(4);
  for(i=0;i<=strlen(zz)+2;i++)
  {
    gotoxy(18+i,3);
    cprintf("%c",205);
  }
  textcolor(7);
  gotoxy(20,4);
}

/*Main Function Starts*/

void main()
{
   int c,n,date1,month1,year1;
   char ch,an,nam,tno[11],cno[5],b,*ph,str[20],str1[20];


/*Main Menu Program Module Starts*/
main1:
    while(1)
    {
       clrscr();
       ph="***M A I N - M E N U ***\n";
       am(ph);
       printf("\n\t\t1: -:- MEMBERS MANAGEMENT   \n ");
       printf("\n\t\t2: -:- QUERY   \n ");
       printf("\n\t\t3: -:- BILL-GENERATION   \n ");
       printf("\n\t\t4: -:- INFORMATION   \n ");
       printf("\n\t\tESC: -:- EXIT   \n ");
       printf("\n\n\t\t\t ENTER YOUR CHOICE  :");
       ch=getch();
       if(ch==27)
	  break;
       switch(ch)
       {
	  case '1':
		  member();
		  break;
	  case '2':
		  query();
		  break;
	  case '3':
		  billy1();
		  break;
	  case '4':
		  info();
		  break;
	  }
    }
end:
}
/*Main Menu Program Ends */



//MEMBER’S MANAGEMENT

/*Member Menu Program Module Starts*/
void member()
{
    char a,*ph;
    ph=" ***M E M B E R ' S  M A N A G E M E N T***\n ";
    while(1)
    {
	clrscr();
	am(ph);
	printf("\n\t\t 1: -:-ADDITION OF MEMBERS   \n");
	printf("\n\t\t 2: -:-MODIFICATION OF MEMBERS   \n");
	printf("\n\t\t 3: -:-DELETION OF MEMBERS   \n");
	printf("\n\t\t 4: -:-MEMBERS  LIST  \n");
	printf("\n\t\t ESC: -:-EXIT   \n");
	printf("\n\n  \t\t ENTER YOUR CHOICE  :");
	fflush(stdin);
	ch=getch();
	if(ch==27)
	    break;
	switch(ch)
	{
	    case '1':
		    add();
		    break;
	    case '2':
		    mod();
		    break;
	    case '3':
		    del();
		    break;
	    case '4':
		    disp();
		    break;
	    }
      }
} /* Member Menu Program Module Ends */



//ADDITION-MODULE

/*Addition Program Module Starts*/
void add()
{
    int aa,x,c;
    int day,mon,year,valid,phone;
    char *ph, *ph1,an,a,d[5],m[5],y[9];
    ph="***A D D I T I O N  O F  M E M B E R S ***";
tops0:
    clrscr();
    am(ph);
    fp=fopen("A.dat","ab+");


    printf("\nenter the name of the member:  ");
    gets(trin.name);
    printf("\nenter the address of the member:  ");
    gets(trin.addr);
ph:
    printf("\nenter the telephone no. of the member:  ");
    gets(trin.phone);
    phone=atoi(trin.phone);
    if(phone==0)
    {
       puts("enter corectly");
       goto ph;
    }
da:
    printf("\nenter the enrollment date of the member:  ");
    puts("enter day(1..31):  ");
    scanf("%d",&day);
    puts("enter month(1..12):  ");
    scanf("%d",&mon);
    puts("enter year(1980..2100):  ");
    scanf("%d",&year);
    valid=dat(day,mon,year);
    if(valid==0)
    {
       puts("enter correctly");
       goto da;
    }
    itoa(day,d,10);
    itoa(mon,m,10);
    itoa(year,y,10);
    strcpy(trin.date,d);
    strcat(trin.date,"/");
    strcat(trin.date,m);
    strcat(trin.date,"/");
    strcat(trin.date,y);

	printf("\n\n\n\t\t ALL ENTRIES CORRECT (Y/N)?");
	fflush(stdin);
	scanf("%c",&an);
	if(an=='y'||an=='Y')
	{
	   fp=fopen("A.dat","ab+");

	   fwrite(&trin,sizeof(struct tel), 1,fp);
	   clrscr();
	}
	printf("\n\n\n\n\n\n\n\t\t\tWANT TO ADD MORE (Y/N)?");
	fflush(stdin);
	an=getchar();
	if(an=='y'||an=='Y')
	{
	       fclose(fp);
	       goto tops0;
	 }
ende:
	fclose(fp);
   }

/*Addition  Program Module Ends */



//MODIFICATION -MODULE

/*Modification Program Module Starts*/

void mod()
{
    int mno,flag=1;
    int day,mon,year,valid,phone;
    char ans,an,nam,tno[8],a,mno1[10],d[5],m[5],y[9];
    char *ph;
    ph="***M O D I F I C A T I O N  O F  N U M B E R S***";
    fp=fopen("A.dat","rb+");

   if(fp==NULL)
    {
	printf("\nERROR IN FILE ");
	member();
    }
tops0:
    rewind(fp);
    clrscr();
    am(ph);
    printf("\n\n\n\t\t ENTER TELEPHONE NUMBER TO BE MODIFIED:");
    fflush(stdin);
    gets(mno1);

      while(fread(&trin,sizeof(struct tel),1,fp)==1)
      {
	    if(strcmp(mno1,trin.phone)==0)
	    {
	       printf("\n\t\t MEMBER'S NAME :%s\n",trin.name);
	       printf("\n\t\t MEMBER'S ADDRESS :%s\n",trin.addr);
	       printf("\n\t\t MEMBER'S ENROLLMENT-DATE :%s\n",trin.date);
	       printf("\n\n\t\t DO YOU WANT TO MODIFY PRESS (Y/N):");
	       flag=0;
	       fflush(stdin);
	       scanf("%c",&ans);
	       if(ans=='y'|| ans=='Y')
	       {
		  clrscr();
		  am(ph);
		  printf("\n\n\t\tTELEPHONE NUMBER TO BE MODIFIED : %s",mno1);
		  fflush(stdin);
		  printf("\nenter the new name of the member:  ");
		  gets(trin.name);
		  printf("\nenter the new address of the member:  ");
		  gets(trin.addr);
	       da:
		  printf("\nenter the new enrollment date of the member:  ");
		  puts("enter day(1..31):  ");
		  scanf("%d",&day);
		  puts("enter month(1..12):  ");
		  scanf("%d",&mon);
		  puts("enter year(1980..2100):  ");
		  scanf("%d",&year);
		  valid=dat(day,mon,year);
		  if(valid==0)
		    {
			puts("enter correctly");
			goto da;
		     }
		  itoa(day,d,10);
		  itoa(mon,m,10);
		  itoa(year,y,10);
		  strcpy(trin.date,d);
		  strcat(trin.date,"/");
		  strcat(trin.date,m);
		  strcat(trin.date,"/");
		  strcat(trin.date,y);
		}

	       printf("\n\n\n\t\t SAVE THE CHANGES (Y/N)?");
	       fflush(stdin);
	       scanf("%c",&a);
	       if(a=='y'||a=='Y')
	       {
		  fseek(fp,-sizeof(struct tel),SEEK_CUR);
		  fwrite(&trin,sizeof(struct tel),1,fp);
	       }
	       else
		   goto end;
	    }
	}
	if(flag)
	     puts("wrong input");
       fclose(fp);
end1:
	printf("\n\t\t\t\tWANT TO MODIFY MORE (Y/N)?");
	fflush(stdin);
	scanf("%c",&an);
	if(an=='y'||an=='Y')
	   goto tops0;
	else
	   goto end;
end:
}/*Modification Program Module Ends */


//DELETION-MODULE

/*Deletion Program Module Starts*/


void del()
{
   int mno,c,x,count,aa,flag=1;
   char ans,an,nam,tno[8],a,mno1[10];
   char *ph;
   ph="*** D E L E T I O N  O F  M E M B E R S ***";
tops0:
   fp=fopen("A.dat","rb+");
   if(fp==NULL)
   {
      printf("\nERROR IN FILE ");
      exit(0);
   }
   clrscr();
   am(ph);
   printf("\n\n\n\t\t ENTER TELEPHONE NUMBER TO BE DELETED:");
   gets(mno1);
   fp1=fopen("temp.dat","w");
   rewind(fp);
   while(fread(&trin,sizeof(struct tel),1,fp)==1)
   {
       if(strcmp(trin.phone,mno1)==0)
	   {
		   printf("\n \t\t\t -:- RECORD FOUND   \n");
		   printf("\n\t\t MEMBER'S ADDRESS :%s\n",trin.addr);
		   printf("\n\t\t MEMBER'S ENROLLMENT-DATE :%s\n",trin.date);
		   flag=0;
		   getch();
		   break;
	    }
    }
    if(flag)
    {
      puts("wrong input");
      getch();
      goto end;
    }

     printf("\n\n\n\t\t\t WANT TO DELETE ?");
     fflush(stdin);
     scanf("%c",&a);
     if(a=='y'|| a=='Y')
     {
	   rewind(fp);
	    while(fread(&trin,sizeof(struct tel),1,fp)==1)
	   {
		 if(strcmp(mno1,trin.phone)!=0)
		     fwrite(&trin,sizeof(struct tel),1,fp1);
	   }

	   fclose(fp);
	   fclose(fp1);

	   remove("A.dat");
	   rename("temp.dat","A.dat");
	   fp=fopen("A.dat","rb+");

	   printf("\t\t\tWANT TO DELETE MORE (Y/N)?");
	   fflush(stdin);
	   scanf("%c",&an);
	   if(an=='y'||an=='Y')
		goto tops0;
	   else
		goto end;

	}
end:
}/*Deletion Program Module Ends */


//DISPLAY-MODULE

/*Display Program Module Starts*/


void disp()
{
    int n=1,n3;
    char a,an[40],*ph;
    ph="*** List Of Members ***";
    clrscr();
    am(ph);
    fp=fopen("A.dat","ab+");
    if(fp!=NULL)
    {
	rewind(fp);
	n3=1;
	printf("\n\n\n\n");
	printf("\n Srno   NAME\t\t\tPHONEno.\t  ADDRESS\n\n\n");
	while(fread(&trin,sizeof(struct tel),1,fp)==1)
	{
	    strcat(trin.name," ");
	    printf(" %-7d%-24s%-17s %s\n",n,trin.name,trin.phone,trin.addr);
	    if(n3>=10)
	    {
		    printf("\n\t\t Press enter to scroll");
		    fflush(stdin);
		    getch();
		    n3=1;
		    clrscr();
		    am(ph);
		    printf("\n\n\n\n");
	    }
	    n++;
	    n3++;
	    fread(&trin,sizeof(struct tel),1,fp);
	}
    }
    if(feof(fp))
    printf("\n\n\t\t\t $$ No more records $$");
    fflush(stdin);
    getch();
    fclose(fp);
}/* Display Module Ends*/


/*Query Menu Starts*/
//QUERY-MENU

/*Query Menu Program Module Starts*/
void query()
{
   int n;
   char b, *ph;
   ph="***Q U E R Y ***";
   while(n!=3)
   {
	clrscr();
	am(ph);
	printf("\n\t\t 1: -:- NAME-WISE  \n");
	printf("\n\t\t 2: -:- TELEPHONE-WISE  \n");
	printf("\n\t\t ESC: -:- EXIT  \n");
	printf("\n\n\n\t\t ENTER YOUR CHOICE  :");
	ch=getch();
	if(ch==27)
	   break;
	switch(ch)
	{
	   case '1':
		   name();
		   break;
	   case '2':
		   telephone();
		   break;
	   }
      }
}/*Query Menu Program Module Ends */



//QUERY-NAMEWISE

/*Namewise Query Program Module Starts*/
void name()
{
   char str[20],*ph,an;
   int flag=1,end,n=1;
   ph="***QUERY-NAMEWISE***";
tops0:
   clrscr();
   fp=fopen("A.dat","r");
   if(fp==NULL)
   {
      printf("\n ERROR IN FILE \n");
      exit(0);
   }
   rewind(fp);
   am(ph);
   printf("\n\n\t\tENTER THE NAME TO BE SEARCHED :");
   gets(str);
   while(fread(&trin,sizeof(struct tel),1,fp)==1)
   {
      if(strcmp(str,trin.name)==0)
      {

	 printf("\n \t\t\t -:- %d RECORD   \n",n);
	 printf("\n\n NAME\t\t\tPHONEno.\t  ADDRESS\n\n\n");
	 printf(" %-24s%-17s %s\n",trin.name,trin.phone,trin.addr);
	 fflush(stdin);
	 n++;
	 flag=0;
	 getch();
      }
   }

   if(flag)
   {
     printf("\ninvalid input");
     goto end1;
    }
end1:
   printf("\n\n\t\t\t WANT TO SEARCH MORE ? (Y/N)");
   fflush(stdin);
   an=getchar();
   if(an=='y'||an=='Y')
      goto tops0;
   else
      goto old;
old:
   fclose(fp);
}/*Namewise Query Program Module Ends*/



//QUERY-TELEPHONEWISE

/*Telephone No. Wise Query Program Module Starts*/
void telephone()
{
   char an,*ph,nam,tno[10];
   int mphone,flag=0,a=0,c;
   char mno1[10];
tops0:
   ph="***QUERY-TELEPHONEWISE***";
   a=0;
   clrscr();
   fp=fopen("A.dat","r");
   if(fp==NULL)
   {
      printf("\n ERROR IN FILE \n");
      exit(0);
   }
   rewind(fp);
   clrscr();
   am(ph);
   printf("\n\n\t\tENTER THE PHONE NO. TO BE SEARCHED :");
   gets(mno1);

   rewind(fp);
   fread(&trin,sizeof(struct tel),1,fp);
   while(!feof(fp))
     {
       if(strcmp(trin.phone,mno1)==0)
       {
	  flag=1;a=1;
	  printf("\n \t\t\t -:- RECORD EXISTS  \n");
	  printf("\n\n NAME\t\t\tPHONEno.\t  ADDRESS\n\n\n");
	  printf(" %-24s%-17s %s\n",trin.name,trin.phone,trin.addr);
	  printf("\n\n\n\t\t WANT TO SEARCH MORE ?(Y/N)");
	  fflush(stdin);
	  an=getchar();
	  if(an=='y'||an=='Y')
	  {
	       fclose(fp);
	       goto tops0;
	  }
	  else
		  goto old;
       }
       else
	 flag=0;

       fread(&trin,sizeof(struct tel),1,fp);

    if(flag==0)
	if(a==0)
    printf("\n\t  -:- NO SUCH RECORDS EXISTS!");
    printf("\n\n\t WANT TO SEARCH MORE ?");
    fflush(stdin);
    scanf("%c",&an);
    if(an=='y'||an=='Y')
    {
	fclose(fp);
	goto tops0;
    }
    else
	goto old;
  }
old:
  fclose(fp);
}
 /*Telephone No. Wise Program Module Ends*/
/*Query Menu Ends*/



/*Information Module Starts*/
//INFORMATION-MENU

/*Information Menu Program Module Starts*/
void info()
{
   int n;
   char b,*ph;
   ph="***INFORMATION***";
   while(1)
   {
      clrscr();
      am(ph);
      printf("\n\t\t 1: -:-HOSPITALS   \n");
      printf("\n\t\t 2: -:-CINEMAS  \n");
      printf("\n\t\t 3: -:-RESTAURENTS   \n");
      printf("\n\t\t 4: -:-RAILWAYS   \n");
      printf("\n\t\t 5: -:-AIRLINES   \n");
      printf("\n\t\t ESC: -:-EXIT   \n");
      printf("\n\n \t ENTER YOUR CHOICE :");
      fflush(stdin);
      ch=getch();
      if(ch==27)
	break;
      switch(ch)
      {
	 case '1':
		hosp();
		break;
	 case '2':
		cine();
		break;
	 case '3':
		rest();
		break;
	 case '4':
		rail();
		break;
	 case '5':
		air();
		break;
	 }
    }
}/*Information Menu Program Module Ends*/



//INFO-HOSPITALS

/*Information Hospitals Program Module Starts*/
void hosp()
{
   char a,*ph;
   clrscr();
   ph="******HOSPITALS******";
   am(ph);
   printf("\n");
   printf("\n\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
   printf("\n\t\tHOSPITAL NAMES              TELEPHONE NOS.");
   printf("\n\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
   printf("\n\t\tAIMS                                6561123");
   printf("\n\t\tDEEN DAYAL UPADHAYA      	    5410335");
   printf("\n\t\tHINDU RAO              	            5674895");
   printf("\n\t\tLNJP                     	    2345642");
   printf("\n\t\tBATRA HOSPITAL            	    2376453");
   printf("\n\t\tAPPOLLO HOSPITAL        	    6935676");
   printf("\n\t\tG.B.PANT                  	    5674895");
   printf("\n\t\tST.STEPHAN HOSPITAL                 6785678");
   printf("\n\t\tESCORTS HEART HOSPITAL              2511488");
   printf("\n\t\tHOLY FAMILY                         6785774");
   printf("\n\t\tGANGA RAM HOSPITAL                  5781839");
   printf("\n\t\tSAFDARJUNG HOSPITAL                 5468789");
   printf("\n\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
   getch();
}/*Information Hospitals Program Module Ends*/



//INFO-CINEMAS

/*Information Cinemas Program Module Starts*/
void cine()
{
   char a,*ph;
   ph="***CINEMA HALLS***";
   clrscr();
   am(ph);
   printf("\n\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
   printf("\n\t\t NAMES                        PHONE NO.");
   printf("\n\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
   printf("\n\t\t ALANKAR                      6831460");
   printf("\n\t\t CHANKYA                      4674009");
   printf("\n\t\t DELITE                       3272903");
   printf("\n\t\t GOLCHA                       3265192");
   printf("\n\t\t JANAK                        5551115");
   printf("\n\t\t NOVELTY                      2513152");
   printf("\n\t\t ODEON                        3322167");
   printf("\n\t\t PARAS                        6432828");
   printf("\n\t\t PRIYA                        6140048");
   printf("\n\t\t REGAL                        3362245");
   printf("\n\t\t RIVOLI                       3362227");
   printf("\n\t\t SHIELA                       7772100");
   printf("\n\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
   getch();
}/*Information Cinema Program Module Ends */



//INFO-RESTAURENTS

/*Information Restaurents Program Module Starts*/
void rest()
{
   char a,*ph;
   clrscr();
   ph="******RESTAURENTS******";
   am(ph);
   printf("\n");
   printf("\n\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
   printf("\n\t\tRESTAURENT NAMES                TELEPHONE NOS.");
   printf("\n\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
   printf("\n\t\tDELHI DARBAR                    5101668");
   printf("\n\t\tVIKAS                           5460006");
   printf("\n\t\tKUMAR                           5465009");
   printf("\n\t\tPUNJABI RASOI                   5415356");
   printf("\n\t\tCHANAKYA                        5104106");
   printf("\n\t\tASKA                            5439684");
   printf("\n\t\tCOFFEE HOME                     5426575");
   printf("\n\t\tCOFFEE SHOP                     5673867");
   printf("\n\t\tANGAN                           5460078");
   printf("\n\t\tDEGCHI                          5453787");
   printf("\n\t\tCHINESE CORNER                  5476854");
   printf("\n\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
   getch();
}/*Information Restaurents Program Module Ends*/



//INFO-RAILWAYS

/*Information Railways Program Module Starts*/
void rail()
{
   char a,*ph;
   clrscr();
   ph="******RAILWAYS******";
   am(ph);
   printf("\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
   printf("\n\t\t RAILWAYS ENQUIRY           TELEPHONE NOS.");
   printf("\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
   printf("\n\t\t IN ENGLISH                 131");
   printf("\n\t\t IN HINDI                   1335");
   printf("\n\t\t RESERVATION                3348686");
   printf("\n\t\t ENQUIRY                    3348787");
   printf("\n\t\t TRAIN RUNNING              366162");
   printf("\n\t\t POSITION                   3366177");
   printf("\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
   printf("\n\n\t ********** COMPUTERISED ANSWERING MACHINE **********");
   printf("\n\n\t PANIPAT/SRINAGAR/MERRUT/ETC                1331");
   printf("\n\t GUHAWATI/WEST BENGAL/CALCUTTA/ETC          1332");
   printf("\n\t MUMBAI/PUNE/GOA/ETC			    1333");
   printf("\n\t BANGALORE/CHENNAI/KERALA		    1334");
   getch();
}/*Information Railways Program Module Ends*/



//INFO-AIRLINES

/*Information Airlines Program Module Starts*/
void air()
{
   char a,*ph;
   clrscr();
   ph="******AIRLINES ENQUIRIES AND FLIGHT INFORMATION******";
   am(ph);
   printf("\n");
   printf("\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
   printf("\n\tAIRLINE ENQUIRIES & AIRPORT          TELEPHONE NOS.");
   printf("\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
   printf("\n\n\tAIR INDIA                            3731225,5652050");
   printf("\n\tINTERNATIONAL BOOKINGS               3736446");
   printf("\n\tDOMESTIC BOOKINGS                    3736447");
   printf("\n\tCANCELLATION                         3736449");
   printf("\n\tINDIAN AIRLINES                      5665121,5663565");
   printf("\n\tINTERNATIONAL AIRPORT                5642011,5642021");
   printf("\n\tPALAM AIRPORT                        5966535,5965121");
   printf("\n\tGENERAL ENQUIRY                      140");
   printf("\n\tTELE RESERVATION                     141");
   printf("\n\tRECORD INFORMATION                   142");
   printf("\n\tARRIVAL                              144");
   printf("\n\tDEPARTURE                            145");
   printf("\n");
   printf("\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
   getche();
}/*Information Airlines Program Module Ends*/


//VALIDATION -MODULE



//BILL-GENERATION

/*Bill Generation Program Module Starts*/
void billy1()
{
   int free=150,calls,flag,rent=250,netcalls;
   char a,*ph,pno[10];
   fp=fopen("a.dat","r");
   clrscr();
   ph="*** BILL GENERATION ***";
   if(fp==NULL)
   {
      printf("\n ERROR IN FILE ");
      exit(0);
   }
   am(ph);
   printf("\n\n\t\tENTER PHONE NUMBER TO GENERATE THE BILL : ");
   gets(pno);
   fread(&trin,sizeof(struct tel),1,fp);
   while(!feof(fp))
   {
      if(strcmp(trin.phone,pno)==0)
      {
	 flag=1;
	 clrscr();
	 am(ph);
	 printf("\n\n\t\t MEMBERS'S PHONE -NO. :%s\n",trin.phone);
	 printf("\n\t\t MEMBERS'S NAME. :%s\n",trin.name);
	 printf("\n\t\t MEMBERS'S ADDRESS. :%s\n",trin.addr);
	 printf("\n\t\t MEMBERS'S ENROLLMENT-DATE. :%s\n",trin.date);
	 printf("\n\t\t\tENTER NO. OF CALLS :");
	 fflush(stdin);
	 scanf("%d",&calls);
	 break;
      }
      else
      {
	    flag=0;
	    fread(&trin,sizeof(struct tel),1,fp);
      }
    }
    if(flag==0)
    {
	printf("\n\n\n\n\t\tRecord Not Found");
	printf("\n\t...press enter to continue ...");
	fflush(stdin);
	getch();
    }
    else
    {
	if(calls<=150)
	   netcalls=0;
	else
	   netcalls=calls-free;
	clrscr();
	am(ph);
	printf("\n\n");
	printf("\n---------------------------------------------------------------------------");
	printf(" \n\t\t    Member's Enrollment-Date: %s",trin.date);
	printf("\n|                                                                         |");
	printf("\t       Phone-No: %d",trin.phone);
	printf("\n|                                                                         |");
	printf("\n\t  Member's Address: %s",trin.addr);
	printf("\n|                                                                         |");
	printf("\n     Total Calls made: %d",calls);
	printf("    Free Calls: %d",free);
	printf("    Net Chargable Calls: %d",netcalls);
	printf("\n|                                                                         |");
	printf("\n\t  Call Charges @rs.3 per call :\t%d",netcalls*3);
	printf("\n|                                                                         |");
	printf("\n\t  Rent-Telephone:\t%d",rent);
	printf("\n|                                                                         |");
	printf("\n\t\t      -:-AMOUNT TO BE PAID :\t%d",(rent+netcalls*3));
	printf("\n|                                                                         |");
	printf("\n---------------------------------------------------------------------------");
	printf("\n\t...Generate More(y/n) : ");
	fflush(stdin);
	a=getchar();
	if(a=='y' || a=='Y')
	   billy1();
    }
fclose(fp);
} /*Bill Generation Program Module Ends*/


int dat(int dd,int mm,int yy)
{
  int days=0,valid=1;
  if((yy>1990)&&(yy<=2100))
     valid=1;
  else
  {
     valid=0;
     return(0);
  }
  switch(mm)
  {
       case 1:
       case 3:
       case 5:
       case 7:
       case 8:
       case 10:
       case 12:
		 days=31;
		 break;
       case 2:
		    if(yy%4==0)
		       days=29;
		    else
			  days=28;
		    break;
       case 4:
       case 6:
       case 9:
       case 11:
		 days=30;
		 break;
       default:
			       valid=0;
   }
   if((dd>0)&&(dd<=days))
       valid=1;
   else
       valid=0;
   return(valid);
}