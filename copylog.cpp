#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int size = atoi(argv[1]);
    char *sourcefilename = argv[2];
    char *destinationfilename = argv[3];
    FILE *source, *destination;
    char ch;
    int i=0;


    printf("\n\nCopying %d MBs from %s to %s \n\n", size, sourcefilename, destinationfilename);

    source = fopen(sourcefilename, "r");
 
   if( source == NULL )
   {
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE);
   }
 
   destination = fopen(destinationfilename, "w");
 
   if( destination == NULL )
   {
      fclose(source);
      printf("Press any key to exit...\n");
      exit(EXIT_FAILURE);
   }
 
   while( ( ch = fgetc(source) ) != EOF )
   {
      fputc(ch, destination);
      printf("%c",ch);
      i++;
   }
 
    long int sourcefilesize = ftell(source);
    long int destinationfilesize = ftell(destination);

   printf("File copied successfully. %d chars copied \n", i);
   printf("Source file size %ld chars \n", sourcefilesize);
   printf("Destination file size %ld chars \n", destinationfilesize);

   fclose(source);
   fclose(destination);
 
   return 0;

}