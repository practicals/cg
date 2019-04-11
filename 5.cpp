
//Write C++/Java program to draw the following pattern using any Line drawing algorithms.

    #include<iostream>
    #include<graphics.h>
    using namespace std;
    int xmid,ymid;

    class pixel1
    {

    	public:
    		float x,y,length,dx,dy,height,width;
    		void DDA(float,float,float,float);
    		void pattern();
    		int sign(float);

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
        int i;
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
        i++;
    	putpixel(x,y,WHITE);
    	}
    }

    void pixel1:: pattern()
    {
        int x1,y1,x2,y2,x3,y3,x4,y4,tx,ty;
    	cout<<"\nEnter co-ordinates (x,y)";
    	cin>>x1>>y1;

    	cout<<"\nEnter width and Height";
    	cin>>width>>height;

        x2=x1+width;x3=x1+width;x4=x1;
        y2=y1;y3=y1+height;y4=y1+height;

        for(int i=0;i<3;i++)
        {
           DDA(xmid+x1,ymid-y1,xmid+x2,ymid-y2);
           DDA(xmid+x2,ymid-y2,xmid+x3,ymid-y3);
           DDA(xmid+x3,ymid-y3,xmid+x4,ymid-y4);
           DDA(xmid+x4,ymid-y4,xmid+x1,ymid-y1);

           tx=x1;ty=y1;
           x1=(x1+x2)/2;           y1=(y1+y2)/2;
           x2=(x2+x3)/2;           y2=(y2+y3)/2;
           x3=(x3+x4)/2;           y3=(y3+y4)/2;
           x4=(x4+tx)/2;           y4=(y4+ty)/2;

        }
    }

    int main()
    {

    	int gd=DETECT,gm,xmax,ymax;
    	initgraph(&gd,&gm,NULL);

        xmax = getmaxx();
        ymax = getmaxy();
        xmid = xmax /2;
        ymid = ymax /2;

        line(xmid,0,xmid,ymax); //y-Axis
        line(0,ymid,xmax,ymid); //x-Axis

    	pixel1 s;
    	s.pattern();


    	delay(10000);
    	closegraph();
    }
