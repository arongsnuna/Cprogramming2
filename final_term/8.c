//get the number of line, word, charcters
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//command-line argument
int main(int argc, char *argv[])
{
	FILE *file;

	char ch; //declare character type variable
	int num=0;
	int words=0;
	int lines=0; 
	//declare integer type variable and initialize

	file = fopen(argv[1], "r"); //open the file with read option
	while ((ch=fgetc(file))!=EOF) //read the character one by one
	{
		printf("%c", ch);
		num++; //increase the number of character
		if ((ch=='\n')||(ch=='\0'))
			lines++; //increase the number of line
		if ((ch==' ')||(ch =='\t')||(ch =='\n')||(ch=='\0'))
			words++; //increase the number of word
	}
	fclose(file);
	//print the number of line, word, character and file name
	printf("%d %d %d %s\n", lines, words, num, argv[1]);
	return 0;
}
