
#include "password.h"
#include "fullName.h"

void password() {
	char pass[21];
	char * storedpassword;
	storedpassword = calloc(21, sizeof(char));
	
	printf("Enter ");
	inputpass(pass, sizeof(pass));	
	char * hpass = crypt(pass, "thisisthesalt");

	store(hpass);
	
	printf("Repeat ");
	inputpass(pass, sizeof(pass));
	hpass = crypt(pass, "thisisthesalt");
	
	storedpassword = getstore();

	if(strcmp(hpass,storedpassword) == 0)
		printf("Correct password\n");
	else {
		printf("Incorrect password\n");
	}

	free(storedpassword);
}

void inputpass(char pass[], size_t length) {
	char s1[] = "your password (only letters and digits are allowed, length [1,20])";
	regex_t regex;

    if(regcomp(&regex, "\\s*^[a-zA-Z0-9]{1,20}$\\s*", REG_EXTENDED)) {
		exit(1);
	}
	do{
		int i;
		for(i = 0; i < 65; i++) {
			putc(s1[i], stdout);
		}
		putc('\n', stdout);
	}while(fgets(pass, length, stdin) != NULL && regexec(&regex, pass, 0, NULL, 0));
	cleanstring(pass, length);
	fdrain(stdin);
}

void store(unsigned char password[]) {
	FILE *fp;

   	fp = fopen("./notpassword.txt", "w");
   	fputs(password, fp);
   	fclose(fp);
}

unsigned char * getstore() {
	FILE *fp;
	unsigned char * password = calloc(32, sizeof(unsigned char));
   	fp = fopen("./notpassword.txt", "r");
   	fgets(password, 14, fp);
   	fclose(fp);

	return password;
}