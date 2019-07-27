#include <stdio.h>
#include <regex.h>
#include <string.h>
#include <stdlib.h>

void getOutputFileName(char outputFileName[], char inputFileName[]);

void getInputFileName(char inputFileName[]) {
	int const BUFF_SIZE = 255;	
	size_t usersInputFileStrLen;
	int isValidFileName = 0;
	regex_t regex;

	if (regcomp(&regex, "^([A-Za-z0-9]){1,254}\\.txt$", REG_EXTENDED)) {
		exit(1);
	}

	do {
		printf("Enter the name of the input text file (1-254 charactors), that must already exist in the current directory.\n");
		fgets(inputFileName, BUFF_SIZE, stdin);

		usersInputFileStrLen = strlen(inputFileName);
		if (usersInputFileStrLen >= 2 && usersInputFileStrLen <= 254 ){  //replace the carrage return with a null char.
			inputFileName[usersInputFileStrLen - 1] = '\0';
			//printf("string is between 1 & 254\n");
		}


		if (0 != regexec(&regex, inputFileName, 0, NULL, 0)) {  //if regex fails
			isValidFileName = 0;
			printf("Make sure you file name is 1 - 250 character in length and has a .txt file.\n");
			//printf("Regex failed - The file name is %s\n", inputFileName);
			//printf("The filename length is %ld \n", strlen(inputFileName));
					   			
		}
		else { //regex passed.
			//printf("Inside the get input filename method - The file name is %s\n", inputFileName);
			return;
		}

	} while (!isValidFileName);
}


void getOutputFileName(char outputFileName[], char inputFileName[]) {
	int const BUFF_SIZE = 255;
	size_t usersOutputFileStrLen;
	int isValidFileName = 0;
	regex_t regex;

	if (regcomp(&regex, "^([A-Za-z0-9]){1,254}\\.txt$", REG_EXTENDED)) {
		exit(1);
	}

	do {
		printf("Enter the name of the output text file (1-254 charactors).\n");
		fgets(outputFileName, BUFF_SIZE, stdin);

		usersOutputFileStrLen = strlen(outputFileName);
		if (usersOutputFileStrLen >= 2 && usersOutputFileStrLen <= 254) {  //replace the carrage return with a null char.
			outputFileName[usersOutputFileStrLen - 1] = '\0';
			//printf("string is between 1 & 254\n");
		}

		if (strcmp(outputFileName, inputFileName) == 0) {
			isValidFileName = 0;
			printf("Error: Output file name matches input file name.\n");
		}
		else if (0 != regexec(&regex, outputFileName, 0, NULL, 0)) {  //if regex fails
			isValidFileName = 0;
			printf("Make sure you file name is 1 - 250 character in length and has a .txt file.\n");
			//printf("Regex failed - The file name is %s\n", inputFileName);
			//printf("The filename length is %ld \n", strlen(inputFileName));

		}
		else { //regex passed.
			//printf("Inside the get output filename method - The file name is %s\n", outputFileName);
			return;
		}

	} while (!isValidFileName);
}