//Write C++/Java program to draw 2-D object and perform following basic transformations,
//a) Scaling
//b) Translation
//c) Rotation 

#include<iostream>
#include<math.h>
#include<graphics.h>
#define M 10
int midx,midy;
using namespace std;

class graph
{
	private:

		int A[M][3],ans[M][3],trans[3][3],n;
		float rotat[2][2],scal[2][2];

	public:
		graph();
	void polynomial();
	void Showpoly();
	void translation();
	void Scaling();
	void Rotation();
	void Display();
};

graph::graph()
{

	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
				if(i==j)
					trans[i][j]=1;

				else
					trans[i][j]=0;
		}

	}

	scal[0][0]=1;
	scal[0][1]=0;
	scal[1][0]=0;
	scal[1][1]=1;
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
		cout<<"\n\n---------MENU-----------\n1. Create polynomial\n2. Show polynomial\n3. Translation\n4. Scaling\n5. Rotation\n6. Exit program\nEnter choice : ";
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
 					obj.translation();
				break;

			case 4:
 					obj.Scaling();
				break;

			case 5:
					obj.Rotation();
				break;
			case 6:
					closegraph();
					return 0;
				break;
			default:
				cout<<"\nWrong Choice Please Try again...";
		}
	}

delay(1000);

}
