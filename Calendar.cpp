#include<stdio.h>
#include<time.h>
#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<ctype.h>
#include<graphics.h>
#include<fstream.h>
#include<stdlib.h>
#include<dos.h>
void today();
void mainscreen();
void dispcalendar();
void options();
void dispmonth();
int pass();
fstream file;
class event
{
	public:
	char month[10];
	int date;
	char name[200];
	void getdata(char [],int);
	void putdata();
	void modify();
	void Delete();
};
void event::getdata(char m[], int mn)
{
		strcpy(month,m);
		int dc = 0;
		while(dc == 0)
		{
			cout<<"Enter the date:";
			cin>>date;
			if(mn == 1 && date>=1 && date<=31)
			{
				dc =1;
				break;
			}
			else if(mn ==2 && date>=1 && date<=29)
			{
				dc = 1;
				break;
			}
			else if(mn == 3 && date >=1 && date<=31)
			{
				dc=1;
				break;
			}
			else if(mn == 4 && date>=1 && date<=30)
			{
				dc = 1;
				break;
			}
			else if(mn == 5 && date>=1 && date<=31)
			{
				dc = 1;
				break;
			}
			else if(mn == 6 && date>=1 && date<=30)
			{
				dc = 1;
				break;
			}
			else if(mn == 7 && date>=1 && date<=31)
			{
				dc = 1;
				break;
			}
			else if(mn == 8 && date>=1 && date<=31)
			{
				dc =1;
				break;
			}
			else if(mn == 9 && date>=1 && date<=30)
			{
				dc = 1;
				break;
			}
			else if(mn == 10 && date>=1 && date<=31)
			{
				dc = 1;
				break;
			}
			else if(mn == 11 && date>1 && date<=30)
			{
				dc = 1;
				break;
			}
			else if(mn == 12 && date>1 && date<=31)
			{
				dc = 1;
				break;
			}
			else
			{
				cout<<"INVALID DATE. ENTER AGAIN: "<<endl;
				dc = 0;
			}


		}
		cout<<"Enter event:";
		gets(name);
}
void event::putdata()
{
		cout<<"Month is:"<<month<<endl;
		cout<<"Date is:"<<date<<endl;
		cout<<"Event:"<<name<<endl;
}
void event::Delete()
{
	clrscr();
	event ev;
	cout<<"All Events"<<endl<<endl;
	fstream file("event.txt",ios::in|ios::binary);
	while(!file.eof())
	{
		file.read((char *)& ev, sizeof(ev));
		if(file.eof())
		break;
		ev.putdata();
	}
	file.close();

	char n[10];
	int md, dd;
	event e;
	fstream efile;
	fstream dfile;
	dm:
	cout<<"Enter the month to delete record:(1 to 12) ";
	cin>>md;
	if(cin.fail())
	  {
		cout<<"Invalid option entered!"<<endl;
		cin.clear();
		cin.ignore();
		delay(2000);
		clrscr();
		goto dm;

	  }
	ddate:
	cout<<"Enter the date to delete: ";
	cin>>dd;
	if(cin.fail())
	  {
		cout<<"Invalid option entered!"<<endl;
		cin.clear();
		cin.ignore();
		delay(2000);
		clrscr();
		goto ddate;

	  }
	if((md == 1) && (dd>=1) && (dd<=31))
		strcpy(n, "JANUARY");
	else if((md == 2) && (dd>=1) && (dd<=28))
		strcpy(n, "FEBRUARY");
	else if((md == 3) && (dd>=1) && (dd<=31))
		strcpy(n,"MARCH");
	else if((md == 4) && (dd>=1) && (dd<=30))
		strcpy(n, "APRIL");
	else if((md == 5) && (dd>=1) && (dd<=31))
		strcpy(n, "MAY");
	else if((md == 6) && (dd>=1) && (dd<=30))
		strcpy(n, "JUNE");
	else if((md == 7) && (dd>=1) && (dd<=31))
		strcpy(n, "JULY");
	else if((md == 8) && (dd>=1) && (dd<=31))
		strcpy(n,"AUGUST");
	else if((md == 9) && (dd>=1) && (dd<=30))
		strcpy(n,"SEPTEMBER");
	else if((md == 10)&& (dd>=1) && (dd<=31))
		strcpy(n,"OCTOBER");
	else if((md == 11)&&(dd>=1) && (dd<=30))
		strcpy(n, "NOVEMBER");
	else if((md == 12)&&(dd>=1) && (dd<31))
		strcpy(n,"DECEMBER");
	else
		cout<<"INVALID ENTRY. CANNOT DELETE THE RECORD. ";

	dfile.open("new.dat",ios::out|ios::binary);
	efile.open("event.txt",ios::in|ios::binary);
	if(!efile)
	{
		cout<<"File not found";
		exit(0);
	}
	else
	{
		int found=0;
		efile.read((char *) &e, sizeof(e));
		while(!efile.eof())
		{
			if(dd == e.date && strcmp(n, e.month)==0 )
			{
				found=1;
				cout<<"Press any key...:"<<endl;
				getch();
			}
			else
			{
				dfile.write((char *)&e, sizeof(e));
			}
			efile.read((char *)&e,sizeof(e));
		}
		if(found==0)
			cout<<" Event not found."<<endl;
		else
			cout<<"Event Deleted."<<endl;
	}
	dfile.close();
	efile.close();
	remove("event.txt");
	rename("new.dat", "event.txt");
}

