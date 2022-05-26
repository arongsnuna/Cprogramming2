//output ascii code
#include <stdio.h>

int main(void)
{
	for (int i = 33; i <= 126; ++i){
		//output in decimal, hevadecimal, character order
		if (i % 6 == 2){//if i % 6 ==2,print data involving \n
			printf("%3d%3X%3c \n", i, i, i);
		}
		else {//on the other cases, just print data
			printf("%3d%3X%3c ", i, i, i);
		}
	}
	printf("\n");
	return 0;
}
