#include <stdio.h>
#include <ctype.h>

#define MAX_STR_LEN (50)

int readInt()
{
	int i;
    float res_add, res_mult;
    char str[MAX_STR_LEN] = {0};
    float num1, num2;

    printf("Enter two numbers separated by a space, numbers could be from -2147483648 to 2147483647: ");
    fgets(str, MAX_STR_LEN, stdin);

    for(i = 0; i < MAX_STR_LEN; i++)
    {
        if(!isdigit(str[i]) && (!isspace(str[i])) && (str[i] != '\0'))
        {
            if((i != 0) && (str[i - 1] != ' ') && ((str[i] != '+') || (str[i] != '-')))
            {
                printf("'%c' is not a digit! Exiting the program!", str[i]);
                return -1;
            }
        }

        if((str[i] == '\n') || (str[i] == '\0'))
            break;
    }

    sscanf(str, "%f%f", &num1, &num2);

    res_add = num1 + num2;
    res_mult = num1 * num2;

    return 0;
}