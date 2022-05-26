//return day of year and month day using multi-dimensional array daytab[][]
#include <stdio.h>
//multi-dimensional array
static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},//common year
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} //leap year
};
//set day of year from month and day
int day_of_year(int year, int month, int day)
{
	int i, leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	//if the year is leap year, leap = 1
	//if the year is common year, leap = 0
	for ( i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}
//set month and day from day of year
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 4 == 0;
	//if the year is leap year, leap = 1
	//if the year is common year, leap = 0
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
	printf("month: %d, day: %d.", *pmonth, *pday);
}

int main(void)
{
	int m, d;
	printf("2021.4.30 is %dth day of the year.\n", day_of_year(2021, 4, 30));
	printf("2014.4.16 is %dth day of the year.\n", day_of_year(2014, 4, 16));
	printf("200th day of 2021 is ");
	month_day(2021, 200, &m, &d);
	printf("\n300th day of 2000 is ");
	month_day(2000, 300, &m, &d);
	printf("\n");
}
