#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<math.h>
#include<iostream.h>
#include<stdio.h>

class Line
{
private:
int dx,dy,len;
char buff[10];
double x,y;
public:
void init();
void bresenham(int,int,int,int);
};
void Line::init()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
}
void Line::bresenham(int x1,int y1,int x2,int y2)
{
float m;
int p;
cout<<"\n BRESENHAM ALGORITHM";
m=(float)(y2-y1)/(x2-x1);
dx=abs(x2-x1);
dy=abs(y2-y1);
p=2*dy-dx;
if(x1 > x2)
{
x=x2;
y=y2;
len=x1;
}
else
{
x=x1;
y=y1;
len=x2;
}
putpixel(x,y,WHITE);
while(x<len)
{
x=x+1;
if(p<0)
p=p+2*dy;
else
{
if(m>0.0)
y++;
else
y--;
p=p+2*(dy-dx);
}
putpixel(x,y,WHITE);
delay(10);
}
sprintf(buff,"(%d,%d)",x1,y1);
outtextxy(x1,y1,buff);
sprintf(buff,"(%d,%d)",x2,y2);
outtextxy(x2,y2,buff);
gotoxy(1,30);
cout<<"\n Press any Key....";
getch();
}
void main()
{
Line k;
int x1,x2,y1,y2;
clrscr();
gotoxy(1,1);
cout<<"\n Enter the first co-ordinate :";
cin>>x1>>y1;
cout<<"\n Enter the second co-ordinate :";
cin>>x2>>y2;
k.init();
cout<<"\n\n LINE DRAWING ALGORITHMS";
cout<<"\n***************************";
k.bresenham(x1,y1,x2,y2);
getch();
}
