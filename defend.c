#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> //INT_MAX and INT_MIN
#include "fullname.c"
#include "password.c"
#include "readInt.c"
#include "writeToOutputFile.c"
#include "FileName.c"


int main() {
	char firstName[51];
	char lastName[51];
	float num1, num2;
	float res_add, res_mult;
	char inputFileName[255];
	char outputFileName[255];

	name(firstName, sizeof(firstName), lastName, sizeof(lastName));

    printf("%s %s", firstName, lastName); //only for testing
	putc('\n', stdout);

	// reads 2 ints from the user
	num1 = readInt();
	num2 = readInt();

	res_add = num1 + num2;
	res_mult = num1 * num2;

	// input out file names
	getInputFileName(inputFileName);
	getOutputFileName(outputFileName, inputFileName);

	// password

	writeToOutputFile(firstName, lastName, res_add, res_mult, "inputFileName", "outputFileName");

	return 0;
}

