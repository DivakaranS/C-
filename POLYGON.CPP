#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

int xt,xr,yb,yt;
class Poly
{
public :
int code(int,int);
void dda(int,int,int,int);
int visible(int,int,int);
void rec();
};
void main()
{
Poly py;
int x[20],y[20];
int n,i,m=0,ct=0,s,c,c1,c2,v,e;
int nx[20],ny[20],xi,yi,x1,x2,y1,y2;
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
cout<<"\n Enter the number of vertices :";
cin>>n;
cout<<endl;
for(i=1;i<=n;i++)
{
cout<<"Enter the polygon co-ordinates :";
cin>>x[i]>>y[i];
}
n++;
x[n]=x[1];
y[n]=y[1];
cout<<"\n Enter the window co=ordinates :";
cin>>xt>>yb>>xr>>yt;
cleardevice();
py.rec();
moveto(x[1],y[1]);
for(i=2;i<=n;i++)
lineto(x[i],y[i]);
getch();
cleardevice();
do
{
m=0;
for(i=1;i<=n;i++)
{
if((i==1)&&(ct==0))
goto pro;
else
{
c2=py.code(x[i],y[i]);
c=(int)pow((float)2,(float)ct);
if(((c1&c) || (c2&c))!=0)
{
x1=x[s];
x2=x[i];
y1=y[s];
y2=y[i];
e=ct;
if(e==0)
{
xi=xt;
yi=y2-(float)(y2-y1)/(x2-x1)*(x2-xt);
}
if(e==1)
{
xi=xr;
yi=y2-(float)(y2-y1)/(x2-x1)*(x2-xr);
}
if(e==2)
{
yi=yt;
xi=x2-(float)(x2-x1)/(y2-y1)*(y2-yt);
}
if(e==3)
{
yi=yb;
xi=x2-(float)(x2-x1)/(y2-y1)*(y2-yb);
}
m++;
nx[m]=xi;
ny[m]=yi;
}
}
pro:
s=i;
c1=py.code(x[i],y[i]);
v=py.visible(x[i],y[i],ct);
if(v==1)
{
m++;
nx[m]=x[i];
ny[m]=y[i];
}
}
ct++;
n=m;
for(i=1;i<=n;i++)
{
x[i]=nx[i];
y[i]=ny[i];
}
}
while(ct<4);
moveto(x[1],y[1]);
for(i=2;i<=n;i++)
lineto(x[i],y[i]);
lineto(x[1],y[1]);
py.rec();
getch();
closegraph();
}
int Poly::code(int a,int b)
{
int c=0;
if(a < xt)
c+=1;
if(a > xr)
c+=2;
if(b < yb)
c+=8;
if(b > yt)
c+=4;
return(c);
}
int Poly::visible(int a,int b,int c)
{
int d,e;
d=code(a,b);
e=(int)pow((float)2,(float)c);
if((d&e)==0)
return(1);
else
return(0);
}
void Poly::rec()
{
dda(xt,yb,xr,yb);
dda(xr,yb,xr,yt);
dda(xr,yt,xt,yt);
dda(xt,yt,xt,yb);
}
void Poly::dda(int x1,int y1,int x2,int y2)
{
float x,y,dy,dx,len;
int i;
if(abs(y2-y1)>=abs(x2-x1))
len=abs(y2-y1);
else
len=abs(x2-x1);
dx=(x2-x1)/len;
dy=(y2-y1)/len;
x=x1+0.5*dx;
y=y1+0.5*dy;
for(i=1;i<=len;i++)
{
putpixel(x,y,getmaxcolor());
x+=dx;
y+=dy;
}
}
