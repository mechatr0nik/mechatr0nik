
//showing list
void showList(){

    char* listPath = "toDoList.txt";
    FILE* fp = openPath(listPath, "r");

    char line[200];
    int count = 1;

    while(fgets(line, 200, fp)){

        printf("(%d).%s", count,  line);
        count++;
    }

    fclose(fp);

    printf("\n----------------------------------------\n");
    printf("(0) Return to menu\n");
    printf("(1) Adding a list item\n");
    printf("(2) Delete a list item\n");
    printf("(3) Replace a list item\n");

    int userChoice;
    printf("Enter your choice:");
    scanf("%d", &userChoice);

    if(userChoice == 0){

            system("cls");
            showMenu();
    } else if ( userChoice == 1 ){

            printf("----------------------------------------\n");
            printf("Adding a new item\n");
            getchar();
            addingNewItem();
    } else if ( userChoice == 2 ){
            //system("cls");
            printf("----------------------------------------\n");
            printf("Delete an item\n");
            deleteItemFromFile();
    } else if( userChoice == 3 ) {

            printf("----------------------------------------\n");
            printf("REPLACE IN ITEM\n");
            replaceItem();

    }else {
        printf(" Invalid !!! return to menu...\n ");
      //  sleep(3000);
        showMenu();
	}

}


// show time
void showTime(){

    time_t t;
    time(&t);

    printf(" %s\n", ctime(&t));
    printf("----------------------------------------\n");
    printf("(0) Press 0 to return to menu\n");

    int choice;
    scanf("%d", &choice);
    while(choice != 0){
        printf("\n press 0 to return to menu\n");
        scanf("%d", &choice);
    }
    system("cls");
    showMenu();

}
//  delete an item from file
int deleteItemFromFile(){
    //open main file
    char* path = "toDoList.txt";
    FILE* fp = openPath(path, "r");

    // open temp file
    char *tempPath = "temp.txt";
    FILE *fpTemp = openPath(tempPath,"w");

    //input the index of file
    printf("Enter the item you wanna del: ");
    int lineNum;
    scanf("%d", &lineNum);

    int countLine = 1;

    char line[200];
    while(fgets(line, 200, fp)){

        if(countLine != lineNum){

            fprintf(fpTemp, "%s", line);
        }
        
			countLine++;
		}
        fclose(fp);
        fclose(fpTemp);

        remove("toDoList.txt");
        rename("temp.txt","toDoList.txt" );

    system("cls");
    printf("Deleting successful! go to menu in 2s...\n");
    Sleep(2000);
    showMenu();
    return 1;
}

void showMenu(){

        printf("--------------- To Do List -------------\n");
        printf("(1) Show list.\n");
        printf("(2) Show datetime rightnow.\n");
        printf("(0) Quit!.\n");
        printf("----------------------------------------\n");

        int userInput;
        printf("Enter your choice:");
        scanf("%d", &userInput);

    do{
        if(userInput == 1){
                system("cls");
                showList();
                break;
        } else if( userInput == 2){
                system("cls");
                showTime();
                break;
        }else if ( userInput == 0 ){
                system("cls");
                printf("Have a nice day!\n");
                //scanf("%d", &userInput);
                break;
        }else{
                printf("Invalid! Try again\n");
                printf("Enter your choice:");
                scanf("%d", &userInput);
        }

    }while(userInput != 0);
}

//adding to menu
int addingNewItem(){
    fflush(stdin);
    char content[200];
    printf("Enter your content(not greater than 200 char):");
    gets(content);

    // now we neet to get index for the new line
    //how??


    char * path = "toDoList.txt";
    FILE * fp = openPath(path, "a+");

    fprintf(fp, "%s\n", content); // need to add a trailing a newline chr because the ...
    fclose(fp);

    printf("Adding successfuly .Do you want to move to menu?? y/n  :");

    char choice;
    scanf("%c", &choice);

    if(choice == 'y'){

        system("cls");
        showMenu();
    } else{

        return 1;
    }

    return 0;

}


// replace item
int replaceItem(){

    printf("Enter your item you want to replace: ");
    int delItem;
    scanf("%d", &delItem);
    fflush(stdin);

    printf("Enter your content:");
    char content[300];
    gets(content);

    //open file
    char *path = "toDoList.txt";
    FILE *fp = openPath(path, "r");

    //open temp file
    char *temp = "temp.txt";
    FILE *fpTemp = openPath(temp,"w");

    int count = 1;
    char line[200];

    while(fgets(line, 200, fp)){

        if(count != delItem){

            //writing to new file
            fprintf(fpTemp, "%s", line );
        } else{

            fprintf(fpTemp, "%s\n", content);

        }
        count++;
    }

    fclose(fp);
    fclose(fpTemp);

    remove("toDoList.txt");
    rename("temp.txt", "toDoList.txt");

    printf("Replace successful! Reload in 2s...\n");
    Sleep(2000);

    system("cls");
    showList();

    return 1;
}//end
