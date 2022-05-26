//creat four random numbers between 0 and 9 using rand(), srand(), time()
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	//decide seed value by relying on time value that change continuously
	srand(time(NULL)); 
	//print random numbers 4 times over using rand()
	for (int i = 0; i < 4; i++)
		printf("%3d", rand() %10);
	printf("\n");
	return 0;
}
