//sort the string array and output the array
#include <stdio.h>
#include <string.h>
#define ELEMENTS 8
#define NAMELEN 10

void sort(char v[][NAMELEN], int n)
{
	char temp[NAMELEN]; //temporary string where the string is stored
	int i, j;

	for (i = 0; i < n; i++){
		for (j = 0; j < n - i; j++){
			if (strcmp(v[j], v[j + 1]) >0){
			//when v[j] string is bigger then v[j+1], it returns 1
				strcpy(temp, v[j]);
				strcpy(v[j], v[j + 1]);
				strcpy(v[j + 1], temp);
				//so this change the position using temp
			}
		}
	}
}

int main(void)
{
	int i, j;
	char array[ELEMENTS][NAMELEN] = {"kim", "lee", "park", "choi", "jung", "kang", "cho"};
	//print the array before sorting
	printf("array[]\n");
	for (i=0; i < ELEMENTS; i++)
		printf("%s ", array[i]);
	//sorting with sort function
	sort(array, ELEMENTS - 1);
	//print the array after sorting
	printf("\n\n");
	printf("array[] after sort\n");
	for (j=0; j < ELEMENTS; j++)
		printf("%s ", array[j]);
	printf("\n");
	return 0;
}




