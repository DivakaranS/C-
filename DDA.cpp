
#include<iostream>


class Line

{
private:
	int dx,dy,len;
	char buff[10];
	double x,y;

public:
	void init();
	void dda(int,int,int,int);

};

void Line::init()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\turboc3\\bgi");
}

void Line::dda(int x1,int y1,int x2,int y2)

{
	int i;
	double xinc,yinc;
	cout<<"\n DDA ALGORITHM";
	dx=(x2-x1);
	dy=(y2-y1);

	if(abs(dx)>abs(dy))
		len=abs(dx);
	else
		len=abs(dy);
	if(len==0)
	{
		putpixel(x1,y1,WHITE);
		return;
	}
	xinc=(float)(dx)/len;
	yinc=(float)(dy)/len;

	x=x1+0.5;
	y=y1+0.5;

	for(i=0;i<len;i++)
	{
		putpixel(floor(x),floor(y),WHITE);
		delay(10);

		x+=xinc;
		y+=yinc;

	}
	sprintf(buff,"(%d,%d)",x1,y1);
	outtextxy(x1,y1,buff);
	sprintf(buff,"(%d,%d)",x2,y2);
	outtextxy(x2,y2,buff);
	gotoxy(1,30);
	cout<<"\nPress any Key...";
	getch();
}

void main()
{
	Line k;
	int x1,x2,y1,y2;
	clrscr();
	gotoxy(1,1);
	cout<<"\nEnter the first co-ordinate :";
	cin>>x1>>y1;
	cout<<"\nEnter the second co-ordinate :";
	cin>>x2>>y2;
	k.init();
	cout<<"\n\nLINE DRAWING ALGORITHMS";
	cout<<"\n*************************";
	k.dda(x1,y1,x2,y2);
	getch();

}