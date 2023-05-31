#include<iostream>
#include<fstream>
#include<string.h>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<conio.h>
#include<stdio.h>

/*Files used..............................
adminPasscode.dat        --> stores ID, Name and password for ADMINs
userPasscode.dat         --> stores ID, Name and password for USERs
StudDetails.dat          --> stores basic details
StudMarks.dat            --> stores marks
StudAttendence.dat       --> stores attendence
StudFee.dat              --> stores fee status
firstCl.dat              --> stores TT for first year
secondCl.dat             --> stores TT for second year
thirdCl.dat              --> stores TT for third year
fourthCl.dat             --> stores TT for fourth year
Event.dat                --> stores events
*/

using namespace std;

void line(int n)                                              //function to draw line. Draws a line every time it's called
	{
		for(int i=0;i<n;i++)
			{
			cout<<"_";
			//delay(3);
			
			}
	}


//--------------------------------------------------------------------------------------------------------------------------------	 
//:::::::::::::::::::::::::::::::::::::::::::::::::: ADMIN CLASS & FUNCTIONS :::::::::::::::::::::::::::::::::::::::::::::::::::::
//--------------------------------------------------------------------------------------------------------------------------------


struct address                                                //structure to record address
	 {
	 char House_no[10];
	 char area[20];
	 char city[20];
	 char state[20];
	 };

struct marks                                                 //marks for different streams, currently only 'cs' has been added
     {
     	float cs[8][5];
     };
     
struct event
{
	char name[50];
	char desig[20];
	char date[10];
	char title[30];
	char msg[1000];
};     
	 
//::::::::::::::::::::::::::::Class for ADMIN::::::::::::::::::::::::::::::::::: 
	 
class ADMIN                                                   
{
	 char Name[80];
	 char ID[11];             //User ID will act as a key on which all major operations depend
	 char passCode[10];       // user password
	 char namM[80];           //Mother's Name
	 char branch[5];          // Student branch
	 char year;               // student year
	 char sem[4];             // semester
	 char trans;               //checking for transportation
	 char hostel;              //checking for hostel
	 char DOB[8];
	 char phone[10];
	 char email[25];
	 float atten[9][12];       //array to store attendence, 9 subjects through 12 months
	 int fee[2][4];          //array to store fee, 2 installments through 4 years
	 string csub[6][8];        //array to store subject wise Class time table through 6 working days and 8 lectures
	 char subCode[3];          // code of branch (for time table)
	 address add;             // address sturcture object : add
	 marks mark;              //marks structure object : mark
	 event eve;               // event structure object : eve
	 
	public:
		void getDetails();     //adds details to StudDetails.dat file
		void addNewUser();     //adds info to both StudDetails.dat file & adminPasscode.dat/userPasscode.dat file
		void showData();       //shows Details added in StudDetails.dat
		void addMarks();       //add marks in StudMarks.dat
		void showMarks();      //shows marks from StudMarks.dat
		void addAttend();      //adds record to StudAttendence.dat
		void showAttend();     //shows records from StudAttendence.dat
		void addFee();         //adds record to StudFee.dat
		void showFee();        //shows records from StudFee.dat
		void showPass();       //Shows User ID & User Name from adminPasscode.dat/userPasscode.dat
		void getPass();        //Adds new password passcode file
		void makeCtt();        //makes Class time table
		void replaceCtt();     //replaces a new tt in place of existing tt
		void showCtt();        //shows Class time table
		void addEvent();       // adds new event
		void showEvent();      // displayes all events
		
		char*RetID()          // returns ID
		{
			return ID;
		}
		
		char*RetPass()        // returns password
		{
			return passCode;
		}
		
		char*RetBranch()     // returns branch
		{
			return subCode;
		}
		
	
};
//:::::::::::::::::::::::::::::class ends here::::::::::::::::::::::::::
//---------------------
//::::::::::::::class functions definations starts here:::::::::::::::::

void ADMIN::getDetails()                                //function to enter student details
{
	
     
	 cout<<"\nEnter Mother's Name: "; cin.getline(namM,80);
	 cout<<"\nEnter Date of Birth (DD-MM-YY): "; cin.getline(DOB,8);
	 cout<<"\nEnter Branch: "; cin.getline(branch,5);
	 cout<<"\nEnter Year (1-4): "; cin>>year;
	 if(year==NULL) 
	 {
	 	year='-';
	 }
     cout<<"\nEnter Semester (I-VIII): "; cin>>sem;
     cout<<"\nEnter E-mail: "; cin.getline(email,25);
     if(strlen(email)==NULL)	strcpy(email,"N/A");
     cout<<"\nDoes the user use college transport? (Y/N): "; cin>>trans;
     if(trans==NULL)
	 { trans='-';}                                                        //condition places N/A in case of no response
     cout<<"\nDoes the user use college hostel? (Y/N) : "; cin>>hostel;
     if(hostel==NULL) 
	 { hostel='-'; }                                         //condition places N/A in case of no response
      
	 cout<<"\nEnter Address Details.....\n";
	 cout<<"\nEnter House no:";cin.getline(add.House_no,10);
	 cout<<"\nEnter Area:"; cin.getline(add.area,20);
	 cout<<"\nEnter City:"; cin.getline(add.city,20);
	 cout<<"\nEnter State:";cin.getline(add.state,20);
}

void ADMIN::addNewUser()                                //function to add new user with unique ID 
{
	cout<<"\n\t Add New user to the system: \n";
	while(1)
	 {
		 n:
		 cout<<"\nRe-Enter College ID (10 digits):\t"; cin>>ID;
		 if(strlen(ID)==0)
					{
					cout<<"\n College ID cannot be blank, please try again..";
					getch();
					goto n;

					}
		 else
					break;
	 }
	cout<<"\nEnter User Name: "; cin.getline(Name,80);
	cout<<"\nEnter Password (10 charecters max): "; cin.getline(passCode,10);
}

void ADMIN::showData()                                 //Displaying student details
{
	 line(210);
	 cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t *** USER DETAILS ***\n"<<endl;
	 line(210);
	 cout<<"\n\n\n\t\t College ID        :"<<ID;
	 cout<<"\n\n\t\t Name    :"<<Name;
	 cout<<"\n\n\t\t Mother's Name :"<<namM;
	 cout<<"\n\n\t\t Date of Birth :"<<DOB;
	 cout<<"\n\n\t\t Branch :"<<branch;
	 cout<<"\n\n\t\t Year: "<<year;
	 cout<<"\n\n\t\t Semester: "<<sem;
	 cout<<"\n\n\t\t E-mail: "<<email;
	 cout<<"\n\n\t\t Transport: "<<trans;
	 cout<<"\n\n\t\t Hosteller: "<<hostel;
	 cout<<"\n\n\t\tAddress     :"<<add.House_no<<", "
	 <<add.area<<", "<<add.city<<", "<<add.state<<endl;
	 
}
          
