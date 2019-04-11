
#include<iostream>
#include<graphics.h>
using namespace std;

class draw
{
   float dx,dy,length,x,y;
   int i,r;
public:
	dline()
	{
		dx=dy=length=x=y=i=r=0;
	}
	void dline(float,float,float,float);
	void dcircle(int,int,int);
	int sign(float x);
};

int draw::sign(float a)
{
  if(a>0)
    return 1;
  else if(a==0)
    return 0;
  else
    return -1;
}

void draw::dline(float x1,float y1,float x2,float y2)      //normal display
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

   putpixel(x,y,15);
   i=1;
     while(i<=length)
       {
          x=x+dx;
          y=y+dy;
          putpixel(x,y,15);
          i=i+1;
       }

}

void draw::dcircle(int x1,int y1,int r) //Bresenham's dcircle
     {
        int x,y;
        float d;

        x=0, y=r;
        d = 3 - 2*r; //decision variable

        do
        {
           putpixel(x1+x, y1+y,15);
           putpixel(x1+y, y1+x,15);
           putpixel(x1+y, y1-x,15);
           putpixel(x1+x, y1-y,15);
           putpixel(x1-x, y1-y,15);
           putpixel(x1-y, y1-x,15);
           putpixel(x1-y, y1+x,15);
           putpixel(x1-x, y1+y,15);

           if(d<=0)
           {
              x = x + 1;
              d = d + (4*x) + 6;
           }
           else
           {
              x = x + 1;
              y = y - 1;
              d = d + (4*x-4*y) + 10;
           }

        }while(x<=y);

    }//Function Closed
int main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,NULL);

draw o;
for (int i=0;i<500;i++)
{
o.dline(50+i,370,90+i,370);
arc(110+i,370,0,180,20);
o.dline(130+i,370,220+i,370);
arc(240+i,370,0,180,20);
o.dline(260+i,370,300+i,370);
o.dline(300+i,370,300+i,350);
o.dline(300+i,350,240+i,330);
o.dline(240+i,330,200+i,300);
o.dline(200+i,300,110+i,300);
o.dline(110+i,300,80+i,330);
o.dline(80+i,330,50+i,340);
o.dline(50+i,340,50+i,370);
o.dline(165+i,305,165+i,330);
o.dline(165+i,330,230+i,330);
o.dline(230+i,330,195+i,305);
o.dline(195+i,305,165+i,305);
o.dline(160+i,305,160+i,330);
o.dline(160+i,330,95+i,330);
o.dline(95+i,330,120+i,305);
o.dline(120+i,305,160+i,305);
o.dcircle(110+i,370,17);
o.dcircle(240+i,370,17);
delay(10);
cleardevice();
o.dline(0,390,639,390);
}
return(0);
}
