#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;


class login
{
public:
    login(){}
    void login_page();

};
class admin: public login
{
private:
    string pas="group2";


public:
    admin(){}
   int adminstr();
    void display_members();
    void product_details();
    void vendor_details();
    void remove_product();
    void enter_product();

};
class ven: public login
{private:
    char user_name[200];
public:
    ven(){}
    void vendors();
   int cs_details();
   int prdcts_purchase();
    int billing();
};
int admin::adminstr(){
    //login page after it run display_members if loged in properly
system("CLS");
admin ad;
int t;
char *ch=NULL;
ch= new char[20];
rr:
cout<<"enter password--->";
cin>>ch;
if(ch==pas)
{
  display_members();
}
else{
        cout<<"password is incorrect\n1.Try Again\t2.Go back---> ";
        cin>>t;
        if(t==1)
            goto rr;
        else
            return(1);
}
}
void admin::product_details()
{ char sata[100];
int z;
  fstream fin;
  fin.open("kk123.csv",ios::in);

 while(fin)
  {z=0;
     if(z<4)
     {fin.getline(sata,50,',');
     cout<<sata<<"  ";
     z++;
  }

  }
  char f;
fin.close();
cout<<"\n\nenter the cold storage number---->";
cin>>f;

char data[100];
int i,r;
char str[20][20][20];
 r=0;
  fstream file;
switch(f)
{
            case '1':
                system("CLS");
                cout<<"\tthe deatails of ganapth cold storage are\n ";
                file.open("data1.csv",ios::in);
                char str[20][20][20];

                    while(file)
                    {
                        for(i=0;i<5;i++)
                           {file.getline(str[r][i],19,',');cout<<str[r][i]<<"\t";}
                        file.getline(str[r][i],19,'\n');cout<<endl;
                        r++;
                    }
                 file.close();
                   break;
  case '2':

     cout<<"\tMaa Tara Cold Storage and Ice Factory  the product details are\n ";

	file.open("data2.csv",ios::in);


	while(file)
    {
        for(i=0;i<5;i++)
           {file.getline(str[r][i],19,',');cout<<str[r][i]<<"\t";}
        file.getline(str[r][i],19,'\n');cout<<endl;
        r++;
    }
 file.close();
   break;
    case '3':

     cout<<"\tMaa Tara Cold Storage and Ice Factory the product details are\n ";

	file.open("data3.csv",ios::in);

	while(file)
    {
        for(i=0;i<5;i++)
           {file.getline(str[r][i],19,',');cout<<str[r][i]<<"\t";}
        file.getline(str[r][i],19,'\n');cout<<endl;
        r++;
    }
 file.close();
   break;

    case '4':

     cout<<"\tOrissa State Co-op Market. Fed, Bhubaneswar the product details are\n ";

	file.open("data4.csv",ios::in);


	while(file)
    {
        for(i=0;i<5;i++)
           {file.getline(str[r][i],19,',');cout<<str[r][i]<<"\t";}
        file.getline(str[r][i],19,'\n');cout<<endl;
        r++;
    }
 file.close();
   break;
    case '5':

     cout<<"\tMahabir Ice & Cold Storage Bhubaneswar the product details \n ";

	file.open("data5.csv",ios::in);


	while(file)
    {
        for(i=0;i<5;i++)
           {file.getline(str[r][i],19,',');cout<<str[r][i]<<"\t";}
        file.getline(str[r][i],19,'\n');cout<<endl;
        r++;
    }
 file.close();
   break;

}
//case'2' more same 5 cases with different csv files

}
void admin::vendor_details()
{fstream file;
	file.open("bill123.csv");
	char str[20][20][20];
	int r=0,i;
	while(file)
    {
        for(i=0;i<5;i++)
           {file.getline(str[r][i],19,',');cout<<str[r][i]<<"  ";}
        file.getline(str[r][i],19,'\n');cout<<endl;
        r++;
    }
 file.close();



}
void admin::enter_product()
{char pr[50];
int a,b,c,d,e;

cout<<"you are ready to enter a new product in the list\n";
cout<<"enter name of the product\n";
cin>>pr;
cout<<"enter prices of the product\n";
cin>>a>>b>>c>>d>>e;
fstream fout;
fout.open("products123.csv",ios::out | ios::app);
fout<<pr<<","<<a<<","<<b<<","<<c<<","<<d<<","<<e<<"\n";
fout.close();

}
void admin::remove_product()
{ char *prd=NULL;
    prd = new char[30];
    fstream file, file2;
    file.open("products123.csv",ios::in);
    ofstream file1("temp.csv");
    file1.close();
    file2.open("temp.csv",ios::in|ios::out);
    char str[30][20][20];
    char temp[30][20][20];
    int r=0,i;
    while(file)
    {
        for(i=0;i<5;i++)
            file.getline(str[r][i],19,',');
        file.getline(str[r][i],19,'\n');
        r++;
    }
    cout<<"The products are :\n ";
    for(i=1;i<20;i++)
        cout<<str[i][0]<<" \n";
    cout<<"\nEnter the product name, you want to remove: ";
    cin>>prd;

    int j;
    for(i=0;i<r;i++)
    {
        if(strcasecmp(prd ,str[i][0])) //compares the prd and str. if it doesn't matches then it stores the line in the temp.csv
        {
            for(j=0;j<5;j++)
            file2<<str[i][j]<<",";
        file2<<str[i][j]<<"\n";
        }
        else
            r--;
    }

    file.close();
        file2.close();

    //delete the original file and rename the temp file to the original
    remove("products123.csv");
    rename("temp.csv","products123.csv");
    r=0;
    file2.open("products123.csv");
    while(file2)
    {
        for(i=0;i<3;i++)
            file2.getline(temp[r][i],19,',');
        file2.getline(temp[r][i],19,'\n');
        r++;
    }
//    cout<<"The vehicles registered are : ";
//    for(i=1;i<20;i++)
//        cout<<temp[i][0]<<" ";
    delete [] prd;}

