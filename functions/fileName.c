#include "fileName.h"
#include "fullName.h"

void getInputFileName(char inputfile[], size_t length) {
	char s1[] = "Enter input file name(only letters and digits are allowed, length [1,20], file must exists in programs' directory)";
	regex_t regex;

	

	if (regcomp(&regex, "^([A-Za-z0-9]){1,20}\\.txt$\\s*", REG_EXTENDED)) {
		exit(1);
	}

	do {
		int i;
		for(i = 0; i < 91; i++) {
			putc(s1[i], stdout);
		}
		putc('\n', stdout);

	} while (!(fgets(inputfile, length, stdin) != NULL) || cleanstring(inputfile, length) || regexec(&regex, inputfile, 0, NULL, 0) || access(inputfile, F_OK));
	cleanstring(inputfile, length);
}

void getOutputFileName(char outputFile[], char inputFile[], size_t length) {
	char s1[] = "Enter output file name(only letters and digits are allowed, length [1,20], if file exists, file will be overwritten)";
	regex_t regex;

	if (regcomp(&regex, "^([A-Za-z0-9]){1,20}\\.txt$\\s*", REG_EXTENDED)) {
		exit(1);
	}

	do {
		int i;
		for(i = 0; i < 116; i++) {
			putc(s1[i], stdout);
		}
		putc('\n', stdout);

	} while (!(fgets(outputFile, length, stdin) != NULL) || regexec(&regex, outputFile, 0, NULL, 0) || !strncmp(outputFile, inputFile, length));
	cleanstring(outputFile, length);
}