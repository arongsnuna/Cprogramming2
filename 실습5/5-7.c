//pointer to function
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 1000 //max length of any input lines
#define MAXLINES 5000 //max lines to be sorted
#define ALLOCSIZE 10000 //size of available space
static char allocbuf[ALLOCSIZE]; //storage for alloc
static char *allocp = allocbuf; //next free position
char *lineptr[MAXLINES]; //pointers to text lines

char *alloc(int n) //return pointer to n characters
{
	if (allocbuf + ALLOCSIZE - allocp >= n)
	{
		allocp += n;
		return allocp - n;
	}
	else //not enough room
		return 0;
}
int mygetline(char s[], int lim) //get line into s, return length
{
	int i;
	char c;

	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

int myreadlines(char *lineptr[], int maxlines) //read input lines
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = mygetline(line, MAXLEN))>0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0'; //delete newline character
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}
void writelines(char *lineptr[], int nlines) //write ouput lines
{
	int i;
	for ( i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}
int numcmp(char *s1, char *s2) //compare s1 and s2 numerically
{
	double v1, v2;
	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}
char myswap(char *v[], int i, int j) //interchange v[i] and v[j]
{
	char *temp;
	temp = v[i];
	v[i] = v[j]; 
	v[j] = temp;
}
void myqsort(char *v[], int left, int right, int (*comp)(void*, void*))
	//sort into increasingly order
{
	int i, last;

	if(left >= right)
		return;
	myswap(v, left, (left + right)/2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			myswap(v, ++last, i);
	myswap(v, left, last);
	myqsort(v, left, last - 1, comp);
	myqsort(v, last + 1, right, comp);
}
//sort input lines
int main(int argc, char *argv[])
{
	int nlines; //number of input lines read
	int numeric = 0; 
	//if numeric sort, numeric = 1 and if alphabetic sort, numeric = 0

	if (argc > 1 && strcmp((*++argv), "-n") == 0) //if argv[0] == "-n"
		numeric = 1;
	if ((nlines = myreadlines(lineptr, MAXLINES)) >= 0)
	{
		myqsort(lineptr, 0, nlines-1, (int (*)(void*, void*))(numeric ? numcmp : strcmp));
		printf("\nAfter sort.\n");
		writelines(lineptr, nlines);
		return 0;
	}

	return 0;
}
