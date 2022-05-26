//find the nearest integer to 1000 
//among the integers that satify the below condition 
#include <stdio.h>
#define DISCOVER 1
#define UNDISCOVER 0

int main(void) 
{
	int i;//declare the integer type variable i
	int state = UNDISCOVER;
	//declare the integer type variable state and it means "undiscover"

	for (i = 1000; state = DISCOVER; --i){
		if (i % 6 == 1 && i % 8 == 5 && i % 13 == 10){ //the condition
			state = DISCOVER;
			//when find the integer i, state is changed to "discover"
			printf("The integer that satifies the condition is %d.\n", i);
			return i;
		}
	}
	
}
