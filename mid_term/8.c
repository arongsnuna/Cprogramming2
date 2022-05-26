//output the sum and mean of rows, columns, total in a two-dimensional array
#include <stdio.h>

int main(void)
{
	int i, j;
	//declare the integer type variable i and j
	//i is related to rows and j is relate to colums
	double row_sum = 0; 
	double column_sum = 0;
	double total_sum = 0;
	//declare the double type variable row_sum, column_sum, total_sum
	//and initialize

	double a[][5] = {{1.0, 6.0, 11.0, 16.0, 21.0},
			 {2.0, 7.0, 12.0, 17.0, 22.0},
			 {3.0, 8.0, 13.0, 18.0, 23.0},
			 {4.0, 9.0, 14.0, 19.0, 24.0},
			 {5.0, 10.0, 15.0, 20.0, 25.0}};
	//print sum and mean of rows 
	for (i = 0; i < 5; i++){
		for (j =0; j < 5; j++){
			printf("%7.2f",a[i][j]);
			row_sum += a[i][j];
			if (j == 4){
				printf("%7.2f", row_sum);
				//print sum of a row
				printf("%7.2f", row_sum/5);
				//print mean of a row
				row_sum = 0;
				//when the row is changed, row_sum is initialize to 0
			}
		}
		printf("\n");
	}
	printf("\n");

	//print sum of columns
	for (j = 0; j < 5; j++){
		for (i = 0; i < 5; i++){
			column_sum += a[i][j];
			total_sum += a[i][j];
		}
		printf("%7.2f", column_sum);
		//print sum of a column
		column_sum = 0;
		//when the column is changed, column_sum is initalized to 0
	}
	printf("%7.2f\n", total_sum);
	//print sum of total
	
	//print mean of columns
	for (j = 0; j < 5; j++){
		for (i = 0; i < 5; i++){
			column_sum += a[i][j];
		}
		printf("%7.2f", column_sum/5);
		//print mean of a column
		column_sum = 0;
		//when the column is change, column_sum is initalized to 0
	}
	printf("       %7.2f\n", total_sum/25);
	//print total mean using total_sum
	return 0;	
}
