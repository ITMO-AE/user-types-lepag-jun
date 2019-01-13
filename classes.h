#ifndef CLASSES_H
#define CLASSES_H

using std::cout;
using std::cin;

class login
{
public:
    char id[100];
    char pass[100];
    char *password;
    void getid()
    {
        cout<<"Enter your id:";
//        gets(id);
        cin.getline(id, 100);
        password=getpass("Enter the password:");
        strcpy(pass,password);
    }
    void displayid()
    {
        cout<<"Id:";
        puts(id);
        cout<<"Password:";
        puts(pass);
    }
};

class detail
{
public:
    int tno;
    char tname[100];
    char bp[10];
    char dest[100];
    int c1,c1fare;
    int c2,c2fare;
    int d,m,y;
    int pnr;
    char pname[10][100];
    int age[20];
    char clas[10];
    int nosr;
    int i;
    int con;
    float amc;
    int nosc;
    float amr;

    void getdetail()
    {
        cout<<"Enter the details as follows\n";
        cout<<"Train no:";
        cin>>tno;
        cout<<"Train name:";
        cin.getline(tname, 100);
        cout<<"Boarding point:";
        cin.getline(bp, 10);
        cout<<"Destination pt:";
        cin.getline(dest, 100);
        cout<<"No of seats in first class & fare per ticket:";
        cin>>c1>>c1fare;
        cout<<"No of seats in second class & fare per ticket:";
        cin>>c2>>c2fare;
        cout<<"Date of travel:";
        cin>>d>>m>>y;
    }
    void displaydetail()
    {
        cout<<tno<<"\t"<<tname<<"\t"<<bp<<"\t"<<dest<<"\t";
        cout<<c1<<"\t"<<c1fare<<"\t"<<c2<<"\t"<<c2fare<<"\t";
        cout<<d<<"-"<<m<<"-"<<y<<"\t\n";
    }

    void getresdet()
    {
        cout<<"Enter the details as follows\n";
        cout<<"Train no:";
        cin>>tno;
        cout<<"Train name:";
        cin.getline(tname, 100);
        cout<<"Boarding point:";
        cin.getline(bp, 10);
        cout<<"Destination pt:";
        cin.getline(dest, 100);
        cout<<"No of seats required:";
        cin>>nosr;
        for(i=0; i<nosr ; i++)
        {
            cout<<"Passenger name:";
            cin.getline(pname[i], 100);
            cout<<"Passenger age:";
            cin>>age[i];
        }
        cout<<"Enter the class f-first class s-second class:";
        cin.getline(clas, 10);
        cout<<"Date of travel:";
        cin>>d>>m>>y;
        cout<<"Enter the concession category\n";
        cout<<"1.Military\n2.Senior citizen\n";
        cout<<"3.Children below 5 yrs\n4.None\n";
        cin>>con;
        cout<<"............END OF GETTING DETAILS............\n";
    }

    void displayresdet()
    {
        cout<<"...............................................\n";
        cout<<"...............................................\n";
        cout<<"Pnr no:"<<pnr;
        cout<<"\nTrain no:"<<tno;
        cout<<"\nTrain name:";
        puts(tname);
        cout<<"Boarding point:";
        puts(bp);
        cout<<"Destination pt:";
        puts(dest);
        cout<<"No of seats reserved:"<<nosr;
        for(i=0; i<nosr; i++)
        {
            cout<<"Passenger name:";
            puts(pname[i]);
            cout<<"Passenger age:"<<age[i];
        }

        cout<<"\nYour class:";
        puts(clas);
        cout<<"\nDate of reservation:"<<d<<"-"<<m<<"-"<<y;
        cout<<"\nYour concession category:"<<con;
        cout<<"\nYou must pay:"<<amc<< "\n";
        cout<<"***********************************************\n";
        cout<<".........END OF RESERVATION.................\n";
        cout<<"***********************************************\n";
    }

    void getcancdet()
    {
        cout<<"Enter the details as follows\n";
        cout<<"Pnr no:";
        cin>>pnr;
        cout<<"Date of cancellation:";
        cin>>d>>m>>y;
        cout<<"...........END OF GETTING DETAILS...........\n";
    }
    void displaycancdet()
    {
        cout<<"...........................................\n";
        cout<<"...........................................\n";
        cout<<"Pnr no:"<<pnr;
        cout<<"\nTrain no:"<<tno;
        cout<<"\nTrain name:";
        puts(tname);
        cout<<"Boarding point:";
        puts(bp);

        cout<<"Destination pt:";
        puts(dest);
        cout<<"\nYour class:";
        puts(clas);
        cout<<"no of seats to be cancelled:"<<nosc;
        for(i=0; i<nosc; i++)
        {
            cout<<"Passenger name:";
            puts(pname[i]);
            cout<<"passenger age:"<<age[i];
        }
        cout<<"\nDate of cancellation:"<<d<<"-"<<m<<"-"<<y;
        cout<<"\nYou can collect:"<<amr<<"rs\n";
        cout<<"*****************************************\n";
        cout<<".........END OF CANCELLATION.............\n";
        cout<<"*****************************************\n";
    }
};

#endif // CLASSES_H
