#include<bits/stdc++.h>
#include<iomanip>
#include<fstream>
#define clr system("cls");
using namespace std;
class customer;
class movie;
class date;
class Time;
class ticket;
void upthefile();
void mv_downthefile();
void user1();
void home();
void bye();
#define tab cout<<"\t\t\t";
#define pres cout<<"\t\t\tchoice: ";
class seatxy
{
public:
    int x,y;
    seatxy():x(0),y(0) {}
};
vector<customer>cslist;
vector<movie>movslist;
int cspos=-1;
int mvpos=-1;
class seatplan
{
public:
    int ar[5][6];
    seatplan()
    {
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<6; j++)
            {
                ar[i][j]=1;
            }
        }
    }

};
class date
{
public:
    int mm,dd,yy;

};
class Time
{
public:
    int hr,mi,sec;

};
class ticket
{

public:
    int tckamt;
    static int itemno;
    char name[20];
    date d;
    char tm[6];
    int prc;
    int netmt;
    int hallno;
    date ddt;
    seatxy sitara[5];
    void show()
    {
        cout<<"\nTicket No: ";
        cout<<itemno;
        cout<<"\n\nName of the Movie: ";
        cout<<name;
        cout<<"\n\nReleasing Date : ";
        cout<<d.mm<<"-"<<d.dd<<"-"<<d.yy;
    }

char* gettktime(){
return tm;}

    int retno()
    {
        return itemno;

    }

};

int ticket::itemno=0;


class movie
{
protected:
    int mx=20;
    char mvname[50];
    char show_time[6];
    // string trailer;
    int tcktprice;
    int seat=30;
    int hall;

    seatplan sp;
public:

    void changesp(int a,int b)
    {
        sp.ar[a][b]=0;
    }
    seatplan getseatplan()
    {
        return sp;
    }
    date dt;
    friend class admin;

    char* getmvname()
    {

        return mvname;
    }
    char* getshow_time()
    {
        return show_time;
    }
    int seatavail()
    {
        return seat;
    }
    bool upseat(int a,int b)
    {
        seatplan cc;
        cc=movslist[mvpos].getseatplan();
        if(cc.ar[a][b]!=1)
        {
            return 0;
        }
        if(a<0 or a>4 or b<0 or b>5)return 0;
        seat--;
        return 1;
    }


    void mv_setdata()
    {
        clr;
        cout<<"\t\t\t\t\t\tADDING A MOVIE\n\n\n";
        cout<<"\t\t\tMovie name: ";
        cin>>mvname;
        for(int i=0; i<50; i++)
        {
            if(mvname[i]=='\n')break;
            mvname[i]=toupper(mvname[i]);

        }

        cout<<"\t\t\tMovie time :\n\t\t\t(09:00/12:00/15:00/18:00/21:00): ";
        cin>>show_time;
        cout<<"\t\t\tDate: ";
        char ch;
        cin>>dt.dd>>ch>>dt.mm>>ch>>dt.yy;
        cout<<"\t\t\tPrice TK: ";
        cin>>tcktprice;
        cout<<"\t\t\tHall No: ";
        cin>>hall;


    }
    void getshow()
    {
        cout<<"Movie name      : "<<mvname<<" "<<endl;
        cout<<"Show time       : "<<show_time<<" "<<endl;
        cout<<"Date            : "<<dt.dd<<'/'<<dt.mm<<'/'<<dt.yy<<endl;
        cout<<"Available seat  : "<<seat<<" "<<endl;
        cout<<"ticket price    : "<<tcktprice<<" "<<endl;
        cout<<endl<<endl;
    }
    int getpice()
    {
        return tcktprice;
    }
    int gethall()
    {
        return hall;
    }
    date getdate()
    {
        return dt;
    }

char* gettime(){
return show_time;}


};

class person
{
public:
    char username[10];
    char password[10];

