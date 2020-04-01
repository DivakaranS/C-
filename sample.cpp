
#include<iostream>
# include <graphics>
# include <stdlib.h>

using namespace std;


class pt
{
protected: int xco=0, yco=0,color=15;
}
void setco(int x, int y)
{
xco=x;
yco=y;
}
void setcolor(int c)
{
color=c;
}
void draw()
{
putpixel(xco,yco,color);
};

class dline:public pt
{
private: int x2, y2;
public:
dline():pt()
{
x2=0;
y2=0;
}
void setline(int x, int y, int xx, int yy)
{
pt::setco(x,y);
x2=xx;
y2=yy;
}
void drawl()
{
float x,y,dx,dy,temp;
int i, s1, s2, ex;
dx= abs(x2-xco);
dy=abs(y2-yco);
x=xco;
y=yco;
e=2*dy-dx;
i=1;
pt::setco(x,y);
pt::draw();
if(x2>xco)
{
s1=1;
}
if(x2==xco)
{
s1=0;
}
if(x2<xco)
{
s1=-1;
}
if(y2>yco)
{
s2=1;
}
if(y2==yco)
{
s2=0;
}
if(y2<yco)
{
s2=-1;
}
if(dy>dx)
{
temp=dx;
dx=dy;
dy=temp;
ex=1;
}
else
{
ex=0;
}
e=2*dy-dx;
i=1;

do
{
while(e>=0)
{
if(ex==1)
{
x=x+s1;
}
else
{
y=y+s2;
}
e=e-2*dx;
}
if(ex==1)
{
y=y+s2;
}
else
{
x=x+s1;
}
e=e+2*dy;
putpixel(x,y,15);
i=i+1;
}
while(i<=dx);
}

void drawl(int colour)
{
float x,y,dx,dy,length;
int i;
pt::setcolor(colour);
dx=abs(x2-xco);
dy=abs(y2-yco);
if(dx>=dy)
{
length=dx;
}
else
{
length=dy;
}
dx=(x2-xco)/length;
dy=(y2-yco)/length;
x=xco+0.5;
y=yco+0.5;

i=1;
while(i<=length)
{
pt::setco(x,y);
pt::draw();
x=x+dx;
y=y+dy;
i=i+1;

}

pt::setco(x,y);
pt::draw();
}
};



int main()
{
int gd=DETECT, gm;
initgraph(&gd, &gm, NULL);
pt p1;
p1.setco(100,100);
p1.setcolor(14);
p1.draw();
dline 1;
l.setline(310,200,210,100);
l.draw();
l.setline(350,50,450,100);
l.drawl(15);
getch();
closegraph();
return 0;
}