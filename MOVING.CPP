																																																																																																																																#include<iostream.h>
#include<conio.h>
#include<dos.h>
void main()
{
clrscr();
int i,j;

for(i=0;i<30;i++)
{
gotoxy(3,3) ;
for(j=0;j<i;j++)
cout<<" ";
cout<<"---";
delay(70);
clrscr();
}
getch();
}
