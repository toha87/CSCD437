#include <stdio.h>
#include <stdlib.h>

void writeToOutputFile(char fname[], char lname[], float add, float mult, char inputFname[], char outputFname[])
{
   FILE *fptrInput;
   FILE *fptrOutput;
   size_t size = 0;
   char *buffer;

   fptrInput = fopen(inputFname, "r");
   fseek(fptrInput, 0, SEEK_END);
   size = ftell(fptrInput);
   rewind(fptrInput);
   buffer = malloc((size + 1) * sizeof(*buffer));
   fread(buffer, size, 1, fptrInput);
   buffer[size] = '\0';

   fptrOutput = fopen(outputFname, "w");
   fprintf(fptrOutput, "%s %s\n %f\n %f\n %s", fname, lname, add, mult, buffer);

   fclose(fptrInput);
   fclose(fptrOutput);
   free(buffer);
}