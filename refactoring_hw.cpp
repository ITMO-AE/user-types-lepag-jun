#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<time.h>
#include<iomanip>
#include<fstream>
#include<unistd.h> //для getpass
#include<classes.h>

using namespace std;

void manage();
void user();
void database();
void res();
void reserve();
void displaypassdetail();
void cancell();
void enquiry();

int main()
{
//    system("clear");
    int ch;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<".......WELCOME TO RAILWAY RESERVATION SYSTEM..........\n";
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    do
    {
        cout<<"^^^^^^^^^^^^^^^^^^^^^^MAIN MENU^^^^^^^^^^^^^^^^^^^^\n";
        cout<<"1.Admin mode\n2.User mode\n3.Exit\n";
        cout<<"Enter your choice:";
        cin>>ch;
        cout<<endl;
        switch(ch)

        {
        case 1:
            database();
            break;
        case 2:
            user();
            break;
        case 3:
            exit(0);
        }
    }
    while(ch<=3);
}

void database()
{
    char *password;
    const char *pass="codewithc";
    password=getpass("Enter the admininistrator password:");
    detail a;
    fstream f;
    int ch;
    if(strcmp(pass,password)!=0)
    {
        cout<<"Enter the password correctly \n";
        cout<<"You are not permitted to logon this mode\n";
        goto h;
    }
    if(strcmp(pass,password)==0)
    {
        char c;
        do
        {
            cout<<"...........ADMINISTRATOR MENU...........\n";
            cout<<"1.Create detail data base\n2.Add details\n";
            cout<<"3.Display details\n4.User management\n";
            cout<<"5.Display passenger details\n6.Return to main menu\n";
            cout<<"Enter your choice:";
            cin>>ch;


            cout<<endl;
            switch(ch)
            {
            case 1:
                f.open("t.txt",ios::out|ios::binary);
                do
                {
                    a.getdetail();
                    f.write((char *) & a,sizeof(a));
                    cout<<"Do you want to add one more record?\n";
                    cout<<"y-for Yes\nn-for No\n";
                    cin>>c;
                }
                while(c=='y');
                f.close();
                break;
            case 2:
                f.open("t.txt",ios::in|ios::out|ios::binary|ios::app);
                a.getdetail();
                f.write((char *) & a,sizeof(a));
                f.close();
                break;
            case 3:
                f.open("t.txt",ios::in|ios::out|ios::binary|ios::app);
                f.seekg(0);
                while(f.read((char *) & a,sizeof(a)))
                {
                    a.displaydetail();
                }
                f.close();
                break;
            case 4:
                manage();
                break;
            case 5:
                displaypassdetail();
                break;
            }
        }
        while(ch<=5);

        f.close();
    }
h:;
}

void reserve()
{
    int ch;
    do
    {
        cout<<"1.Reserve\n2.Return to the main menu\n";
        cout<<"Enter your choice:";
        cin>>ch;
        cout<<endl;
        switch(ch)
        {
        case 1:
            res();
            break;
        }
    }
    while(ch==1);

}

