#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;


class pixel
{

	public:
		float x,y,length,dx,dy;
		int r,x1,y1,d;
};

class pixel1:public pixel
{
	public:
		void DDA(float,float,float,float);
		int sign(float);
		void circle(int,int,int);
	    void display1(int,int,int,int);

};

int pixel1::sign(float x)
{
	if(x<0)
	return -1;
	else if(x=0)
	return 0;
	else
	return 1;
}

void pixel1::DDA(float x1,float y1,float x2,float y2)
{
	dx=abs(x2-x1);
	dy=abs(y2-y1);

	if(dx>dy)
	length=dx;
	else
	length=dy;

	dx=(x2-x1)/length;
	dy=(y2-y1)/length;

	x=x1+0.5*sign(dx);
	y=y1+0.5*sign(dy);

	for(int i=0;i<length;i++)
	{
	x=x+dx;
	y=y+dy;

	putpixel(x,y,WHITE);

	}
}


void pixel1::circle(int x,int y,int r)
{

   //initialize decision variable
    d=3-2*r;
    //initialize starting points
    x1=0;y1=r;

    do{

         display1(x1,y1,x,y);
         if(d<0)
         	d=d+4*x1+6;
         else{
         	d=d+4*(x1-y1)+10;
         	y1--;
         }
         x1++;
      }while(x1<=y1);
}

void pixel1::display1(int x1,int y1,int x,int y)
{
    putpixel(x1+x,y1+y,WHITE);
    putpixel(x1+x,y-y1,WHITE);
    putpixel(x-x1,y1+y,WHITE);
    putpixel(x-x1,y-y1,WHITE);
    putpixel(x+y1,y+x1,WHITE);
    putpixel(x+y1,y-x1,WHITE);
    putpixel(x-y1,y+x1,WHITE);
    putpixel(x-y1,y-x1,WHITE);
}


int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);

	pixel1 s;
	float x1,y1,x2,y2,x3,y3,x,y,r1,r2,area,height,side,centerx;
	int xmax,ymax,xmid,ymid;

	xmax = getmaxx();
    ymax = getmaxy();
    xmid = xmax /2;
    ymid = ymax /2;

    line(xmid,0,xmid,ymax); //Y-Axis
    line(0,ymid,xmax,ymid); //X-Axis

    cout<<"\nEnter co-ordinates of side x1,y1,x2,y2 : ";
	cin>>x1>>y1>>x2>>y2;

    side=x2-x1;
    area=(sqrt(3)/4)*side*side;
    height=(2*area)/side;

    r1=side/sqrt(3);           //outer circle radius

    r2=side/(2*sqrt(3));       //inner circle radius

    centerx=(x2-x1)/2;

    //remaining vertex of triangle
    x3=x1+centerx;
    y3=y1+height;

    //center pt of circle
    x=x1+centerx;
    y=y1+r2;

    //triangle
	s.DDA(x1+xmid,ymid-y1,x2+xmid,ymid-y2);
	s.DDA(x2+xmid,ymid-y2,x3+xmid,ymid-y3);
	s.DDA(x3+xmid,ymid-y3,x1+xmid,ymid-y1);

	//outer circle
	s.circle(x+xmid,ymid-y, r1);

	//inner circle
	s.circle(x+xmid,ymid-y, r2);

	delay(10000);
	closegraph();
    return 0;
}
