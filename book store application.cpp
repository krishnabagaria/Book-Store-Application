#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

fstream myfile;
string s[100000];


struct books
{
 string name,authur,type,price;

 books *link;

  books()
  {
   link=NULL;
  }

};

class records
{
 books *start,*cur,*temp;

 public:

 records()
 {
  start=NULL;
 }

 creat_file (string n,string a,string t,string p)
 {

   if(start==NULL)
   {
    start=new books;
    start->link=NULL;
    start->name=n;
    start->authur=a;
    start->type=t;
    start->price=p;

    myfile.open ("books store.txt",ios::out | ios::app);
    myfile<<"Name_:_"<<start->name<<"__|__Authur:_"<<start->authur<<"__|__Type_:_"<<start->type<<"__|__Price_:_"<<start->price<<endl;
	myfile.close();

   }

   else
   {
    cur=start;

    while(cur->link!=NULL)
    {
     cur=cur->link;
    }

    temp=new books;
    temp->name=n;
	temp->authur=a;
    temp->type=t;
    temp->price=p;
    temp->link=NULL;
    cur->link=temp;

   myfile.open ("books store.txt",ios::out | ios::app);

	 myfile<<"Name_:_"<<temp->name<<"__|__Authur_:_"<<temp->authur<<"__|__Type_:_"<<temp->type<<"__|__Price_:_"<<temp->price<<endl;
	myfile.close();

   }

    }

    void print_now()
    {
     cur=start;
     int c;
     cout<<"Book #"<<" ---> Name\tAuthur\t\tType\t\tprice"<<endl;

     for(c=1;cur->link!=NULL;c++)
     {
      cout<<"     "<<c<<" ---> "<<cur->name<<"\t"<<cur->authur<<"\t\t"<<cur->type<<"\t\t"<<cur->price<<endl;
      cur=cur->link;
     }

      cout<<"     "<<c<<" ---> "<<cur->name<<"\t"<<cur->authur<<"\t\t"<<cur->type<<"\t\t"<<cur->price<<endl;
 }

 void search(string n)
 {
 	int i,k=0;
 	string ss;
 	myfile.open("books store.txt",ios::in);

 	while(!myfile.eof())
 	{
 		myfile>>s[k];
 		k++;
	 }
	 k--;
	 myfile.close();

for( i=0;i<k;i++)
{

		if(s[i].find(n)>0 && s[i].find(n)<s[i].length())
		{
			break;
		}

}

if(i!=k)
{
    cout<<s[i];
char mod;
	cout<<"\nWant to modify Book Data ..?? (y/n) ";
	cin>>mod;

	if(mod=='y'|| mod=='Y')
	{
		string n,an,tp,p;
		cout<<"Enter book name ";
		cin>>n;

		cout<<"Enter Authur Name ";
		cin>>an;
		cout<<"Enter Book Type :";
		cin>>tp;

		cout<<"Enter Book Price :";
		cin>>p;

		s[i]="Name_:_"+n+"__|__Authur_:_"+an+"__|__Type_:_"+tp+"__|__Price_:_"+p;

	 myfile.open("books store.txt",ios::out);
	 for(  int j=0;j<k;j++)
	 {myfile<<s[j];
	 myfile<<endl;
	 }
	 myfile.close();

}

 }

 else
 {
 	cout<<"\nRecord Not found "<<endl;
 }
}

void search1(string n)
 {
 	int i,k=0;
 	string ss;
 	myfile.open("books store.txt",ios::in);

 	while(!myfile.eof())
 	{
 		myfile>>s[k];
 		k++;
	 }

	 k--;
	 myfile.close();

for( i=0;i<k;i++)
{

		if(s[i].find(n)>0 && s[i].find(n)<s[i].length())
		{
			break;
		}

}

if(i!=k)
{
    cout<<endl;
    cout<<s[i];
}

else
{
        cout<<"\nRecord Not found ";
}
cout<<endl<<endl;
 }