void res()
{
    char s[10]="s";
    char f[10]="f";
    int addr;
    int ad;
    int flag;
    int amt;
    detail a;
    detail b;
    fstream f1,f2;
    time_t t;
    f1.open("t.txt",ios::in|ios::out|ios::binary);
    f2.open("p.txt",ios::in|ios::out|ios::binary|ios::app);
    b.getresdet();
    while(f1.read((char *) &a,sizeof(a)))
    {
        if(a.tno==b.tno)
        {
            if(strcmp(b.clas,f)==0)
            {
                if(a.c1>=b.nosr)

                {
                    amt=a.c1fare;
                    addr=f1.tellg();
                    ad=sizeof(a.c1);
                    f1.seekp(addr-(7*ad));
                    a.c1=a.c1-b.nosr;
                    f1.write((char *) & a.c1,sizeof(a.c1));
                    if(b.con==1)
                    {
                        cout<<"Concession category:MILITARY PERSONNEL\n";

                        b.amc=b.nosr*((amt*50)/100);
                    }
                    else if(b.con==2)
                    {
                        cout<<"Concession category:SENIOR CITIZEN\n";
                        b.amc=b.nosr*((amt*60)/100);
                    }
                    else if(b.con==3)
                    {
                        cout<<"Concession category:CHILDERN BELOW FIVE\n";
                        b.amc=0.0;
                    }
                    else if(b.con==4)
                    {
                        cout<<"You cannot get any concession\n";
                        b.amc=b.nosr*amt;
                    }
                    srand((unsigned) time(&t));
                    b.pnr=rand();
                    f2.write((char *) & b,sizeof(b));
                    b.displayresdet();
                    cout<<"------------------------------------------------------\n";
                    cout<<"--------------Your ticket is reserved-----------\n";
                    cout<<"-----------------End of reservation menu-------\n";
                }
                else
                {
                    cout<<"**********Sorry req seats not available********\n";

                }
            }
            else if(strcmp(b.clas,s)==0)
            {
                if(a.c2>=b.nosr)
                {
                    amt=a.c2fare;
                    addr=f1.tellg();
                    ad=sizeof(a.c2);
                    f1.seekp(addr-(5*ad));
                    a.c2=a.c2-b.nosr;
                    f1.write((char *) & a.c2,sizeof(a.c2));
                    if(b.con==1)
                    {
                        cout<<"Concession category:MILITARY PRESONNEL\n";
                        b.amc=b.nosr*((amt*50)/100);
                    }
                    else if(b.con==2)
                    {
                        cout<<"Concession category:SENIOR CITIZEN\n";
                        b.amc=b.nosr*((amt*60)/100);
                    }
                    else if(b.con==3)
                    {
                        cout<<"Concession category:CHILDERN BELOW FIVE\n";
                        b.amc=0.0;
                    }
                    else if(b.con==4)
                    {
                        cout<<"You cannot get any concession\n";
                        b.amc=b.nosr*amt;
                    }
                    f2.write((char *) & b,sizeof(b));
                    b.displayresdet();
                    cout<<"---------------------------------------\n";
                    cout<<"--------Your ticket is reserved--------\n";
                    cout<<"------------End of reservation---------\n";
                }
                else


                {
                    cout<<"********Sorry req no of seats not available*******\n";
                }
            }


            goto h;
        }
        else
        {
            flag=0;
        }
    }
    if(flag==0)
    {
        cout<<"............Wrong train no......................\n";
        cout<<"......Enter the train no from the data base.....\n";
    }
    f1.close();
    f2.close();

h:;
}

void displaypassdetail()
{
    fstream f;
    detail b;
    f.open("p.txt",ios::in|ios::out|ios::binary);
    f.seekg(0);
    while(f.read((char *) & b,sizeof(b)))
    {
        b.displayresdet();
    }
    f.close();

}

void enquiry()
{
    fstream f;
    f.open("t.txt",ios::in|ios::out|ios::binary);
    detail a;
    while(f.read((char *) & a,sizeof(a)))
    {
        a.displaydetail();
    }

}

