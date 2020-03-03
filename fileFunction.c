

FILE* openPath(char* path, char* mode){

    FILE* fp = fopen(path, mode);
    if(!fp ){
        printf("Can't open file at %s\n", path);
        return NULL;
    }
    //printf("Open successfully\n");
    return fp;
}
// remove word from file

int delWordFromFile(FILE* fp , char* word){

    char* tempPath = "temp.txt";
    FILE *fTemp = openPath(tempPath, "a");

    char *line = (char*)malloc(sizeof(char)*500);

    while(fgets(line,500,fp) != NULL){

        if(isWordInStr(line, word) >=0){
            line = delWordFromStr(line, word);
            line = delRedundantSpace(line);
            printf("found the word in string \n");
            printf("after del %s\n", line);
            fputs(line, fTemp);
        }else{
            // if not then we simply put the line into temp life
            fputs(line, fTemp);
        }

    }
    // now after we sorting line in the p we close and delete old file
    fclose(fp);

    remove("text.txt");
    fclose(fTemp);
    rename("temp.txt", "text.txt");


    return 4;

}

//delete a line from a file

int delLineFromFile(FILE* path, int lineNum){
    char* tempPath = "temp.txt";

    FILE* tempFile = openPath(tempPath, "a");

    int countLine = 1;
    char str[200] ;

    while(    fgets(str,200, path) != NULL ){
        if(lineNum != countLine){
            fputs(str, tempFile);

        }
        countLine++;
    }


    return 1;

}


