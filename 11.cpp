
//Write C++/Java program to implement translation, sheer, rotation and scaling transformations
//on equilateral triangle and rhombus.

#include<iostream>
#include<math.h>
#include<graphics.h>
#define M 10
int midx,midy;
using namespace std;

class graph
{
	private:

		int A[M][3],ans[M][3],trans[3][3],sh[3][3],n;
		float rotat[2][2],scal[2][2];

	public:
		graph();
	void polygon();
	void Showpoly();
	void translation();
	void Scaling();
	void Rotation();
	void shear();
	void Display();
};

graph::graph()
{

	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
				if(i==j)
					sh[i][j]=trans[i][j]=1;

				else
					sh[i][j]=trans[i][j]=0;
		}

	}

	scal[0][0]=1;
	scal[0][1]=0;
	scal[1][0]=0;
	scal[1][1]=1;
}

void graph::polygon()
{
	int ch,area,height,base,length,centerx,x1,y1,x2,y2;
	cout<<"1. Equilateral triangle\n2. rhombus \nenter choice : ";
	cin>>ch;
    cout<<"Enter one side x1,y1,x2,y2 : ";
    cin>>x1>>y1>>x2>>y2;
    A[0][0]=x1;
    A[0][1]=y1;
    A[0][2]=1;
    A[1][0]=x2;
    A[1][1]=y2;
    A[1][2]=1;
	switch(ch)
	{
        case 1:
        {
              area= (sqrt(3)/4)*(x2-x1)*(x2-x1);
              height= (2* area)/abs(x2-x1);
              centerx=abs(x2-x1)/2;
              A[2][0]=x1+centerx;
              A[2][1]=y1+height;
              A[2][2]=1;
              n=3;
        }
        break;

        case 2:
        {
        	  n=4;
              length=abs(x2-x1);
              A[2][0]=x2+length;
		 	  A[2][1]=y2+length;
		 	  A[2][2]=1;
              A[3][0]=x1+length;
		 	  A[3][1]=y1+length;
		 	  A[3][2]=1;
        }
        break;
	}
}

void graph::Showpoly()
{
	setcolor(YELLOW);
	for(int i=0;i<n-1;i++)
	line(midx+A[i][0],midy-A[i][1],midx+A[i+1][0],midy-A[i+1][1]);

	line(midx+A[0][0],midy-A[0][1],midx+A[n-1][0],midy-A[n-1][1]);

}


void graph::translation()
{
	int tx,ty;
	cout<<"Enter translation value tx,ty : ";
	cin>>tx>>ty;

	trans[2][0]=tx;
	trans[2][1]=ty;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
	       ans[i][j]=A[i][0]*trans[0][j]+A[i][1]*trans[1][j]+A[i][2]*trans[2][j];
		}
	}
	Display();
}

void graph::Scaling()
{
	int sx,sy;

	cout<<"Enter Scaling value sx,sy: ";
	cin>>sx>>sy;

	scal[0][0]=sx;
	scal[1][1]=sy;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<2;j++)
		{
			ans[i][j]=A[i][0]*scal[0][j]+A[i][1]*scal[1][j];
		}
	}

	Display();
}

void graph::Rotation()
{
	int t;

	cout<<"Enter rotation angle value in degree : ";
    cin>>t;

	rotat[0][0]=cos(t*3.14/180);
	rotat[0][1]=sin(t*3.14/180);
	rotat[1][0]=-1*sin(t*3.14/180);
	rotat[1][1]=cos(t*3.14/180);

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<2;j++)
		{
			ans[i][j]=A[i][0]*rotat[0][j]+A[i][1]*rotat[1][j];
		}
	}
	Display();
}

void graph::shear()
{
    int ch,shx,shy;

    cout<<"\n1. X-shear\n2. Y-shear\nEnter choice : ";
    cin>>ch;

    switch(ch)
    {
    	case 1:
    	     cout<<"\nEnter sx : ";
    	     cin>>shx;
    	     sh[1][0]=shx;
    	break;
    	case 2:
    	     cout<<"\nEnter sy : ";
    	     cin>>shy;
    	     sh[0][1]=shy;
    	break;
    }
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<2;j++)
		{
			ans[i][j]=A[i][0]*sh[0][j]+A[i][1]*sh[1][j]+A[i][2]*sh[2][j];
		}
	}
	Display();    


}

void graph::Display()
{
    setcolor(12);
	for(int i=0;i<n-1;i++)
	{
		line(midx+ans[i][0],midy-ans[i][1],midx+ans[i+1][0],midy-ans[i+1][1]);
	}
	line(midx+ans[0][0],midy-ans[0][1],midx+ans[n-1][0],midy-ans[n-1][1]);
}

int main()
{

	int gd=DETECT,gm,maxx,maxy;
 	initgraph(&gd,&gm,NULL);
	int t,ch;

	        maxx=getmaxx();
                maxy=getmaxy();

                midx=maxx/2;
                midy=maxy/2;
                line(midx,0,midx,maxy);
                line(0,midy,maxx,midy);

               graph obj;

	while(1)
	{
		cout<<"\n\n---------MENU-----------\n1. Create polygon\n2. Show polygon\n3. Translation\n4. Scaling\n5. Rotation\n6. Shearing\n7. Exit program\nEnter choice : ";
        cin>>ch;
        cout<<endl;

		switch(ch)
		{
			case 1:
 					obj.polygon();
				break;

			case 2:
					obj.Showpoly();
					break;

			case 3:
 					obj.translation();
				break;

			case 4:
 					obj.Scaling();
				break;

			case 5:
					obj.Rotation();
				break;
            case 6:
                    obj.shear();
                break;
			case 7:
					closegraph();
					return 0;
				break;
			default:
				cout<<"\nWrong Choice Please Try again...";
		}
	}

delay(1000);

}
