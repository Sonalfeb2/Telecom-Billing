#include<iostream>
#include<string.h>
#include<process.h>
#include<conio.h>
#include<iomanip>
#include<fstream>


using namespace std;

    class customer
	{
	    public:
	char name[20],email_id[20],mno[20],address[20],adhaarno[20],istatus[10],cstatus[10];
	int sno;
	
	  customer()
	 {
	 sno=0;
	 }

		void input();
		void show();
}ob;


class filedata
{
	public:
	void customerdata_w();
	void customerdata_r();
	void resume();
	void customerdata_dlt();
	void customerdata_edt();
	//Bill
	void b_internet();
	void b_calls();


}f;


void customer();


void payments();

void mainmenu();

int main()
{    
   cout<<"\n\n\n\n\n\n\n\n\n\n**************************************************************************\n";
  cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t-------WELCOME TO TELECOME BILLING SYSTEM-------\n";
  cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t********************************************************************************";
  
  getche();  
	system("cls");
	mainmenu();
	
}
void customer()
{   
    system("cls");
	int ch;
	cout<<"\t\tCustomer Informations\n";
	cout<<"=======================================\n";
	cout<<"1:\tto Add\n";
	cout<<"2:\tto Delete\n";
	cout<<"3:\tto Edit\n";
	cout<<"4:\tto Read\n";
	cout<<"5:\tto Go back to main menu\n";
	cout<<"=======================================\n";
	cout<<"Select What You Want To Do :";
	cin>>ch;
	switch(ch)
	{
	case 1:
		f.customerdata_w();
		break;
	case 2:
		f.customerdata_dlt();
		break;
	case 3:
		f.customerdata_edt();
		break;
case 4:
		f.customerdata_r();
		break;

			
	case 5:
		mainmenu();
		break;
	default:
		cout<<"wrong input";
		break;
	}
}
void payments()
{
	system("cls");
	int ch;
	
	cout<<"\t\tCUSTOMER BILL GENERATION\n";
	cout<<"========================================\n";
	cout<<"1:\tto Pay Internet Bill\n";
	cout<<"2:\tto Pay Mobile Bill\n";
	cout<<"3:\tto Go back to main menu\n";
	cout<<"========================================\n";
	cout<<"Select What You Want To Do :";
	cin>>ch;
	switch(ch)
	{
	case 1:
		f.b_internet();
		break;
	case 2:
		f.b_calls();
		break;
	case 3:
		mainmenu();
		break;
	default:
		cout<<"wrong input";
		break;
	}
}
//bill readings function defination

