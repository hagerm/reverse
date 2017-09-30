/**********************************************************************
The main function to demonstrate the read/write functionality for the
reverse_file library.

@author Matthew A. Hager
@version September 29, 2017
**********************************************************************/

#include "file_utils.h"
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

/**********************************************************************
Accepts agruments from the command line.
The first is the input to read_file, the 2nd is the file to write to.
**********************************************************************/
int main(int argc, char** argv){

    // Define variables.
	char * file_in = argv[1];
	char * file_out = argv[2];
	char * buffer;
	int size_compare;

    // Provided struct to check filesize in linux
	struct stat st;
	stat(file_in, &st);
	int size = st.st_size;

    size_compare = read_file( file_in, &buffer);

    // Check for a read error.    
    if ( size_compare < 0 || size_compare != size ){
        printf("The file failed to be read properly.\n");
    }
    else{
        size_compare = write_file( file_out, buffer, size);
        
        // Check for a write error.
        if ( size_compare < 0 || size_compare != size ) {
            printf("The file failed to write properly.\n");
        }
    }

    // Successful print
	printf("\nThe file: %s was reversed and stored in: %s\n\n",
           file_in, file_out);
    
    // buffer was malloced inside of read_file and thus needs freed.
	free(buffer);
	return 0;
}
