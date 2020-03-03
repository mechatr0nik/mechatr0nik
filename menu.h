#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED



//menu struct

typedef struct {
    char name[200];
    char createdDate[200];

}Menu;



// show Menu
void showMenu();

//show list
void showList();
// show timezone
void showTime();
// adding a new item to the list
int addingNewItem();
int deleteItemFromFile();


//int
int replaceItem();


#include "menu.c"

#endif // MENU_H_INCLUDED