    virtual bool login()=0;

};
class admin: public person
{

public:
    friend class movie;
    virtual bool login()
    {
        clr;

        bool loginSucess=false;
        cout<<"\n\t\t\t\tADMIN PANEL - LOGIN \n\n\n\n"<<endl;

return true;
        while(1)
        {
            char uu[]="chandan";
            char pp[]="12345";

            cout<<"\t\t\tEnter Your Username: ";
            cin>> username;

            cout<<"\n\t\t\tEnter Your Password: ";
            cin>> password;
            if(strcmp(username,uu)==0 and strcmp(password,pp)==0)
            {
                clr;
                cout<<"\n\t\t\t\t      \tSUCCESSFULLY LOGGED IN\n\n" ;
                loginSucess = true;
            }
            else
            {
                clr;
                 cout<<"\n\t\t\t\tADMIN PANEL - LOGIN \n\n\n\n"<<endl;
                cout<<"\t\t\tIncorrect username or password\n\n\n\n\n";
            }
            if(loginSucess==true)return true;
        }

        return false;
    }
    void addmovie()
    {

        int x=1;

        int i=0;
        while(1)
        { clr;
            cout<<"\t\t\tTO add a movie press (1) \n\t\t\tTo go back (2)\n\t\t\t:";
            movie xx;
            cin>>x;
            clr;
            if(x==2)break;

            if(x==1)
            {
                xx.mv_setdata();
                movslist.push_back(xx);
                upthefile();
            }

            i++;
        }

    }


    void showalluser();

    void changemv()
    {
        cout<<"\t\t\t1. Change \n\t\t\t2. Delete\n\t\t\t3. Go Back"<<endl;
        pres
        int ch;
        cin>>ch;
        if(ch==1)
        {
            clr;
            cout<<"\t\t\tEnter movie name: ";
            char mv[20];
            gets(mv);
            for(int i=0; i<50; i++)
            {
                if(mv[i]=='\n')break;
                mv[i]=toupper(mv[i]);

            }
            movie x;
            mvpos=0;
            for(auto it:movslist)
            {
                x=it;
                if(strcmp(x.getmvname(),mv)==0)
                {
                    clr;
                    cout<<"\t\t\tREWRITING MOVIE DATA\n\n\n";
                    movslist[mvpos].mv_setdata();
                    upthefile();
                    cout<<"\t\t\tMOIVE UPDATED SUCCESSFULLY\n";
                    break;
                }
                mvpos++;
            }
            clr;
            cout<<"\n\t\t\tNot found"<<endl;
            changemv();
        }
        else if(ch==2)
        {
            admin v;

            here:
                clr;
            cout<<"\t\t\t1. Delete all movies"<<endl;
            cout<<"\t\t\t2. Delete a single movie"<<endl;
            tab cout<<"3. Go back\n";
            pres
            int choice;
            cin>>choice;
            if(choice==1){
                    cout<<"\t\t\tAre you sure to delete all movies?[y/n]"<<endl;
                    pres
            char y;
            cin>>y;
            if(y=='y'){
                movslist.clear();
                upthefile();}
                else{
                    goto here;
                }

            }
            else if(choice==2){
                     v.showallmv();
            cout<<"enter the movie position to delete: ";
            cin>>mvpos;
            mvpos--;
            int i=0;
            for(auto it=movslist.begin(); it!=movslist.end(); it++)
            {
                if(i==mvpos)
                {
                    movslist.erase(it);
                    upthefile();
                    clr;
                    cout<<"\t\t\tMOVIE DELETED\n";
                    break;
                }
                i++;
            }
            cout<<"\t\t\tPREES ANYTHING TO GO BACK\n";
            char hh;
            cin>>hh;

            this->changemv();
        }
        }
        else {
             this->changemv();
        }


    }