void ADMIN::addMarks()                              // adds marks
{
	
	int s; char ch='y';
	cout<<"Re-enter college ID, record will be lost in case of wrong input:";
	cin>>ID;
	cout<<"\n\n Which sem marks do would you like to enter? (1-8) "; cin>>s;
	int i;
	cout<<"Entering Marks of "<<s<<"th Semester Main Exams: (Enter in this format ONLY '00.0') ";
	
	while(ch=='y' || ch=='Y')
	{
	
	for (i=0; i<5; i++)
	                
	{
	    switch(i)
	       {
	            case 0: cout<<"\n\n Communication Skills MM 80  : "; break;
	            case 1: cout<<"\n Computer Science       MM 80  : "; break;
	            case 2: cout<<"\n Chemistry              MM 160 : "; break;
	            case 3: cout<<"\n Electrical             MM 80  : "; break;
	            case 4: cout<<"\n Mathematics            MM 160 : "; break;
	            default: break;
	                		
			}
	                	
	    cin>>mark.cs[s-1][i];  
						      
	}
	cout<<"\n\n\t\t Would you like to enter more? (Y/N)\t"; cin>>ch;
    }
	
					
}
	

void ADMIN::showMarks()                                                 // displayes marks
{
	cout<<"                  **** STUDENT MARKS RECORD ****\n\n"<<endl;
	float sum, sgpa;
		
				cout<<"  Semester  | Communtication Skills |    Computer Science   |       Chemistry       |       Electrical      |      Mathematics      |         SGPA          |"<<endl;
				cout<<"------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|"<<endl;
				cout<<"            |                       |                       |                       |                       |                       |                       |"<<endl;
				int i,j;
				for(i=0; i<8; i++)
				{   sum=0;
					switch(i)
					{
						case 0: cout<<"     I      |          "; break;
						case 1: cout<<"     II     |          "; break;
						case 2: cout<<"     III    |          "; break;
						case 3: cout<<"     IV     |          "; break;
						case 4: cout<<"     V      |          "; break;
						case 5: cout<<"     VI     |          "; break;
						case 6: cout<<"     VII    |          "; break;
						case 7: cout<<"     VIII   |          "; break;
						default: break;
					}
					
					for(j=0; j<5; j++)
					{
						if (mark.cs[i][j]== 0) cout<<"---          |          ";
						else cout<<mark.cs[i][j]<<"          |          ";
						sum+=mark.cs[i][j];
					}
					sgpa=(((sum/560)* 100))/10;
					cout<<round(sgpa)<<"          |";
					cout<<endl;
				}
			//return();
	
}

void ADMIN::addAttend()                                      // adds attendence
{
	int m; char ch='y';
	cout<<"Re-enter college ID, record will be lost in case of worong input:";
	cin>>ID;
	cout<<"Which month's attendence would you like to enter?  "; 
	cout<<"1.  August     \t\t 2.  September"<<endl;
	cout<<"3.  October    \t\t 4.  November"<<endl;
	cout<<"5.  December   \t\t 6.  January"<<endl;
	cout<<"7.  February   \t\t 8.  March"<<endl;
	cout<<"9.  April      \t\t 10. May"<<endl;
	cout<<"11. June       \t\t 12. July"<<endl;
	cout<<"\n\n\t\t\t Enter choice:\t";
	cin>>m;
	int i;
	cout<<"Entering Attendence in % : (Enter in this format ONLY '(00.00)'";
	
	while(ch=='y' || ch=='Y')
	{
	
	for (i=0; i<9; i++)
	                
	{
	    switch(i)
	       {
	            case 0: cout<<"\n\n Communication Skills : "; break;
	            case 1: cout<<"\n Computer Science       : "; break;
	            case 2: cout<<"\n Chemistry              : "; break;
	            case 3: cout<<"\n Electrical             : "; break;
	            case 4: cout<<"\n Mathematics            : "; break;
	            case 5: cout<<"\n Communication Skills Pract. : "; break;
	            case 6: cout<<"\n Computer Science     Pract. : "; break;
	            case 7: cout<<"\n Chemistry            Pract. : "; break;
	            case 8: cout<<"\n Electrical           Pract. : "; break;
	            default: break;
	                		
			}
	                	
	    cin>>atten[i][m-1];  
						      
	}
	cout<<"\n\n\t\t Would you like to enter more? (Y/N)\t"; cin>>ch;
    }
}

void ADMIN::showAttend()                                         // displays attendence
{
	int i, j;
	cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t ***STUDENT ATTENDENCE***"<<endl;
  cout<<"\n\n\n\n\n\t\t\t ___________________________________________________________________________________________________________________________________________"<<endl;
	cout<<"\t\t\t|                               |        |        |        |        |        |        |        |        |        |        |        |        |"<<endl;
  cout<<"\t\t\t|            Subjects           |  Jan   |  Feb   |  Mar   |  Apr   |  May   |  Jun   |  Jul   |  Aug   |  Sep   |  Oct   |  Nov   |  Dec   |"<<endl;
	cout<<"\t\t\t|===============================|========|========|========|========|========|========|========|========|========|========|========|========|"<<endl;
	cout<<"\t\t\t|                               |        |        |        |        |        |        |        |        |        |        |        |        |"<<endl;
  for(i=0; i<9; i++)
  {  
	 switch(i)
  { 
  	case 0: cout<<"\t\t\t|  Communication Skills         |  "; break;
  	case 1: cout<<"\t\t\t|  Computer Science             |  "; break;
  	case 2: cout<<"\t\t\t|  Chemistry                    |  "; break;
  	case 3: cout<<"\t\t\t|  Electrical                   |  "; break;
  	case 4: cout<<"\t\t\t|  Mathematics                  |  "; break;
  	case 5: cout<<"\t\t\t|  Communication Skills Pract.  |  "; break;
  	case 6: cout<<"\t\t\t|  Computer Science     Pract.  |  "; break;
  	case 7: cout<<"\t\t\t|  Chemistry            Pract.  |  "; break;
  	case 8: cout<<"\t\t\t|  Electrical           Pract.  |  "; break;
  	default: break;
  } 	
	for(j=0; j<12; j++)
  	{   
  	    
  	    if(atten[i][j] == NULL) cout<<"----  |  ";
  		else cout<<atten[i][j]<<"  |  ";
  		
	  }cout<<endl;
	  cout<<"\t\t\t|_______________________________|________|________|________|________|________|________|________|________|________|________|________|________|"<<endl;
	  cout<<"\t\t\t|                               |        |        |        |        |        |        |        |        |        |        |        |        |"<<endl;
	  
}
}


void ADMIN::addFee()                                        // adds fee status
{
	int y; char ch='y';
	cout<<"Re-enter college ID, record will be lost in case of worong input:\t";
	cin>>ID;
	cout<<endl<<"Which year's record would you like to enter?"<<endl;
	cout<<"\n\t\t 1. First Year";
	cout<<"\n\t\t 2. Second Year";
	cout<<"\n\t\t 3. Third Year";
	cout<<"\n\t\t 4. Fourth Year";
	cout<<"\n\n\t\t\t Enter your choice:\t";
	cin>>y;
	while(ch=='y' || ch=='Y')
	{
	
	cout<<"Enter '1' if Fee is DEPOSITED, '0' in case of DUE...\n"<<endl;
	for ( int i=0; i<2; i++)
	                
	{
	    switch(y)
	       {
	            case 0: cout<<"\n\n I Installment       :\t"; break;
	            case 1: cout<<"\n II Installment       :\t"; break;
	            default: break;
	                		
			}
	                	
	    cin>>fee[i][y-1];  
						      
	}
	    cout<<"\n\n\t\t Would you like to enter more? (Y/N)\t"; cin>>ch;
    }
}

