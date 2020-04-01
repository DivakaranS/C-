#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>

class Cir
{
private:
int x,y;
char buff[10];
public:
void init();
void trig(int,int,int);
void bres(int,int,int);
};
void Cir::init()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
}
void Cir::trig(int h,int k,int r)
{
int theta;
float t;
cout<<"\n TRIGONOMETRIC METHOD";
cout<<"\n *********************";
sprintf(buff,"(%d,%d)",h,k);
outtextxy(h,k,buff);
for(theta=0;theta<360;theta++)
{
t=theta*0.017453;
x=h+r*cos(t);
y=k+r*sin(t);
putpixel(x,y,15);
}
cout<<"\n Press any key to continue....";
getch();
cleardevice();
}
void Cir::bres(int h,int k,int r)
{
int d;
cout<<"\n BRESENHEMS ALGORITHM";
cout<<"\n ********************";
sprintf(buff,"(%d,%d)",h,k);
outtextxy(h,k,buff);
x=0;
y=r;
d=3-(2*r);
while(x<=y)
{
if(d<0)
{
d=d+(4*x)+6;
x++;
}
else
{
d=d+4*(x-y)+10;
x++;
y--;
}
putpixel(x+h,y+k,15);
putpixel(-x+h,y+k,15);
putpixel(x+h,-y+k,15);
putpixel(-x+h,-y+k,15);
putpixel(y+h,x+k,15);
putpixel(-y+h,x+k,15);
putpixel(y+h,-x+k,15);
putpixel(-y+h,-x+k,15);
}
cout<<"\n Pres any key to Continue...";
getch();
cleardevice();
}
void main()
{
Cir c;
int ch,h,k,r;
clrscr();
do
{
cout<<"\n\t MENU";
cout<<"\n\t *****";
cout<<"\n1.Trigonometric Method \n2.Bresenhams Method \n3.Exit";
cout<<"\n\nEnter your choice :";
cin>>ch;
if(ch==1 || ch==2)
{
cout<<"\n\nEnter the co-ordinate :";
cin>>h>>k;
cout<<"\Enter the radius :";
cin>>r;
}
switch(ch)
{
case 1:
c.init();
c.trig(h,k,r);
break;
case 2:
c.init();
c.bres(h,k,r);
break;
case 3:
exit(0);
default:
continue;
}
}
while(1);
}


