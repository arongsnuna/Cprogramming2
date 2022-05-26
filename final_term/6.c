//get two integer a,b from user
//get fibonacci numbers between a and b
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
        long long a, b; //declare long long type variable
        scanf("%lld %lld", &a, &b); //get number from user

	long long fibo1=1, fibo2=2;
        long long result; 
	//declare long long type variable to get fibonacci number
	
        int count=0; //declare integer type variable for counting number of fibonacii
	//get the i th fibonacci number (result)
        for (int i = 3; i < b; i++){
		result = fibo1 + fibo2;
		fibo1 = fibo2;
		fibo2 = result;

                if (result>a && result<b){
                        printf("%lld ", result);
                        count++;
		}
        }
        printf("\n%d\n", count); 
	//print the number of fiboanacci number between a and b
        return 0;
}

