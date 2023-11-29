// directives (#include, for example): editing commands that modify the program prior to compilation
// 	- intended for the preprocessor
// headers (<stdio.h>): each contains information about some part of the standard library
#include <stdio.h>

// functions:  named blocks of executable code, of which main in an example
// 	- a series of statements that have been grouped together and given a name
int main(void) {
	// statements: commands to be performed when the program is run
	printf("To C, or not to C: that is the question.\n"); // function call
	return 0; // return statement
}