void filedata::b_internet()
{
system("cls");
int count=0;
char ch[10],k;
ifstream fr;
fr.open("customer.dat");

cout<<"\n>>Enter Mobile No.:\n";
cin>>ch;
while(fr.read((char*)&ob,sizeof(ob)))
{
	if(strcmp(ch,ob.mno)==0)
	count++;
	    
}
fr.close();
if(count>0)
{
ofstream fw("billi.txt");
fr.open("customer.dat");
fr.seekg(0);
while(fr.read((char*)&ob,sizeof(ob)))
{
if(strcmp(ch,ob.mno)==0)
{
				fw<<"\t\t\tInternet Bill\n";
		fw<<"\t\t\t------------------\n\n\n";
		fw<<"\t\t\t\t\tStatus:"<<ob.istatus<<'\n';
		fw<<"\tName:"<<ob.name<<'\n';
		fw<<"\tMobile No.:"<<ob.mno<<'\n';
		fw<<"\tAddress:"<<ob.address<<'\n';
		fw<<"\tAdhar No.:"<<ob.adhaarno<<"\n\n";
		fw<<"\tTotal internet usage for this month: 30GB"<<'\n';
		fw<<"\tTotal amount to be paid: Rs3000";
		
		//printing On Screen
		cout<<"\t\t\tInternet Bill\n";
		cout<<"\t\t\t------------------\n\n\n";
		cout<<"\t\t\t\t\tStatus:"<<ob.istatus<<'\n';
		cout<<"\tName:"<<ob.name<<'\n';
		cout<<"\tMobile No.:"<<ob.mno<<'\n';
		cout<<"\tAddress:"<<ob.address<<'\n';
		cout<<"\tAdhar No.:"<<ob.adhaarno<<"\n\n";
		cout<<"\tTotal internet usage for this month: 30GB"<<'\n';
		cout<<"\tTotal amount to be paid: Rs3000";
	}
}
fr.close();
fw.close();
}
else
cout<<"\n>>Record Not Found!!\n";


fr.open("customer.dat");

count=0;
fr.seekg(0);

while(fr.read((char*)&ob,sizeof(ob)))
{
	if(strcmp(ch,ob.mno)==0)
	if(strcmp(ob.istatus,"unpaid")==0)
	count++;
}

fr.close();


if(count>0)
{
	cout<<"\n\n>>You Wanted To Pay The Bill?";
	cout<<">>\nIf yes then Press y";
	cout<<">>\notherwise press n for pay later";
	k=getche();
	if(k=='y'||k=='Y')
	{
		ofstream fw2;
fw2.open("temp2.dat",ios::ate);

 ofstream fw("billi.txt");
fr.open("customer.dat");
fr.seekg(0);
while(fr.read((char*)&ob,sizeof(ob)))
{
if(strcmp(ch,ob.mno)==0)
{strcpy(ob.istatus,"paid");
		fw<<"\t\t\tInternet Bill\n";
		fw<<"\t\t\t------------------\n\n\n";
		fw<<"\t\t\t\t\tStatus:"<<ob.istatus<<'\n';
		fw<<"\tName:"<<ob.name<<'\n';
		fw<<"\tMobile No.:"<<ob.mno<<'\n';
		fw<<"\tAddress:"<<ob.address<<'\n';
		fw<<"\tAdhar No.:"<<ob.adhaarno<<"\n\n";
		fw<<"\tTotal internet usage for this month: 30GB"<<'\n';
		fw<<"\tTotal amount to be paid: Rs3000";
	}
	fw2.write((char*)&ob,sizeof(ob));
}
fr.close();
fw.close();
fw2.close();

fr.open("temp2.dat");
fw.open("customer.dat",ios::ate);  
    int sn=0;
    while(fr.read((char*)&ob,sizeof(ob)))
	{
		ob.sno=sn;
		fw.write((char*)&ob,sizeof(ob));
		sn++;
	}
fr.close();
fw.close();
}
else if(k=='n'||k=='N')
{
system("cls");


payments();
}

}
cout<<"\n>>Press b to go back to payment menu\n";
k=getche();
if(k=='b'||k=='B')
payments();
}