    void showallmv()
    {
        clr;
        ifstream file;
        file.open("MOVIES.DAT",ios::binary|ios::in);
        file.seekg(0);
        movie yy;
        int i=1;
        file.read((char*)&yy,sizeof(movie));
        while(!file.eof())
        {
            cout<<i<<')'<<endl;
            yy.getshow();
            file.read((char*)&yy,sizeof(movie));

            i++;

        }
        char ch;
        cout<<"\t\t\tpress any to return\n";
        cin>>ch;
        clr;
    }



};

class card
{
protected:
    char cno[17];
    char exdt[6];
    char CVV[4];
public:
    void setcard()
    {
        cout<<"\tEnter card Number        : ";
        cin>>cno;
        cout<<"\tEnter Expire Date (mm/yy): ";
        cin>>exdt;
        cout<<"\tEnter Pin(3digit)        :";
        cin>>CVV;
    }
    char* getno()
    {
        return cno;
    }
    char* getx()
    {
        return exdt;
    }
    char* getcvv()
    {
        return CVV;
    }
};
class bkash
{
protected:
    char bkshno[12];
    char pin[5];
public:
    bkash()
    {
        bkshno[0]='0';
        bkshno[1]=='\n';
    }

};

class customer : public person
{
protected:
    char name[20];
    char phone[11];
    char email[50];
    // card cc;
    int top=-1;
    ticket x[5];
    int purcout=0;
    //bkash bb;

public:
    friend class ticket;
    char* getname()
    {
        return name;
    }
    int getpur()
    {
        return purcout;
    }
    void getall()
    {


        cout<<"\nName          : ";
        cout<<name;
        cout<<"\nPhone         : +880";
        cout<<phone;
        cout<<"\nEmail         : "<<email;
        cout<<"\nUsername      : ";
        cout<<username;
        cout<<"\nPassword      : ";
        cout<<"*****";
        cout<<"\nTicket bought : "<<purcout;
        cout<<endl<<endl;
        purcout=0;
    }
    char* getun()
    {
        return username;
    }
    char* getps()
    {
        return password;
    }
    virtual bool login()
    {
        clr;

cout<<"\t\t\t\t\tUSER LOGIN\n\n\n";
        char ar[10];
        cout<<"\t\t\tEnter username: ";
        cin>>ar;
        cout<<"\n\t\t\tPassword: ";
        char pss[10];
        cin>>pss;
        customer tmp;
        cspos=-1;
        for(auto i:cslist)
        {
            tmp=i;
            cspos++;
            if(strcmp(tmp.getun(),ar)==0 and strcmp(tmp.getps(),pss)==0)
            {
                clr;
                return true;
            }

        }
        cspos=-1;
        return false;

    }
    void showtickts()
    {
        int tt=top;
        if(tt==-1)
        { clr;
            cout<<"\n\n\t\t\tHAVEN'T DONE ANY PURCHASE YET\n\n\t\t\t1. To view showtime\n\t\t\t0. To return: ";
            int ff;
            cin>>ff;
            if(ff==1)this->view_showtime();
            else return;
        }
        tt++;
        for(int i=0; i<tt; i++)
        {

            cout<<"\n\n\n\t\t*********************************************";
            cout<<"\n\t\t                 DETAILS                  ";
            cout<<"\n\t\t*********************************************";
            cout<<"\n\n\t\tNAME                           :"<<this->getname();
            cout<<"\n\n\t\tMOVIE                          :"<<x[i].name;
            cout<<"\n\n\t\tDATE                           :"<<x[i].ddt.dd<<"/"<<x[top].ddt.mm<<"/"<<x[top].ddt.yy;
            cout<<"\n\n\t\tSHOWTIME                       :"<<x[i].tm;
            cout<<"\n\n\t\tPRICE                          :"<<x[i].netmt/x[top].tckamt;
            cout<<"\n\n\t\tQUANTITY                       :"<<x[i].tckamt;
            cout<<"\n\n\t\tHALL NO                        :"<<x[i].hallno;
            cout<<"\n\n\t\tNET AMOUNT\t               :TK."<<x[i].netmt;
            cout<<"\n\n\t\tSEATNO                  :";
            int j=x[i].tckamt;
            j--;
            while(1)
            {
                if(j<0)break;
                cout<<'('<<x[top].sitara[j].x<<','<<x[top].sitara[j].y<<')'<<" ";
                j--;

            }
            cout<<"\n\n\t\t*********************************************\n\n\n";
        }


    }

