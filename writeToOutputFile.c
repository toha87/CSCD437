#include <stdio.h>
#include <stdlib.h>

void writeToOutputFile(char fname[], char lname[], float add, float mult, char inputFname[], char outputFname[])
{

// https://stackoverflow.com/questions/3747086/reading-the-whole-text-file-into-a-char-array-in-c

   FILE *fptrInput;
   FILE *fptrOutput;
   long lSize;
   char *buffer;

   fptrInput = fopen(inputFname, "r");
   if( !fptrInput ) perror(fptrInput),exit(1);

   fseek( fptrInput , 0L , SEEK_END);
   lSize = ftell( fptrInput );
   rewind( fptrInput );

   buffer = calloc( 1, lSize+1 );
   if( !buffer ) fclose(fptrInput),fputs("memory alloc fails",stderr),exit(1);

   if( 1!=fread( buffer , lSize, 1 , fptrInput) )
   fclose(fptrInput),free(buffer),fputs("entire read fails",stderr),exit(1);

   fptrOutput = fopen(outputFname, "w");

   fputc (fname, fptrOutput);
   fputc (lname, fptrOutput);
   fputc (add, fptrOutput);
   fputc (mult, fptrOutput);
   fputc (buffer, fptrOutput);

   fclose(fptrInput);
   fclose(fptrOutput);
   free(buffer);
}