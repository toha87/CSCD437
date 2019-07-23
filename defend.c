#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> //INT_MAX and INT_MIN
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
		for(i = 0; i < 57; i++) {
			putc(s1[i], stdout);
		}
		putc('\n', stdout);
	}while(fgets(firstName, sizeof(firstName), stdin) != NULL && regexec(&regex, firstName, 0, NULL, 0));
	putc('\n', stdout);
	do{
		int i;
		for(i = 0; i < 56; i++) {
			putc(s2[i], stdout);
		}
		putc('\n', stdout);
	}while(fgets(lastName, sizeof(lastName), stdin) != NULL && regexec(&regex, lastName, 0, NULL, 0));
	putc('\n', stdout);


	printf("%s %s", firstName, lastName); //only for testing
	regfree(&regex);

	return 0;
}
