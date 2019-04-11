//Write C++/Java program to draw line using DDA and Bresenham‘s algorithm. Inherit pixel class and Use function overloading.


#include<graphics.h>
#include<iostream>
using namespace std;

class pt //base class
{
   protected: int x1,y1,color;
   public:
          pt()
          {
            x1=0;y1=0;color=15;
          }

          void setco(int x,int y)
          {
            x1=x;
            y1=y;
          }

          void setcolor(int c)
          {
            color=c;
          }

          void draw()
          {
            putpixel(x1,y1,color);
          }

};

class dline: public pt //derived class
{
    private: int x2,y2;
    public:
           dline():pt()
           {
             x2=0,y2=0;
           }

           void setline(int x, int y, int xx, int yy)
           {
             pt::setco(x,y);
             x2=xx;
             y2=yy;
           }

           int sign(float x)
           {
		    if(x<0)
			return -1;
			else if(x=0)
			return 0;
			else
			return 1;
		   }

           void drawl() //Bresenham's Line
           {
             float x,y,dx,dy,e,temp;
             int i,s1,s2,ex;

             //Step2
             dx=abs(x2-x1);
             dy=abs(y2-y1);

             //Step3
             x=x1;
             y=y1;
             pt::setco(x,y);
             pt::draw();

             s1=sign(x2-x1);
             s2=sign(y2-y1);

             //Step5
             if(dy > dx)
             {
                temp = dx;
                dx = dy;
                dy = temp;

                ex = 1;
             }
             else
             {
                ex=0;
             }

             //Step6
             e=2*dy-dx; //decision variable

             //Step7
             i=1;
             do
             {
                  while(e>=0)
                  {
                     if(ex==1)
                     {
                        x = x + s1;
                     }
                     else
                     {
                        y = y + s2;
                     }
                     e = e - 2*dx;
                  }
                  if(ex==1)
                  {
                     y = y + s2;
                  }
                  else
                  {
                     x = x + s1;
                  }

                  e = e + 2*dy;
                  pt::setco(x,y);
                  pt::draw();
                  i = i + 1;

           }while(i<=dx);

      }//funciton closed


      void drawl(int colour) //DDA Line
      {
          float x,y,dx,dy,len;
          int i;

          pt::setcolor(colour);

          //step2
          dx=abs(x2-x1);
          dy=abs(y2-y1);

          //step3
          if(dx >= dy)
          {
             len=dx;
          }
          else
          {
             len=dy;
          }

          //step4
          dx=(x2-x1)/len;
          dy=(y2-y1)/len;

          //step5
          x = x1 + 0.5*sign(dx);
          y = y1 + 0.5*sign(dy);

          pt::setco(x,y);
          pt::draw();

          //step6
          i=1;
          while(i<=len)
          {
               x = x + dx;
               y = y + dy;
               i = i + 1;
               pt::setco(x,y);
               pt::draw();
          }
    }//function closed
};

int main()
{
    int gd=DETECT,gm;
    int ch,x1,y1,x2,y2, xmax,ymax,xmid,ymid;
    char a;
    initgraph(&gd,&gm,NULL);
    dline dda;

    xmax = getmaxx();
    ymax = getmaxy();
    xmid = xmax /2;
    ymid = ymax /2;

    line(xmid,0,xmid,ymax); //Y-Axis
    line(0,ymid,xmax,ymid); //X-Axis

    while(1)
    {
       cout<<"\n1.DDA LINE..";
       cout<<"\n2.BRESENHAM'S LINE..";
       cout<<"\n3.EXIT..";
       cout<<"\nEnter your choice: ";
       cin>>ch;

       switch(ch)
       {
         case 1:
                 cout<<"\nEnter the co-ordinates of the endpoints of line Below";
                 cout<<"\nEnter x1 y1 x2 y2 : ";
                 cin>>x1>>y1>>x2>>y2;

                 dda.setline(x1+xmid,ymid-y1,x2+xmid,ymid-y2);
                 dda.drawl(14);
                 break;

         case 2:
                 cout<<"\nEnter the co-ordinates of the endpoints of line Below\n";
                 cout<<"\nEnter x1 y1 x2 y2 : ";
                 cin>>x1>>y1>>x2>>y2;

                 dda.setline(x1+xmid,ymid-y1,x2+xmid,ymid-y2);
                 dda.drawl();
                 break;

         case 3:
                 exit(0);
                 break;
       }
   }

   delay(3000);
   closegraph();
   return 0;
}
