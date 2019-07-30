#include "writeToOutputFile.h"

void writeToOutputFile(char fname[], char lname[], long long int add, long long int mult, char inputFname[], char outputFname[])
{
   FILE *fptrInput;
   FILE *fptrOutput;
   size_t size = 0;
   char *buffer;

   fptrInput = fopen(inputFname, "r");
   fseek(fptrInput, 0, SEEK_END);
   size = ftell(fptrInput);
   rewind(fptrInput);
   buffer = calloc((size + 1), sizeof(*buffer));
   fread(buffer, size, 1, fptrInput);
   fclose(fptrInput);

   fptrOutput = fopen(outputFname, "w");
   fprintf(fptrOutput, "Full name: %s %s\nAddition: %.2lld\nMultiplication: %.2lld\n%s file content:\n%s", fname, lname, add, mult, inputFname, buffer);
   fclose(fptrOutput);

   free(buffer);
}