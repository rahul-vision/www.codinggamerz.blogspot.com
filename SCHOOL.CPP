#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<process.h>
class file
{
private:
int roll;
int age;
int phy,chem,mat,eng,cs;
char grade;
char name[100];
float per;
public:
void input();
void show();
void cal();
char *getn()
{
return name;
}
};
file fileobj;
void file::cal()
{
per=(phy+chem+mat+eng+cs)/5;
if(per>=90)
grade='A';
else if(per<=89&&per>=70)
grade='B';
else if(per<70&&per>=60)
grade='C';
else if(per<60&&per>=50)
grade='D';
else if(per<50&&per>=33)
grade='E';
else
grade='F';
}

void file::input()
{
cout<<"Enter the roll";
cin>>roll;
cout<<"\nEnter the age";
cin>>age;
cout<<"\nEnter the name";
gets(name);
cout<<"\nEnter the marks of physics";
cin>>phy;
cout<<"\nEnter the marks of chemistry";
cin>>chem;
cout<<"\nEnter the marks of maths";
cin>>mat;
cout<<"\nEnter the marks of english";
cin>>eng;
cout<<"\nEnter the marks computer science";
cin>>cs;
cal();
}
void file::show()
{
cout<<"Roll"<<"\t"<<"Age"<<"\t"<<"name"<<"\t"<<"phy"<<"\t"<<"chem"<<"\t"<<"math"<<"\t"<<"eng"<<"\t"<<"comp"<<"\t"<<"per"<<"\t"<<"grade"<<endl;
cout<<roll<<"\t"<<age<<"\t"<<name<<"\t"<<phy<<"\t"<<chem<<"\t"<<mat<<"\t"<<eng<<"\t"<<cs<<"\t"<<per<<"\t"<<grade;
}
void Create();
void Add();
void Display();
void search();
void Modify();
void Delete();
void intro();
fstream fil;
int main()
{
int opt;
while(1)
{
clrscr();
cout<<"\t\t\tSTUDENT RECORD SYSTEM"<<endl;
cout<<"\n1.Create File\n"<<endl;
cout<<"2.Add New Record \n"<<endl;
cout<<"3.Display Record\n"<<endl;
cout<<"4.Display Particular Record\n"<<endl;
cout<<"5.Modify Record\n"<<endl;
cout<<"6.Delete Record \n"<<endl;
cout<<"7.introduction of programmer\n"<<endl;
cout<<"8.Exit From the Program\n"<<endl;
cout<<"Enter your Option => "<<endl;
cin>>opt;
switch(opt)
{
case 1:
{
Create();
cout<<"\n\tDisplay Main Menu(y/n)"<<endl;
getch();
break;
}
case 2:
{
Add();
cout<<"\n\tDisplay Main Menu(y/n)"<<endl;
getch();
break;
}
case 3:
{
Display();
cout<<"\n\n----------------------------------FINISH-----------------------------------"<<endl;
cout<<"\n\n\n\tDisplay Main Menu(y/n)"<<endl;
getch();
break;
}
case 4:
{
search();
cout<<"\n\tDisplay Main Menu(y/n)"<<endl;
getch();
break;
}
case 5:
{
Modify();
cout<<"\n\tDisplay Main Menu(y/n)"<<endl;
getch();
break;
}
case 6:
{
Delete();
cout<<"\n\tDisplay Main Menu(y/n)"<<endl;
getch();
break;
}
case 7:
{
intro();
getch();
break;
}
case 8:
{
exit(0);
}
default:
{
cout<<"Wrong Choice....Press Key For View the Main Menu";
getch();
clrscr();
}
}
}
}

void Create()
{ clrscr();
char ch='y';
fil.open("binary.dat",ios::out| ios::binary);
while(ch=='y' || ch =='Y')
{
fileobj.input();
fil.write((char*)&fileobj, sizeof(fileobj));
cout<<"Want to Continue.....(y/n)";
cin>>ch;
}
fil.close();
}

void Add()
{  clrscr();
char ch='y';
fil.open("binary.dat",ios::in| ios::binary);
while(ch=='y' || ch =='Y')
{
fileobj.input();
fil.write((char*)&fileobj, sizeof(fileobj));
cout<<"Want to Continue.....(y/n)";
cin>>ch;
}
fil.close();
}

void Display()
{ clrscr();
fil.open("binary.dat",ios::in| ios::binary);
if(!fil)
{
cout<<"File not Found";
exit(0);
}
else
{
fil.read((char*)&fileobj, sizeof(fileobj));
while(!fil.eof())
{
fileobj.show();
fil.read((char*)&fileobj, sizeof(fileobj));
}
}
fil.close();
}

void search()
{  clrscr();
char n[100];
cout<<"Enter Name that should be searched:";
gets(n);
fil.open("binary.dat",ios::in| ios::binary);
if(!fil)
{
cout<<"File not Found";
exit(0);
}
else
{
fil.read((char*)&fileobj, sizeof(fileobj));
while(!fil.eof())
{
if(strcmp(n,fileobj.getn())==0)
{
fileobj.show();
cout<<"Press enter Key...."<<endl;
getch();
}
else
{
cout<<"Press enter Key....For Search"<<endl;
getch();
}
fil.read((char*)&fileobj, sizeof(fileobj));
}
}
fil.close();
}
void Modify()
{   clrscr();
char n[100];
cout<<"Enter Name that should be searched:";
gets(n);
fil.open("binary.dat",ios::in| ios::out|ios::binary);
if(!fil)
{
cout<<"File not Found";
exit(0);
}
else
{
fil.read((char*)&fileobj, sizeof(fileobj));
while(!fil.eof())
{
if(strcmp(n,fileobj.getn())==0)
{
fil.seekg(0,ios::cur);
cout<<"Enter New Record.."<<endl;
fileobj.input();
fil.seekp(fil.tellg() - sizeof(fileobj));
fil.write((char*)&fileobj, sizeof(fileobj));
}
else
{
cout<<"Press enter Key....For Search"<<endl;
getch();
}
fil.read((char*)&fileobj, sizeof(fileobj));
}
}
fil.close();
}

void Delete()
{ clrscr();
char n[100];
cout<<"Enter Name that should be Deleted :";
gets(n);
ofstream o;
o.open("new.dat",ios::out|ios::binary);
fil.open("binary.dat",ios::in| ios::binary);
if(!fil)
{
cout<<"File not Found";
exit(0);
}
else
{
fil.read((char*)&fileobj, sizeof(fileobj));
while(!fil.eof())
{
if(strcmp(n,fileobj.getn())!=0)
{
o.write((char*)&fileobj, sizeof(fileobj));
}
else
{
cout<<"Press enter Key....For Search"<<endl;
getch();
}
fil.read((char*)&fileobj, sizeof(fileobj));
}
}
o.close();
fil.close();
remove("binary.dat");
rename("new.dat", "binary.dat");
}
void intro()
{
clrscr();
gotoxy(35,6);
cout<<"PROJECT WORK ON";
gotoxy(31,11);
cout<<"STUDENT MANAGEMENT SYSTEM";
cout<<"\n\n\nNAME:RAHUL GUPTA";
cout<<"\n\nSCHOOL:MOUNT OLIVET SR.SEC SCHOOL";
cout<<"\n\nCLASS:12th SCIENCE";
cout<<"\n\nsubmitted to:MR. RAKESH SINHA SIR";
cout<<"\n\n\nPRESS (ENTER) FOR THE MAIN MENU";
}