    void registration1()
    {
        clr;
        cout<<"\t\t\t\t\tCREAT A NEW ACCOUNT\n\n\n";
        cout<<"\t\t\tName: ";
        cin>>name;
        for(int i=0; i<20; i++)
        {
            if(name[i]=='\0')break;
            name[i]=toupper(name[i]);
        }
        cout<<"\t\t\tPhone: +880";
        cin>>phone;
        cout<<"\t\t\tEmail: ";
        cin>>email;
        cout<<"\t\t\tSet an username: ";
        cin>>username;
        cout<<"\t\t\tset password: ";
        cin>>password;
        while(sizeof(password)<4)
        {
            cout<<"\t\t\tSet an password(must be minimum 4 characters)\n";
            cin>>password;
        }

        cslist.push_back(*this);

        upthefile();
        /*   ofstream infile;
           infile.open("userdata.dat",ios::app|ios::binary);

           infile.write(reinterpret_cast<char*>(this),sizeof(*this));
           infile.close();
           */

//mv_downthefile();
        //cout<<"Set payment:";
        //cc.setcard();
    }

    void searchmv()
    {
        movie temp;
        char ar[20];
        clr;
        cout<<"\t\t\tEnter movie name to search :";
        cin>>ar;
        for(int i=0; i<20; i++)
        {
            if(ar[i]=='\n')break;
            ar[i]=toupper(ar[i]);
        }
        mvpos=-1;
        for(auto i:movslist)
        {
            mvpos++;
            temp=i;
            if(strcmp(temp.getmvname(),ar)==0)
            {
                movie yy;
                yy=movslist[mvpos];
                cout<<endl<<endl;
                cout<<setw(5)<<setw(15)<<"MOVIE"<<setw(15)<<"DATE"<<setw(12)<<"SHOW"<<setw(18)<<"AVAILABLE SEAT"<<setw(10)<<"  PRICE\n\n---------------------------------------------------------------------------";
                cout<<endl<<endl;
                cout<<setw(5)<<setw(15)<<yy.getmvname();
                if(yy.dt.dd==9) cout<<setw(10)<<'0'<<yy.dt.dd;
                else cout<<setw(10)<<yy.dt.dd;
                cout<<'/'<<yy.dt.mm<<'/'<<yy.dt.yy<<setw(10)<<yy.getshow_time();
                cout<<setw(10)<<yy.seatavail()<<setw(13)<<yy.getpice();
                cout<<"\n\n\n\t\t\tTo buy press 1\n\t\t\tElse 0\n";
                int kk;
                cin>>kk;
                if(kk==1)
                {
                    buytickt();
                    return;
                }
                else
                {
                    mvpos=-1;
                    user1();
                }
            }


        }
        cout<<"\t\t\tNOT FOUND"<<endl;
    }



