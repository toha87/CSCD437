#include "fullName.h"

void name(char fname[], size_t fsize, char lname[], size_t lsize) {
    regex_t regex;
	char s1[] = "Enter first name(only letters are allowed, length [2,50]";
	char s2[] = "Enter last name(only letters are allowed, length [2,50]";

    if(regcomp(&regex, "\\s*^[a-zA-Z]{2,50}$\\s*", REG_EXTENDED)) {
		exit(1);
	}
	int c;
	do{
		fdrain(stdin);
		int i;
		for(i = 0; i < 56; i++) {
			putc(s1[i], stdout);
		}
		putc('\n', stdout);
	}while(!(fgets(fname, fsize, stdin) != NULL) || regexec(&regex, fname, 0, NULL, 0));
	cleanstring(fname, fsize);
	do{
		fdrain(stdin);
		int i;
		for(i = 0; i < 55; i++) {
			putc(s2[i], stdout);
		}
		putc('\n', stdout);
		
	}while(!(fgets(lname, lsize, stdin) != NULL) || regexec(&regex, lname, 0, NULL, 0));
    cleanstring(lname, lsize);
	fdrain(stdin);
	regfree(&regex);
}

int cleanstring(char string[], int length) {
    int i;
	int k = -1;
    for(i = 0 ; i < length; i++) {
        if(string[i] == '\n') {
            string[i] = '\0';
			k = 0;
        }
    }

	return k;
}

void fdrain(FILE *const in) {
    if (in) {
        int const descriptor = fileno(in);
        int       flags, dummy;

        flags = fcntl(descriptor, F_GETFL);
        fcntl(descriptor, F_SETFL, flags | O_NONBLOCK);

        do {
            dummy = getc(in);
        } while (dummy != EOF);

        fcntl(descriptor, F_SETFL, flags);
    }
}