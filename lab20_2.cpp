#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *R1, Rect *R2)
{
	double maxx=0,maxy=0,minx=0,miny=0;
	double sumx=0,sumy=0;

	if(abs(R1->x-R2->x) > R1->w || abs(R1->y-R2->y) > R1->w)
	{
		return 0;
	}
	else
	{
		maxx = R1->x;
		if(R2->x > maxx) maxx = R2->x;
		
		minx = R1->x + R1->w;
		if((R2->x + R2->w) < minx) minx = (R2->x + R2->w);

		miny = R1->y;
		if(R2->y < miny) miny = R2->y;

		maxy = R1->y-R1->h;
		if((R2->y - R2->h) > maxy) maxy = (R2->y - R2->h);

		sumx = maxx-minx;
		sumy = maxy-miny;
		return sumx*sumy;
	}
}

int main()
{
	Rect R1 = {1,1,5,5};
	Rect R2 = {2,2,5,5};	
	cout << overlap(&R1,&R2);	
}