
#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
void cleanstring(char string[], size_t length);

void name(char fname[], size_t fsize, char lname[], size_t lsize) {
    regex_t regex;
	int result_reg;
	char s1[] = "Enter first name(only letters are allowed, length [2,50]";
	char s2[] = "Enter last name(only letters are allowed, length [2,50]";

    if(regcomp(&regex, "\\s*^[a-zA-Z]{2,50}$\\s*", REG_EXTENDED)) {
	}
	do{
		int i;
		for(i = 0; i < 56; i++) {
			putc(s1[i], stdout);
		}
		putc('\n', stdout);
	}while(fgets(fname, fsize, stdin) != NULL && regexec(&regex, fname, 0, NULL, 0));
    cleanstring(fname, fsize);
	do{
		int i;
		for(i = 0; i < 55; i++) {
			putc(s2[i], stdout);
		}
		putc('\n', stdout);
	}while(fgets(lname, lsize, stdin) != NULL && regexec(&regex, lname, 0, NULL, 0));
    cleanstring(lname, lsize);

	regfree(&regex);
}

void cleanstring(char string[], size_t length) {
    int i;
    for(i = 0 ; i < length; i++) {
        if(string[i] == '\n') {
            string[i] = '\0';
        }
    }
}