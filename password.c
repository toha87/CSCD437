
#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <crypt.h>

void inputpass(char pass[], size_t length);

void password() {
	char pass[20];
	char storedpassword[14];

	inputpass(pass, sizeof(pass));	
	char * hpass = crypt(pass, "thisisthesalt");

	int i;
	for(i = 0; i < 14; i++) {

		storedpassword[i] = hpass[i];
	}
	storedpassword[14] = '\0';

	inputpass(pass, sizeof(pass));
	hpass = crypt(pass, "thisisthesalt");

	if(strcmp(hpass,storedpassword) == 0)
		printf("Correct password\n");
	else {
		printf("Incorrect password\n");
	}
}

void inputpass(char pass[], size_t length) {
	char s1[] = "Enter your password(only letters and digits are allowed, length [1,20]";
	regex_t regex;

    if(regcomp(&regex, "\\s*^[a-zA-Z0-9]{1,20}$\\s*", REG_EXTENDED)) {
		exit(1);
	}
	do{
		int i;
		for(i = 0; i < 70; i++) {
			putc(s1[i], stdout);
		}
		putc('\n', stdout);
	}while(fgets(pass, length, stdin) != NULL && regexec(&regex, pass, 0, NULL, 0));
	//clean string

}