void ADMIN::showFee()                                    // shows fee status
{
	cout<<"\n\n\t\t\t\t\t\t\t\t\t ***STUDENT FEE DETAILS***"<<endl;
	cout<<"\n  Intallments  |      Year 1      |      Year 2      |      Year 3      |      Year 4      |"<<endl;
	cout<<"---------------|------------------|------------------|------------------|------------------|"<<endl;
	cout<<"               |                  |                  |                  |                  |"<<endl;
	for(int i=0; i<2; i++)
    {
	    switch(i)
        {
  	        case 0: cout<<"       I       |       "; break;
  			case 1: cout<<"       II      |       "; break;
  			default: break;
  		} 	
		for(int j=0; j<4; j++)
  		{   
  	    
  	    	if(fee[i][j] == NULL) cout<<"----       |       ";
  			else cout<<"Done       |       ";
  		
	  	}cout<<endl;
	  	cout<<"               |                  |                  |                  |                  |"<<endl;
	}
	cout<<"\n\n\n\t\t\t\t\t\t\t\t***";	
}

void ADMIN::getPass()                                          // for changing password
{
	cout<<"\n\n\t\t *Change My Password*"<<endl;
	line(210);
	cout<<"\n\nRe-enter college ID, record will be lost in case of worong input:\t";
	cin>>ID;
	cout<<"\nEnter User Name:\t";cin.getline(Name,80);
	cout<<"\nEnter NEW Password (10 charecters max):\t"; cin>>passCode;
}

void ADMIN::showPass()                                        // shows that user exits in case we need to change password
{
	cout<<"\n\n\t\t User ID  :\t"<<ID<<endl;
	cout<<"\n\t\t User Name:\t"<<Name<<endl;
	//cout<<"\n\t\t Pass:\t"<<passCode<<endl;
}

void ADMIN::makeCtt()                                      // makes a time table
{
	char ch='y';
	while(ch=='y' || ch=='Y')
	{
	cout<<"\n\n\tChoose among the following branches to enter the class Time Table"<<endl;
	cout<<"\n\n\t         BRANCH             \t\t\t\t\t\tCODE"<<endl;
	cout<<"\n\t  Computer Science            \t\t\t\t\t\t 01"<<endl;
	cout<<"\n\t  Electronics & Communication \t\t\t\t\t\t 02"<<endl;
	cout<<"\n\t  Civil                       \t\t\t\t\t\t 03"<<endl;
	cout<<"\n\t  Mechanical                  \t\t\t\t\t\t 04"<<endl;
	cout<<"\n\n\t\tEnter branch CODE, record will be lost in case of worong input:\t";
	cin>>subCode;
	int i,j;
	line(210);
	cout<<"\n\nEntering Time Table: "<<endl;
	cout<<"\n\tNOTE: Make sure the subjects you enter contain exactly 6 charecters, you may include initials of the subject along \n\twith the teachers. But total charecters must be no more and no less the 6 including space!"<<endl;
	
	for (i=0; i<6; i++)
	                
	{
		for(j=0; j<8; j++)
		{
		
	    switch(j)
	       {
	            case 0: cout<<"\n\n 10-11       :\t"; break;
	            case 1: cout<<"\n 11-12       :\t"; break;
	            case 2: cout<<"\n 12-1        :\t"; break;
	            case 3: cout<<"\n 1-1.30      :\t"; break;
	            case 4: cout<<"\n 1.30-2.30   :\t"; break;
	            case 5: cout<<"\n 2.30-3.20   :\t"; break;
	            case 6: cout<<"\n 3.20-4.10   :\t"; break;
	            case 7: cout<<"\n 4.10-5      :\t"; break;
	            default: break;
	                		
			}
			cin>>csub[i][j]; 
	}
						      
	}
	cout<<"\n\n\t\t Would you like to enter more? (Y/N)\t"; cin>>ch;
    }
}

void ADMIN::replaceCtt()                              // replaces old with new tt
{
	int i,j;
	cout<<"\n\n\tEntering Time Table: "<<endl;
	cout<<"\n\tNOTE: Make sure the subjects you enter contain exactly 6 characters, you may include initials of the subject along \n\twith the teachers. But total characters must be no more and no less the 6 including space!"<<endl;
	for (i=0; i<6; i++)
	                
	{   
	    switch(i)
  		{ 
  			case 0: cout<<"\n\t\t\t|   Monday      |     "; break;
  			case 1: cout<<"\t\t\t|   Tuesday     |     "; break;
  			case 2: cout<<"\t\t\t|   Wednesday   |     "; break;
  			case 3: cout<<"\t\t\t|   Thurday     |     "; break;
  			case 4: cout<<"\t\t\t|   Friday      |     "; break;
  			case 5: cout<<"\t\t\t|   Saturday    |     "; break;
  			default: break;
  		} 
  		
  		
		for(j=0; j<8; j++)
		{
		
	    switch(j)
	       {
	            case 0: cout<<"\n\n 10-11       :\t"; break;
	            case 1: cout<<"\n 11-12       :\t"; break;
	            case 2: cout<<"\n 12-1        :\t"; break;
	            case 3: cout<<"\n 1-1.30      :\t"; break;
	            case 4: cout<<"\n 1.30-2.30   :\t"; break;
	            case 5: cout<<"\n 2.30-3.20   :\t"; break;
	            case 6: cout<<"\n 3.20-4.10   :\t"; break;
	            case 7: cout<<"\n 4.10-5      :\t"; break;
	            default: break;
	                		
			}
			cin>>csub[i][j]; 
	}
						      
	}
}

void ADMIN::showCtt()                             // displayes tt
{
	int i,j;
	cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t ***Time Table***"<<endl;
    cout<<"\n\n\n\n\n\t\t\t _______________________________________________________________________________________________________________________________________________"<<endl;
	cout<<"\t\t\t|               |               |               |               |               |               |               |               |               |"<<endl;
    cout<<"\t\t\t|               |     10-11     |    11-12      |     12-1.30   |    1-1.30     |   1.30-2.30   |   2.30-3.20   |   3.20-4.10   |     4.10-5    |"<<endl;
	cout<<"\t\t\t|===============|===============|===============|===============|===============|===============|===============|===============|===============|"<<endl;
	cout<<"\t\t\t|               |               |               |               |               |               |               |               |               |"<<endl;
    for(i=0; i<6; i++)
  	{	  
	 	switch(i)
  		{ 
  			case 0: cout<<"\t\t\t|   Monday      |     "; break;
  			case 1: cout<<"\t\t\t|   Tuesday     |     "; break;
  			case 2: cout<<"\t\t\t|   Wednesday   |     "; break;
  			case 3: cout<<"\t\t\t|   Thurday     |     "; break;
  			case 4: cout<<"\t\t\t|   Friday      |     "; break;
  			case 5: cout<<"\t\t\t|   Saturday    |     "; break;
  			default: break;
  		} 	
		for(j=0; j<8; j++)
  		{	    
			cout<<csub[i][j]<<"    |     ";
  		
	  	}cout<<endl;
	  	cout<<"\t\t\t|_______________|_______________|_______________|_______________|_______________|_______________|_______________|_______________|_______________|"<<endl;
	  	cout<<"\t\t\t|               |               |               |               |               |               |               |               |               |"<<endl;
	  
	}
   
}

