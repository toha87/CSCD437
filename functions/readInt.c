#include "readInt.h"
#include "fullName.h"

#define BUFF_LEN 12

int readInt(char count[])
{
	int i;
    char str[BUFF_LEN];
    long long int num;
    regex_t regex;
	char s1[] = " number, numbers could be from -2,147,483,648 to 2,147,483,647";

    if(regcomp(&regex, "\\s*^(-)?[0-9]{1,11}$\\s*", REG_EXTENDED)) {
		exit(1);
	}

    do {
        do{
            fdrain(stdin);
            int i;
            for(i = 0; i < 12; i++) {
                putc(count[i], stdout);
            }
            for(i = 0; i < 62; i++) {
                putc(s1[i], stdout);
            }
            putc('\n', stdout);
        }while(!(fgets(str, BUFF_LEN, stdin) != NULL) || regexec(&regex, str, 0, NULL, 0));
        cleanstring(str, BUFF_LEN);
        sscanf(str, "%lld", &num);
        fdrain(stdin);
    } while(num > INT_MAX || num < INT_MIN);

    return num;
}