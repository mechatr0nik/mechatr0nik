#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <windows.h>


#include "stringFunction.h"
#include "fileFunction.h"
#include "menu.h"

#define TRUE 1
#define FALSE 0

void countFreKeyboard(){


    char* str = "the title case converter is perfect for those who are a bit unsure on how to title an upcoming essay it essentially ensures the correct letters are capitalized within the context of a title words such as an will be left all in lower case and words that are important will be converted such as title this is a  good solution for beginners because this dictionary enables native speakers to find translations from their languages into german here are the combinations that are available for you english german polish german and spanish german  and viceon the other hand we denounce with righteous indignation and dislike men who are so beguiled and demoralized by the charms of pleasure of the moment so blinded by desire that they cannot foresee the pain and trouble that are bound to ensue  and equal blame belongs to those who fail in their duty through weakness of will which is the same as saying through shrinking from toil and pain  these cases are perfectly simple and easy to distinguish  in a free hour when our power of choice is untrammelled and when nothing prevents our being able to do what we like best every pleasure is to be welcomed and every pain avoided but in certain circumstances and owing to the claims of duty or the obligations of business it will frequently occur that pleasures have to be repudiated and annoyances accepted the wise man therefore always holds in these matters to this principle of selection he rejects pleasures to secure other greater pleasures  or else he endures pains to avoid worse pains these were the lovely bones that had grown around my absense the connections sometimes tenuous sometimes made great cost but often magnificent that happened after i was done and i began to see things in a way that let me hold the world without me in it lorem ipsum is simply dummy text of the printing and typesetting industry lorem ipsum has been the industry standard dummy text ever since the  when an unknown printer took a galley of type and scrambled it to make a type specimen book it has survived not only five centuries but also the leap into electronic typesetting remaining essentially unchanged it was popularised in the with the release of letraset sheets containing lorem ipsum passages, and more recently with desktop publishing software like aldus pagemaker including versions of lorem ipsum";

    int leng = strlen(str);
    int left = 0, right = 0;
    for(int i = 0; i < leng; i ++){
        switch(str[i]){
            case 32:
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'a':
            case 'q':
            case 'z':
            case 'x':
            case 'y':
            case 'p':
            case 'j':
                left++;
                break;
            default :
            right++;
                break;
        }
    }
    printf("\n left is %f \n right is %f\n",((float)left/leng)*100 , ((float)right/leng)*100);
}