void ADMIN::addEvent()                            // adds event
{
	cout<<"\n\n************************************************************************************************************************************************************"<<endl;
	line(210);
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\t *** EVENT MENU ***\n"<<endl;
	line(210);
	cout<<"**************************************************************************************************************************************************************"<<endl;
	cout<<"\n\n\t\t Enter your Announcement:"<<endl;
	
	cout<<"\n\n\t\t\t Your Name         :\t"; cin.getline(eve.name,50);
	cout<<"\n\n\t\t\t Designation       :\t"; cin.getline(eve.desig,20);
	cout<<"\n\n\t\t\t Date  (DD-MM-YY)  :\t"; cin.getline(eve.date,10);
	cout<<"\n\n\t\t\t Title             :\t"; cin.getline(eve.title,30);
	cout<<"\n\n\t\t\t Message           :\t"; cin.getline(eve.msg,1000);
}

void ADMIN::showEvent()                                       // shows events
{
	
cout<<endl;
line(210);
cout<<"\n\n   *************************************************************************************************************************************************************************************************************"<<endl;
cout<<"\n\t\t"<<eve.name<<endl;
cout<<"\t\t"<<eve.desig<<endl;
cout<<"\n\t\t"<<eve.date<<endl;
cout<<"\n\t\t"<<eve.title<<endl;
cout<<"\t\t";
int i;
           for(i=0; eve.msg[i]!=0; i++)
           {
           	cout<<eve.msg[i];
           	if(i==160) cout<<endl<<"\t\t";
		   }
cout<<"\n\n\n   *************************************************************************************************************************************************************************************************************"<<endl;		   
line(210);
}

//:::::::::::::::::::: class functions end here ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//---------------------------------------------------------------------------------------------------------------------


void createUser()                                   //Function creates a new user and adds details
{   
	ADMIN A;
	line(210);
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t ***CREATE NEW USER***\n\n";
	line(210);
	ofstream fout1, fout2;
	fout2.open("StudDetails.dat",ios::binary|ios::app);
	int mode;
	//
	char searchID[11];
		          char found='f';
		          ifstream file;                                              //read StudDetails.dat file to check for already existing user                                 
		          file.open("StudDetails.dat",ios::binary | ios::in);
		          line(210);
		          cout<<"Enter User ID: ";
		          cin>>searchID;
		          line(210);
	              while(file.read((char*)&A,sizeof(A))&&found=='f')
		          {
			        if(strcmpi(searchID,A.RetID())==0)
			           {   found = 't';
					       cout<<"\n\t User already exists!"; 
					       file.close();
					       break;
					       
					   }
			      }
				  if(found=='f')                   //in case user not found, if condition
		            {
		            file.close();	
		            line(210);
		            cout<<"\n\n\t 1. Create new ADMIN ID"<<endl;
					cout<<"\t 2. Create new USER ID"<<endl;
					cout<<"\n\t\t Enter Mode: \t";
					cin>>mode;
					char ch='y';
	 	while(ch=='y'||ch=='Y')
			{
			if (mode==1)
			{	
			    fout1.open("adminPasscode.dat",ios::binary|ios::app);
		    }
		    else if(mode==2)
		    {
		    	fout1.open("userPasscode.dat",ios::binary| ios::app);
			}
			A.addNewUser();
			fout1.write((char*)&A,sizeof(A));
			fout2.write((char*)&A,sizeof(A));
			fout1.close();
			A.getDetails();
			fout2.write((char*)&A,sizeof(A));
			line(210);
			cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t ** NEW USER CREATED **\n";
			line(210);
			cout<<"\nDo you want to create another user? (Y/N)?: ";
			cin>>ch;
			line(210);
			}
	 fout2.close();
		            line(210);
		            getch(); 
		            return;
		            }
	//
	

}



void updateDetails()                              //modifies StudDetails.dat for details
   {
	 ADMIN A;
	 int cnt=0;
	 char searchID[11];
	 char found='f';
	 fstream file;
	 file.open("StudDetails.dat",ios::binary|ios::in|ios::out);
		line(210);
		cout<<"Enter User ID: ";
		cin>>searchID;
		line(210);
	 while(file.read((char*)&A,sizeof(A))&&found=='f')
			{
			cnt++;
			if(strcmpi(searchID,A.RetID())==0)
				{
					line(210);
					cout<<"User found....";
					line(210);
				 A.showData();
			    }
			char ch;
			cout<<"\nDo you want to modify this record Y/N?:"; cin>>ch;
			if(ch=='Y'||ch=='y')
			{
			A.getDetails();
			file.seekp(0);
			file.seekp((cnt-1)*sizeof(A));
			file.write((char*)&A,sizeof(A));
			found='t';
			line(210);
			cout<<"User Details Updated....";
			line(210);
			file.close();
			getch();
			return;
			}
		}
		
		if(found=='f')
			{
			 line(210);
			cout<<"\nUser not found! Redirecting back to Update MENU...\n";
			 line(210);
			getch();

			file.close();
			return;
			}
    }		


void studMarks()                           //adds, shows student Marks. File: StudMarks.dat
{
	ADMIN A;
	int n;
	do
	{
	
	cout<<"Would you like to: ";
	cout<<"\n 1. Add Student Marks";
	cout<<"\n 2. View Student Marks";
	cout<<"\n 3. UPDATE Menu";
	cout<<"\n\n    Enter your choice: "; cin>>n;
	switch(n)
	{
		case 1: {
			     char searchID[11];
	             char found='f';
	             ifstream file;
	             file.open("StudDetails.dat",ios::binary);
	             ofstream fout;
	             fout.open("StudMarks.dat",ios::binary|ios::app);
		         line(210);
		         cout<<"Enter User ID: ";
		         cin>>searchID;
		         line(210);
	             while(file.read((char*)&A,sizeof(A))&&found=='f')
			     {
			        if(strcmpi(searchID,A.RetID())==0)
				    {  
					    found = 't';
					    A.addMarks();
					    fout.write((char*)&A,sizeof(A));
					    cout<<"\n\n  ***Marks added to database! ***";
					    file.close(); fout.close();
					    break;
		            }
		         }
		         if(found=='f')
		         {
		            line(210);
		            cout<<"\n User ID not found, returning to UPDATE MENU....\n";
		            line(210);
		            getch(); file.close(); fout.close();
		            return;
		         }
		 
                
                } break;
                
                
		case 2: { char searchID[11];
		          char found='f';
		          ifstream file;                                 
		          file.open("StudMarks.dat",ios::binary | ios::in);
		          line(210);
		          cout<<"Enter User ID: ";
		          cin>>searchID;
		          line(210);
	              while(file.read((char*)&A,sizeof(A))&&found=='f')
		          {
			        if(strcmpi(searchID,A.RetID())==0)
			           {   found = 't';
					       A.showMarks();
					       getch();
					       file.close();
					       break;
					   }
			      }
				  if(found=='f')
		            {
		            line(210);
		            cout<<"\n User ID does not exit, redirecting back to UPDATE MENU....\n";
		            line(210);
		            getch(); file.close();
		            return;
		            }
	            } break;
		case 3: break;
		default: "Wrong input!!";
	}
    } while(n!=3);
}

