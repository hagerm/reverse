/**********************************************************************
A reverse file library to containing the necessary functions. Utilizes
a malloc inside of the function read_file which will need to be freed.

@author Matthew A. Hager
@version September 29, 2017
**********************************************************************/

// Includes
#include "file_utils.h"
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>

/**********************************************************************
read_file reads in a file and stores its contents in a char* that is 
          passed as pointer to a pointer so it can be used outside the
          function.
@param filename The name of the existing file to be read in.
@param buffer The char 'array' to hold the file contents.
@return Returns the size of the file read.
**********************************************************************/
int read_file( char* filename, char **buffer ) {
	
    // Setting up read_file
	FILE * read_file;
	read_file = fopen( filename, "r" );
		
    // Error check for a non-existing file
	if ( read_file == NULL ) {
		fprintf( stderr, "ERR 2: Input file was not found.\n" );
		return -1;
	}

    // Checking the file  size that was read in.
	struct stat st;
	stat(filename, &st);
	size_t file_size = st.st_size;

    // Mallocing the buffer.
	if ( file_size > 0 ) {
		*buffer = malloc(file_size * sizeof(char));
	}
	else {
        fprintf( stderr,
                "ERR: There was an error determining file size.\n");
		return -1;
	}

    // Size of the character array from the file. For Error checking
    size_t read_size = fread( *buffer, 1, file_size, read_file);

	fclose( read_file);
	
	if ( file_size != read_size ) {
        fprintf( stderr,
                "ERR: There was an error reading the file.\n" );
		return -1;
	}
    
    // returns size of character array
    return read_size;
}

/**********************************************************************
write_file Writes to a given file name a character array that is passed
           in.
@param filename is the name of the file to write to.
@param buffer is the characters to be reversed from read_file
@param size is the expected size of the file. Should match the filesize
            that was used in read_file. (Assuming these functions are
            used together.
@return Returns the size of the file written.
**********************************************************************/
int write_file( char* filename, char *buffer, int size) {

    // Opens file to write to.
	FILE * write_file;
	write_file = fopen( filename, "w");

	int i = size - 1;

    // Goes through the characters in buffer in the reverse order.
	while( i >= 0 )	{
		fputc( buffer[i], write_file);
		i = i - 1;
	}	
	
    // Closes the file.
	fclose( write_file);	

    // Gets the size of the file.
	struct stat st;
	stat(filename, &st);
	int file_size = st.st_size;

    // Returns -1 if the write file ends up a different size than the
    // input.
	if ( size != file_size ) {
		fprintf( stderr,
                "ERR 2: There was an error in writing the file.\n");
		return -1;
	}

    // Returns the file size written.
	return file_size;
}