void admin::display_members()
{ admin ad;
cout<<"in display";
system("CLS");
    do
    {
        char ch;
        cout<<"\n"<<"1.Get product details"<<endl;
        cout<<"\n"<<"2.To get vendors details "<<endl;//showing all details of billing
         cout<<"\n"<<"3.To  remove a  product  "<<endl;//product 123 should be updated
        //cout<<"\n"<<"4.To change the price of product and availability "<<endl;//of a particular csv file of data
          cout<<"\n"<<"4.To enter  a  product  "<<endl;
        cout<<"\n"<<"5.Exit---->"<<endl<<endl;


        cin>>ch;
        cout<<endl;
       switch(ch)
        {
            case '1':
                ad.product_details(); // Gives information about product
                break;
            case '2':
                ad.vendor_details();   // Gives information about stock details
                break;
            case '3':
               ad.remove_product();
                break;

          case '4':
               ad.enter_product();
                break;
         case '5':
             exit(0);

        }
    }while(1);
}
void login::login_page()
{
    login ob_log; admin ob_admin; ven ob_ven;
    cout<<endl;
    uu:
    cout<<"1.ADMIN \t\t\t2.VENDORS\t\t\t3.Exit---->";
    int check,p;
    cout<<"\nYour choice: ";
    cin>>check;

    if(check == 1)
      { p=ob_admin.adminstr();
         if(p==1)
            goto uu;

      }

    else if(check == 2){
        ob_ven.vendors();

    }
    else if(check == 3)
        exit(0);
    else
    {
          cout<<"Invalid Choice\n"<<endl;
          ob_log.login_page();
    }
}