void studAttend()                                             //adds, shows attendence records. File : StudAttendence.dat
{
	ADMIN A;
	int n;
	do
	{
		cout<<"\n  Choose action: "<<endl;
		cout<<"    1. Add a record"<<endl;
		cout<<"    2. View Attendence"<<endl;
		cout<<"    3. UPDATE Menu"<<endl;
		cout<<"\n       Enter choice: "; cin>>n;
		switch(n)
		{
			case 1: {
			     char searchID[11];
	             char found='f';
	             ifstream file;
	             file.open("StudDetails.dat",ios::binary);
	             ofstream fout;
	             fout.open("StudAttendence.dat",ios::binary|ios::app);
		         line(210);
		         cout<<"Enter User ID: ";
		         cin>>searchID;
		         line(210);
	             while(file.read((char*)&A,sizeof(A))&&found=='f')
			     {
			        if(strcmpi(searchID,A.RetID())==0)
				    {  
					    found = 't';
					    A.addAttend();
					    fout.write((char*)&A,sizeof(A));
					    cout<<"\n\n    ***Student attendence added to databse! ***";
					    file.close(); fout.close();
					    break;
		            }
		         }
		         if(found=='f')
		         {
		            line(210);
		            cout<<"\n User ID not found, returning to UPDATE MENU....\n";
		            line(210);
		            getch(); file.close(); fout.close();
		            return;
		         }
		     }
		         
			case 2: { char searchID[11];
			      char found='f';
				  ifstream file;                               
		          file.open("StudAttendence.dat",ios::binary);
		          line(210);
		          cout<<"Enter User ID: ";
		          cin>>searchID;
		          line(210);
	              while(file.read((char*)&A,sizeof(A))&&found=='f')
		          {
			        if(strcmpi(searchID,A.RetID())==0)
			           {   found = 't';
					       A.showAttend();
					       getch();
					       file.close();
					       break;
					   }
			      }
				  if(found=='f')
		            {
		            line(210);
		            cout<<"\n User ID does not exit, redirecting back to UPDATE MENU....\n";
		            line(210);
		            getch(); file.close();
		            return;
		            }
	              } break;
			case 3: break;
			default: cout<<"Wrong Input!"; break;
		}
		
	}while(n!=3);
}


void studFee()                                              //adds, shows fee records. file: StudFee.dat
{
	ADMIN A;
	int n;
	do
	{
		cout<<"\n  Choose action: "<<endl;
		cout<<"    1. Add fee record"<<endl;
		cout<<"    2. View fee status"<<endl;
		cout<<"    3. UPDATE Menu"<<endl;
		cout<<"\n       Enter choice: "; cin>>n;
		switch(n)
		{
			case 1: {
			     char searchID[11];
	             char found='f';
	             ifstream file;
	             file.open("StudDetails.dat",ios::binary);
	             ofstream fout;
	             fout.open("StudFee.dat",ios::binary|ios::app);
		         line(210);
		         cout<<"Enter User ID: ";
		         cin>>searchID;
		         line(210);
	             while(file.read((char*)&A,sizeof(A))&&found=='f')
			     {
			        if(strcmpi(searchID,A.RetID())==0)
				    {  
					    found = 't';
					    A.addFee();
					    fout.write((char*)&A,sizeof(A));
					    cout<<"\n\n    ***Student's current fee status added to databse! ***";
					    file.close(); fout.close();
					    break;
		            }
		         }
		         if(found=='f')
		         {
		            line(210);
		            cout<<"\n User ID not found, returning to UPDATE MENU....\n";
		            line(210);
		            getch(); file.close(); fout.close();
		            return;
		         }
		     } break;
		         
			case 2: { 
			      char searchID[11];
				  char found='f';
				  ifstream file;                               
		          file.open("StudFee.dat",ios::binary);
		          line(210);
		          cout<<"Enter User ID: ";
		          cin>>searchID;
		          line(210);
	              while(file.read((char*)&A,sizeof(A))&&found=='f')
		          {
			        if(strcmpi(searchID,A.RetID())==0)
			           {   found = 't';
					       A.showFee();
					       getch();
					       file.close();
					       break;
					   }
			      }
				  if(found=='f')
		            {
		            line(210);
		            cout<<"\n User ID does not exit, redirecting back to UPDATE MENU....\n";
		            line(210);
		            getch(); file.close();
		            return;
		            }
	              } break;
			case 3: break;
			default: cout<<"Wrong Input!"; break;
		}
		
	}while(n!=3);
}


void changePass()                          //Change password function
{
	ADMIN A;
	 int cnt=0, mode;
	 char searchID[11];
	 char found='f';
	 fstream file;
	 cout<<"Who's password to change?"<<endl;
	 cout<<"1. ADMIN"<<endl;
	 cout<<"2. USER"<<endl;
	 cin>>mode;
	 if(mode==1)
	 {
	 	file.open("adminPasscode.dat",ios::binary|ios::in|ios::out);
	 }
	 
	 else if (mode==2)
	 {
	 	file.open("userPasscode.dat",ios::binary|ios::in|ios::out);
	 }
	 
		line(210);
		cout<<"Enter ID to modify Password....:";
		cin>>searchID;
		line(210);
	 while(file.read((char*)&A,sizeof(A))&&found=='f')
			{
			cnt++;
			if(strcmpi(searchID,A.RetID())==0)
				{
					line(210);
					cout<<"User Found....";
					line(210);
				 A.showPass();
			char ch;
			cout<<"\nDo you want to change your Password? (Y/N)\t"; cin>>ch;
			if(ch=='Y'||ch=='y')
			{
			A.getPass();
			file.seekp(0);
			file.seekp((cnt-1)*sizeof(A));
			file.write((char*)&A,sizeof(A));
			found='t';
			line(210);
			cout<<"\n\tPassword sucessfully changed....";
			line(210);
			file.close();
			getch();
			return;
			}
		}
		}
		if(found=='f')
			{
			 line(210);
			cout<<"\nUser does not exist!! Redirecting back to UPDATE Menu...\n";
			 line(210);
			getch();

			file.close();
			return;
			}
	 
}


void updateUser()                                     //Update MENU (Details, Marks, Attendence, Fee, Password)
{
	int ch;
	a:
	system("CLS");	
	cout<<"\n\t\t\t\t\t ** UPDATE MENU **"<<endl;
	line(210);
	cout<<"\n\t Choose Action:"<<endl;
	cout<<"\n\t   1. Update User Details"<<endl;
	cout<<"\n\t   2. Add Marks"<<endl;
	cout<<"\n\t   3. Add Attendence"<<endl;
	cout<<"\n\t   4. Update Fee Status"<<endl;
	cout<<"\n\t   5. Change Password"<<endl;
	cout<<"\n\t   6. Main MENU"<<endl;
	line(210);
	cout<<"\n\t\t Enter choice: "; cin>>ch;
	do
	{
		switch(ch)
		{
			case 1: updateDetails(); goto a; break;
			case 2: studMarks(); goto a; break;
			case 3: studAttend(); goto a; break;
			case 4: studFee(); goto a; break;
			case 5: changePass(); goto a; break;
			case 6: break;
			default: cout<<"Wrong Input"; break;
		}
	}while(ch!=6);
}


