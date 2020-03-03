#ifndef STRINGFUNCTION_H_INCLUDED
#define STRINGFUNCTION_H_INCLUDED


#include "stringFunction.c"
//#include "stringFunction.c"

int countWord(char* str);
//delete a character in string


//this function will deleted first occurence of the character in string
char* delChar(char* str, char ch );

// delete at specific position in a string
char* delAtPosition(char* str, int pos);

//delete all charcaters in a string that
char* delAllChar(char* str, char ch);

// fucntion to detect if the word is existed in the string
// if yes then it will return index of first letter of the word in the string
// if no then it will return -1
// *** so when use if else you need to check carefully
int isWordInStr(char* str, char* word);

// delete a word from a string
char* delWordFromStr(char* str, char* word);

// delete a redundant space in string
char* delRedundantSpace(char* str);

//write a function to replace a word with another word in string

char* replaceWordInStr(char* str, char* oldWord, char* newWord);



#endif // STRINGFUNCTION_H_INCLUDED


