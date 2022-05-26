//convert ' ' to '\n'
#include <stdio.h>

int main(void)
{
	char ch; //declare char type variable ch

  	printf("Input some characters, then press Ctrl+D.\n");

	while ((ch = getchar()) != EOF){
		if (ch == ' ' || ch == '\t')
			putchar('\n');
	       	//when sentence has space, it writes '\n' instead of space.
		else
			putchar(ch);
	       	//when sentence has char, it writes just char.
	}

	return 0;
}
