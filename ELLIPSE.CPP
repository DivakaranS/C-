#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>

class Ellipse
{
public:
void init();
void ellip1(float,float,float,float);
void ellip2(float,float,float,float);
void plotpts(float,float,float,float);
};
void Ellipse::init()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
}
void Ellipse::ellip1(float h,float k,float a, float b)
{
int x,y,xend;
x=0;
xend=a;
while(x <= xend)
{
y=b*sqrt(1-(pow(x,2))/pow(a,2));
putpixel(x+h,y+k,15);
putpixel(-x+h,-y+k,15);
putpixel(-x+h,y+k,15);
putpixel(x+h,-y+k,15);
delay(10);
x=x+1;
}
getch();
}
void Ellipse::ellip2(float h,float k,float a,float b)
{
float x,y,aa,bb,fx,fy,p;
x=0;y=b;
aa=a*a;
bb=b*b;
fx=0;
fy=2*aa*b;
p=(bb-(aa*b)+(0.25*aa));
while(fx<fy)
{
plotpts(h,k,x,y);
x++;
fx=fx+(2*bb);
if(p < 0)
p=p+fx+bb;
else
{
y--;
fy=fy-(2*aa);
p=p+fx+bb-fy;
}
}
plotpts(h,k,x,y);
p=(bb*(x+0.5)*(x+0.5)+aa*(y-1)-aa*bb);
while(y > 0)
{
y--;
fy=fy-(2*aa);
if(p>=0)
p=p-fy+aa;
else
{
x++;
fx=fx+(2*bb);
p=p+fx-fy+aa;
}
plotpts(h,k,x,y);
}
getch();
}
void Ellipse::plotpts(float h,float k,float x,float y)
{
putpixel(h=x,k+y,15);
putpixel(h-x,k+y,15);
putpixel(h+x,k-y,15);
putpixel(h-x,k-y,15);
delay(10);
}
void main()
{
int ch;
float h,k,a,b;
Ellipse e;
do
{
e.init();
cout<<"\n\t Ellipse Drawing Algorithm.";
cout<<"\n\t1.Polynomial Method \n2.Midpoint Method \n3.Exit";
cout<<"\n\n Enter your choice:";
cin>>ch;
if(ch==1 || ch==2)
{
cout<<"\n Enter the Center Co-ordinate :";
cin>>h>>k;
cout<<"\n Enter the Horizontal Axis :";
cin>>a;
cout<<"\n Enter the Veritical Axis :";
cin>>b;
}
switch(ch)
{
case 1:
e.init();
e.ellip1(h,k,a,b);
break;
case 2:
e.init();
e.ellip2(h,k,a,b);
break;
case 3:
exit(0);
default:
continue;
}
}
while(1);
}



