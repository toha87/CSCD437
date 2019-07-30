#ifndef PASSWORD_H
#define PASSWORD_H

#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <crypt.h>

void password();
void inputpass(char pass[], size_t length);
unsigned char * getstore();
void store(unsigned char password[]);

#endif