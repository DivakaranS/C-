#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<math.h>
#include<graphics.h>
void show_message()
{
char *msg[]={"-","=","[","","3","D","-","T","r","a","n","s","f","o","r","m","a","t","i","o","n","","]","=","-"};
int front=28,end=52,i,j;
_setcursortype(_NOCURSOR);
for(i=0,j=24;i<15,j>=12;i++,j--)
{
gotoxy(front,1);
cout<<msg[i];
front++;
gotoxy(end,1);
cout<<msg[j];
end--;
delay(100);
}
_setcursortype(_NORMALCURSOR);
}
void draw_cube(double edge[20][3])
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
double x1,x2,y1,y2;
int i;
for(i=0;i<19;i++)
{
x1=edge[i][0]+edge[i][2]*(cos(2.3562));
y1=edge[i][1]-edge[i][2]*(sin(2.3562));
x2=edge[i+1][0]+edge[i+1][2]*(cos(2.3562));
y2=edge[i+1][1]-edge[i+1][2]*(sin(2.3562));
line(x1+320,240-y1,x2+320,240-y2);
}
line(320,240,320,25);
line(320,240,550,240);
line(320,240,150,410);
getch();
}
void translate(double edge[20][3])
{
int a,b,c;
int i;
cout<<"\n Enter the Translation factors :";
cin>>a>>b>>c;
for(i=0;i<20;i++)
{
edge[i][0]+=a;
edge[i][1]+=b;
edge[i][2]+=c;
}
draw_cube(edge);
}
void scale(double edge[20][3])
{
double a,b,c;
int i;
cout<<"\n Enter the Scalling Factors :";
cin>>a>>b>>c;
for(i=0;i<20;i++)
{
edge[i][0]=edge[i][0]*a;
edge[i][1]=edge[i][1]*b;
edge[i][2]=edge[i][2]*c;
}
draw_cube(edge);
}
void rotate(double edge[20][3])
{
int ch;
int i;
double temp,theta,temp1;
clrscr();
cout<<"\n\tRotation About";
cout<<"\n1. X-Axis";
cout<<"\n2. Y-Axis";
cout<<"\n3. Z-Axis";
cout<<"\n\n Enter your Choice :";
cin>>ch;
cout<<"\n Enter the Angle :";
cin>>theta;
theta=(theta*3.14)/180;
switch(ch)
{
case 1:
for(i=0;i<20;i++)
{
edge[i][0]=edge[i][0];
temp=edge[i][1];
temp1=edge[i][2];
edge[i][1]=temp*cos(theta)-temp1*sin(theta);
edge[i][2]=temp*sin(theta)+temp1*cos(theta);
}
break;
case 2:
for(i=0;i<20;i++)
{
edge[i][1]=edge[i][1];
temp=edge[i][0];
temp1=edge[i][2];
edge[i][0]=temp*cos(theta)+temp1*sin(theta);
edge[i][2]=temp*sin(theta)+temp1*cos(theta);
}
break;
case 3:
for(i=0;i<20;i++)
{
edge[i][2]=edge[i][2];
temp=edge[i][0];
temp1=edge[i][1];
edge[i][0]=temp*cos(theta)-temp1*sin(theta);
edge[i][1]=temp*sin(theta)+temp1*cos(theta);
}
break;
}
draw_cube(edge);
}
void reflect(double edge[20][3])
{
int ch;
int i;
clrscr();
cout<<"\n\t Reflection About";
cout<<"\n1. X-Axis";
cout<<"\n2. Y-Axis";
cout<<"\n3. Z-Axis";
cout<<"\n Enter your Choice :";
cin>>ch;
switch(ch)
{
case 1:
for(i=0;i<20;i++)
{
edge[i][0]=edge[i][0];
edge[i][1]=-edge[i][1];
edge[i][2]=-edge[i][2];
}
break;
case 2:
for(i=0;i<20;i++)
{
edge[i][1]=edge[i][1];
edge[i][0]=-edge[i][0];
edge[i][2]=-edge[i][2];
}
break;
case 3:
for(i=0;i<20;i++)
{
edge[i][2]=edge[i][2];
edge[i][0]=-edge[i][0];
edge[i][1]=-edge[i][1];
}
break;
}
draw_cube(edge);
}
void perspect(double edge[20][3])
{
int ch;
int i;
double p,q,r;
clrscr();
cout<<"\n\t Perspective Projection About";
cout<<"\n1. X-Axis";
cout<<"\n2. Y-Axis";
cout<<"\n3. Z-Axis";
cout<<"\n Enter your Choice :";
cin>>ch;
switch(ch)
{
case 1:
cout<<"\n Enter P :";
cin>>p;
for(i=0;i<20;i++)
{
edge[i][0]=edge[i][0]/(edge[i][0]*p+1);
edge[i][1]=edge[i][1]/(edge[i][0]*p+1);
edge[i][2]=edge[i][2]/(edge[i][0]*p+1);
}
break;
case 2:
cout<<"\n Enter Q :";
cin>>q;
for(i=0;i<20;i++)
{
edge[i][1]=edge[i][1]/(edge[i][1]*q+1);
edge[i][0]=edge[i][0]/(edge[i][1]*q+1);
edge[i][2]=edge[i][2]/(edge[i][1]*q+1);
}
break;
case 3:
cout<<"\n Enter R :";
cin>>r;
for(i=0;i<20;i++)
{
edge[i][2]=edge[i][2]/(edge[i][2]*r+1);
edge[i][0]=edge[i][0]/(edge[i][2]*r+1);
edge[i][1]=edge[i][1]/(edge[i][2]*r+1);
}
break;
}
draw_cube(edge);
}
void main()
{
while(1)
{
int choice;
double edge[20][3]={100,0,0,
100,100,0,
0,100,0,
0,100,100,
0,0,100,
0,0,0,
100,0,0,
100,0,100,
100,75,100,
75,100,100,
100,100,75,
100,100,0,
100,100,75,
100,75,100,
75,100,100,
0,100,100,
0,100,0,
0,0,0,
0,0,100,
100,0,100};
clrscr();
show_message();
cout<<"\n1. Draw Cube";
cout<<"\n2. Translation";
cout<<"\n3. Scaling";
cout<<"\n4. Rotation";
cout<<"\n5. Reflection";
cout<<"\n6. Prespective Projection";
cout<<"\n7. Exit";
cout<<"\n\n Enter your Choice : ";
cin>>choice;
switch(choice)
{
case 1:
draw_cube(edge);
break;
case 2:
translate(edge);
break;
case 3:
scale(edge);
break;
case 4:
rotate(edge);
break;
case 5:
reflect(edge);
break;
case 6:
perspect(edge);
break;
case 7:
exit(0);
deafult:
cout<<"\n Press A Valid Key....!!!";
getch();
break;
}
closegraph();
}
}

