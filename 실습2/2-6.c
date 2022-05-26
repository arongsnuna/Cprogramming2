#include <stdio.h>

int htoi(char s[])
{
	int n = 0, i = 0; //declare int type variable n, i and initialize n, i

	while (s[i] != '\0'){ //until the string is finished
		if (s[i] >= '0'&& s[i] <= '9')//change string to hexagonal 0~9
			n = 16 * n + (s[i] - '0');
		if (s[i] >= 'A' && s[i] <= 'F')//change string to hexagonal A~F
		       n = 16* n + (s[i] - 'A' + 10);
		i++;
	}
	return n;
}

int main(void)
{
	char h[] = "12AF";

	printf("%s\n", h); //print string h
	printf("%X\n", htoi(h));//print hexagonal number h
	printf("%d\n", htoi(h));//print decimal number h

	return 0;
}