    void view_showtime()
    {
        clr;
        cout<<"\n\n\t\t\t";
        cout<<setw(5)<<"SN"<<setw(15)<<"MOVIE"<<setw(17)<<"DATE"<<setw(12)<<"SHOW"<<setw(18)<<"AVAILABLE SEAT"<<setw(10)
            <<"  PRICE\n\n\t\t\t---------------------------------------------------------------------------";
        cout<<endl<<endl;

        movie yy;
        int i=1;

        for(auto it:movslist)
        {
            yy=it;

            cout<<"\t\t\t";
            cout<<setw(5)<<i<<") "<<setw(15)<<it.getmvname();
            if(yy.dt.dd==9) cout<<setw(10)<<'0'<<yy.dt.dd;
            else cout<<setw(10)<<yy.dt.dd;
            cout<<'/'<<yy.dt.mm<<'/'<<yy.dt.yy<<setw(10)<<yy.getshow_time();
            cout<<setw(10)<<yy.seatavail()<<setw(13)<<yy.getpice();

            i++;
            cout<<endl<<endl;

        }
        int ch;
        cout<<"\t\t\tPress 1 to select movie\n\t\t\tPress 0 to back: \n";
        cin>>ch;
        if(ch==1)
        {
            cout<<"\t\t\tSelect the movie Number: ";

            cin>>mvpos;
            mvpos--;
            this->buytickt();
        }
        else
        {
            user1();
        }


    }
    void showseats()
    {
        seatplan xy;
        xy=movslist[mvpos].getseatplan();
        clr;
        cout<<"\t\t\t\t\t\t\tSEATS";
        cout<<"\n\t\t\t\t      -------------------------------------------\n\n\n";
        cout<<"  \t\t\t\t\t   1      2      3      4      5      6\n";

        for(int i=0; i<5; i++)
        {
            for(int j=0; j<6; j++)
            {
                if(xy.ar[i][j]==1)
                {

                    if(j==0)cout<<"\t\t\t\t\t"<<i+1<<" [ ]    ";
                    else cout<<"[ ]    ";
                }
                else
                {
                    if(j==0)cout<<"\t\t\t\t\t"<<i+1<<" [X]    ";
                    else cout<<"[X]    ";

                }

            }

            cout<<"\n\n";
        }
        cout<<"\t\t\t\t\t========================================\n";
        cout<<"\t\t\t\t\t              MOVIE SCREEN\n";
        cout<<"\t\t\t\t\t========================================\n";
        cout<<"[ ]available seats\n[X]booked\n\n\n";
    }



