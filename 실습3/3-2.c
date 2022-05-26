//do the calcution without scanf
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
	char ch;
	int i = 0, j = 0;
	char str[50];
	char a[20], b[20], op;
	int fp = 0;

	while ((ch = getchar()) != EOF){//run until ^D is received
		str[i++] = ch;//put char in str
		if (ch == '\n'){
			for (i = 0, j = 0; isdigit(str[i])|| str[i] == '.';){
			//recognize as a digit
				if (str[i] == '.')
					fp = 1;//fp = 1 means float
				a[j++] = str[i++];//first number is in a[]
			}
			a[j] = '\0';
			for (; str[i] == ' '; i++);//space
			op = str[i++];//+,-,/,*
			for (; str[i] == ' '; i++);//space
			for (j = 0; isdigit(str[i])|| str[i] == '.'; ){
			//recognize as a digit
				if(str[i] == '.')
					fp = 1;//fp = 1 means float
				b[j++] = str[i++];//second number is in b[]
			}
			b[j] = '\0';
		
			switch (op)
			//according to op and type, do different calculations
			{
			case '+':
				if (fp == 1)
					printf("%f\n",atof(a) + atof(b));
				else
					printf("%d\n", atoi(a) + atoi(b));
				fp = 0;//clear the fp
				break;
			case '-':
				if (fp == 1)
					printf("%f\n", atof(a) - atof(b));
				else
					printf("%d\n", atoi(a) - atoi(b));
				fp = 0;//clear the fp
				break;
			case '/':
				if (fp == 1)
					printf("%f\n", atof(a) / atof(b));
				else
					printf("%d\n", atoi(a) / atoi(b));
				fp = 0;//clear the fp
				break;
			case '*':
				if (fp == 1)
					printf("%f\n", atof(a) * atof(b));
				else
					printf("%d\n", atoi(a) * atoi(b));
				fp = 0;//clear the fp
				break;
			case '%':
				if (fp == 1)
					printf("Error occured.");
				else
					printf("%d\n", atoi(a) % atoi(b));
				fp = 0;//clear the fp
				break;

			}
			i=0;
		}
	}
		
	
	return 0;
}
