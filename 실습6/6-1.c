//find distance and area of rectangle using pt1 and pt2
#include <stdio.h>
#include <math.h>

int main(void)
{
	//declare structure
	struct point{
		int x;
		int y;
	};
	struct point pt1 = {10, 20}; //pt1 = (10, 20)
	struct point pt2 = {30, 40}; //pt2 = (30, 40)
	
	//find distance between pt1 and pt2
	double dist = sqrt((pt1.x - pt2.x)*(pt1.x - pt2.x) + (pt1.y - pt2.y)*(pt1.y - pt2.y));
	printf("Distacne: %.2lf\n", dist);
	//find area of rectangle made by pt1, pt2
	double area = (pt2.x - pt1.x)*(pt2.y - pt1.y);
	printf("Area: %.2lf\n", area);
}