    void buytickt()
    {


        if(top>=10)
        {
            cout<<"\t\t\tcant buy more tickets"<<endl;
            user1();
        }

        showseats();

        cout<<"\t\t\tEnter the number of tickets: (MAX 5)\n";
        int gg=6;
        while(gg>5)
            cin>>gg;
        if(30-movslist[mvpos].seatavail()+gg>30)
        {
            cout<<"\t\t\tnot enough seats\npress 1 to check seat left: ";
            int x;
            cin>>x;
            if(x==1)cout<<movslist[mvpos].seatavail()<<endl;
        }
        seatxy a1;

        top++;
        int hh;
        x[top].netmt=gg*movslist[mvpos].getpice();
        x[top].hallno=movslist[mvpos].gethall();
        x[top].ddt=movslist[mvpos].getdate();
        strcpy(x[top].tm,movslist[mvpos].gettime());
        strcpy(x[top].name,movslist[mvpos].getmvname());
        int i=0;
        cout<<"\t\tCHOOSE YOUR SEAT CAREFULLY\n\n";
        while(gg--)
        {

uu:
            cout<<"\t\tenter seat no(x space y): ";
            cin>>a1.x>>a1.y;
            i++;
            x[top].tckamt=i;
            if(x[top].tckamt>=6)
            {
                cout<<"\nMAX TICKET REACHED"<<endl;
                return;
            }
            hh=movslist[mvpos].upseat(a1.x-1,a1.y-1);
            if(hh==0)
            {
                cout<<"\n\t\tINVAILD INPUT\n";
                goto uu;
            }
            x[top].sitara[x[top].tckamt-1].x=a1.x;
            x[top].sitara[x[top].tckamt-1].y=a1.y;
//movslist[mvpos].sp.ar[a1.x-1][a1.y-1]=0;
            movslist[mvpos].changesp(a1.x-1,a1.y-1);
        }
        viewtkt();

        upthefile();
        user1();
    }
    void makepaymt();
    void viewtkt()
    {
        clr;
        cout<<"\n\n\n\t\t*********************************************";
        cout<<"\n\t\t                 DETAILS                  ";
        cout<<"\n\t\t*********************************************";
        cout<<"\n\n\t\tNAME                           :"<<getname();
        cout<<"\n\n\t\tMOVIE                          :"<<x[top].name;
        cout<<"\n\n\t\tDATE                           :"<<x[top].ddt.dd<<"/"<<x[top].ddt.mm<<"/"<<x[top].ddt.yy;
        cout<<"\n\n\t\tSHOWTIME                       :"<<x[top].tm;
        cout<<"\n\n\t\tPRICE                          :"<<x[top].netmt/x[top].tckamt;
        cout<<"\n\n\t\tQUANTITY                       :"<<x[top].tckamt;
        cout<<"\n\n\t\tHALL NO                        :"<<x[top].hallno;
        cout<<"\n\n\t\tNET AMOUNT\t               :TK."<<x[top].netmt;
        cout<<"\n\n\t\tSEATNO                  :";
        int i=x[top].tckamt;
        i--;
        while(1)
        {
            if(i<0)break;
            cout<<'('<<x[top].sitara[i].x<<','<<x[top].sitara[i].y<<')'<<" ";
            i--;

        }
        cout<<"\n\n\t\t*********************************************";
        cout<<"\n\nto make payment press 1\nto go back 0\n:";
        int ch;
        cin>>ch;
        if(ch==1)
        {
            this->makepaymt();
        }
        else if(ch==0)
        {
            user1();
        }
    }


};
void admin::showalluser()
{
    int i=1;

    for(auto it:cslist)
    {
        cout<<i<<')'<<endl;
        customer x;
        x=it;
        x.getall();
        i++;
    }


}
void customer::makepaymt()
{

    char ps[10];
    int c;
    int i=0;
    cout<<"Enter your password :";
yy:
    if(i>=3)
    {
        cout<<"\t\t\ttry again\n";
        return;
    }
    cin>>ps;

    if(strcmp(ps,cslist[cspos].getps())==0)
    {
        cout<<"payment done\n\n\n";
        purcout++;
        upthefile();
    }
    else
    {
        i++;
        cout<<"\t\t\tWrong password\n\t\t\ttry again\n\n\t\t\t: ";
        goto yy;
    }
    cout<<"\n\t\tenter 0 to go back"<<endl;
    cin>>c;



}






class amount: public ticket
{
    float price,netamt,amt;
    int qty;
public:
    amount():netamt(0.0),amt(0.0) {}
    void add();
    void calculate();
    void pay();
    float retnetamt()
    {
        return netamt;
    }

};
void ui();
void amount::calculate()
{
    netamt=qty*price;
}


void amount::pay()
{

    cout<<"\nPRICE                       :"<<price;
    cout<<"\nQUANTITY                    :"<<qty;
    cout<<"\nNET AMOUNT           :TK."<<netamt;

}
void home()
{
    clr;
    ui();

}
void user1()
{
    clr;
    cout<<"\t\t\tUSER PANEL\n\t\t\t====================================\n\n\n\n";
    cout<<"\t\t\tWELCOME "<<cslist[cspos].getname()<<endl<<endl;
    cout<<"\t\t\t1. View movie\n"
        <<"\t\t\t2. Search movie\n"<<
        "\t\t\t3. Show my tickets\n"<<
        "\t\t\t4. Logout"<<endl;
        cout<<"\n\n\t\t\tPRESS: ";


    int x;


    while(1)
    {
        cin>>x;
        if(x==1)
        {
            cslist[cspos].view_showtime();
            char ll;
            cout<<"\t\t\tPress 0 to return";
            cin>>ll;
            user1();
        }
        if(x==2)
        {
            cslist[cspos].searchmv();
            char pp;
            cout<<"\t\t\tPress any thing to go back\n";
            cin>>pp;
            user1();
        }
        if(x==3)
        {
            cslist[cspos].showtickts();
            char pp;
            cout<<"\t\t\tPress any thing to go back\n";
            cin>>pp;
            user1();
        }
        if(x==4)break;
    }
    ui();
}

