//input two integer(>0) from user and get sum of them
#include <stdio.h>
int main(void)
{
	unsigned long long num1, num2;//declare unsigned long long type variable 
	scanf("%llu %llu", &num1, &num2); //get 2 integer from user

	printf("1st integer %llu\n2nd integer %llu\n%llu\n", num1, num2, num1+num2);
	//print sum of two integer
	return 0;
}

