//do integer factorization  and ouput it
#include <stdio.h>

int main (void)
{
	int num; //declare integer type variable num (integer to factorize)
	int i;//declare integer type variable i
	printf("Input Integer: ");
	scanf("%d", &num);//get the integer from the user

	for (i = 2; i <= num; i++){
		if (num % i == 0){ 
		//i is prime of num
			printf("%d ", i);
			num /= i; //set new num and find the prime of the num 
			if (num % i == 0) //if there is more prime of num
				printf("* ");//insert operator *
			else {//num % i != 0
				if (num > i)
				//when there is no more prime, num becomes 1 and num < i
				//so if num > i, there is more prime
					printf("* "); //so insert operator *
			}
			i = 1; 
			//initialize i into 1 and i will become 2 on next step
		} 
	}
	printf("\n");
	return 0;
}