void event::modify()
{
	clrscr();
	/*event e1;
	cout<<"All Events"<<endl<<endl;
	fstream file("event.txt",ios::in|ios::binary);
	while(!file.eof())
	{
		file.read((char *)& e1, sizeof(e1));
		if(file.eof())
		break;
		e1.putdata();
	}
	file.close();
	*/
	char mm[50];
	strcpy(mm,month);
	int dd=date;
	cout<<"Event being modified:"<<endl;
	cout<<"Month:"<<month<<endl;
	cout<<"Date:"<<date<<endl;
	cout<<"Event:"<<name<<endl<<endl;
	cout<<"Enter new details:"<<endl;
	char ev[30];
	int mon,day,temp=0;
	cout<<"New month(press'0' to retain old one)"<<endl;
	cin>>mon;
	cout<<"New date(press '0' to retain old one)"<<endl;
	cin>>day;
	cout<<"New event name(press '0' to retain old one)"<<endl;
	gets(ev);
	if(mon!=0)
	{
		if((mon == 1) && (day>=0) && (day<=31))
			strcpy(month, "JANUARY");
		else if((mon == 2) && (day>=0) && (day<=28))
			strcpy(month, "FEBRUARY");
		else if((mon == 3) && (day>=0) && (day<=31))
			strcpy(month, "MARCH");
		else if((mon == 4) && (day>=0) && (day<=30))
			strcpy(month, "APRIL");
		else if((mon == 5) && (day>=0) && (day<=31))
			strcpy(month, "MAY");
		else if((mon == 6) && (day>=0) && (day<=30))
			strcpy(month, "JUNE");
		else if((mon == 7) && (day>=0) && (day<=31))
			strcpy(month, "JULY");
		else if((mon == 8) && (day>=0) && (day<=31))
			strcpy(month,"AUGUST");
		else if((mon == 9) && (day>=0) && (day<=30))
			strcpy(month,"SEPTEMBER");
		else if((mon == 10)&& (day>=0) && (day<=31))
			strcpy(month,"OCTOBER");
		else if((mon == 11)&& (day>=0) && (day<=30))
			strcpy(month, "NOVEMBER");
		else if((mon == 12)&& (day>=0) && (day<=31))
			strcpy(month,"DECEMBER");
		else
		{
			temp=1;
			cout<<"INVALID ENTRY."<<endl;
			cout<<"RETAINING OLD DETAILS."<<endl;
			strcpy(month,mm);
			date=dd;
		}
	}
	if(day!=0&&temp!=1)
	{
		date=day;
	}
	if(strcmp(ev,"0")!=0&&temp!=1)
	{
		strcpy(name,ev);
	}
}