void filedata::b_calls()
{
system("cls");
int count=0;
char ch[10],k;
ifstream fr;
fr.open("customer.dat");

cout<<"\n>>Enter Mobile No.:\n";
cin>>ch;
while(fr.read((char*)&ob,sizeof(ob)))
{
	if(strcmp(ch,ob.mno)==0)
	count++;
	    
}
fr.close();
if(count>0)
{
ofstream fw("billc.txt");
fr.open("customer.dat");
fr.seekg(0);
while(fr.read((char*)&ob,sizeof(ob)))
{
if(strcmp(ch,ob.mno)==0)
{
				fw<<"\t\t\tCalls Bill\n";
		fw<<"\t\t\t------------------\n\n\n";
		fw<<"\t\t\t\t\tStatus:"<<ob.cstatus<<'\n';
		fw<<"\tName:"<<ob.name<<'\n';
		fw<<"\tMobile No.:"<<ob.mno<<'\n';
		fw<<"\tAddress:"<<ob.address<<'\n';
		fw<<"\tAdhar No.:"<<ob.adhaarno<<"\n\n";
		fw<<"\tTotal Calls Minute Talk in this month: 500min"<<'\n';
		fw<<"\tTotal amount to be paid: Rs1500";
		
		//printing On Screen
		cout<<"\t\t\tCalls Bill\n";
		cout<<"\t\t\t------------------\n\n\n";
		cout<<"\t\t\t\t\tStatus:"<<ob.cstatus<<'\n';
		cout<<"\tName:"<<ob.name<<'\n';
		cout<<"\tMobile No.:"<<ob.mno<<'\n';
		cout<<"\tAddress:"<<ob.address<<'\n';
		cout<<"\tAdhar No.:"<<ob.adhaarno<<"\n\n";
		cout<<"\tTotal Calls Minute Talk in this month: 500min"<<'\n';
		cout<<"\tTotal amount to be paid: Rs1500";
		
	}
}
fr.close();
fw.close();
}
else
cout<<"\n>>Record Not Found!!\n";

fr.open("customer.dat");

count=0;
fr.seekg(0);

while(fr.read((char*)&ob,sizeof(ob)))
{
	if(strcmp(ch,ob.mno)==0)
	if(strcmp(ob.cstatus,"unpaid")==0)
	count++;
}

fr.close();


if(count>0)
{
	cout<<"\n\n>>You Wanted To Pay The Bill?";
	cout<<">>\n\nIf yes then Press y";
	cout<<">>\notherwise press n for pay later";
	k=getche();
	if(k=='y'||k=='Y')
	{
		ofstream fw2;
fw2.open("temp3.dat",ios::ate);

 ofstream fw("billc.txt");
fr.open("customer.dat");
fr.seekg(0);
while(fr.read((char*)&ob,sizeof(ob)))
{
if(strcmp(ch,ob.mno)==0)
{strcpy(ob.cstatus,"paid");
		fw<<"\t\t\tCalls Bill\n";
		fw<<"\t\t\t------------------\n\n\n";
		fw<<"\t\t\t\t\tStatus:"<<ob.cstatus<<'\n';
		fw<<"\tName:"<<ob.name<<'\n';
		fw<<"\tMobile No.:"<<ob.mno<<'\n';
		fw<<"\tAddress:"<<ob.address<<'\n';
		fw<<"\tAdhar No.:"<<ob.adhaarno<<"\n\n";
		fw<<"\tTotal Calls Minute Talk in this month: 500min"<<'\n';
		fw<<"\tTotal amount to be paid: Rs1500";
	}
	fw2.write((char*)&ob,sizeof(ob));
}
fr.close();
fw.close();
fw2.close();

fr.open("temp3.dat");
fw.open("customer.dat",ios::ate);  
    int sn=0;
    while(fr.read((char*)&ob,sizeof(ob)))
	{
		ob.sno=sn;
		fw.write((char*)&ob,sizeof(ob));
		sn++;
	}
fr.close();
fw.close();
}
else if(k=='n'||k=='N')
{
system("cls");


payments();
}

}
cout<<"\n>>Press b to go back to payment menu\n";
k=getche();
if(k=='b'||k=='B')
payments();
}


void mainmenu()
{  
    system("cls");
	int ch;
cout<<"#########Account Informations System##########\n";
cout<<"Select One Option Below\n";
cout<<"\t\t1-->CUSTOMER DATABASE\n";
cout<<"\t\t2-->PAYMENTS DATABASE\n";
cout<<"\t\t3-->exit\n";
cout<<"Enter Your Choice : ";
cin>>ch;
switch(ch)
{
	case 1:
    customer();
	break;
	case 2:
	payments();
	break;
	case 3:
	exit(0);
	break;
	default:
		cout<<"\nwrong input";
		break;
		}
}

void customer::input()
{
      	
	cout<<"\Customer name: ";
	cin>>name;
	cout<<"\n Email id: ";
	cin>>email_id;
	cout<<"\n Mobile number: ";
	cin>>mno;
	cout<<"\n  Address: ";
	cin>>address;
	cout<<"\n Adhaar no:";
	cin>>adhaarno;
	strcpy(istatus,"unpaid");
	strcpy(cstatus,"unpaid");
	sno++;
}
void customer::show()
{
cout<<"\n\n\tCustomer Name-"<<name<<'\n';
cout<<"\tEmail_id-"<<email_id<<'\n';
cout<<"\tmno-"<<mno<<'\n';
cout<<"\tAddress-"<<address<<'\n';
cout<<"\tAdhaarno-"<<adhaarno<<'\n';
	
}

void filedata::customerdata_w()
{
	system("cls");
	cout<<">>Add Mode\n\n\n";
	resume();
	ofstream fw;
	fw.open("customer.dat",ios :: app);
	ob.input();
    fw.write((char*)&ob,sizeof(ob));
    fw.close();
cout<<"\n>>Record Added!!";
char k;
k=getche();
cout<<"\n>>Press b to go back to Customer Database menu\n";
k=getche();
if(k=='b'||k=='B')
customer();

}


