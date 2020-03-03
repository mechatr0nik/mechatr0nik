#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARR 100

#define TRUE 1

#define FALSE 0
#include <conio.h>
typedef struct Student{
    char name[100];
    int age;

}Student;


int gcf(int a, int b);
int lcf(int a, int b);
// find how many digit of a number
int numDigit(int num);
// check if is num a prime num or not
int isPrime(int num);
// check if is num a amstrong number
int isAmstrongNum(int num);
// check if is num a perfect number
int isPerfectNum(int );
// check if is num a strong number
int isStrongNum(int );
//  factorial
int factorial(int );
void fibonacci(int );

// count even and odd number in a array
void countOddEven(int arr[], int size);
// copy array
int * copyArr(int arr[], int size);
// insert an element into a dynamic arr
void insertIntoArr(int *arr, int *size, int val, int pos);
// initiate an arr
int * setArr( int *size);
// delete a element in an arr
int * delEleArr(int *arr, int *size, int pos);
// count the frequency of each element in arr
void countFreArr(int arr[], int size);
// print unique element in arr
void priUniArr(int arr[], int size);
// delete duplicate element in an array
int* delDuplicateEle(int * arr , int *size);
// reverse an array
int* reverseArr(int* arr , int size){
    int temp;

    for(int i = 0; i < size/2 ; i++){

        temp= arr[i];
        *(arr + i) = *(arr +size -1 -i);
        *(arr +size -1 - i ) = temp;
    }
    return arr;
}

// merge two array into one array
int * mergeTwoArr(int firstArr[],int size1, int secondArr[], int size2, int *totalSize){
    *totalSize = size1 + size2;
    int* resArr = (int*)malloc(*totalSize * sizeof(int));

    for(int i = 0; i < size1; i++){
        *(resArr + i) = firstArr[i];
    }

    for(int i = 0, j = size1; i<size2; i++,j++){
        *(resArr + j) = secondArr[i];
    }

    return resArr;

}
//swap two number
void swapNum(int* num1, int* num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;

}
// sorting array accesnding
int* sortAscArr(int arr[], int size){
    for(int i = 0; i< size -1  ; i++){
        for(int j = i+1; j < size ; j++){
            if(arr[i] <= arr[j]){
                swapNum(&arr[i], &arr[j]);

            }
        }
    }
    return arr;
}

#include <graphics.h>

int main()
{
// gm is Graphics mode which is
    // a computer display mode that
    // generates image using pixels.
    // DETECT is a macro defined in
    // "graphics.h" header file
    int gd = DETECT, gm, color;

    // initgraph initializes the
    // graphics system by loading a
    // graphics driver from disk
    initgraph(&gd, &gm, "");

    // Draws circle in white color
    // center at (100, 100) and radius
    // as 50
    circle(100, 100, 50);

    // setcolor function
    setcolor(GREEN);

    // Draws circle in green color
    // center at (200, 200) and radius
    // as 50
    circle(200, 200, 50);

    getch();

    // closegraph function closes the
    // graphics mode and deallocates
    // all memory allocated by
    // graphics system .
    closegraph();



    return 0;
} // end main

int * setArr( int *size){
    int * arr = (int *)malloc(*size * sizeof(int));

    for(int i = 0 ; i < *size ; i ++){
        printf("Enter %d value:", i);
        scanf("%d", &arr[i]);
    }


    return arr;
}

int gcf(int a, int b){
    int smallerNum, largerNum;
    if(a<=b){
        smallerNum = a;
        largerNum = b;
    }else {
        largerNum = b;
        smallerNum = a;
    }

    int commonF = 1;
    for(int i = 2; i<=smallerNum; i++) {
        if(smallerNum % i == 0){
            if(largerNum % i == 0){
                commonF = i;
            }
        }
    }

    return commonF;
}

int lcf(int a, int b){
    int smallerNum, largerNum;
    if(a<=b){
        smallerNum = a;
        largerNum = b;
    }else {
        largerNum = b;
        smallerNum = a;
    }
    int result = smallerNum * largerNum;
    int temp;
    for(int i = 1; i<= smallerNum; i++){
        temp = largerNum * i;
        if(temp % largerNum == 0 && temp % smallerNum == 0 ){
            result = temp;
            break;
        }
    }

    return result;
}

int isPrime(int num){
    for(int i = 2; i < num; i++){
        if(num % i == 0){
            return FALSE;
        }
    }
    return TRUE;
}

