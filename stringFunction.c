//this is where you defined your function

int countWord(char* str){
    int length = strlen(str);
    int count = 1;

    for(int i= 1; i< length; i++){

        if(str[i] == 32){
            count++;
        }
    }

    return count;
}

char* delChar(char* str, char ch){
    int length = strlen(str);

    for(int i = 0; i < length; i ++){

        if(str[i] == ch){
            int pos = i ;
            for(int j = pos; j < length ; j++){

                str[j] = str[j + 1];
            }
            str[length - 1] = '\0';
            break;
        }
    }
    return str;
}

//

char* delAtPosition(char* str, int pos){
    int length = strlen(str);

    for(int i = 0; i < length; i ++){

        if(i == pos){

            for(int j = pos; j < length; j++){

                str[j] = str[j + 1];
            }

            return str;
            //break;
        }
    }
    return NULL;
}

//
char* delAllChar(char* str,char ch){
    int length = strlen(str);


    for(int i = 0; i < length; i++){

        if(str[i] == ch){
            str = delAtPosition(str, i);
            printf("inside f is %s\n", str);
            if(i == 0) i = -1;
            i--;
        }
    }

    return str;

}

// is this word in the string

int isWordInStr(char* str, char* word){

    int length = strlen(str);

    int wordLength = strlen(word);

    for(int i = 0; i< length ; i ++){

        if(str[i] == word[0]){
            int flag = FALSE;
            int wordIndex = i;
            for(int j = 0 ; j < wordLength ; j++){
                if(str[wordIndex] == word[j]){

                    flag = TRUE;
                    wordIndex++;
                }else{
                    flag = FALSE;
                    break;
                }


            }
            // if flag is true then the word is in the string
            // we can return the index of the word in the string
            if(flag == TRUE){

                return i;
            }

        }
    }

    // we return -1 when i can find the word in the string
    return -1;
}
//delete redundand space
char* delRedundantSpace(char* str){
    int length = strlen(str);

    //we have three case
    // 1 : redundant space at begining of string
    // 2 : inside the string
    // 3 : at the end of the string

    // now first
    while(str[0] == 32){
        str = delAtPosition(str, 0);
    }
    length = strlen(str);

    // deleting all redundant at the end of string
    while(str[length - 1] == 32){
        str = delAtPosition(str, length - 1);
        length = strlen(str);
    }

    // ok b
    // now we find redundand space between words HOW

    for(int i= 0; str[i] != '\0' ; i++){

        if(str[i] == 32){
            if(str[i + 1] ==  32){
                str = delAtPosition(str, i);
                i--;
            }
        }
    }

    return str;
}



// delete a word from a string
char* delWordFromStr(char* str, char* word){

    int wordLength = strlen(word);

    // first we need to check if the word is in the string or not
    while(isWordInStr(str, word) != -1){
        int indexWord = isWordInStr(str, word);

        for(int i = 0; i < wordLength; i ++){
            str = delAtPosition(str, indexWord);
        }

    }


    return str;
}

// replace word
char* replaceWordInStr(char* str, char* oldWord, char* newWord){
    int length = strlen(str);
    int oldLength = strlen(oldWord);
    int newLength = strlen(newWord);
    //

    // now we have three cases
    // first we handle the case when length of old word is equal to the length of new word

    if(isWordInStr(str, oldWord) >= 0){
            int pos = isWordInStr(str, oldWord);
        if(oldLength == newLength) {

            int newWordIndex = 0;
            for(int i = pos ; i <pos + oldLength ; i ++){
                str[i] = newWord[newWordIndex];
                newWordIndex++;
            }
            printf("str inside is %s", str);
            return str;
        } else if ( oldLength < newLength){
            int addNum = abs(oldLength - newLength);
            // allocating new section that can contain the changed string

            char* newStr = (char*) realloc(str, sizeof(char) * (length + addNum));

            strcpy(newStr, str);

            printf("str inside is %s\n", str);
            //return;
            for(int i = 0; i < addNum; i++ ){

                for( int j = (length + addNum) ; j > pos; j--){

                    newStr[j] = newStr[j - 1];
                }

            }
                newStr[length + addNum] = '\0';

            printf("str inside is %s\n", newStr);
            int iWord = 0;
            for(int i = pos ; i < pos + newLength ; i++){
                newStr[i] = newWord[iWord];
                iWord++;
            }


            return newStr;
        }else { // if old length is greater than new length . what to do
            int addNum = abs(oldLength - newLength);

            char* newStr = (char*) malloc(sizeof(char) * (length - addNum + 1));

            //find index of first space after replaced word
            int indexSpace = pos;
            for(int i = pos; i< length; i ++){
                if(str[i] == 32){
                    indexSpace = i;
                    break;
                }
            }
            printf("space pos is %d\n", indexSpace);
            for(int i = 0; i < pos; i ++){

                newStr[i] = str[i];
            }
            printf("%s\n", newStr);
            int iword = 0;
            for(int i = pos ; i< pos + newLength;i ++ ){

                newStr[i] = newWord[iword];
                iword++;
            }
            if ( pos == indexSpace){
                newStr[pos + newLength]= '\0';
                return newStr;
            }

            int indexNewStr = pos + newLength ;
            for(int i = indexSpace; i < length ; i++){
                newStr[indexNewStr] = str[i];
                indexNewStr++;
            }
            newStr[(length - addNum)] = '\0';
            return newStr;


        }


    } else {
        printf("Can't find the word %s in the string\n", oldWord);
        return '\0';

    }


}


