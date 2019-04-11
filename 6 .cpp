#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
int xmid,ymid;

class DDA
{
  public:
      float x,y,x1,y1,x2,y2,length,dx,dy,e;
      int i;
      void getdata();
      void display(float,float,float,float);
      float sign(float);
      void solid();
      void dotted();
      void dashed();
      void dashdot();
      void thick();
      DDA();
};

DDA::DDA()
{
x=y=x1=y1=x2=y2=length=dx=dy=e=0;
i=0;

}

void DDA::getdata()
{
   cout<<"\nEnter co-ordinates of 1st line x1 y1 x2 y2 : ";
   cin>>x1>>y1>>x2>>y2;
   x1=x1+xmid;
   x2=x2+xmid;
   y1=ymid-y1;
   y2=ymid-y2;
}                                      

float DDA::sign(float a)
{
  if(a>0)
    return 1;
  else if(a==0)
    return 0;
  else
    return -1;
}

void DDA::display(float m1,float n1,float m2,float n2)      //normal display
{
x1=m1;
y1=n1;
x2=m2;
y2=n2;

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

void DDA::solid()                      // for solid line
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

   putpixel(x,y,RED);
   i=1;
     while(i<=length)
       {
          x=x+dx;
          y=y+dy;
          putpixel(x,y,15);
          i=i+1;
       }
}


void DDA::dotted()
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


   putpixel(x,y,WHITE);
   i=0;
     while(i<=length)
       {
          x=x+dx;
          y=y+dy;

          if(i%2 == 1)
          putpixel(x,y,15);
          i=i+1;
       }

}

void DDA::dashed()
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
   i=0;
     while(i<=length)
       {
          x=x+dx;
          y=y+dy;

          if(!(i%10==1|i%10==2||i%10==3||i%10==4))
          putpixel(x,y,15);
          i=i+1;
       }

}

void DDA::dashdot()
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
  i=0;
     while(i<=length)
       {
          x=x+dx;
          y=y+dy;

          if(!(i%10==1||i%10==2||i%10==4||i%10==5))
          putpixel(x,y,15);
          i=i+1;
       }
}


void DDA::thick()
{
int th,i,wx,wy;
cout <<"Enter the thickness of line you want:\n";
cin  >>th;

 DDA D5;
 D5.display(x1+xmid,ymid-y1,xmid+x2,ymid-y2);

 wy=(th-1)*sqrt(pow((x2-x1),2)+pow((y2-y1),2))/(2*abs(x2-x1));
 wx=(th-1)*sqrt(pow((x2-x1),2)+pow((y2-y1),2))/(2*abs(y2-y1));

 if((y2-y1)/(x2-x1) <=1)
  {
    for(i=0;i<wy;i++)
    {
      D5.display(x1+xmid,ymid-y1-i,x2+xmid,ymid-y2-i);
      D5.display(x1+xmid,ymid-y1+i,x2+xmid,ymid-y2+i);
    }
  } 
 if((x2-x1)/(y2-y1) < 1)
  {
    for(i=0;i<wx;i++)
    {
      D5.display(x1-i,y1,x2-i,y2);
      D5.display(x1+i,y1,x2+i,y2);
    }
  }


}


int main()
{
   int gd=DETECT,gm,ymax,xmax;
   initgraph(&gd,&gm,NULL);
   int ch;
   char ans;
   DDA D;

   xmax = getmaxx();
   ymax = getmaxy();
   xmid = xmax /2;
   ymid = ymax /2;

   line(xmid,0,xmid,ymax); //Y co-ordinate
   line(0,ymid,xmax,ymid); //X co-ordinate

    do
      {
        cout<<"Enter choice:\n1.Solid\n2.Dotted\n3.Dashed\n4.Dashdot\n5.Thick\nEnter choice :";
        cin >>ch;
       switch(ch)
               {
               case 1:
                D.getdata();
               	cout<<"Answer by DDA Algorithm, Solid line:\n";
                D.solid();

                break;

               case 2:
                cleardevice();
                D.getdata();
                cout<<"Answer by DDA Algorithm, Dotted line:\n";
                D.dotted();

                break;
             case 3:
                D.getdata();
             	cout<<"Answer by DDA Algorithm, Dashed line:\n";
                D.dashed();

                break;

             case 4:
                D.getdata();
             	cout<<"Answer by DDA Algorithm, Dashdot line:\n";
                D.dashdot();

               break;

               case 5:
                D.getdata();
             	cout<<"Answer by DDA Algorithm, thick line:\n";
                D.thick();

               break;
              default:
              cout<<"Wrong choice, try again!\n";
               }
         cout<<"Do you wish to continue:(y/n)?\t";
         cin>>ans;
      }while(ans=='Y' || ans=='y');

   closegraph();
  return 0;
}
