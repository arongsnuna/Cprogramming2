//output all the primes between 1 and 200
#include <stdio.h>

int main (void)
{
	int i, j;
	for (i = 1; i <=200; i++){ 
	//if n is a prime, loop is finished when j becomes i
		for ( j =2; j < i; j++){
			if (i%j ==0){//j is a divisor of i
				break;
			}
		}
		if ( j == i){//j is a prime
			printf("%d\n", j);
		}
	}
	return 0;
}
