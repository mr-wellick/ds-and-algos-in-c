#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void){
	printf("The min int is %d\n",INT_MIN);
	printf("The max int is %d\n", INT_MAX);
	printf("\n");

	printf("Size of int: %zu bytes\n", sizeof(int));
	printf("Size of int: %zu bits\n", sizeof(int)*8);
	printf("\n");

	printf("The min float is %e\n",FLT_MIN);
	printf("The max float is %e\n", FLT_MAX);
	printf("\n");

	printf("Size of float: %zu bytes\n", sizeof(float));
	printf("Size of float: %zu bits\n", sizeof(int)*8);
	printf("\n");
	return 0;
}

// Notes

// The type of a numeric variable determines the largest and smallest numbers that the variable can store.
// int: wholes numbers
