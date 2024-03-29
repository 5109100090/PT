// function decleration for the search phone information

void search_object()
{
	fstream file;
	unsigned long rec;
	long  phno = 0, faxno = 0, mail = 0;
	char name[20];
	int ch;

	do
	{
		clrscr();
		int count = 0;
		box(10, 5, 67, 20);
		gotoxy(21, 7);
		cout << "\t SEARCH MENU";
		gotoxy(20, 8);
		cout << "===============================";
		gotoxy(20, 10);
		cout << "1. RECORD ID. NO. ";
		gotoxy(20, 11);
		cout << "2. NAME  ";
		gotoxy(20, 12);
		cout << "3. PHONE NO. ";
		gotoxy(20, 13);
		cout << "4. FAX NO. ";
		gotoxy(20, 14);
		cout << "5. E-MAIL NO.";
		gotoxy(20, 15);
		cout << "6. EXIT ";
		gotoxy(20, 17);
		cout << "Enter The Field To Search..........";
		gotoxy(20, 60);
		cin >> ch;
		switch (ch)
		{
			case 1:
				clrscr();
				gotoxy(20, 15);
				cout << "Enter The Record Id to Search........";
				gotoxy(20, 60);
				cin >> rec;
				file.open(pa2, ios::in);
				file.seekg(0, ios::beg);
				file.read((char *)&pers, sizeof(pers));

				while (!file.eof())
				{
					if (pers.record_id == rec)
					{
						count++;
						show_data();
						getch();
					}
					file.read((char *)&pers, sizeof(pers));

			}
			file.close();
			gotoxy(24, 23);
			cout << "Records Found =" << count;
			getch();
			break;

		case 2:
			��r1�0��������gp�y��pxC< �@    @  �y�zy9y�{      ��  ��v   �����               $'�p�Cm��{ �f���'HJF7��[x����,�  D $'' � �@�� �<|�  DȀ�$'' � �H���<8�8�L�$�x�HD�@ � �8x�HD$#�;
			while (!file.eof())
			{
				if ((strcmpi(name,pers.person_name)) == 0)
				{
					count++;
					show_data();
					getch();
				}
				file.read((char *)&pers, sizeof(pers));
			}
			file.close();
			gotoxy(24, 23);
			cout << "Records Found =" << count;
			getch();
			break;
		case 3:
			clrscr();
			gotoxy(20, 15);
			cout << "Enter The Phone NO.  to Search........";
			gotoxy(20, 60);
			cin >> phno;
			file.open(pa2, ios::in);
			file.seekg(0, ios::beg);
			file.read((char *)&pers, sizeof(pers));
			while (!file.eof())
			{
				if (pers.off_phone1 == phno || pers.off_phone2 == phno || pers.res_phone1 == phno)
				{
					count++;
					show_data();
					getch();
				}
				file.read((char *)&pers, sizeof(pers));

			}
			file.close();
			gotoxy(24, 23);
			cout << "Records Found =" << count;
			getch();
			break;

		case 4:
			clrscr();
			gotoxy(20, 15);
			cout << "Enter The Fax.No. to Search........";
			gotoxy(20, 60);
			cin >> faxno;
			file.open(pa2, ios::in);
			file.seekg(0, ios::beg);
			file.read((char *)&pers, sizeof(pers));
			while (!file.eof())
			{
				if (pers.off_fax_no == faxno)
				{
					count++;
					show_data();
					getch();
				}
				file.read((char *)&pers, sizeof(pers));

			}
			file.close();
			gotoxy(24, 23);
			cout << "Records Found =" << count;
			getch();
			break;
		case 5:
			clrscr();
			gotoxy(20, 15);
			cout << "Enter The  E-Mail  to Search........";
			gotoxy(20, 60);
			cin >> mail;
			file.open(pa2, ios::in);
			file.seekg(0, ios::beg);
			file.read((char *)&pers, sizeof(pers));
			while (!file.eof())
			{
				if (pers.e_mail_no == mail)
				{
					count++;
					show_data();
					getch();
				}
				file.read((char *)&pers, sizeof(pers));
			}
			file.close();
			gotoxy(24, 23);
			cout << "Records Found =" <<count;
			getch();
			break;
		case 6:
			clrscr();
			break;

		}
	} while(ch != 6);
}

// Function for the modification of telephone record
void modify_object()
{
	fstream file;
	unsigned long rec;
	char ans;
	clrscr();
	gotoxy(20, 15);
	cout << "Enter The Record Id to Modify........";
	gotoxy(53, 15);
	cin >> rec;
	file.open(pa2, ios::in|ios::out);
	file.seekg(0, ios::beg);
	file.read((char *)&pers, sizeof(pers));
	int n = file.tellg();
	while (!file.eof())
	{
		if (pers.record_id == rec)
		{
			show_data();
			gotoxy(20, 23);
			cout << "Want to Update this Record......";
			gotoxy(53, 23);
			cin >> ans;

			if (ans == 'y' || ans == 'Y')
			{
				cout << "Modified value" << endl;
				show_data();
				getch();

				file.seekg(n - sizeof(pers), ios::beg);
				mod_data(rec);
				file.write((char *)&pers, sizeof(pers));
				file.flush();
				break;
			}
			else
			{
				file.close();
				return;
			}
		}
		file.read((char *)&pers, sizeof(pers));
		n = file.tellg();
	}
	file.close();
}

/*This function is used to sort the phone.dat data file according the name wise.
  Also the function uses the concept of linked list */
void ex_change()
{
	temp = new node;
	temp->pin = ptr2->pin;
	temp->recno = ptr2->recno;
	strcpy(temp->name, ptr2->name);

	strcpy(ptr2->name, ptr1->name);
	ptr2->pin = ptr1->pin;
	ptr2->recno = ptr1->recno;

	strcpy(ptr1->name, temp->name);
	ptr1->pin = temp->pin;
	ptr1->recno = temp->recno;
	delete temp;
}

// This function makes index of all the records from the data base file to a linked list of primary memory, which holds all the records for further display operation
void make_index()
{
	fstream infile;
	first = new node;
	ptr = first;
	infile.open(pa2, ios::in);
	infile.seekg(0, ios::beg);
	infile.read((char *)&pers, sizeof(pers));

	while (!infile.eof())
	{
		ptr->recno = pers.record_id;
		ptr->pin = pers.res_pincode;
		strcpy(ptr->name, pers.person_name);
		ptr->link = new node;
		ptr = ptr->link;
		infile.read((char *)&pers, sizeof(pers));
	}
	ptr->link = NULL;
	infile.close();
}

//	This fuction sorts name of telephone customers with the help
//  of ex_change() function
void sort_name()
{
	make_index();  //call make index function

	for(ptr1 = first; (ptr1); ptr1 = ptr1->link)
	{
		for(ptr2 = ptr1->link; (ptr2); ptr2 = ptr2->link)
		{
			if (strcmpi(ptr2->name, ptr1->name) < 0)
				ex_change();
		}
	}
}

// This function sorts records according to id. no wise with the help
// of ex_change() function
void sort_recno()
{
	make_index();  //call make index function;

	for(ptr1 = first; (ptr1); ptr1 = ptr1->link)
	{
		for(ptr2 = ptr1->link; (ptr2); ptr2 = ptr2->link)
		{
			if(ptr2->recno < ptr1->recno)
				ex_change();
		}
	}

}

// This function sorts records according to pincode wise with the help
// of ex_change() function
void sort_pin()
{

	 make_index();  //call make index function
	for(ptr1 = first;ptr1 != NULL;ptr1 = ptr1->link)
	{
		for(ptr2 = ptr1->link;ptr2 != NULL; ptr2 = ptr2->link)
		{
			if(ptr2->pin < ptr1->pin)
				ex_change();
		}
	}
}

// This function prints sorted record on the screen with the help
// of show_data() function
void sort_print()
{
	fstream infile;
	ptr = first;
	while (ptr != NULL)
	{
		infile.open(pa2, ios::in);
		infile.seekg(0, ios::beg);
		infile.read((char *)&pers, sizeof(pers));

		while (!infile.eof())
		{
			if(ptr->recno == pers.record_id)
			{
				show_data();
				getch();
				infile.seekg(0, ios::end);

			}
			infile.read((char *)&pers, sizeof(pers));
		}

		infile.close();
		ptr = ptr->link;
	}
}

// The function is used to delete a linked node from main memory
void del_index()
{
	while (first != NULL)
	{
		ptr = first;
		first = first->link;
		delete ptr;
	}
}

/* This function is used to list out the records on different
   way of sorting order. */
void sort_object()
{
	int ch;

	do
	{
		clrscr();
		box(10, 5, 67, 20);
		gotoxy(21, 7);
		cout << "\t SORT MENU";
		gotoxy(20, 8);
		cout << "===============================";
		gotoxy(20, 12);
		cout << "1. SORTED RECORD ID.  ";
		gotoxy(20, 13);
		cout << "2. SORTED NAME  ";
		gotoxy(20, 14);
		cout << "3. SORTED PINCODE  NO. ";
		gotoxy(20, 15);
		cout << "4. EXIT ";
		gotoxy(20, 18);
		cout << "Enter Your Choice.........";
		gotoxy(20, 60);
		cin >> ch;

		switch (ch)
		{
			case 1:
				clrscr();
				sort_recno();
				sort_print();
				del_index();
				delay(200);
				break;
			case 2:
				clrscr();
				sort_name();
				sort_print();
				del_index();
				delay(200);
				break;
			case 3:
				clrscr();
				sort_pin();
				sort_print();
				del_index();
				delay(200);
				break;
			case 4:
				clrscr();
				break;
		}
	} while(ch != 4);
}

/* This function is used to generate different reports as:
	1. LIST OF NAMES  RESISDANCE & OFFICE  PHONE NO.
	2. LIST OF NAMES  OFFICE ADDRESS & PHONE NO.
	3. LIST OF NAMES RECORDS NOS. &  RESIDENTIAL ADDRESS
on screen. */

void reports()
{
	fstream infile;
	int ch;
	do
	{
		clrscr();
		box(10, 5, 71, 20);
		gotoxy(24, 7);
		cout << "\t REPORT MENU";
		gotoxy(23, 8);
		cout << "===============================";
		gotoxy(15, 12);
		cout << "1. LIST OF NAMES  RESIDENCE & OFFICE  PHONE NO. ";
		gotoxy(15, 13);
		cout << "2. LIST OF NAMES  OFFICE ADDRESS & PHONE NO.  " ;
		gotoxy(15, 14);
		cout << "3. LIST OF NAMES RECORD NOS. &  RESIDENTIAL ADDRESS  ";
		gotoxy(15, 15);
		cout << "4. EXIT ";
		gotoxy(22, 18);
		cout << "Enter Your Choice.........";
		gotoxy(20, 60);
		cin >> ch;

		switch (ch)
		{
			case 1 :
				clrscr();
				cout << "\n     NAME             RESIDENCE PHONE NO.         OFFICE PHONE NO.";
				cout << "\n--------------------------------------------------------------------";

				infile.open(pa2, ios::in);
				infile.seekg(0, ios::beg);
				// Reads file from begining

				infile.read((char *)&pers, sizeof(pers));
				cout << endl;
				while (!infile.eof())
				{
					cout << setiosflags(ios::left)
					<< setw(28) << pers.person_name
					<< setw(30) << pers.res_phone1
					<< setw(30) << pers.off_phone1
					<< endl;
					infile.read((char *)&pers, sizeof(pers));
				}
				infile.close();
				gotoxy(20, 24);
				cout << "Press any key to continue........";
				getch();
				break;
			case 2:
				clrscr();
				cout << "\n  NAME                COMPANY NAME           OFFICE PHONE1             ";
				cout << "\n------------------------------------------------------------------";
				infile.open(pa2, ios::in);
				infile.seekg(0, ios::beg);

				// Reads file from begining
				infile.read((char *)&pers, sizeof(pers));

				while (!infile.eof())
				{
					cout << "\n";
					cout << setiosflags(ios::left)
						<< setw(20) << pers.person_name
						<< setw(25) << pers.company_name
						<< setw(20) << pers.off_phone1;

					infile.read((char *)&pers, sizeof(pers));
				}
				infile.close();
				gotoxy(20, 24);
				cout<<"Press any key to continue.........";
				getch();
				break;

			case 3 :
				clrscr();
				int row = 4;
				cout<<"\n RECORDS NO.         PERSON  NAME               RES. ADDRESS     ";
				cout<<"\n------------------------------------------------------------------\n";
				infile.open(pa2, ios::in);
				infile.seekg(0, ios::beg);
				// Reads file from begining
				infile.read((char *)&pers, sizeof(pers));

				while (!infile.eof())
				{
					gotoxy(5, row);
					cout << pers.record_id;
					gotoxy(20, row);
					cout << pers.person_name;
					gotoxy(50, row);
					cout << pers.res_address;
					infile.read((char *)&pers, sizeof(pers));
					row++;
					// If display row greater than 23 then the row set to 4 again
					if (row >= 23)
					{
						cout << "Press any key to continue";
						getch();
						row = 4;
					}

				}
				infile.close();
				gotoxy(20, 24);
				cout << "Press any key to continue.........";
				getch();
				break;

			case 4:
				clrscr();
				break;
		}
	} while(ch != 4);
}