 void print()
 {
   myfile.open("books store.txt",ios::in);
 	int l=0;
 	while(!(myfile.eof()))
 	{
 		myfile>>s[l];
 		cout<<s[l]<<endl;
 		l++;
	 }
	 myfile.close();
 }


void administrator()
{
    int number,i;
    int ch,k,j;
    string n,an,t,p;
    int del;
    char name[30];
    char password[30];


		cout<<"\n\t\t\t\t \t---------- ADMIN Login -------";
		cout<<"\n\n Enter Admin Name: ";
		cin>>name;
		cout<<"\n Enter password:";
		cin>>password;

		if( (strcmp(name,"krishna") ==0)  &&
		    (strcmp(password,"krishna") == 0))
		    {


	system("CLS");

do
    {
        cout<<"\n\n\t\t\t\t\t===============ADMIN  ACCOUNT=================";
 cout<<"\n\nWhat You want to do with your Books now"<<endl;
 cout<<"\n1-Save new Book\n";
 cout<<"2-Delete any book"<<endl;
 cout<<"3-Search and Modify"<<endl;
 cout<<"4-See All list of books "<<endl;
 cout<<"5-Back To Menu\n"<<endl;

  cout<<"Enter your choice :";
 cin>>ch;

    system("CLS");
 switch(ch)
 {
  case 1:
   cout<<"\n\t============================ADD NEW BOOK============================\n\n";
   cout<<"How many books you want to save"<<endl;
    cin>>number;

    for(i=0;i<number;i++)
    {
  cout<<"\nEnter Name \t";
  cin>>n;


  cout<<"\nEnter Authur name \t";
  cin>>an;

  cout<<"Enter Type \t";
  cin>>t;


  cout<<"Enter Price \t";
  cin>>p;

  creat_file(n,an,t,p);
    }
   cout<<"Book has been Saved in your store "<<endl;
   break;

  case 2 :
     cout<<"\n\t=========================DELETE Book============================\n\n";


 	myfile.open("books store.txt",ios::in);
 	  k=0;


 	while(myfile.good())
 	{
 		myfile>>s[k];
 		cout<<k+1;
 		cout<<"-"<<s[k]<<endl;

 		k++;
	 }

	 myfile.close();
	 cout<<"Which Book data you want to delete ..? ";
	 cin>>del;
	 s[del-1]="";
	 for(int i=del-1;i<k;i++)
     {
         s[i]=s[i+1];
     }
    k--;
	 cout<<"\nBook record has been deleted "<<endl;
	 myfile.open("books store.txt",ios::out);
	 for(  j=0;j<k;j++)
	 {myfile<<s[j];
	 myfile<<endl;
	 }

	 myfile.close();
     break;

   case 3:
   	cout<<"\n\t===============SEARCH AND UPDATE BOOK data=====================\n\n";
   	cout<<"Enter NAME of Book to search it from Store\t";
   	getline(cin,n);
   	getline(cin,n);
   	search(n);
   	break;

   	case 4:
	cout<<"\n\t=====================PRINTING ALL LIST============================\n\n";
   	print();
   	break;

  case 5:
   return ;

  default:
   cout<<"\t----------Invalid----------"<<endl;

 }
    }while(ch<=5);
		    }

}

void user()
{
    int ch;
    string  n;

    do
        {
            cout<<"\t\t\t\t=============USER ACCOUNT============="<<endl;
    cout<<"1-See All list of books"<<endl;
    cout<<"2-Search Book Data"<<endl;
    cout<<"3-Read online books "<<endl;
    cout<<"4-Back To Menu\n"<<endl;

    cout<<"Enter your choice  :";
    cin>>ch;

    system("CLS");

    switch(ch)
 {
	case 1:
	cout<<"\n\t=====================PRINTING ALL LIST============================\n\n";
   	print();
   	break;



   case 2:
   	cout<<"\n\t===============SEARCH BOOK data=====================\n\n";
   	cout<<"Enter Name of Book to search it from Store\t";
   	getline(cin,n);
    getline(cin,n);
   	search1(n);
   	break;

   	case 3:
   	cout<<"\n\t=====================SEARCH BOOK ONLINE============================\n\n";
   system("start https://books.google.com/");
   		break;

  case 4:
      return;;

  default:
   cout<<"\t----------Invalid----------"<<endl;

 }
    }while(ch<=4);
}

};





int main()
{
 records l1;
 int number,i,p;
 int ch,k,j;
 string n,an,t;


do
    {
 cout<<"\n\t===================================================================\n\n";
 cout<<"\t\t\t BOOKS STORE\n";
 cout<<"\n\t===================================================================\n\n";
 cout<<"\n\t===================================================================\n\n";
 cout<<"\n\t1- ENTER NEW BOOK\n";
 cout<<"\n\t2- SEARCH AND UPDATE THE BOOKS DATA\n";
 cout<<"\n\t3- DELETE BOOK FROM YOUR Store\n";
 cout<<"\n\t4- SEE ALL THE LIST OF BOOKS ANY TIME\n";
 cout<<"\n\t5- YOU CAN SEARCH ANY BOOK ONLINE\n";
 cout<<"\n\t===================================================================\n\n";
 cout<<"\n\t========================MENU MENU===============================\n"<<endl;


cout<<"1. Adminstrator"<<endl;
cout<<"2. User"<<endl;
cout<<"3. Exit"<<endl;
cout<<"Enter your choice  :";
cin>>ch;

system("CLS");

 switch(ch)
 {
     case 1:
         l1.administrator();
         break;
     case 2:
        l1.user();
        break;
     case 3:
          cout<<"\n\t====================LIST OF Books added Now======================\n\n";
          l1.print_now();
          break;
 }

}while(ch<3);

 return 0;
}