int isAmstrongNum(int num){
    int oriNum = num;
    int sum = 0;
    int countDigit = numDigit(num);
    int temp;
    while(num != 0){
        temp = num % 10;
        sum += (int)pow(temp, countDigit);
        num /= 10;
    }

    if(oriNum == sum){

        return TRUE;
    } else{
        return FALSE;
    }
}

int numDigit(int num){
    int count = 0;
    while(num != 0){
        num /= 10;
        count++;
    }
    return count;
}

int isPerfectNum(int num){
    int sum = 1;

    for(int i = 2; i < num; i++){
        if(num % i == 0){
            sum += i;
        }
    }

    if(sum == num)
        return TRUE;
    return FALSE;
}

int isStrongNum(int num){
    int oriNum = num;
    int sum = 0;
    int temp;

    while(num != 0){
        temp = num % 10;
        sum += factorial(temp);
        num /= 10;
    }

    if(sum == oriNum){
        return TRUE;
    }else{
        return FALSE;
    }


}
int factorial(int num){
    int mul =1;
    if (num == 0) return 1;
    for(int i = 2; i <= num;i++){
        mul*= i;

    }
    return mul;
}

void fibonacci(int num){
    int term1 = 1, term2 = 1;

    int sum = 0;
    printf("%d \n %d\n", term1, term2);

    for(int i = 0 ; i <= num ; i++){
        sum = term1 + term2;
        printf("%d \n", sum);
        term1 = term2;
        term2 = sum;
    }
}

void readArr(int *arr, int size){

    printf("Printing... \n");
    for(int i = 0; i < size ; i++){
        printf("  %d ", *(arr+i));
    }
    printf("\n-------------\n");
}

void secondLagNum(int arr[], int size){
    int max1, max2;
    max1 = 0;
    max2 = 0;

    for(int i = 0; i< size ; i++){
        if(arr[i] >= max1){
            max2 = max1;
            max1 = arr[i];
        }
        else if(arr[i] >= max2){
            max2 = arr[i];
        }else{
            continue;
        }

    }

    if(max1 < max2){
        max2 = max1;
    }

    printf("\nSecond lagest number is %d", max2);
}

void countOddEven(int arr[], int size){
    int countEven = 0, countOdd = 0;
    for(int i = 0; i< size ; i++){
        if(arr[i] % 2 == 0){
            countEven++;
        }else{
            countOdd++;
        }
    }

    printf("\nEven number: %d, Odd number : %d\n", countEven, countOdd);
}


int * copyArr(int arr[], int size){
    int * resArr = (int*)malloc((size) * sizeof(int));
    for(int i = 0; i< (size);i++){
        *(resArr+ i) = arr[i];
    }
    return resArr;
}

void insertIntoArr(int *arr, int *size, int val, int pos){
 // copy arr into new arr with new size
    arr = (int*) realloc(arr, sizeof(int )* ((*size)+1) );
    *size = *size + 1;
 //
    for(int i=(*size -1) ; i>= pos;i--){
       *(arr + i) = *(arr + i - 1);
    }

    *(arr + pos) = val;

}

int *  delEleArr(int *arr, int *size, int pos){
    if(pos == *size-1){
        arr = copyArr(arr, *size - 1);
        *size = *size-1;
        return arr;
    }else {
        for(int i = pos ; i< *size; i++){
            *(arr+i) = *(arr+ i+ 1);
        }
        arr = copyArr(arr, *size - 1);
        *size = *size-1;

        return arr;
    }
}

void countFreArr(int arr[], int size){

    for(int i = 0 ; i < size; i++){
        int count = 0;

        for(int j = 0 ;j < size; j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }

        printf("Frequency of %d is  %d \n", arr[i], count);
        count = 0;
    }
}

void priUniArr(int arr[], int size){
    int flag = TRUE;
    printf("\n -*Unique elements in array is: ");
    for(int i = 0;i < size ; i++){
        for(int j = 0; j < size ; j++){
            if(i == j) continue;
            if(arr[i] == arr[j]){
                flag = FALSE;
                break;
            }
        }
        if(flag == TRUE){
            printf("%d ", arr[i]);
        }
        flag = TRUE;
    }
}

int* delDuplicateEle(int * arr,int *size){

    for(int i = 0;i < *size ; i++){
        for(int j = 0; j < *size ; j++){
            if(i==j)   continue;
            if(arr[i] == arr[j]){
                arr = delEleArr(arr, size, j);
                i = 0;
                break;
            }
        }
    }

    return arr;
}