void main()
{
   clrscr();
   mainscreen();
   today();
   dispcalendar();
   getch();
   clrscr();
   today();
   options();
}
void today()
{
   time_t t;
   time(&t);
   textcolor(WHITE);
   cout<<"\t \t Today's date and time: "<<ctime(&t);

}
void options()
{
	clrscr();
	today();
	cout<<'\a';
	//setbkcolor(BLUE);
	int o;
	textcolor(GREEN);
	cputs("                          \t  \t  \t  YEAR PLANNER 2016  \t  \t  \t");
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"1.Enter a Month"<<endl;
	cout<<endl;
	cout<<"2.List of Holidays and Festivals"<<endl;
	cout<<endl;
	cout<<"3.Task Manager"<<endl;
	cout<<endl;
	cout<<"4.Back to Calender"<<endl;
	cout<<endl;
	cout<<"5.Quit"<<endl;
	cin>>o;
	switch(o)
	{
	case 1:
	dispmonth();
	cout<<"Press any key to go back to main menu..."<<endl;
	getch();
	today();
	options();
	break;
	case 2:
	ifstream fin("Holiday.txt");
	char ch[50];
	clrscr();
	if(!fin)
	{
		cout<<"FILE NOT FOUND: "<<endl;
		exit(0);
	}
	textcolor(WHITE);
	while(!fin.eof())
	{
		fin.getline(ch,50);
		if(strcmp(ch,"MONTH")!=0)
		cout<<ch<<endl;
		else
		getch();
	}
	fin.close();
	cout<<"Press any key to go back to main menu..."<<endl;
	getch();
	today();
	options();
	break;
	case 3:
	clrscr();
	char yesno;
	int mno,op,count=1;
	do
	{
	menu:
	clrscr();
	cout<<"				WELCOME TO THE TASK MANAGER"<<endl<<endl;
	cout<<"Choose an option:"<<endl<<endl;
	cout<<"1.Add an event"<<endl<<endl;
	cout<<"2.View all events"<<endl<<endl;
	cout<<"3.Delete an event"<<endl<<endl;
	cout<<"4.Modify an event"<<endl<<endl;
	cout<<"5.Go back to Main Menu"<<endl<<endl;
	cout<<"6.Quit"<<endl<<endl;
	cin>>op;
	if(cin.fail())
	  {
		cout<<"Invalid option entered!"<<endl;
		cin.clear();
		cin.ignore();
		delay(2000);
		clrscr();
		goto menu;

	  }
	event e;
	if(op==1)
	{
		fstream efile;
		dam:
		cout<<"Enter Month Number:(1 to 12)"<<endl;
		cin>>mno;
		if(cin.fail())
	  {
		cout<<"Invalid option entered!"<<endl;
		cin.clear();
		cin.ignore();
		delay(2000);
		clrscr();
		goto dam;

	  }
		switch(mno)
		{
			case 1:
			efile.open("event.txt",ios::in|ios::out|ios::ate|ios::binary);
			cout<<"Enter Details:"<<endl;
			e.getdata("JANUARY", mno);
			efile.write((char *)& e,sizeof(e));
			efile.close();
			break;
			case 2:
			efile.open("event.txt",ios::in|ios::out|ios::ate|ios::binary);
			cout<<"Enter Details:"<<endl;
			e.getdata("FEBRUARY", mno);
			efile.write((char *)& e,sizeof(e));
			efile.close();
			break;
			case 3:
			efile.open("event.txt",ios::in|ios::out|ios::ate|ios::binary);
			cout<<"Enter Details:"<<endl;
			e.getdata("MARCH", mno);
			efile.write((char *)& e,sizeof(e));
			efile.close();
			break;
			case 4:
			efile.open("event.txt",ios::in|ios::out|ios::ate|ios::binary);
			cout<<"Enter Details:"<<endl;
			e.getdata("APRIL",mno);
			efile.write((char *)& e,sizeof(e));
			efile.close();
			break;
			case 5:
			efile.open("event.txt",ios::in|ios::out|ios::ate|ios::binary);
			cout<<"Enter Details:"<<endl;
			e.getdata("MAY", mno);
			efile.write((char *)& e,sizeof(e));
			efile.close();
			break;
			case 6:
			efile.open("event.txt",ios::in|ios::out|ios::ate|ios::binary);
			cout<<"Enter Details:"<<endl;
			e.getdata("JUNE",mno);
			efile.write((char *)& e,sizeof(e));
			efile.close();
			break;
			case 7:
			efile.open("event.txt",ios::in|ios::out|ios::ate|ios::binary);
			cout<<"Enter Details:"<<endl;
			e.getdata("JULY",mno);
			efile.write((char *)& e,sizeof(e));
			efile.close();
			break;
			case 8:
			efile.open("event.txt",ios::in|ios::out|ios::ate|ios::binary);
			cout<<"Enter Details:"<<endl;
			e.getdata("AUGUST",mno);
			efile.write((char *)& e,sizeof(e));
			efile.close();
			break;
			case 9:
			efile.open("event.txt",ios::in|ios::out|ios::ate|ios::binary);
			cout<<"Enter Details:"<<endl;
			e.getdata("SEPTEMBER",mno);
			efile.write((char *)& e,sizeof(e));
			efile.close();
			break;
			case 10:
			efile.open("event.txt",ios::in|ios::out|ios::ate|ios::binary);
			cout<<"Enter Details:"<<endl;
			e.getdata("OCTOBER",mno);
			efile.write((char *)& e,sizeof(e));
			efile.close();
			break;
			case 11:
			efile.open("event.txt",ios::in|ios::out|ios::ate|ios::binary);
			cout<<"Enter Details:"<<endl;
			e.getdata("NOVEMBER",mno);
			efile.write((char *)& e,sizeof(e));
			efile.close();
			break;
			case 12:
			efile.open("event.txt",ios::in|ios::out|ios::ate|ios::binary);
			cout<<"Enter Details:"<<endl;
			e.getdata("DECEMBER",mno);
			efile.write((char *)& e,sizeof(e));
			efile.close();
			break;
			default:
			cout<<"SUCH A MONTH DOESN'T EXIST."<<endl;
			break;
		}
	}
	else if(op==2)
	{
		clrscr();
		cout<<"All Events"<<endl;
		fstream efile("event.txt",ios::in|ios::binary);
		while(!efile.eof())
		{
			efile.read((char *)& e, sizeof(e));
			if(efile.eof())
			break;
			e.putdata();
		}
		efile.close();
	}
	else if(op==3)
	{
		e.Delete();
	}
	else if(op==4)
	{
		fstream file("event.txt",ios::in|ios::out|ios::binary);
		int md,dd,found=0;
		long pos;
		char n[50];
		event ev;
		cout<<"Enter details of event to be modified:"<<endl;

		am:
		cout<<"Enter month number (1-12):"<<endl;

		cin>>md;
		if(cin.fail())
	  {
		cout<<"Invalid option entered!"<<endl;
		cin.clear();
		cin.ignore();
		delay(2000);
		clrscr();
		goto am;

	  }
	     ad:
		cout<<"Enter date:"<<endl;
		cin>>dd;
		if(cin.fail())
	  {
		cout<<"Invalid option entered!"<<endl;
		cin.clear();
		cin.ignore();
		delay(2000);
		clrscr();
		goto ad;

	  }
		if((md == 1) && (dd>=0) && (dd<=31))
			strcpy(n, "JANUARY");
		else if((md == 2) && (dd>=0) && (dd<=28))
			strcpy(n, "FEBRUARY");
		else if((md == 3) && (dd>=0) && (dd<=31))
			strcpy(n,"MARCH");
		else if((md == 4) && (dd>=0) && (dd<=30))
			strcpy(n, "APRIL");
		else if((md == 5) && (dd>=0) && (dd<=31))
			strcpy(n, "MAY");
		else if((md == 6) && (dd>=0) && (dd<=30))
			strcpy(n, "JUNE");
		else if((md == 7) && (dd>=0) && (dd<=31))
			strcpy(n, "JULY");
		else if((md == 8) && (dd>=0) && (dd<=31))
			strcpy(n,"AUGUST");
		else if((md == 9) && (dd>=0) && (dd<=30))
			strcpy(n,"SEPTEMBER");
		else if((md == 10)&& (dd>=0) && (dd<=31))
			strcpy(n,"OCTOBER");
		else if((md == 11)&&(dd>=0) && (dd<=30))
			strcpy(n, "NOVEMBER");
		else if((md == 12)&&(dd>=0) && (dd<=31))
			strcpy(n,"DECEMBER");

		else

			cout<<"INVALID ENTRY. CANNOT MODIFY THE RECORD. ";

		pos=file.tellg();
		file.read((char *)& ev, sizeof(ev));
		while(!file.eof())
		{

			//cout<<pos;
			if(strcmp(n,ev.month)==0 &&dd==ev.date)
			{

				ev.modify();
				file.seekg(pos);
				file.write((char*)&ev,sizeof(ev));
				found=1;
				break;
			}
			pos=file.tellg();
			file.read((char *)& ev,sizeof(ev));

		}
		if(found==0)
			cout<<"RECORD NOT FOUND."<<endl;
		else
			cout<<"RECORD MODIFIED."<<endl;
		file.close();
	}
	else if(op==5)
	{
		clrscr();
		options();
	}
	else if(op==6)
		exit(0);
	else
		cout<<"Option does not exist"<<endl;
	do
	{
		cout<<"Do you want to continue?(y/n)"<<endl;
		cin>>yesno;
		if(yesno == 'y' || yesno == 'n' || yesno == 'Y' || yesno == 'N')
			break;

	}while((yesno!='y') || (yesno!= 'Y') || (yesno!='n') || (yesno != 'N'));

	if(yesno == 'y' || yesno == 'Y')
		count = 1;
	else
		count = 0;

	}while(count==1);
	break;
	case 4:
	clrscr();
	dispcalendar();
	cout<<"Enter any key to continue..."<<endl;
	getch();
	today();
	options();
	break;
	case 5:
	exit(0);
   }
   getch();
}
void dispmonth()
{
	char month[10];
	cout<<"Enter month name:"<<endl;
	gets(month);
	int l=strlen(month);
	for(int j=0; j<l; j++)
	{
		month[j]=tolower(month[j]);
	}
	clrscr();

	if(strcmp(month,"january")==0)
	{
		textcolor(WHITE);
		cputs("                                    JANUARY");
		cout<<endl<<endl<<endl<<endl;
		textcolor(GREEN);
		cputs("               S       M       T       W       T       F       S  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("                                                       1       2  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               3       4       5       6       7       8       9  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               10      11      12      13      14      15      16  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               17      18      19      20      21      22      23  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               24      25      26      27      28      29      30  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               31                    ");
		cout<<endl;
	}

	if(strcmp(month,"february")==0)
	{
		textcolor(WHITE);
		cputs("                                   FEBRUARY");
		cout<<endl<<endl<<endl<<endl;
		textcolor(GREEN);
		cputs("               S       M       T       W       T       F       S  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("                       1       2       3       4       5       6  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               7       8       9       10      11      12      13  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               14      15      16      17      18      19      20  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               21      22      23      24      25      26      27  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               28      29                                          ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("                                     ");
		cout<<endl;
	}

	if(strcmp(month,"march")==0)
	{
		textcolor(WHITE);
		cputs("                                     MARCH");
		cout<<endl<<endl<<endl<<endl;
		textcolor(GREEN);
		cputs("               M       T       W       T       F       S       S  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("                       1       2       3       4       5       6  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               7       8       9       10      11      12      13  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               14      15      16      17      18      19      20  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               21      22      23      24      25      26      27  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               28      29      30      31                          ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("                                     ");
		cout<<endl;
	}

	if(strcmp(month,"april")==0)
	{
		textcolor(WHITE);
		cputs("                                   APRIL");
		cout<<endl<<endl<<endl<<endl;
		textcolor(GREEN);
		cputs("               T       F       S       S       M       T       W  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("                       1       2       3       4       5       6  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               7       8       9       10      11      12      13  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               14      15      16      17      18      19      20  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               21      22      23      24      25      26      27  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               28      29      30                                  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("                                     ");
		cout<<endl;
	}

	if(strcmp(month,"may")==0)
	{
		textcolor(WHITE);
		cputs("                                   MAY  ");
		cout<<endl<<endl<<endl<<endl;
		textcolor(GREEN);
		cputs("               S       S       M       T       W       T       F  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("                       1       2       3       4       5       6  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               7       8       9       10      11      12      13  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               14      15      16      17      18      19      20  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               21      22      23      24      25      26      27  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               28      29      30      31                          ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("                                     ");
		cout<<endl;
	}

	if(strcmp(month,"june")==0)
	{
		textcolor(WHITE);
		cputs("                                   JUNE");
		cout<<endl<<endl<<endl<<endl;
		textcolor(GREEN);
		cputs("               T       W       T       F       S       S       M  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("                       1       2       3       4       5       6  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               7       8       9       10      11      12      13  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               14      15      16      17      18      19      20  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               21      22      23      24      25      26      27  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               28      29      30                                  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("                                     ");
		cout<<endl;
	}

	if(strcmp(month,"july")==0)
	{
		textcolor(WHITE);
		cputs("                                    JULY   ");
		cout<<endl<<endl<<endl<<endl;
		textcolor(GREEN);
		cputs("               T       F       S       S       M       T       W  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("                       1       2       3       4       5       6  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               7       8       9       10      11      12      13  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               14      15      16      17      18      19      20  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               21      22      23      24      25      26      27  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               28      29      30      31                            ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("                                     ");
		cout<<endl;

	}

	if(strcmp(month,"august")==0)
	{
		textcolor(WHITE);
		cputs("                                    AUGUST ");
		cout<<endl<<endl<<endl<<endl;
		textcolor(GREEN);
		cputs("               S       M       T       W       T       F       S  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("                       1       2       3       4       5       6  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               7       8       9       10      11      12      13  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               14      15      16      17      18      19      20  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               21      22      23      24      25      26      27  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               28      29      30      31                                  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("                                     ");
		cout<<endl;
	}

	if(strcmp(month,"september")==0)
	{
		textcolor(WHITE);
		cputs("                                   SEPTEMBER");
		cout<<endl<<endl<<endl<<endl;
		textcolor(GREEN);
		cputs("               W       T       F       S       S       M       T  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("                       1       2       3       4       5       6  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               7       8       9       10      11      12      13  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               14      15      16      17      18      19      20  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               21      22      23      24      25      26      27  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               28      29      30                                  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("                                     ");
		cout<<endl;
	}

	if(strcmp(month,"october")==0)
	{
		textcolor(WHITE);
		cputs("                                   OCTOBER");
		cout<<endl<<endl<<endl<<endl;
		textcolor(GREEN);
		cputs("               F       S       S       M       T       W       T  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("                       1       2       3       4       5       6  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               7       8       9       10      11      12      13  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               14      15      16      17      18      19      20  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               21      22      23      24      25      26      27  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               28      29      30      31                          ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("                                     ");
		cout<<endl;
	}

	if(strcmp(month,"november")==0)
	{
		textcolor(WHITE);
		cputs("                                   NOVEMBER");
		cout<<endl<<endl<<endl<<endl;
		textcolor(GREEN);
		cputs("               M       T       W       T       F       S       S  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("                       1       2       3       4       5       6  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               7       8       9       10      11      12      13  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               14      15      16      17      18      19      20  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               21      22      23      24      25      26      27  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               28      29      30                                  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("                                     ");
		cout<<endl;
	}

	if(strcmp(month,"december")==0)
	{
		textcolor(WHITE);
		cputs("                                   DECEMBER");
		cout<<endl<<endl<<endl<<endl;
		textcolor(GREEN);
		cputs("               W       T       F       S       S       M       T  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("                       1       2       3       4       5       6  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               7       8       9       10      11      12      13  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               14      15      16      17      18      19      20  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               21      22      23      24      25      26      27  ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("               28      29      30      31                          ");
		cout<<endl<<endl<<endl;
		textcolor(WHITE);
		cputs("                                     ");
		cout<<endl;
	}
}
void dispcalendar()
{       textcolor(GREEN);
	cputs("\t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t CALENDAR 2016 \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t \t");
	//cout<<endl;

	cout<<" ------------------------------------------------------------------------------"<<endl;
	cout<<"|        ";
	textcolor(GREEN);
	cputs("JANUARY");
	cout<<"         |";
	cout<<"          ";
	textcolor(GREEN);
	cputs("FEBRUARY");
	cout<<"         |";
	cout<<"          ";
	textcolor(GREEN);
	cputs(" MARCH ");
	cout<<"        |";

	cout<<endl;

	cout<<"| ";
	textcolor(WHITE);
	cputs("  S  M  T  W  T  F  S  ");
	cout<<"|";
	textcolor(WHITE);
	cputs("    S  M  T  W  T  F  S  ");
	cout<<"  |";
	textcolor(WHITE);
	cputs("   S  M  T  W  T  F  S  ");
	cout<<" |";

	cout<<endl;

	cout<<"| ";
	textcolor(YELLOW);
	cputs("                 1  2  ");
	cout<<"|";
	textcolor(YELLOW);
	cputs("       1  2  3  4  5  6  ");
	cout<<"  |";
	textcolor(YELLOW);
	cputs("               1  2  3  ");
	cout<<" |";


	cout<<"| ";
	textcolor(YELLOW);
	cputs("  3  4  5  6  7  8  9  ");
	cout<<"|";
	textcolor(YELLOW);
	cputs("    7  8  9 10 11 12 13  ");
	cout<<"  |";
	textcolor(YELLOW);
	cputs("   3  4  5  6  7  8  9  ");
	cout<<" |";

	cout<<"| ";
	textcolor(YELLOW);
	cputs(" 10 11 12 13 14 15 16  ");
	cout<<"|";
	textcolor(YELLOW);
	cputs("   14 15 16 17 18 19 20  ");
	cout<<"  |";
	textcolor(YELLOW);
	cputs("  10 11 12 13 14 15 16  ");
	cout<<" |";


	cout<<"| ";
	textcolor(YELLOW);
	cputs(" 17 18 19 20 21 22 23  ");
	cout<<"|";
	textcolor(YELLOW);
	cputs("   21 22 23 24 25 26 27  ");
	cout<<"  |";
	textcolor(YELLOW);
	cputs("  17 18 19 20 21 22 23  ");
	cout<<" |";


	cout<<"| ";
	textcolor(YELLOW);
	cputs(" 24 25 26 27 28 29 30  ");
	cout<<"|";
	textcolor(YELLOW);
	cputs("   28 29                  ");
	cout<<" |";
	textcolor(YELLOW);

	cputs("  24 25 26 27 28 29 30 ");
	cout<<"  |";


	cout<<"| ";
	textcolor(YELLOW);
	cputs(" 31                    ");
	cout<<"|";
	textcolor(YELLOW);
	cputs("                         ");
	cout<<"  |";
	textcolor(YELLOW);
	cputs("  31                    ");
	cout<<" |";


	cout<<" ------------------------------------------------------------------------------"<<endl;

	cout<<"|        ";
	textcolor(GREEN);
	cputs(" APRIL ");
	cout<<"         |";
	cout<<"          ";
	textcolor(GREEN);
	cputs("   MAY  ");
	cout<<"         |";
	cout<<"          ";
	textcolor(GREEN);
	cputs("  JUNE ");
	cout<<"        |";

	cout<<endl;

	cout<<"| ";
	textcolor(WHITE);
	cputs("  S  M  T  W  T  F  S  ");
	cout<<"|";
	textcolor(WHITE);
	cputs("    S  M  T  W  T  F  S  ");
	cout<<"  |";
	textcolor(WHITE);
	cputs("   S  M  T  W  T  F  S  ");
	cout<<" |";

	cout<<endl;

	cout<<"| ";
	textcolor(YELLOW);
	cputs("                 1  2  ");
	cout<<"|";
	textcolor(YELLOW);
	cputs("    1  2  3  4  5  6  7  ");
	cout<<"  |";
	textcolor(YELLOW);
	cputs("            1  2  3  4  ");
	cout<<" |";



	cout<<"| ";
	textcolor(YELLOW);
	cputs("  3  4  5  6  7  8  9  ");
	cout<<"|";
	textcolor(YELLOW);
	cputs("    8  9 10 11 12 13 14  ");
	cout<<"  |";
	textcolor(YELLOW);
	cputs("   5  6  7  8  9 10 11  ");
	cout<<" |";


	cout<<"| ";
	textcolor(YELLOW);
	cputs(" 10 11 12 13 14 15 16  ");
	cout<<"|";
	textcolor(YELLOW);
	cputs("   15 16 17 18 19 20 21  ");
	cout<<"  |";
	textcolor(YELLOW);
	cputs("  12 13 14 15 16 17 18  ");
	cout<<" |";


	cout<<"| ";
	textcolor(YELLOW);
	cputs(" 17 18 19 20 21 22 23  ");
	cout<<"|";
	textcolor(YELLOW);
	cputs("   22 23 24 25 26 27 28  ");
	cout<<"  |";
	textcolor(YELLOW);
	cputs("  19 20 21 22 23 24 25  ");
	cout<<" |";


	cout<<"| ";
	textcolor(YELLOW);
	cputs(" 24 25 26 27 28 29 30  ");
	cout<<"|";
	textcolor(YELLOW);
	cputs("   29 30 31              ");
	cout<<"  |";
	textcolor(YELLOW);
	cputs("  26 27 28 29 30        ");
	cout<<" |";
	cout<<" ------------------------------------------------------------------------------"<<endl;

	cout<<"Press Any key to proceed to next page";
	int koch;
	if(koch=getche())
	{

	clrscr();

	cout<<" ------------------------------------------------------------------------------"<<endl;

	cout<<"|        ";
	textcolor(GREEN);
	cputs("  JULY ");
	cout<<"         |";
	cout<<"          ";
	textcolor(GREEN);
	cputs(" AUGUST");
	cout<<"          |";
	cout<<"         ";
	textcolor(GREEN);
	cputs("SEPTEMBER");
	cout<<"       |";

	cout<<endl;

	cout<<"| ";
	textcolor(WHITE);
	cputs("  S  M  T  W  T  F  S  ");
	cout<<"|";
	textcolor(WHITE);
	cputs("    S  M  T  W  T  F  S  ");
	cout<<"  |";
	textcolor(WHITE);
	cputs("   S  M  T  W  T  F  S  ");
	cout<<" |";

	cout<<endl;

	cout<<"| ";
	textcolor(YELLOW);
	cputs("                 1  2  ");
	cout<<"|";
	textcolor(YELLOW);
	cputs("       1  2  3  4  5  6  ");
	cout<<"  |";
	textcolor(YELLOW);
	cputs("               1  2  3  ");
	cout<<" |";
