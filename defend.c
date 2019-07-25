#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> //INT_MAX and INT_MIN

#include "readInt.c"
FILE *getInputFile();
FILE *getOutputFile();

/*
atoi to convert to integer
*/
int main() {
	regex_t regex;
	int result_reg;
	char firstName[51];
	char lastName[51];
	char s1[] = "Enter first name(only letters are allowed, length [2,50]";
	char s2[] = "Enter last name(only letters are allowed, length [2,50]";

	if(regcomp(&regex, "\\s*^[a-zA-Z]{2,50}$\\s*", REG_EXTENDED)) {
		return 1;
	}
	do{
		int i;
		for(i = 0; i < 56; i++) {
			putc(s1[i], stdout);
		}
		putc('\n', stdout);
	}while(fgets(firstName, sizeof(firstName), stdin) != NULL && regexec(&regex, firstName, 0, NULL, 0));
	putc('\n', stdout);
	do{
		int i;
		for(i = 0; i < 55; i++) {
			putc(s2[i], stdout);
		}
		putc('\n', stdout);
	}while(fgets(lastName, sizeof(lastName), stdin) != NULL && regexec(&regex, lastName, 0, NULL, 0));
	putc('\n', stdout);


	printf("%s %s", firstName, lastName); //only for testing
	regfree(&regex);

	// reads 2 ints from user
	int done = -1;

	do {
		done = readInt();
	} while(done == -1);

	return 0;
}

File *getInputFile() {
	const FILE_NAME_BUF_SIZE = 255;
	char filename[FILE_NAME_BUF_SIZE];
	FILE *file = NULL;
	int isValidFileName = 0;
	regex_t regex;

	if (regcomp(&regex, "^([A-Za-z0-9\\-\\_]){1,251}.txt$", REG_EXTENDED)) {
		return 1;
	}

	do {
		printf("Enter the name of the input text file (1-255 charactors), that must already exist in the current directory.\n");
		fgets(filename, FILE_NAME_BUF_SIZE, stdin);

		if (regexec(&regex, filename, 0, NULL, 0)) {
			isValidFileName = 0;
			printf("Make sure you file name is 1 - 251 character in length and has a .txt file.\n");
		}
		else if (file = fopen(file, "r")) == NULL){
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

File *getOutputFile() {
	const FILE_NAME_BUF_SIZE = 255;
	char filename[FILE_NAME_BUF_SIZE];
	FILE *file = NULL;
	int isValidFileName = 0;
	regex_t regex;

	if (regcomp(&regex, "^([A-Za-z0-9\\-\\_]){1,251}.txt$", REG_EXTENDED)) {
		return 1;
	}

	do {
		printf("Enter the name of the output text file (1-255 charactors), which will be created in the current directory.\n");
		fgets(filename, FILE_NAME_BUF_SIZE, stdin);

		if (regexec(&regex, filename, 0, NULL, 0)) {
			isValidFileName = 0;
			printf("Make sure you file name is 1 - 251 character in length and has a .txt file.\n");
		}
		else if (file = fopen(file, "w")) == NULL){
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

