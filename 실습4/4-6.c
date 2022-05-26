//print sorted array by using qsort function and swap function
#include <stdio.h>
//sort into incresing order
void qsort(double v[], int left, int right)
{
	int i, last;
	void swap(double v[], int i, int j);

	if (left >= right)
		return;
	//do nothing if array contains fewer than two elements
	
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if (v[i] < v[left]) 
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}
void swap(double v[], int i, int j)//interchange v[i] and v[j]
{
	double temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
#define ELEMENTS 10
int main(void){
	double array[] = {1.1, 9.9, 2.2, 8.8, 3.3, 7.7, 4.4, 6.6, 5.5, 0.0};
	int i, j;
	//print original array from first to last 
	printf("array[] \n");
	for (i = 0; i < ELEMENTS; i++)
		printf("%4.1f", array[i]);
	//sorting
	qsort(array, 0, 9);
	//print sorted array from first to last
	printf("\n\narray[] after qsort()\n");
	for (j = 0; j < ELEMENTS; j++)
		printf("%4.1f", array[j]);
	
	printf("\n");
	return 0;
}