void deleteUser()                             //Deletes User
	 {
	 ADMIN A;
	 char found='f';
	 char sid[11],confirm;
	 ifstream fin("StudDetails.dat",ios::binary|ios::in);
	 ofstream fout("Temp.dat",ios::binary|ios::out);
	 line(210);
	 cout<<"\nEnter User ID to be deleted: ";
	 cin>>sid;
	 line(210);
	 while(fin.read((char*)&A,sizeof(A)))
			{

			if(strcmpi(sid,A.RetID())==0)
				 {
				 found='t';
				 A.showData();
					 line(210);
					 cout<<"\n\n Confirm to delete(y/n): ";
					 cin>>confirm;
					 line(210);
						 if(confirm=='n'||confirm=='N')
								{
									line(210);
									cout<<"User Found! But Not Deleted.....\n\n"<<endl;
									getch();
									line(210);
									fout.write((char*)&A,sizeof(A));
								}
						 else if(confirm=='y'||confirm=='Y')
								{
								 line(210);
								 cout<<"User Successfully Deleted.....\n\n"<<endl;
								 getch();
								 line(210);
								continue;
								}
				 }
			else
				 fout.write((char*)&A,sizeof(A));
			}//end of while loop

	 if(found=='f')
			{
			 line(210);
			 cout<<"USER not found, redirecting back to MAIN Menu...";
			 line(210);
			//getch();
			}
	 remove("StudDetails.dat");
	 rename("Temp.dat","StudDetails.dat");
	 fin.close();
	 fout.close();
	 //return;
	 }
	 
void createCtt()                         // creates a new tt
{
	ADMIN A;
	ofstream fout;
	int y;
	cout<<"\n\n\n\t\tChoose year (1-4):\t";
	cin>>y;
	if(y==1)
	{
	fout.open("firstCl.dat",ios::binary|ios::app);
    }
    else if(y==2)
    {
    	fout.open("secondCl.dat",ios::binary|ios::app);
	}
	else if(y==3)
	{
		fout.open("thirdCl.dat",ios::binary|ios::app);
	}
	else if(y==4)
	{
		fout.open("fouthCl.dat",ios::binary|ios::app);
	}
	line(210);
	A.makeCtt();
	fout.write((char*)&A,sizeof(A));
	cout<<"\n\n    ***Class Time Table added to database! ***";
	fout.close();
		    
}	 

void modifCtt()                         // modifies tt
{
	ADMIN A;
	fstream file;
	int y; char scode[3];
	int cnt=0;
	char found='f';
	cout<<"\n\n\n\t\tChoose year (1-4):\t";
	cin>>y;
	if(y==1)
	{
		file.open("firstCl.dat",ios::binary|ios::in|ios::out);
	}
	else if(y==2)
	{
		file.open("secondCl.dat",ios::binary|ios::in|ios::out);
	}
	else if(y==3)
	{
		file.open("thirdCl.dat",ios::binary|ios::in|ios::out);
	}
	else if(y==4)
	{
		file.open("fourthCl.dat",ios::binary|ios::in|ios::out);
	}
	
		line(210);
		cout<<"Enter Branch CODE: ";
		cin>>scode;
		line(210);
	 while(file.read((char*)&A,sizeof(A))&&found=='f')
			{
			cnt++;
			if(strcmpi(scode,A.RetBranch())==0)
				{
					line(210);
					cout<<"Current Time Table....";
					line(210);
				    A.showCtt();
			    }
			char ch;
			cout<<"\nDo you want to replace with New Time Table? (Y/N)\t"; cin>>ch;
			if(ch=='Y'||ch=='y')
			{
			A.replaceCtt();
			file.seekp(0);
			file.seekp((cnt-1)*sizeof(A));
			file.write((char*)&A,sizeof(A));
			found='t';
			line(210);
			cout<<"\n\n\t\t\tTime Table Updated....";
			line(210);
			file.close();
			getch();
			return;
			}
		}
		
		if(found=='f')
			{
			 line(210);
			cout<<"\nTime Table of this branch does not exist! Redirecting back to Time Table Menu...\n";
			 line(210);
			getch();

			file.close();
			return;
			}
}


void viewCtt()                         // shows tt
{   system("CLS");
	ADMIN A;
	int y; char scode[3];
	cout<<"\n\n\t Enter Year (1-4) :\t"; cin>>y;
	ifstream file;
	if(y==1)
	{
		file.open("firstCl.dat",ios::binary);
	}
	else if(y==2)
	{
		file.open("secondCl.dat",ios::binary);
	}
	else if(y==3)
	{
		file.open("thirdCl.dat",ios::binary);
	}
	else if(y==4)
	{
		file.open("fourthCl.dat",ios::binary);
	}
	char found='f';
	line(210);
	cout<<"\n\n\tChoose among the following branches to enter the class Time Table"<<endl;
	cout<<"\n\n\t         BRANCH             \t\t\t\t\t\tCODE"<<endl;
	cout<<"\n\t  Computer Science            \t\t\t\t\t\t 01"<<endl;
	cout<<"\n\t  Electronics & Communication \t\t\t\t\t\t 02"<<endl;
	cout<<"\n\t  Civil                       \t\t\t\t\t\t 03"<<endl;
	cout<<"\n\t  Mechanical                  \t\t\t\t\t\t 04"<<endl;
	cout<<"\n\n\t\tEnter branch CODE to view Time Table:\t";
	cin>>scode;
	line(210);
	while(file.read((char*)&A,sizeof(A))&&found=='f')
	{
		if(strcmpi(scode,A.RetBranch())==0)
			{   found = 't';
				A.showCtt();
				getch();
				file.close();
				break;
			}
	}
	if(found=='f')
	{
		line(210);
		cout<<"\n Requested Time Table does not exist, redirecting back to Time Table MENU....\n";
		line(210);
		getch(); file.close();
		return;
	}
}

	 
void timeTable()                            //Time Table MENU
{
	int m; //int tt;
	system("CLS");
	line(210);
	cout<<"\n\n\t\t\t\t\t\t*** TIME TABLE MENU ***"<<endl;
	line(210);
	/*cout<<"\n\tChoose between the following:"<<endl;
	cout<<"\n\t  1. Class Time Table"<<endl;
	cout<<"\n\t  2. Exam Time Table (DO NOT CHOOSE THIS OPTION, WORK IN PROGRESS)"<<endl;
	cout<<"\n\n\t\tEnter choice:\t";
	cin>>tt;*/
	cout<<'\n'<<endl;;
	line(210);
	cout<<"\n\n\tActions:\n\n";               
	cout<<"\t  1. Create Table\n"<<endl;
	cout<<"\t  2. Modify Table\n"<<endl;
	cout<<"\t  3. View Table\n"<<endl;
	cout<<"\t  4. MAIN Menu\n"<<endl;
	cout<<"\n\t\tChoose Action:\t"; 
	cin>>m;
	//if(tt==1)
	//{
	do
	{
	switch(m)
	{
		case 1: createCtt(); break;
		case 2: modifCtt(); break;
		case 3: viewCtt(); break;
		case 4: break;
		default: cout<<"Wrong Input"; break;
	} 
    }while(m!=4);
    //}
    
    /*else if(tt==2)
    {
    	return;
	}*/
	
}

