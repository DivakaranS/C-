#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
#include<string.h>
#include<io.h>

class Clip
{
private:
typedef int reg[4];
public:
void concode(reg,int,int,int,int,int,int);
int accode(reg,reg);
int regcode(reg,reg);
int inside(reg);
void swap(int*,int*,int*,int*,reg,reg);
};
void main()
{
Clip c;
int fin=0,pr=0;
int lx,ly,rx,ry;
typedef int reg[4];
reg a,b;
int x1,y1,x2,y2;
float m;
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
cout<<"\n Enter the line co-ordinates :";
cin>>x1>>y1>>x2>>y2;
cout<<"\n Enter the window co-ordinates :";
cin>>lx>>ly>>rx>>ry;
cleardevice();
setbkcolor(8);
outtextxy(10,10,"\n Original Line");
setcolor(BLUE);
line(x1,y1,x2,y2);
setcolor(RED);
rectangle(lx,ly,rx,ry);
getch();
while(!fin)
{
c.concode(a,x1,y1,lx,ly,rx,ry);
c.concode(b,x2,y2,lx,ly,rx,ry);
if(c.accode(a,b))
{
pr=1;
fin=1;
}
else if(c.regcode(a,b))
fin=1;
else
{
if(c.inside(a))
c.swap(&x1,&y1,&x2,&y2,a,b);
if(x2!=x1)
m=(float)(y2-y1)/(x2-x1);
if(a[0])
{
y1=y1+m*(lx-x1);
x1=lx;
}
else if(a[1])
{
y1=y1+m*(rx-x1);
x1=rx;
}
else if(a[2])
{
x1=x1+(ly-y1)/m;
y1=ly;
}
else if(a[3])
{
x1=x1+(ry-y1)/m;
y1=ry;
}
}
}
if(pr)
{
cleardevice();
setbkcolor(8);
outtextxy(10,10,"\n Line inide clipping window");
setcolor(GREEN);
line(x1,y1,x2,y2);
setcolor(RED);
rectangle(lx,ly,rx,ry);
}
else
{
cleardevice();
outtextxy(10,10,"\n Line inside clipping window");
rectangle(lx,ly,rx,ry);
}
getch();
exit(0);
}
void Clip::concode(reg code,int x,int y,int lx,int ly,int rx,int ry)
{
if(x<lx)
code[0]=1;
else
code[0]=0;
if(x>rx)
code[1]=1;
else
code[1]=0;
if(y<ly)
code[2]=1;
else
code[2]=0;
if(y>ry)
code[3]=1;
else
code[3]=0;
}
int Clip::accode(reg x,reg y)
{
int i,ok=1;

for(i=0;i<4;i++)
if(x[i] || y[i])
ok=0;
return(ok);
}
int Clip::regcode(reg x,reg y)
{
int i,ok=0;
for(i=0;i<4;i++)
if(x[i] && y[i])
ok=1;
return(ok);
}

void Clip::swap(int *x1,int *y1,int *x2,int *y2,reg a,reg b)
{
int tmp1,tmp2;
reg c;
tmp1=*x1;*x1=*x2;*x2=tmp1;
tmp2=*y1;*y1=*y2;*y2=tmp2;
c[0]=a[0];a[0]=b[0];b[0]=c[0];
c[1]=a[1];a[1]=b[1];b[1]=c[1];
c[2]=a[2];a[2]=b[2];b[2]=c[2];
c[3]=a[3];a[3]=b[3];b[3]=c[3];
}
int Clip::inside(reg e)
{
int point=1;
if(e[0] || e[1] || e[2] || e[3])
point=0;
return(point);
}