void ui()
{
    clr;
    int x;

    cout<<"\t\t\t1. LOGIN AS ADMIN" <<endl;
    cout<<"\t\t\t2. LOGIN AS USER"<<endl;
    cout<<"\t\t\t3. (EXIT)\n"<<endl;

    cin>>x;
    if(x==1)
    {
        clr;
        admin x1;
        int yy;
        x1.login();
here:
        cout<<" \t\t\t\t\t\tADMIN PANEL\n\t\t\t============================================================\n";
        cout<<"\t\t\t1. Add Movie"<<endl;
        cout<<"\t\t\t2. View All Movie" <<endl;
        cout<< "\t\t\t3. View User "<<endl<<
            "\t\t\t4. Change Movie"<<endl;
        cout<<"\t\t\t5. Logout"<<endl;
        cout<<"\n\t\t\t\tYour Choice:";





        cin>>yy;
        clr;
        switch(yy)
        {
        case 1:
        {
            x1.addmovie();

            break;

        }
        case 2:
        {
            x1.showallmv();

            break;
        }
        case 5:
        {

            home();
            break;
        }
        case 3:
        {

            x1.showalluser();
            break;
        }
        case 4:
        {

            x1.changemv();
            break;
        }

        }
        goto here;


    }
    else if(x==2)
    {
        customer c1,c2;
coco:
        int ch;
 clr;
        cout<<"\t\t\t1. Create A New Account\n\t\t\t2. Login\n\t\t\t0. to go back\n\t\t\tpress: ";

        cin>>ch;
        clr;
        if(ch==1)
        {

            c1.registration1();


            goto coco;
        }
        else if(ch==2)
        {
            if(c1.login()==false)
            {
                cout<<"\n\n\t\t\tuser not found\n\n";
                goto coco;

            }
            else
            {
                clr;
                cout<<"\t\t\tLogged in successfully\n";

            }


        }
        else ui();
        user1();
    }
    else
    {
        clr;
        bye();
    }
}

void upthefile()
{
    ofstream file;
    movie x;
    file.open("MOVIES.DAT",ios::binary);
    for(auto it:movslist)
    {
        x=it;
        file.write(reinterpret_cast<char*>(&it),sizeof(movie));

    }
    file.close();


    customer y;
    ofstream cs;
    cs.open("userdata.dat",ios::binary);

    for(auto i:cslist)
    {
        y=i;
        cs.write(reinterpret_cast<char*>(&y),sizeof(customer));


    }
    cs.close();
}
void mv_downthefile()
{

    movie x;
    ifstream file;
    file.open("MOVIES.DAT",ios::binary|ios::in);
    file.seekg(0);

    while(!file.eof())
    {
        file.read(reinterpret_cast<char*>(&x),sizeof(movie));
        movslist.push_back(x);
    }
    movslist.pop_back();
    file.close();
}
void cs_downthefile()
{

    customer y;
    ifstream cs;
    cs.open("userdata.dat",ios::binary|ios::in);
    cs.seekg(0);
    while(!cs.eof())
    {

        cs.read(reinterpret_cast<char*>(&y),sizeof(customer));
        cslist.push_back(y);

    }
    cslist.pop_back();
    cs.close();

}


void welcome()
{
    cout<<"\t\t\t\t\tMOVIE TICKET MANGEMENT SYSTEM";
    cout<<"\n          ========================================================================================";
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n          press any  to  continue:";
    char a;
    cin>>a;
}
void bye()
{
    cout<<"A program by TEAM 26\n\n\n\t\tBRAMUEL CHANDAN HEMBROM\n\t\tROLL: 407\n\n\n\t\tAZMAIN FAYEK\n\t\tROLL: 399"<<endl;
    char a;
    cin>>a;

    exit(0);

}

int main()
{
    mv_downthefile();
    cs_downthefile();

    welcome();
    ui();


    return 0;
}
