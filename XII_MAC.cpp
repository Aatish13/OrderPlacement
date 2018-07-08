//*******************************************************
//      PROJECT : DRIVE THROUGH MANAGEMENT SYSTEM
//*******************************************************
//passward for admin is "1234" 
//*******************************************************
//	INCLUDED HEADER FILES
//*******************************************************

#include<conio.h>
#include<fstream.h>
#include<iomanip.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<graphics.h>
#include<dos.h>
//*******************************************************
// GLOBAL DECLERATION
//*******************************************************

char code[5];
struct date d;
void mainmenu(int,int);
char name1[100];

//*******************************************************
//	CLASSES
//*******************************************************

class member
{

	char phno[11];
	char pass[5];
	public:
	char name[100];
	int DD,MM,YY;
	void create();
	void search();
	char* getphno()
	{
		return phno;
	}

}m;
class bill
{     public:
	int DD,MM,YY;
	char name[100];
	char phno[11];
	int amount;
	char* getphno()
	{
		return phno;
	}
}c;

void bill(bill c)
{     ofstream fout;
	fout.open("d:bill.txt",ios::app|ios::binary);
	fout.write((char *)&c,sizeof(c));
	fout.close();
}
void fileins()
{     ofstream fout;
	fout.open("d:XII_file.txt",ios::app|ios::binary);
	fout.write((char *)&m,sizeof(m));
	fout.close();
}
void member::create()
{

	cout<<"Enter user Name:";
	cin>>name;
	cout<<"Enter password:";
	cin>>pass;
	cout<<"Enter phone no.:";
	cin>>phno;
	getdate(&d);
	YY=d.da_year;
	DD=d.da_day;
	MM=d.da_mon;
	fileins();
	mainmenu(1,1);
}
void member::search()
{

	cout<<"Enter User Name:";
	cin>>name1;
	ifstream fin("d:XII_file.txt",ios::in|ios::binary);
	if(fin.fail())
		cout<<"file not found";
	else
	{
		fin.read((char *)&m,sizeof(member));
		while(!fin.eof())
		{
			if(strcmp(name1,name)==0)
				strcpy(code,pass);
		fin.read((char *)&m,sizeof(m));
		}
	}
	fin.close();
}

//*******************************************************
//	FUNCTIONS TO DISPLAY BILL DETAILS
//*******************************************************

void manager()
{     clrscr();
	ifstream fin("d:bill.txt",ios::in|ios::binary);
	if(fin.fail())
		cout<<"file not found";
	else
	{
		cout<<endl<<"________________________________________________________________";
		cout<<endl<<setw(5)<<"name"<<setw(15)<<"phone no"<<setw(15)<<"amount"<<setw(15)<<"Date";
		cout<<endl<<"________________________________________________________________";
		fin.read((char *)&c,sizeof(c));
		while(!fin.eof())
		{
				cout<<endl<<setw(5)<<c.name<<setw(15)<<c.phno
					<<setw(15)<<c.amount<<setw(15)<<c.DD<<"/"<<c.MM<<"/"<<c.YY;
					cout<<endl<<"----------------------------------------------------------------";

		     //	cout<<"coustmer name :"<<c.name<<":phone no:"<<c.phno<<"total amount :"<<c.amount<<endl<<endl;
		fin.read((char *)&c,sizeof(c));
		}
	}
	fin.close();
	getch();
}

//*******************************************************
//	FUNCTIONS TO ACCEPT & CHECK PASSWORD
//*******************************************************

int passwords()
{
	char p[10];
	int i=0;
	gotoxy(33,10);
	cout<<"ENTER THE PASSWORD\n";
	gotoxy(33,12);
	do
	{
	p[i]=getch();
	cout<<"*";
	i++;
	}
	while(p[i-1]!='\r');
	p[i-1]='\0';
	gotoxy(30,20);
	if (strcmp(p,code)==0)

		return 1;

	else
		return 0;
}
int sum;

void mainmenu(int,int);

//*******************************************************
//	FUNCTION MAIN()                                 `
//*******************************************************

