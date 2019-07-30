/*Team:
Grigory Ostanin
Jeff Howes
Anatoli Railean */

#include "functions/fullName.h"
#include "functions/password.h"
#include "functions/readInt.h"
#include "functions/writeToOutputFile.h"
#include "functions/fileName.h"

int main() {
	char firstName[51];
	char lastName[51];
	long long int num1, num2;
	long long int res_add, res_mult;
	char inputFileName[25];
	char outputFileName[25];

	name(firstName, sizeof(firstName), lastName, sizeof(lastName));
	//printf("\n%s %s\n", firstName, lastName);

	num1 = readInt("Enter first ");
	num2 = readInt("Enter second");
	//printf("\n%lld %lld\n", num1, num2);

	res_add = num1 + num2;
	res_mult = num1 * num2;

	getInputFileName(inputFileName, sizeof(inputFileName));
	getOutputFileName(outputFileName, inputFileName, sizeof(inputFileName));

	password();

	writeToOutputFile(firstName, lastName, res_add, res_mult, inputFileName, outputFileName);

	return 0;
}

