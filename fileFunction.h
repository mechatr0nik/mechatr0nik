#ifndef FILEFUNCTION_H_INCLUDED
#define FILEFUNCTION_H_INCLUDED



#include "fileFunction.c"
//include "fileFunction.c"
// write a function to check if a path is valid or not
// it will return path of file or null if not
FILE* openPath(char* path, char* mode);


//remove a word from file
int delWordFromFile(FILE* path, char* word);


//delete a line in a file
int delLineFromFile(FILE* path, int lineNum);

#endif // FILEFUNCTION_H_INCLUDED