void main()
{
clrscr();
textcolor(YELLOW);
textbackground(RED);
int choice,flag=0;
clrscr();
	cout<<"\t%%      %%      ";
	cout<<"\n\t%%      %% %%%%%%% %%      %%%%%% %%%%%% %%%%%%%%%% %%%%%%%";
	cout<<"\n\t%%      %% %%      %%      %%     %%  %% %%  %%  %% %%       ";
	cout<<"\n\t%%  %%  %% %%%%%   %%      %%     %%  %% %%  %%  %% %%%%%      ";
	cout<<"\n\t%%  %%  %% %%      %%      %%     %%  %% %%      %% %%           ";
	cout<<"\n\t%%%%%%%%%% %%%%%%% %%%%%%% %%%%%% %%%%%% %%      %% %%%%%%%     ";
	cout<<"\n\n\t\t\t        $$$$$$$$  $$$$$        ";
	cout<<"\n\t\t\t           $$     $   $      ";
	cout<<"\n\t\t\t           $$     $$$$$    ";

	cout<<"\n\t\t\t%%%%%%%%%%   %%%%%%         %%%%%%  "  ;
	cout<<"\n\t\t\t%%  %%  %%   %%             %%    %% " ;
	cout<<"\n\t\t\t%%  %%  %%   %%             %%    %% " ;
	cout<<"\n\t\t\t%%      %%   %%             %%    %%  ";
	cout<<"\n\t\t\t%%      %%   %%%%%%   %%    %%%%%%   " ;
	cout<<"\n\n\n\tCOMPUTER   PROJECT  (******** DRIVETHROUGH MANAGEMENT SYSTEM>> *******)";
	cout<<" \n\n\n\t\t     press any KEY???? to continue: ";


	getch();
	clrscr();

do
{
		cout << "\n\t\t--------------------------";
		cout << "\n\t\t0. DO you have a membership ?";
		cout << "\n\t\t1. YES";
		cout << "\n\t\t2. NO";
		cout << "\n\t\t3. Create new member ship";
		cout << "\n\t\t4. ADMIN";
		cout << "\n\t\t--------------------------";
		cout << "\nEnter choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1: m.search();
			for(int i=0;i<3;i++)
			{
			if(!passwords())
			{
				clrscr();
				cout<<"\nWrong password try once more\n";
			}
			else
			{
				flag=1;
				mainmenu(choice,flag);
			}
			}
			if(i==3)
			{
			clrscr();
			cout<<"\n\n\t\t\t all attempts failed.....";
			cout<<"\n\n\n\t\t\t see you.................. ";
			getch();
			exit(0);
			}
			break;
		case 2:
			mainmenu(choice,flag);
			break;
		case 3:    m.create();
			break;
		case 4:
			strcpy(code,"1234");
			for(i=0;i<3;i++)
			{
			if(!passwords())
			{
				clrscr();
				cout<<"\nWrong password try once more\n";
			}
			else
			{

				manager();
			}
			}
			if(i==3)
			{
			clrscr();
			cout<<"\n\n\t\t\t all attempts failed.....";
			cout<<"\n\n\n\t\t\t see you.................. ";
			getch();
			exit(0);
			}
}
}while(choice!=3);
	getch();
	clrscr();
}
//*******************************************************
//	FUNCTION OF MAIN MENU
//*******************************************************

