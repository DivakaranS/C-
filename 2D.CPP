#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>

class tdt
{
private :
int n,poly[100];
int tpoly[100],tx,ty;
int spoly[100],sx,sy;
int rpoly[100],ang,h,k;
int shxpoly[100],shypoly[100],shx,shy;
public :
void oldpoly();
void transpoly();
void rotatepoly();
void scalepoly();
void shearxpoly();
void shearypoly();
};
void tdt::oldpoly()
{
cout<<"\n Enter the number of sides ";
cin>>n;
cout<<"\n Enter the co-ordintes : ";
for(int i=0;i<(n*2);i++)
{
cin>>poly[i];
}
poly[i]=poly[0];
poly[i+1]=poly[1];
drawpoly(n+1,poly);
getch();
}
void tdt::transpoly()
{
cout<<"\n Enter the increment co-ordinates :";
cin>>tx>>ty;
for(int i=0;i<(n*2);i++)
{
if(i%2 == 0)
tpoly[i]=poly[i]+tx;
else
tpoly[i]=poly[i]+ty;
}
tpoly[i]=tpoly[0];
tpoly[i+1]=tpoly[1];
drawpoly(n+1,tpoly);
getch();
}
void tdt::rotatepoly()
{
float rad;
cout<<"\n Enter the angle :";
cin>>ang;
rad=(3.14*ang)/180;
cout<<"\n Enter the point at which rotate :";
cin>>h>>k;
for(int i=0;i<(n*2);i=i+2)
{
rpoly[i]=h+(poly[i]-h)*cos(rad)-(poly[i+1]-k)*sin(rad);
rpoly[i+1]=k+(poly[i]-h)*sin(rad)+(poly[i+1]-k)*cos(rad);
}
rpoly[i]=rpoly[0];
rpoly[i+1]=rpoly[1];
drawpoly(n+1,rpoly);
getch();
}
void tdt::scalepoly()
{
cout<<"\n Enter the scalling distance :";
cin>>sx>>sy;
for(int i=0;i<(n*2);i++)
{
if(i%2 == 0)
spoly[i]=poly[i]*sx;
else
spoly[i]=poly[i]*sy;
}
spoly[i]=spoly[0];
spoly[i+1]=spoly[1];
drawpoly(n+1,spoly);
getch();
}
void tdt::shearxpoly()
{
cout<<"\n Enter the shear points :";
cin>>shx;
for(int i=0;i<(n*2);i=i+2)
{
shxpoly[i]=poly[i]+(shx*poly[i+1]);
shxpoly[i+1]=poly[i+1];
}
shxpoly[i]=shxpoly[0];
shxpoly[i+1]=shxpoly[1];
drawpoly(n+1,shxpoly);
getch();
}
void tdt::shearypoly()
{
cout<<"\n Enter the shear points : ";
cin>>shy;
for(int i=0;i<(n*2);i=i+2)
{
shypoly[i]=poly[i];
shypoly[i+1]=poly[i+1]+(shy*poly[i]);
}
shypoly[i]=shypoly[0];
shypoly[i+1]=shypoly[1];
drawpoly(n+1,shypoly);
getch();
}
void main()
{
tdt obj;
int ch;
char op;
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
do
{
cleardevice();
cout<<"\n\n Menu";
cout<<"\n1. Translate";
cout<<"\n2. rotate";
cout<<"\n3. Scale";
cout<<"\n4. Shear X";
cout<<"\n5. Shear Y";
cout<<"\n6. Exit";
cout<<"\n Enter Your Choice :";
cin>>ch;
switch(ch)
{
case 1:
obj.oldpoly();
obj.transpoly();
break;
case 2:
obj.oldpoly();
obj.rotatepoly();
break;
case 3:
obj.oldpoly();
obj.scalepoly();
break;
case 4:
obj.oldpoly();
obj.shearxpoly();
break;
case 5:
obj.oldpoly();
obj.shearypoly();
break;
case 6:
exit(0);
default:
cout<<"\n Enter only 1 to 6....";
break;
}
cleardevice();
gotoxy(1,1);
cout<<"\n Do you want to continue (Y/N) :";
cin>>op;
}
while((op!='N')&&(op!='n'));
closegraph();
}
