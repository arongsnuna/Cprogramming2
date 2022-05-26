//sort and output word in the  input string supplied to the command-line argument in alphabetical order
#include <stdio.h>
#include <string.h>

//command-line arguments
int main(int argc, char *argv[])
{	
	//there is unsorted char array named argv 

	int i, j, min; //declare integer type variable i, j, min
	char *temp; //declare character pointer
	
	for (i = 0; i < argc - 1; i++){
		min = i;
		for (j = i + 1; j < argc; j++){
			if (strcmp(argv[min], argv[j]) > 0)
			//if argv[min] is bigger than argv[j] in alphabetical order
				min = j; //min becomes j
		}
		temp = argv[min];
		argv[min] = argv[i];
		argv[i] = temp;
		//swap argv[min] and argv[i]
	}

	//print sorted argv
	for (i = 1; i < argc; i++)
		printf("%s \n", argv[i]);
	return 0;

}

