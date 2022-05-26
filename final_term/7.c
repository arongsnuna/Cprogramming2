//change decimal number to binary number
#include <stdio.h>

int main(void)
{
	int num; //declare integer type variable for decimal number
	int arr[20] = {0}; //array for binary number

	printf("Enter decimal number: ");
	scanf("%d", &num); //decimal number from user

	int i = 0; //declare integer type variable for counting
	while (num > 0){ //binary number
		arr[i] = num % 2;
		num /= 2;
		i++;
	}

	printf("Binary number is: ");
	//ouput in reverse order because binary number is upside down in the array
	for (int j = i-1; j >= 0; j--)
		printf("%d", arr[j]);
	printf("\n");
	return 0;
}
