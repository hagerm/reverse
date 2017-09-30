/**********************************************************************
Header file for the reverse library.

@author Matthew A. Hager
@version September 29, 2017
**********************************************************************/

// Include Guards
#ifndef FILE_UTILS_H
#define FILE_UTILS_H

/**********************************************************************
read_file Uses a internal malloc to allocate a char array to be used
          by write_file.
@param filename is the name of the existing file to read.
@param buffer is the address of a point to point to the character array
**********************************************************************/
int read_file( char* filename, char **buffer );

/**********************************************************************
write_file writes a given char array to a chosen file.
@param filename is the file you are writing to. Will overwrite existing
                files.
@param buffer is the character array to write to the file.
@param size is the expected size of the file that is normal gotten from
            read_file.
**********************************************************************/
int write_file( char* filename, char *buffer, int size);

#endif