int ven::cs_details()
{ven ob_ven;
 char data[100];
int z;
  fstream fin;
  fin.open("kk123.csv",ios::in);

 while(fin)
  {z=0;
     if(z<4)
     {fin.getline(data,50,',');
     cout<<data<<"  ";
     z++;

  }}
char W;
qqqp:
    char str[20][20][20];
    fstream file;
	int r=0,i;
	int yb=0;
	bool status=false; char ch[20];
cout<<"\nEnter the number of cold storage to see its products--->\n\n";

cin>>W;
switch(W)
{
case('1')://start of case 1
    for(int i=0;i<7;i++)
        cout<<"    ";
    cout<<"*** Ganpath Ice & Coldstorage(P) Ltd,Pitapalli,Bhubaneswar***"<<endl;
    for(int i=0;i<7;i++)
        cout<<"    ";
    cout<<"*                   WELCOMES YOU            *"<<endl;
    for(int i=0;i<7;i++)
        cout<<"    ";
    cout<<" ********fstream file";
	file.open("data1.csv");

	while(file)
    {
        for(i=0;i<5;i++)
            file.getline(str[r][i],19,',');
        file.getline(str[r][i],19,'\n');
        r++;
    }
   cout<<"The products registered are->\n ";
    for(i=1;i<r;i++)
        {
           if(yb<5)
            {cout<<str[i][0]<<" ";
             yb++;
            }
            else{
                cout<<endl;
                yb=0;
            }

        }
      prd1_no:

	cout<<"\nEnter product :";

	cin>>ch;
    for(i=0;i<20;i++)
    {
        if(!strcasecmp(ch,str[i][0]))
        {
            status=true;
            break;
        }
    }
    if(status)
        {
            status = 0;
             cout<<"The product is: "<<str[i][0]<<endl;
            cout<<"The availability of product is: "<<str[i][1]<<endl;
            cout<<"The import date is: "<<str[i][2]<<endl;
            cout<<"longlasting duration is: "<<str[i][3]<<" kg"<<endl;
            cout<<"If seasional?: "<<str[i][4]<<endl;
            cout<<"Price per kg is: "<<str[i][5]<<endl;
            cout<<"\tDo you want to continue with products enquiry:\n1.yes\n 2.to go back\n3.vendors menu\n4.exitt-> ";
            int cho;
            cin>>cho;
            if(cho==1)
                goto prd1_no;
            else if(cho==2)
                goto qqqp;
           else if(cho==4)
           exit(0);
           else
           return(1);

    }
break;

case('2'):
    for(int i=0;i<7;i++)
        cout<<"    ";
    cout<<"***Maa Tara Cold Storage and Ice Factory, Balugaon***"<<endl;
    for(int i=0;i<7;i++)
        cout<<"    ";
    cout<<"*                   WELCOMES YOU            *"<<endl;
    for(int i=0;i<7;i++)
        cout<<"    ";
    cout<<" ********       *******************************      ********"<<endl;

	file.open("data1.csv");

	while(file)
    {
        for(i=0;i<5;i++)
            file.getline(str[r][i],19,',');
        file.getline(str[r][i],19,'\n');
        r++;
    }
   cout<<"The products registered are->\n ";
    for(i=1;i<r;i++)
        {
           if(yb<5)
            {cout<<str[i][0]<<" ";
             yb++;
            }
            else{
                cout<<endl;
                yb=0;
            }

        }
      prd2_no:

	cout<<"\nEnter product :";

	cin>>ch;
    for(i=0;i<20;i++)
    {
        if(!strcasecmp(ch,str[i][0]))
        {
            status=true;
            break;
        }
    }
    if(status)
        {
            status = 0;
             cout<<"The product is: "<<str[i][0]<<endl;
            cout<<"The availability of product is: "<<str[i][1]<<endl;
            cout<<"The import date is: "<<str[i][2]<<endl;
            cout<<"longlasting duration is: "<<str[i][3]<<" kg"<<endl;
            cout<<"If seasional?: "<<str[i][4]<<endl;
            cout<<"Price per kg is: "<<str[i][5]<<endl;
             cout<<"\tDo you want to continue with products enquiry:\n1.yes\n 2.to go back\n3.vendors menu\n4.exitt-> ";
            int cho;
            cin>>cho;
            if(cho==1)
                goto prd2_no;
            else if(cho==2)
                goto qqqp;
           else if(cho==4)
           exit(0);
           else
           return(1);

    }
break;
case('3'):
    for(int i=0;i<7;i++)
        cout<<"    ";
    cout<<"*** Mahalaxmi Cold Storage (P) Ltd., Patrapara***"<<endl;
    for(int i=0;i<7;i++)
        cout<<"    ";
    cout<<"*                   WELCOMES YOU            *"<<endl;
    for(int i=0;i<7;i++)
        cout<<"    ";
    cout<<" ********       *******************************      ********"<<endl;

	file.open("data3.csv");

	while(file)
    {
        for(i=0;i<5;i++)
            file.getline(str[r][i],19,',');
        file.getline(str[r][i],19,'\n');
        r++;
    }
   cout<<"The products registered are->\n ";
    for(i=1;i<r;i++)
        {
           if(yb<5)
            {cout<<str[i][0]<<" ";
             yb++;
            }
            else{
                cout<<endl;
                yb=0;
            }

        }
      prd3_no:

	cout<<"\nEnter product :";

	cin>>ch;
    for(i=0;i<20;i++)
    {
        if(!strcasecmp(ch,str[i][0]))
        {
            status=true;
            break;
        }
    }
    if(status)
        {
            status = 0;
             cout<<"The product is: "<<str[i][0]<<endl;
            cout<<"The availability of product is: "<<str[i][1]<<endl;
            cout<<"The import date is: "<<str[i][2]<<endl;
            cout<<"longlasting duration is: "<<str[i][3]<<" kg"<<endl;
            cout<<"If seasional?: "<<str[i][4]<<endl;
            cout<<"Price per kg is: "<<str[i][5]<<endl;
               cout<<"\tDo you want to continue with products enquiry:\n1.yes\n 2.to go back\n3.vendors menu\n4.exitt-> ";
            int cho;
            cin>>cho;
            if(cho==1)
                goto prd3_no;
            else if(cho==2)
                goto qqqp;
           else if(cho==4)
           exit(0);
           else
           return(1);

    }
break;
case('4')://start of case 1
    for(int i=0;i<7;i++)
        cout<<"    ";
    cout<<"*** Orissa State Co-op Market. Fed, Bhubaneswar***"<<endl;
    for(int i=0;i<7;i++)
        cout<<"    ";
    cout<<"*                   WELCOMES YOU            *"<<endl;
    for(int i=0;i<7;i++)
        cout<<"    ";
    cout<<" ********       *******************************      ********"<<endl;

	file.open("data4.csv");


	while(file)
    {
        for(i=0;i<5;i++)
            file.getline(str[r][i],19,',');
        file.getline(str[r][i],19,'\n');
        r++;
    }
   cout<<"The products registered are->\n ";
    for(i=1;i<r;i++)
        {
           if(yb<5)
            {cout<<str[i][0]<<" ";
             yb++;
            }
            else{
                cout<<endl;
                yb=0;
            }

        }
      prd4_no:

	cout<<"\nEnter product :";

	cin>>ch;
    for(i=0;i<20;i++)
    {
        if(!strcasecmp(ch,str[i][0]))
        {
            status=true;
            break;
        }
    }
    if(status)
        {
            status = 0;
             cout<<"The product is: "<<str[i][0]<<endl;
            cout<<"The availability of product is: "<<str[i][1]<<endl;
            cout<<"The import date is: "<<str[i][2]<<endl;
            cout<<"longlasting duration is: "<<str[i][3]<<" kg"<<endl;
            cout<<"If seasional?: "<<str[i][4]<<endl;
            cout<<"Price per kg is: "<<str[i][5]<<endl;
              cout<<"\tDo you want to continue with products enquiry:\n1.yes\n 2.to go back\n3.vendors menu\n4.exitt-> ";
            int cho;
            cin>>cho;
            if(cho==1)
                goto prd4_no;
             else if(cho==2)
                goto qqqp;
           else if(cho==4)
           exit(0);
           else
           return(1);

    }
break;
case('5'):
    for(int i=0;i<7;i++)
        cout<<"    ";
    cout<<"*** Mahabir Ice & Cold Storage Bhubaneswar(patia)***"<<endl;
    for(int i=0;i<7;i++)
        cout<<"    ";
    cout<<"*                   WELCOMES YOU            *"<<endl;
    for(int i=0;i<7;i++)
        cout<<"    ";
    cout<<" ********       *******************************      ********"<<endl;

	file.open("data5.csv");

	while(file)
    {
        for(i=0;i<5;i++)
            file.getline(str[r][i],19,',');
        file.getline(str[r][i],19,'\n');
        r++;
    }
   cout<<"The products registered are->\n ";
    for(i=1;i<r;i++)
        {
           if(yb<5)
            {cout<<str[i][0]<<" ";
             yb++;
            }
            else{
                cout<<endl;
                yb=0;
            }

        }
      prd5_no:

	cout<<"\nEnter product :";

	cin>>ch;
    for(i=0;i<20;i++)
    {
        if(!strcasecmp(ch,str[i][0]))
        {
            status=true;
            break;
        }
    }
    if(status)
        {
            status = 0;
             cout<<"The product is: "<<str[i][0]<<endl;
            cout<<"The availability of product is: "<<str[i][1]<<endl;
            cout<<"The import date is: "<<str[i][2]<<endl;
            cout<<"longlasting duration is: "<<str[i][3]<<" kg"<<endl;
            cout<<"If seasional?: "<<str[i][4]<<endl;
            cout<<"Price per kg is: "<<str[i][5]<<endl;
              cout<<"\tDo you want to continue with products enquiry:\n1.yes\n 2.to go back\n3.vendors menu\n4.exitt-> ";
            int cho;
            cin>>cho;
            if(cho==1)
                goto prd5_no;
 else if(cho==2)
                goto qqqp;
           else if(cho==4)
           exit(0);
           else
           return(1);

    }
break;
}

}
int ven::prdcts_purchase()
{//call from ven::vendors
    ven ob_ven;
    char oou[20];
    char date[50];

    char mystring[6];
    int hy,price,gg,ss;
    bool status=false;
    float kil;
    char re[10];
    fstream file;
    file.open("products123.csv");
    char str[20][18][10];
    int r=0,i,c;
    int row;
    while(file)
    {   if(r==0)
               { for(i=0;i<5;i++)
               {               file.getline(str[r][i],19,',');cout<<str[r][i]<<"     ";

                }

                   file.getline(str[r][i],19,'\n');cout<<str[r][i]<<endl;
              r++;}//endof if
              else{
                    for(i=0;i<5;i++)
                  {
                     file.getline(str[r][i],19,',');cout<<str[r][i]<<"\t    ";
                  }
                   file.getline(str[r][i],19,'\n');cout<<str[r][i]<<endl;
        r++;}//end of else

    }//endof while

    file.close();
    /*for(row=0;row<r-1;row++)
    {
        for(c=0;c<5;c++)
            cout<<str[row][c]<<"***  ";
        cout<<endl;
    }*/
    //storing the csv file in a array of stirng
    qwe:

    cout<<"\nenter the product name--->";
    cin>>oou;
     for(row=0;row<r;row++)
           {
                if(!strcasecmp(oou,str[row][0]))
                {
                status=true;
                break;
              }

    }//end of for oou is name of product to be written in file
    if(status)//strat of outer if
      { status=0;
        cld_:
        cout<<"\nenter the cold storage name--->";
        cin>>re;//re is name of storage to be written in file bil123
             for(i=0;i<6;i++)
              {
                if(!strcasecmp(re,str[0][i]))
                 {
                      price=atoi(str[row][i]);//int value = atoi(myString.c_str());
                      //cout<<price+5;
                      status=true;
                     break;
             }
          }//end of inner for
           if(status)//inner if
          {cout<<"\nenter number of kilos--->";
          cin>>kil;
          cout<<"\nenter todays date(dd/mm/yy)--->";
          cin>>date;//kil is to  be entered in file
          //here have to add user_name,date, oou,re,price,kil,kil*price in a bill123 csv file
            ofstream mybill;
            mybill.open("bill123.csv",ios::out| ios::app) ;/*myfile.open ("vendors123.csv", ios::out | ios::app);*/

          mybill <<user_name<<","<<date<<","<<oou<<","<<re<<","<<price<<","<<kil<<","<<kil*price<<"\n";
          mybill.close();

          cout<<"1.add more products \t2.Go to see your billing list\n3.vendors menu\t4.exit";
          cin>>ss;
          if(ss==1)
            goto qwe;
          else if(ss==2)
            ob_ven.billing();
            else if(gg==4)
                exit(0);
             else
                return(1);
          }
          else{cout<<"cold storage doesn't exist\n1.renter cold storage name \t2.enter product\n3.vendors menu\t4.exit";//start of inner else
            cin>>gg;
              if(gg==1)
              goto cld_;
              else if(gg==2)
                        goto qwe;
              else if(gg==4)
                exit(0);
             else
                return(1);
        }
}//end of outer if
else//outer else start
        {cout<<"the product is not in the list\n1.enter product name\t2.To see vendors menu 3.exit";
          cin>>hy;
          if(hy==1)
            goto qwe;
          else if(hy==2)
           {cout<<"in hy else if";return(1);}
        else
            exit(0);
        }//end of outer else
}//end of function 2
int ven::billing()
{getchar();
int ed;
char dte[50];
int s=0;
int fgh;
cout<<"*****welcome to billing ------->"<<user_name<<"****\n";
fstream file;
cout<<"1.TO SEE YOUR BILLING DETAILS\n2.GO TO VENDORS MENU\n3.EXIT--->";
cin>>ed;
file.open("bill123.csv");
char str2[20][20][10];
char arr2[20][20][10];
int row,c;
	int r=0,i,j,rf;


	while(!file.eof())
    {   for(i=0;i<6;i++)
           file.getline(str2[r][i],19,',');
        file.getline(str2[r][i],19,'\n');
         r++;
    }getchar();
 int sum=0;
    if(ed==1)
         {for(i=0;i<r;i++)
         {
             if(!(strcasecmp(user_name,str2[i][0])))
             {
                 for(j=1;j<7;j++)
                   {
                    cout<<str2[i][j]<<"  ";
                     sum=sum+atoi(str2[i][6]);
                    }
              cout<<endl;}
        } cout<<"                             Total="<<sum;
        cout<<"\n1.VENDORS MENU\t2.EXIT--->";
             cin>>rf;
             if(rf==2)
                goto tyr;
                else
                   goto  byt;
         }
        else if(ed==3)
            {tyr:
                exit(0);}
else
{ byt:
     return (1);
}

getchar();


}

