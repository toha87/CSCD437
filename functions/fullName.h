#ifndef FULLNAME_H
#define FULLNAME_H

#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <fcntl.h>

int cleanstring(char string[], int length);
void name(char fname[], size_t fsize, char lname[], size_t lsize);
void fdrain(FILE *const in);

#endif
