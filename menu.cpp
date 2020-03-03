


void showMenu(){

    int userInput;

    do{
        printf("--------------- To Do List -------------\n");
        printf("(1) Show list.\n");
        printf("(2) Add a list item.\n");
        printf("(3) Delete a list item.\n");
        printf("Enter your choice:");
        scanf("%d", &userInput);
        system("cls");
        printf("\n");

    }while(userInput != 0);



}