void eventPage()                           //adds, shows Events
{   
	ADMIN A;
	int n;
	a:
	system("CLS");	
	cout<<"\n\n************************************************************************************************************************************************************"<<endl;
	line(210);
	cout<<"\n\t\t\t\t\t\t\t\t\t\t\t *** EVENT MENU ***\n"<<endl;
	line(210);
	cout<<"**************************************************************************************************************************************************************"<<endl;
	cout<<"\n\n\t\t Choose Action:"<<endl;
	cout<<"\n\t\t\t 1. Add an event"<<endl;
	cout<<"\n\t\t\t 2. View Event Page\n"<<endl;
	cout<<"\n\t\t\t 3. MAIN Menu\n"<<endl;
	line(210);
	cout<<"\n\n\t\t\t\t Your choice:\t"; cin>>n;
	do
	{
	switch(n)
	{
		case 1: {   system ("CLS");
					ofstream fout;
                    fout.open("Event.dat",ios::binary|ios::app);
                    char ch='y';
	                while(ch=='y'||ch=='Y')
					{
						A.addEvent();
						fout.write((char*)&A,sizeof(A));
						line(210);
						cout<<"\nDo you want to enter more? (Y/N)\t";
						cin>>ch;
						line(210);
					}
	 				fout.close();
                    } goto a; break;
                    
        case 2: {   system("CLS");
        	    	ifstream fin;
        	    	int count=1;
	 				fin.open("Event.dat",ios::binary);
	 				cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t * * *";
					cout<<"\n   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
					cout<<"\n\t\t\t\t\t\t\t\t\t\t\t --- EVENT PAGE ---"<<endl;
					cout<<"\n   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
					cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t * * *"<<endl;
	 				while(fin.read((char*)&A,sizeof(A)))
					{
						//line(210);
			 			A.showEvent();
						//line(210);
			 			count++;
						if(count%2==0)              //displays 2 events at a time
						{
			 				
			 				cout<<"\n\t\tPress any key to see more events...\n";
							
							getch();
							
						}
					}
					if(count==1)
					{
		 			line(210);
		 			cout<<"\nNo EVENTS added yet...";
		 			line(210);
		 			getch();
					}
	 				fin.close();
        	       
			
				} getch(); goto a; break;    
		case 3: break;
		default: cout<<"Wrong Input"; break;		      
	}
}while(n!=3);

	
}	 
 
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\  ADMIN PANEL \\\\\\\\\\\\\\\\\\\\\\\	 
		
void adminMenu()		                                              //ADMIN MENU
{   a:
    system("CLS");
	line(210);
	cout<<"\n\n\t\t\t\t\t\t\t\t ***ADMIN PANEL***\n\n";
    line(210);
	cout<<"\n\tActions:\n\n";
	cout<<"\t  1. Create User\n"<<endl;
	cout<<"\t  2. Update User\n"<<endl;
	cout<<"\t  3. Delete User\n"<<endl;
	cout<<"\t  4. Time Table\n"<<endl;
	cout<<"\t  5. EVENT PAGE\n"<<endl;
	cout<<"\t  6. Log OUT and EXIT\n\n"<<endl;
	line(210);
	cout<<"\n\t    Enter your choice:\t";
	int ch;
	cin>>ch;
	do
	{
		switch(ch)
		{
			case 1: createUser(); goto a; break;
			case 2: updateUser(); goto a; break;
			case 3: deleteUser(); goto a; break;
			case 4: timeTable(); goto a; break;
			case 5: eventPage();  goto a; break;
			case 6: break;
			default: cout<<"\n\t\tWrong Input!"; break;
		}
	}while(ch!=6);
	getch();
	
	
}