void cancell()
{
    char f[10]="f";
    char s[10]="s";
    int addr;
    int ad;
    int flag;
    int m;
    int d;
    float tamt;
    detail a;
    detail b;
    detail c;
    fstream f1,f2,f3;
    f1.open("t.txt",ios::in|ios::out|ios::binary);
    f2.open("p.txt",ios::in|ios::out|ios::binary);
    f3.open("cn.txt",ios::in|ios::out|ios::binary);
    cout<<"**********CANCELLATION MENU*********\n";
    c.getcancdet();
    while(f2.read((char *) & b,sizeof(b)))
    {
        if(b.pnr==c.pnr)
        {
            c.tno=b.tno;
            strcpy(c.tname,b.tname);
            strcpy(c.bp,b.bp);
            strcpy(c.dest,b.dest);
            c.nosc=b.nosr;
            for(int j=0; j<c.nosc; j++)
            {
                strcpy(c.pname[j],b.pname[j]);
                c.age[j]=b.age[j];
            }
            strcpy(c.clas,b.clas);
            if(strcmp(c.clas,f)==0)
            {
                while(f1.read((char *) & a,sizeof(a)))
                {

                    if(a.tno==c.tno)
                    {
                        a.c1=a.c1+c.nosc;
                        d=a.d;
                        m=a.m;
                        addr=f1.tellg();
                        ad=sizeof(a.c1);
                        f1.seekp(addr-(7*ad));
                        f1.write((char *) & a.c1,sizeof(a.c1));
                        tamt=b.amc;
                        if((c.d==d)&&(c.m==m))
                        {
                            cout<<"You are cancelling at the date of departure\n";
                            c.amr=tamt-((tamt*60)/100);
                        }
                        else if(c.m==m)
                        {
                            cout<<"You are cancelling at the month of departure\n";
                            c.amr=tamt-((tamt*50)/100);
                        }
                        else if(m>c.m)
                        {
                            cout<<"You are cancelling one month before the date of departure\n";
                            c.amr=tamt-((tamt*20)/100);
                        }
                        else
                        {
                            cout<<"Cancelling after the departure\n";
                            cout<<"Your request cannot be completed\n";
                        }
                        goto h;
                        c.displaycancdet();
                    }
                }
            }
            else if(strcmp(c.clas,s)==0)
            {
                while(f1.read((char *) & a,sizeof(a)))
                {

                    if(a.tno==c.tno)
                    {
                        a.c2=a.c2+c.nosc;
                        d=a.d;
                        m=a.m;
                        addr=f1.tellg();
                        ad=sizeof(a.c2);
                        f1.seekp(addr-(5*ad));
                        f1.write((char *) & a.c2,sizeof(a.c2));
                        tamt=b.amc;
                        if((c.d==d)&&(c.m==m))
                        {
                            cout<<"You are cancelling at the date of departure\n";
                            c.amr=tamt-((tamt*60)/100);
                        }
                        else if(c.m==m)
                        {
                            cout<<"You are cancelling at the month of departure\n";
                            c.amr=tamt-((tamt*50)/100);
                        }
                        else if(m>c.m)
                        {
                            cout<<"You are cancelling one month before the date of departure\n";
                            c.amr=tamt-((tamt*20)/100);
                        }
                        else
                        {
                            cout<<"Cancelling after the departure\n";
                            cout<<"Your request cannot be completed\n";
                        }
                        goto h;
                        c.displaycancdet();
                    }
                }
            }
        }
        else
        {
            flag=0;

        }
    }
h:
    if(flag==0)
    {
        cout<<"Enter the correct pnr no\n";
    }
    f1.close();
    f2.close();
    f3.close();

}

void user()
{
    login a;
    int d;
    int ch;
    cout<<"*****************************************************\n";
    cout<<"***********WELCOME TO THE USER MENU**\n";
    cout<<"****************************************************\n";
    char *password;

    fstream f;
    f.open("id.txt",ios::in|ios::out|ios::binary);
    char id[100];
    puts("Enter your id:");
    cin.getline(id, 100);
    password=getpass("Enter your password:");
    while(f.read((char *) & a,sizeof(a)))
    {
        if((strcmp(a.id,id)==0)&&(strcmp(a.pass,password)==0))
        {
            do
            {
                cout<<"1.Reserve\n2.Cancell\n3.Enquiry\n4.Return to the main menu\n";
                cout<<"Enter your choice:";
                cin>>ch;
                cout<<endl;
                switch(ch)
                {
                case 1:
                    reserve();
                    break;
                case 2:
                    cancell();
                    break;
                case 3:
                    enquiry();
                    break;
                }
            }
            while(ch<=3);
            goto j;
        }
        else
        {
            d=1;
        }
    }
    if(d==1)
    {
        cout<<"Enter your user id and password correctly\n";
    }
j:;
}

void manage()
{
    int ch;
    fstream f;
    char c;
    login a;
    cout<<".........WELCOME TO THE USER MANAGEMENT MENU........\n";
    do
    {
        cout<<"1.Create id data base\n2.Add details\n";
        cout<<"3.Display details\n4.Return to the main menu\n";
        cout<<"Enter your choice:";
        cin>>ch;
        cout<<endl;
        switch(ch)
        {
        case 1:
            f.open("id.txt",ios::out|ios::binary);
            do
            {
                a.getid();
                f.write((char *) & a,sizeof(a));
                cout<<"Do you want to add one more record\n";
                cout<<"y-Yes\nn-No\n";
                cin>>c;
            }
            while(c=='y');
            f.close();
            break;
        case 2:
            f.open("id.txt",ios::in|ios::out|ios::binary|ios::app);
            a.getid();
            f.write((char *) & a,sizeof(a));
            f.close();
            break;
        case 3:
            f.open("id.txt",ios::in|ios::out|ios::binary);

            f.seekg(0);
            while(f.read((char *) & a,sizeof(a)))
            {
                a.displayid();
            }
            f.close();
            break;
        }
    }
    while(ch<=3);
}