void mainmenu(int choice,int flag)
{
	int O1=0,O2=0,O3=0,O4=0,N1=0,N2=0,N3=0,N4=0;
	do
	{
		cout<<"\n\t\t\tMAIN MENU";
		cout << "\n\t\t--------------------------";
		cout << "\n\t\t1. Veg";
		cout << "\n\t\t2. Non.veg";
		cout << "\n\t\t3. Exit";
		cout << "\n\t\t--------------------------";
		cout << "\nEnter choice : ";
		cin >> choice;

		switch (choice)
		{
			case 1 :do
				{   	clrscr();
					cout << "\n\t\t--------------------------No of item";
					cout << "\n\t\t1. peri peri($45)---------  "<<O1;
					cout << "\n\t\t2. veg.maharaja($50)------  "<<O2;
					cout << "\n\t\t3. veg.kabbab($60)--------  "<<O3;
					cout << "\n\t\t4. veg.paneer warp($90)---  "<<O4;
					cout << "\n\t\t5. To Goto Main Menu ";
					cout << "\n\t\t6. Place Order";
					cout << "\n\t\t--------------------------";
					cout << "\nEnter choice : ";
					cin >> choice;
				switch (choice)
				{
				case 1: sum+=45;O1+=1;
					break;

				case 2: sum+=50;O2+=1;
					break;

				case 3: sum+=60;O3+=1;
					break;

				case 4: sum+=90;O4+=1;
					break;
				case 5: mainmenu(choice,flag);
					break;
				case 6:

						if(flag==1)
						{
						sum=sum-((sum/100)*10);
						strcpy(c.name,m.name);
						c.amount=sum;
						getdate(&d);
						strcpy(c.phno,m.getphno());
						c.DD=d.da_day;
						c.MM=d.da_mon;
						c.YY=d.da_year;
						bill(c);
						}
						else
						{char ph[11];
						cout<<"ENTER PH NO.:";
						cin>>ph;
						char na[100];
						cout<<"ENTER NAME :";
						cin>>na;
						strcpy(c.name,na);
						c.amount=sum;
						getdate(&d);
						c.DD=d.da_day;
						c.MM=d.da_mon;
						c.YY=d.da_year;
						strcpy(c.phno,ph);
						bill(c);
						}
							cout<<"\t\t....................................................";
							cout<<"\n\t\t\t\tTotal Amount="<<sum;
							cout<<"\n\t\t....................................................";
						getch();
						exit(0);
						break;
				default:
						cout << "\nInvalid Choice!!!";

				}

				}while(choice!=6);
				getch();
				clrscr();
					break;
			case 2 :do
				{   clrscr();
					cout << "\n\t\t--------------------------No of item";
					cout << "\n\t\t1. chicken maharaja($45)--  "<<N1;
					cout << "\n\t\t2. lollipop burger($50)---  "<<N2;
					cout << "\n\t\t3. chicken.kabbab($60)----  "<<N3;
					cout << "\n\t\t4. chikzza crunch($90)----  "<<N4;
					cout << "\n\t\t5. To Goto Main Menu";
					cout << "\n\t\t6. Place Order";
					cout << "\n\t\t--------------------------";
					cout << "\nEnter choice : ";
					cin >> choice;
				switch (choice)
					{
					case 1: sum+=45;N1+=1;
						break;

					case 2: sum+=50;N2+=1;
						break;

					case 3: sum+=60;N3+=1;
						break;

					case 4: sum+=90;N4+=1;
						break;
					case 5: mainmenu(choice,flag);
							break;
					case 6:	if(flag==1)
							{
							sum=sum-((sum/100)*10);
							strcpy(c.name,m.name);
							c.amount=sum;
							getdate(&d);
							c.DD=d.da_day;
							c.MM=d.da_mon;
							c.YY=d.da_year;

							strcpy(c.phno,m.getphno());
							bill(c);
							}
							else
							{char ph[11];
							cout<<"ENTER PH NO.:";
							cin>>ph;
							char na[100];
							cout<<"ENTER NAME :";
							cin>>na;
							strcpy(c.name,na);
							getdate(&d);
							c.DD=d.da_day;
							c.MM=d.da_mon;
							c.YY=d.da_year;
							c.amount=sum;
							strcpy(c.phno,ph);
							bill(c);
							}
							cout<<"\t\t....................................................";
							cout<<"\n\t\t\t\tTotal Amount="<<sum;
							cout<<"\n\t\t....................................................";
							getch();
							exit(0);


							break;
					default:
							cout << "\n\tInvalid Choice!!!";
							}
				}while(choice!=6);
					getch();
					clrscr();
			case 3 : exit(0);
			case 99 : manager();
			default : cout << "\nInvalid Choice!!!";
}
	  }	while(choice!=3);
}
