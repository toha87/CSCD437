#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> //INT_MAX and INT_MIN
#include "fullname.c"
#include "password.c"
#include "readInt.c"

FILE *getInputFile();
FILE *getOutputFile();

int main() {
	char firstName[51];
	char lastName[51];

	name(firstName, sizeof(firstName), lastName, sizeof(lastName));

    printf("%s %s", firstName, lastName); //only for testing
	putc('\n', stdout);

	// reads 2 ints from user
	int done = -1;

	do {
		done = readInt();
	} while(done == -1);

	return 0;
}

FILE *getInputFile() {
	const int FILE_NAME_BUF_SIZE = 255;
	char filename[FILE_NAME_BUF_SIZE];
	FILE * file;
	int isValidFileName = 0;
	regex_t regex;

	if (regcomp(&regex, "^([A-Za-z0-9\\-\\_]){1,251}.txt$", REG_EXTENDED)) {
		exit(1);
	}

	do {
		printf("Enter the name of the input text file (1-255 charactors), that must already exist in the current directory.\n");
		fgets(filename, FILE_NAME_BUF_SIZE, stdin);

		if (regexec(&regex, filename, 0, NULL, 0)) {
			isValidFileName = 0;
			printf("Make sure you file name is 1 - 251 character in length and has a .txt file.\n");
		}
		else if ((file = fopen(filename, "r")) == NULL){
			isValidFileName = 0;
			printf("Error: Can not read from input file : \n");
		}
		else {
			isValidFileName = 1;
		}

	} while (!isValidFileName);
	
	regfree(&regex);
	return file;
} //end of getInputFile function

FILE *getOutputFile() {
	const int FILE_NAME_BUF_SIZE = 255;
	char filename[FILE_NAME_BUF_SIZE];
	FILE * file;
	int isValidFileName = 0;
	regex_t regex;

	if (regcomp(&regex, "^([A-Za-z0-9\\-\\_]){1,251}.txt$", REG_EXTENDED)) {
		exit(1);
	}

	do {
		printf("Enter the name of the output text file (1-255 charactors), which will be created in the current directory.\n");
		fgets(filename, FILE_NAME_BUF_SIZE, stdin);

		if (regexec(&regex, filename, 0, NULL, 0)) {
			isValidFileName = 0;
			printf("Make sure you file name is 1 - 251 character in length and has a .txt file.\n");
		}
		else if ((file = fopen(filename, "w")) == NULL){
		isValidFileName = 0;
		printf("Error: Can not write to output file : \n");
		}
		else {
			isValidFileName = 1;
		}

	} while (!isValidFileName);

	regfree(&regex);
	return file;
} //end of getOutputFile function

