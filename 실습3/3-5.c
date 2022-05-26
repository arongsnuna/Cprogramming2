//receive two integers from user and ouput the common divisors of the integers
#include <stdio.h>

int main(void)
{
	int i, j;
	printf("Enter two Integer: ");
	scanf("%d %d", &i, &j); //receive two integers

	if (i > j) //if i is bigger than j
		for(int n = 1; n <= j; n++){
		//n is increased by one until n becomes j
			if ((i % n == 0) && (j % n == 0))
				printf("%d ", n);}
			//when i and j are divided into n, print n
	else //if i is smaller than j
		for (int n = 1; n <= i; n++){
		//n is increased by one until n becomes i
			if ((i % n == 0) && (j % n == 0))
				printf("%d ", n);}
			//when i and j are divided into n, print n
	
	printf("\n");
	return 0;
}