//end of function 3
void ven::vendors()
{ ven ob_ven;  login ob_log;int ii;
cout<<"\t\t****Welcome Dear VENDORS****"<<endl;
adminpp:

cout<<"1.REGISTER\t\t\t2.LOG IN\t\t3.EXIT--->";
cin>>ii;
int y;
char ch;
char u[20];
char o[200];

char ll[200];
if(ii==1)
{
     char u[100];
    char o[100];
    ofstream myfile;
    myfile.open ("vendors123.csv", ios::out | ios::app);
      cout<<"enter user_name--->";
     cin>>u;
     cout<<"enter password-->";
     cin>>o;
      myfile << u<<","<<o<<"\n";
          myfile.close();
          goto adminpp;
}

else if(ii==2)//loginstart
   { int ol;
       fstream file;
    file.open("vendors123.csv");


    char str[20][20][20];

    int r=0,i,c,d;
    int rr=0;
    while(file)
    {
        for(i=0;i<1;i++)
            file.getline(str[r][i],19,',');
        file.getline(str[r][i],19,'\n');
        r++;
    }
//fully right for loop and all
  cout<<"\n";

    bool status=false;
    rrr:
    cout<<"\nenter your user_name--->";
    cin>>user_name;
for(i=0;i<20;i++)
    {

      if(!strcasecmp(user_name,str[i][0]))
        {
            status=true;
            break;
        }
    }
    if(status)
        {   if((strcasecmp(user_name,str[i][0])==0))
            {  cout<<"\nenter your passowrd--->";
               cin>>ll;
               if(!strcasecmp(ll,str[i][1]))
                 goto fff;
                else
               { cout<<"\npassword is incorrect--->";
                  goto rrr;
                }


           }}
    else
     {cout<<"the user name doesn't exist\n";
      cout<<"enter 1. for opening a new account \t 2.to retry--->";
      cin>>y;
       if(y==1)
         goto adminpp;
        else
            goto rrr;
     }
     fff:
   cout<<"****WELCOME****" <<user_name;
   cout<<"\n\t\t1.COLD STORAGE DETAILS \t2.PRODUCTS COMPARE & PURCHASE   \n\t\t3.BILLING \t4.Back to Login page\nYour Choice: ";
   int chc;
    cin>>chc;
    if(chc==1)
        { d=ob_ven.cs_details();
           if(d==1)
            goto fff;

        }
    else if(chc==2)
       {
          d=ob_ven.prdcts_purchase();
          if(d==1)
            goto fff;
       }
    else if(chc==3)
     {d=ob_ven.billing();
          if(d==1)
            goto fff;}
    else
        ob_log.login_page();

}
else if(ii==3)
    exit(0);
}
int main()
{ system("color 3F");
    for(int i=0;i<7;i++)
        cout<<"    ";
    cout<<"   !!!!KHURDA COLD STORAGE NETWORK!!!!"<<endl;
    for(int i=0;i<7;i++)
        cout<<"    ";
    cout<<"*             WELCOMES YOU            *"<<endl<<endl;

login ob_log;
    ob_log.login_page();
}
