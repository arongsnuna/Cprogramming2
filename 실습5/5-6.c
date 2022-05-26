//related echo -r option
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int i;//declare integer type variable 

	if (strcmp((*++argv), "-r") == 0)//if argv[0] == "-r"
	{
		for (i = argc - 2; i >= 1; i--)
			printf("%s ", argv[i]); 
		//output in reverse order of input
	}
	else //if argv[0] != "-r"
	{
		for(i = 0; i < argc - 1; i++)
			printf("%s ", argv[i]); 
		//ouput in the order entered
	}
	putchar('\n');
	return 0;
}
