//Write C++/Java program to implement reflection of2-D object about X axis, Y axis and about X=Y axis. Also rotate object about arbitrary point given by user.

#include<iostream>
#include<math.h>
#include<graphics.h>
#define M 10
int midx,midy;
using namespace std;

class graph
{
	private:

		int A[M][3],ans[M][3],refx[3][3],refy[3][3],refxy[3][3],n;
		float rotat[3][3];

	public:
		graph();
	void polynomial();
	void Showpoly();
	void reflectx();
	void reflecty();
	void reflectxy();
	void rotateA();
	void Display();
};

graph::graph()
{

	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
				if(i==j)
						refx[i][j]=refy[i][j]=1;
				else
					    refx[i][j]=refy[i][j]=0;

			    refxy[i][j]=0;
		}

	}

	rotat[0][2]=0;
	rotat[1][2]=0;
	rotat[2][2]=1;
}

void graph::polynomial()
{
	cout<<"Enter number of vertex: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{

		cout<<"\nX coordinate and Y coordinate for "<<i+1<<" point: ";
		cin>>A[i][0]>>A[i][1];
		A[i][2]=1;
	}
}

void graph::Showpoly()
{
	setcolor(YELLOW);
	for(int i=0;i<n-1;i++)
	line(midx+A[i][0],midy-A[i][1],midx+A[i+1][0],midy-A[i+1][1]);

	line(midx+A[0][0],midy-A[0][1],midx+A[n-1][0],midy-A[n-1][1]);

}


void graph::reflectx()
{

	refx[1][1]=-1;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
	       ans[i][j]=A[i][0]*refx[0][j]+A[i][1]*refx[1][j]+A[i][2]*refx[2][j];
		}
	}
	Display();
}

void graph::reflecty()
{

	refy[0][0]=-1;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
	       ans[i][j]=A[i][0]*refy[0][j]+A[i][1]*refy[1][j]+A[i][2]*refy[2][j];
		}
	}
	Display();
}

void graph::reflectxy()
{

	refxy[0][1]=1;
	refxy[1][0]=1;
	refxy[2][2]=1;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
	       ans[i][j]=A[i][0]*refxy[0][j]+A[i][1]*refxy[1][j]+A[i][2]*refxy[2][j];
		}
	}
	Display();
}

void graph::rotateA()
{
	int t,x,y;

    cout<<"Enter arbitary point (x,y) : ";
    cin>>x>>y;
	cout<<"\nEnter rotation angle value in degree : ";
    cin>>t;

	rotat[0][0]=cos(t*3.14/180);
	rotat[0][1]=sin(t*3.14/180);
	rotat[1][0]=-1*sin(t*3.14/180);
	rotat[1][1]=cos(t*3.14/180);
	rotat[2][0]=-x*cos(t*3.14/180)+y*sin(t*3.14/180)+x;
	rotat[2][1]=-x*sin(t*3.14/180)-y*cos(t*3.14/180)+y;


	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			ans[i][j]=A[i][0]*rotat[0][j]+A[i][1]*rotat[1][j]+A[i][2]*rotat[2][j];
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

    line(midx,0,midx,maxy); //Y-Axis
    line(0,midy,maxx,midy);

               graph obj;

	while(1)
	{
		cout<<"\n\n---------MENU-----------\n1. Create polynomial\n2. Show polynomial\n3. Reflection about X\n4. Reflection about Y\n5. Reflection about X=Y\n6. Rotation about arbitary point\n7. Exit program\nEnter choice : ";
        cin>>ch;
        cout<<endl;

		switch(ch)
		{
			case 1:
 					obj.polynomial();
				break;

			case 2:
					obj.Showpoly();
					break;

			case 3:
 					obj.reflectx();
				break;

			case 4:
 					obj.reflecty();
				break;

			case 5:
					obj.reflectxy();
				break;
			case 6:
			        obj.rotateA();
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
