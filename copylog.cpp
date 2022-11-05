#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

// Edited: note comments after the code
#ifndef O_LARGEFILE
#define O_LARGEFILE 0
#endif

int read_from_file_open(char *filename,size_t size)
{
    int fd, sz; 
    char *c = (char *) calloc(100, sizeof(char)); 
    
    fd = open(filename, O_RDONLY); 
    if (fd < 0) { perror("r1"); exit(1); } 
    
    lseek(fd, -1 * size, SEEK_END);
    sz = read(fd, c, size); 
    printf("called read(% d, c, 10). returned that"
            " %d bytes were read.\n", fd, sz); 
    c[sz] = '\0'; 
    printf("Those bytes are as follows: % s\n", c); 

    return(0);
}


int main(int argc, char *argv[])
{
    int size = atoi(argv[1]);
    char *sourcefilename = argv[2];
    char *destinationfilename = argv[3];
    FILE *source, *destination;
    char ch;
    int i=0;


    printf("\n\nCopying %d MBs from %s to %s \n\n", size, sourcefilename, destinationfilename);

    read_from_file_open (sourcefilename, size);
/*
    source = fopen(sourcefilename, "r");
 
   if( source == NULL )
   {
      printf("can't open source file.\nPress any key to exit...\n");
      exit(EXIT_FAILURE);
   }
 
   destination = fopen(destinationfilename, "w");
 
   if( destination == NULL )
   {
      fclose(source);
      printf("can't open destination file\nPress any key to exit...\n");
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
*/

}

