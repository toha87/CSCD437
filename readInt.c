#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_STR_LEN (50)

int readInt()
{
	int i;
    char str[MAX_STR_LEN] = {0};
    float num;

    printf("Enter a number, numbers could be from -2147483648 to 2147483647: ");
    fgets(str, MAX_STR_LEN, stdin);

    for(i = 0; i < MAX_STR_LEN; i++)
    {
        if(!isdigit(str[i]) && (!isspace(str[i])) && (str[i] != '\0'))
        {
            if((i != 0) && (str[i - 1] != ' ') && ((str[i] != '+') || (str[i] != '-')))
            {
                printf("'%c' is not a digit! Exiting the program!", str[i]);
                exit(1);
            }
        }

        if((str[i] == '\n') || (str[i] == '\0') || (str[i] == ' '))
            break;
    }

    sscanf(str, "%f", &num);

    return num;
}