void filedata::customerdata_r()
{
	system("cls");
	cout<<">>Read Mode\n\n\n";
int count=0;
	ifstream fr;
	char ch[10];
	fr.open("customer.dat");
	cout<<">>Enter Mobile No.:";
	cin>>ch;
while(fr.read((char*)&ob,sizeof(ob)))
{
count++;
if(count==1)
break;
}
fr.seekg(0);
if(count>0)
while(fr.read((char*)&ob,sizeof(ob)))
{if(strcmp(ch,ob.mno)==0)
ob.show();
break;
}
else 
cout<<"\nNO Record Found!!";
    fr.close();
    char k;
k=getche();
cout<<"\n>>Press b to go back to Customer Database menu\n";
k=getche();
if(k=='b'||k=='B')
customer();

}

void filedata::resume()
{

	ifstream fr;
	fr.open("customer.dat");

while(fr.read((char*)&ob,sizeof(ob)));

    fr.close();
}


void filedata::customerdata_dlt()
{
	system("cls");
	cout<<">>Delete Mode\n\n\n";
    char ch[10];
	int sn=1;
	int count=0;
	ifstream fr;
	fr.open("customer.dat");
	ofstream fw;
	fw.open("temp1.dat",ios::ate);

cout<<"\n>>Enter Mobile No.:";
cin>>ch;
while(fr.read((char*)&ob,sizeof(ob)))
{
	count++;
	if(count==1)
	break;
}

fr.seekg(0);
if(count>0)
{
while(fr.read((char*)&ob,sizeof(ob)))
	{
		if(strcmp(ch,ob.mno)==0)
		{continue;
		}
		fw.write((char*)&ob,sizeof(ob));
	}
	
    fr.close();
    fw.close();

fr.open("temp1.dat");
fw.open("customer.dat",ios::ate);  
    
    while(fr.read((char*)&ob,sizeof(ob)))
	{
		ob.sno=sn;
		fw.write((char*)&ob,sizeof(ob));
		sn++;
	}

cout<<"\n>>Record Deleted!!";
}

else 
{cout<<"\n>>Record Not Found!!";
}
fr.close();
fw.close();

char k;
k=getche();
cout<<"\n>>Press b to go back to Customer Database menu\n";
k=getche();
if(k=='b'||k=='B')
customer();
}

void filedata::customerdata_edt()
{
	system("cls");
	cout<<">>Edit Mode\n\n\n";
	int count=0;
	char ch[10];
	int e;
	int sn=1;
	ifstream fr;
	fr.open("customer.dat");
	
cout<<"\n>>Enter Mobile No.:\n";
cin>>ch;
while(fr.read((char*)&ob,sizeof(ob)))
{
	if(strcmp(ch,ob.mno)==0)
	count++;
	    
}
fr.close();
if(count>0)
{
ofstream fw;
fw.open("temp.dat",ios::ate);
fr.open("customer.dat");
fr.seekg(0);

cout<<"\n 1.Customer Name-";
cout<<"\n 2.Email_id-";
cout<<"\n 3.Address-";
cout<<"\n 4.Adhaarno-";
cout<<"\n>>Choose What You Want To Edit!!\n";
cin>>e;

while(fr.read((char*)&ob,sizeof(ob)))
	{
	    if(strcmp(ch,ob.mno)==0)
	    {
	    	if(e==1)
	    	{
			cout<<"\nCustomer Name- ";
	    	cin>>ob.name;}
	    	else if(e==2)
	{
	cout<<"\n Email id: ";
	cin>>ob.email_id;}
	
	else if(e==3)
	{
	cout<<"\n  Address: ";
	cin>>ob.address;
	}
	
	else if(e==4)
	{
	cout<<"\n Adhaar no:";
	cin>>ob.adhaarno;
		}
	}
		fw.write((char*)&ob,sizeof(ob));
	

}
    fr.close();
    fw.close();

fr.open("temp.dat");
fw.open("customer.dat",ios::ate);  
    
    while(fr.read((char*)&ob,sizeof(ob)))
	{
		ob.sno=sn;
		fw.write((char*)&ob,sizeof(ob));
		sn++;
	}
fr.close();
fw.close();
cout<<"\n>>Record Edited!!";
}
else
cout<<"\n>>Record Not Found!!";

char k;
k=getche();
cout<<"\n>>Press b to go back to payment menu\n";
k=getche();
if(k=='b'||k=='B')
customer();

}