//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ STUDENT PANEL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void studMenu()                                                     //STUDENT MENU
{   a:
	system("CLS");
	line(210);
	cout<<"\n\n\t\t\t\t\t\t\t\t ***STUDENT PANEL***\n\n";
    line(210);
	cout<<"\n\tActions:\n\n"<<endl;
	cout<<"\t  1. My Details\n"<<endl;
	cout<<"\t  2. My Marks\n"<<endl;
	cout<<"\t  3. My Attendence\n"<<endl;
	cout<<"\t  4. Check Fee Status\n"<<endl;
	cout<<"\t  5. Check Time Table\n"<<endl;
	cout<<"\t  6. EVENT PAGE\n"<<endl;
	cout<<"\t  7. Change my PASSWORD\n"<<endl;
	cout<<"\t  8. Log OUT and EXIT\n"<<endl;
	line(210);
	cout<<"\n\t    Enter your choice:\t";
	int ch;
	cin>>ch;
	do
	{
		switch(ch)
		{
			case 1: {
						ADMIN A;
	 					ifstream fin;
	 					char searchID[11]; char found='f';
	 					fin.open("StudDetails.dat",ios::binary|ios::in);
	 					line(210);
	 					cout<<"\nEnter your ID:\t";
	 					cin>>searchID;
	 					line(210);
	 					while(fin.read((char*)&A,sizeof(A))&&found=='f')
						{
							if(strcmpi(searchID,A.RetID())==0)
				 			{
				 				A.showData();
				 				getch();
				 				found='t';
				 				fin.close();
				 				break;
				 			}
						}
	 					if(found=='f')
		 				{
		 					line(210);
		 					cout<<"\nNo such Record Exists....\n";
		 					line(210);
		 					getch(); fin.close();
		 					return;
		 				}
				
			        } goto a; break;
			        
			case 2: {   ADMIN A;
						char searchID[11];
		          char found='f';
		          ifstream file;                                 
		          file.open("StudMarks.dat",ios::binary | ios::in);
		          line(210);
		          cout<<"Enter your ID:\t";
		          cin>>searchID;
		          line(210);
	              while(file.read((char*)&A,sizeof(A))&&found=='f')
		          {
			        if(strcmpi(searchID,A.RetID())==0)
			           {   found = 't';
					       A.showMarks();
					       getch();
					       file.close();
					       break;
					   }
			      }
				  if(found=='f')
		            {
		            line(210);
		            cout<<"\n No such record exists....\n";
		            line(210);
		            getch(); file.close();
		            return;
		            }
					}  goto a;
					break;
					
			case 3: {   ADMIN A;
						char searchID[11];
			      char found='f';
				  ifstream file;                               
		          file.open("StudAttendence.dat",ios::binary);
		          line(210);
		          cout<<"Enter User ID: ";
		          cin>>searchID;
		          line(210);
	              while(file.read((char*)&A,sizeof(A))&&found=='f')
		          {
			        if(strcmpi(searchID,A.RetID())==0)
			           {   found = 't';
					       A.showAttend();
					       getch();
					       file.close();
					       break;
					   }
			      }
				  if(found=='f')
		            {
		            line(210);
		            cout<<"\n No such record exists....\n";
		            line(210);
		            getch(); file.close();
		            return;
		            }
	              } goto a; break;
	              
			case 4: { ADMIN A;
			      char searchID[11];
				  char found='f';
				  ifstream file;                               
		          file.open("StudFee.dat",ios::binary);
		          line(210);
		          cout<<"Enter your ID: ";
		          cin>>searchID;
		          line(210);
	              while(file.read((char*)&A,sizeof(A))&&found=='f')
		          {
			        if(strcmpi(searchID,A.RetID())==0)
			           {   found = 't';
					       A.showFee();
					       getch();
					       file.close();
					       break;
					   }
			      }
				  if(found=='f')
		            {
		            line(210);
		            cout<<"\n No such record exists....\n";
		            line(210);
		            getch(); file.close();
		            return;
		            }
	              }  goto a; break;
				
			case 5: viewCtt(); goto a; break;
			
			case 6: {   system("CLS");
			        ADMIN A;
        	    	ifstream fin;
        	    	int count=1;
	 				fin.open("Event.dat",ios::binary);
	 				cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t* * *";
					cout<<"\n   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
					cout<<"\n\t\t\t\t\t\t\t\t\t\t\t --- EVENT PAGE ---"<<endl;
					cout<<"\n   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
					cout<<"\n\t\t\t\t\t\t\t\t\t\t\t\t* * *"<<endl;
	 				while(fin.read((char*)&A,sizeof(A)))
					{
						//line(210);
			 			A.showEvent();
						//line(210);
			 			count++;
						if(count%2==0)              //displays 2 events at a time
						{
			 				//line(210);
			 				cout<<"\n\n\t\tPress any key to see more events...\n";
							//line(210);
							getch();
						}
					}
					if(count==1)
					{
		 			line(210);
		 			cout<<"\nNo EVENTS added yet...";
		 			line(210);
		 			getch();
					}
	 				fin.close();
        	    }
			goto a; break;
			
			case 7:	{
						ADMIN A;
	 	int cnt=0;
	 	char searchID[11];
	 	char found='f';
	 	fstream file;
	 	file.open("userPasscode.dat",ios::binary|ios::in|ios::out);
	    line(210);
		cout<<"Enter your ID to modify Password....:";
		cin>>searchID;
		line(210);
	 while(file.read((char*)&A,sizeof(A))&&found=='f')
			{
			cnt++;
			if(strcmpi(searchID,A.RetID())==0)
				{
					line(210);
					cout<<"User Found....";
					line(210);
				 A.showPass();
			char ch;
			cout<<"\nDo you want to change your Password? (Y/N)\t"; cin>>ch;
			if(ch=='Y'||ch=='y')
			{
			A.getPass();
			file.seekp(0);
			file.seekp((cnt-1)*sizeof(A));
			file.write((char*)&A,sizeof(A));
			found='t';
			line(210);
			cout<<"\n\tPassword sucessfully changed....";
			line(210);
			file.close();
			getch();
			return;
			}
		}
		}
		if(found=='f')
			{
			 line(210);
			cout<<"\nID does not exist!! Redirecting back to UPDATE Menu...\n";
			 line(210);
			getch();

			file.close();
			}
			}
			 goto a;	break;
			
		case 8: break;	
			
		default: cout<<"\n\t\tWrong Input!"; break;
		}
	}while(ch!=8);
	getch();
}

/*--------------------------------------------------------------------------------------------------
  ::::::::::::::::::::::::::::::::::::::: MAIN FUNCTION :::::::::::::::::::::::::::::::::::::::::::
--------------------------------------------------------------------------------------------------*/


int main()
{
	
   ADMIN A;
    ifstream fin;
    int mode;
    char menu;
    cout<<"\n\t\t\t\t\t\t\t\t *** WELCOME TO TECHNO INDIA NJR MANAGEMENT SYSTEM ***"<<endl;
    line(210);
    cout<<"\n \t\t\t\t\t *LOGIN PAGE*"<<endl;
    line(210);
    cout<<"\n\t1. Login as ADMIN"<<endl;
    cout<<"\t2. Login as USER"<<endl;
    cout<<"\n\t\t Enter mode:\t"; cin>>mode;
    if(mode==1)
    {
	fin.open("adminPasscode.dat",ios::binary|ios::in);
	menu='a';
    }
    
    else if(mode==2)
    {
    	fin.open("userPasscode.dat", ios::binary|ios::in);
    	menu='u';
	}
    char ch; 
    int i,cnt=0;
    char sid[10];
    char pass[8];
    while(cnt<3)
    	{
    	cout<<"\n\tEnter User ID (10 charecters)                 :\t"; 
		cin>>sid;	
		cout<<"\n\tEnter the maximum 8 character access password :\t"; cin>>pass; 
		/*i=0;
		while(ch=getch())
				{
				    if(ch==13) break;
				    pass[i]=ch;
				    i++;
				    putchar('*');
				}
	    pass[i]='\0';*/
	    int a,b;
	    a=(strcmp(sid,A.RetID())==0);                                         // PASSWORD CHECK
		cout<<a<<endl;
	    b=(strcmp(pass, A.RetPass())==0); 
		cout<<b<<endl;
	    //cout<<i<<endl;
	    //cout<<A.RetID();
		if(a==0) 
			{
				if(b==0)
				{
			    cout<<endl;
			    line(210);
			    cout<<"\n\n\t\tCongratulations!!! Password Verified\n";
			    line(210);
			    fin.close();
			    getch();
			    break;
			    }
			}
		 else
			{
			line(210);
			cout<<"\n\n\t\tInvalid User ID or Password! Try again\n";
			fin.close();
			getch();
			}
	    cnt++;
		if(cnt==3)
			{
			cout<<"\n\n\n \t\t\t\t\tYou're locked out....."; 
			getch();
			fin.close();
			system("CLS");
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
            cout<<"\n\n\t\t\t\t\t\t\t\t\t***End of project***\n";
			getch();
			exit(1);
			}
		}
		
fin.close();	
 
switch(menu)                                               // navigates to a panel accoring to login mode
{
	case 'a': adminMenu(); break;                        
	case 'u': studMenu(); break;
	default: cout<<"\n  Wrong Input"; break;
}
  
  system("CLS");
  cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
  cout<<"\t\t\t\t*** THANKYOU FOR VISITING ***\n";
  getch();
  
}

//                                                          -------------------  ***************  -------------------



// POTENTIAL FIXES
/*
1. Fix the menu problems (smooth the working)
2. Login issues
3. provide a logout option to navigate back to the login page
4. after fixing login issue, secure the records more, by adding password check to change my password system for users
5. in student panel, elimainate the option for students to enter their ID, instead directly display their data
6. add an exam time table option (maybe not now)..badme phir kabhi
7. fix update menu's functions. --> in modify details, id check is faulty
                                --> add attendence, marks, faulty..their op is also faulty
                                --> title table, op faulty

                                                           * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

*/
