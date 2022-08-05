#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

/* Before using this library don't forget to declare variables with the right data types (e.g. long long unsigned int and double).
If implementing merge sort, declare and initialize mid point before that with a simple formula:
int mid = (number of elements) / 2;

This library's point is to give you guys a picture of how different sorting algorithms work.
That's why you see the sorting of the array step by step.

Do what you want with this code (I'm a supporter of open source).
This library will get updated in the future.

This library will get updated in the future(more sorting algorithms coming here), so don't worry.

I also added some functions with what you can see a char array in different codes(dec, oct, hex)

There could easily be some mistakes in the code, so if you catch them, feel totally free to change it to your needs.
Some input functions may be malfunctioning a little bit, so feel free to change them if necessary.
*/

int unsintswap(long long unsigned int *x, long long unsigned int *y){
    long long unsigned int temp = *x;
    *x = *y;
    *y = temp;
}

void unsintprintarr(long long unsigned int *arr, int size){
    for(int i = 0; i < size; i++){
        printf(" %llu", arr[i]);
    }
}

void unsintbubsort(long long unsigned int arr[], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size-1; j++){
            if(arr[j] > arr[j+1]){
                unsintswap(&arr[j], &arr[j+1]);
                unsintprintarr(arr, size);
                printf("\n");
            }
        }
    }
}

void unsintselsort(long long unsigned int arr[], int size){
    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            if(arr[i] > arr[j]){
                unsintswap(&arr[i], &arr[j]);
                unsintprintarr(arr, size);
                printf("\n");
            }
        }
    }
}

void unsintmersort(long long unsigned int arr[], int mid, int size){
    int i,j,k;
    int n1 = mid;
    int n2 = size - mid;
    long long unsigned int l[n1],r[n2];
    for(i = 0; i < n1; i++){
        l[i] = arr[i];
    }
    for(j = 0; j < n2; j++){
        r[j] = arr[mid+j];
    }
    printf("\nValues given to first temporary subarray: ");
    unsintprintarr(l, n1);
    printf("\nValues given to second temporary subarray: ");
    unsintprintarr(r, n2);
    for(i = 0; i < n1; i++){
        for(j = 0; j < n1-1; j++){
            if(l[j] > l[j+1]){
                unsintswap(&l[j],&l[j+1]);
                printf("\n");
                unsintprintarr(l, n1);
            }
        }
    }
    for(i = 0; i < n2; i++){
        for(j = 0; j < n2-1; j++){
            if(r[j] > r[j+1]){
                unsintswap(&r[j],&r[j+1]);
                printf("\n");
                unsintprintarr(r, n2);
            }
        }
    }
    printf("\nSorted first temporary subarray: ");
    unsintprintarr(l, n1);
    printf("\nSorted second temporary subarray: ");
    unsintprintarr(r, n2);
    printf("\n");
    i = 0;
    j = 0;
    k = 0;
    while(i < n1 && j < n2){
        if(l[i] <= r[j]){
            arr[k] = l[i];
            i++;
        }
        else{
            arr[k] = r[j];
            j++;
        }
        k++;
        printf("\n");
        unsintprintarr(arr, k);
    }
    while(i < n1){
        arr[k] = l[i];
        i++;
        k++;
        printf("\n");
        unsintprintarr(arr, k);
    }
    while(j < n2){
        arr[k] = r[j];
        j++;
        k++;
        printf("\n");
        unsintprintarr(arr, k);
    }
}

void unsintinssort(long long unsigned int arr[], int size){
    for(int i = 0; i < size; i++){
        long long unsigned int place = arr[i];
        int j = i - 1;
        while(place < arr[j] && j >= 0){
            arr[j+1] = arr[j];
            j--;
            arr[j+1] = place;
            unsintprintarr(arr, size);
            printf("\n");
        }
    }
}

int dblswap(double *x, double *y){
    double temp = *x;
    *x = *y;
    *y = temp;
}

void dblprintarr(double *arr, int size){
    for(int i = 0; i < size; i++){
        printf(" %.2lf", arr[i]);
    }
}

void dblbubsort(double arr[], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size-1; j++){
            if(arr[j] > arr[j+1]){
                dblswap(&arr[j], &arr[j+1]);
                dblprintarr(arr, size);
                printf("\n");
            }
        }
    }
}

void dblselsort(double arr[], int size){
    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            if(arr[i] > arr[j]){
                dblswap(&arr[i], &arr[j]);
                dblprintarr(arr, size);
                printf("\n");
            }
        }
    }
}

void dblmersort(double arr[], int mid, int size){
    int i,j,k;
    int n1 = mid;
    int n2 = size - mid;
    double l[n1],r[n2];
    for(i = 0; i < n1; i++){
        l[i] = arr[i];
    }
    for(j = 0; j < n2; j++){
        r[j] = arr[mid+j];
    }
    printf("\nValues given to first temporary subarray: ");
    dblprintarr(l, n1);
    printf("\nValues given to first temporary subarray: ");
    dblprintarr(r, n2);
    for(i = 0; i < n1; i++){
        for(j = 0; j < n1-1; j++){
            if(l[j] > l[j+1]){
                dblswap(&l[j],&l[j+1]);
                printf("\n");
                dblprintarr(l, n1);
            }
        }
    }
    for(i = 0; i < n2; i++){
        for(j = 0; j < n2-1; j++){
            if(r[j] > r[j+1]){
                dblswap(&r[j],&r[j+1]);
                printf("\n");
                dblprintarr(r, n2);
            }
        }
    }
    printf("\nSorted first temporary subarray: ");
    dblprintarr(l, n1);
    printf("\nSorted second temporary subarray: ");
    dblprintarr(r, n2);
    printf("\n");
    i = 0;
    j = 0;
    k = 0;
    while(i < n1 && j < n2){
        if(l[i] <= r[j]){
            arr[k] = l[i];
            i++;
        }
        else{
            arr[k] = r[j];
            j++;
        }
        k++;
        printf("\n");
        dblprintarr(arr, k);
    }
    while(i < n1){
        arr[k] = l[i];
        i++;
        k++;
        printf("\n");
        dblprintarr(arr, k);
    }
    while(j < n2){
        arr[k] = r[j];
        j++;
        k++;
        printf("\n");
        dblprintarr(arr, k);
    }
}

void dblinssort(double arr[], int size){
    for(int i = 0; i < size; i++){
        double place = arr[i];
        int j = i - 1;
        while(place < arr[j] && j >= 0){
            arr[j+1] = arr[j];
            j--;
            arr[j+1] = place;
            dblprintarr(arr, size);
            printf("\n");
        }
    }
}

int chswap(unsigned char *x, unsigned char *y){
    unsigned char temp = *x;
    *x = *y;
    *y = temp;
}

void chprintarr(unsigned char *arr, int size){
    for(int i = 0; i < size; i++){
        printf("  %d.\'%c\'", i+1, arr[i]);
    }
}

void chbubsort(unsigned char arr[], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size-1; j++){
            if(arr[j] > arr[j+1]){
                chswap(&arr[j], &arr[j+1]);
                chprintarr(arr, size);
                printf("\n");
            }
        }
    }
}

void chselsort(unsigned char arr[], int size){
    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            if(arr[i] > arr[j]){
                chswap(&arr[i], &arr[j]);
                chprintarr(arr, size);
                printf("\n");
            }
        }
    }
}

void chmersort(unsigned char arr[], int mid, int size){
    int i,j,k;
    int n1 = mid;
    int n2 = size - mid;
    unsigned char l[n1],r[n2];
    for(i = 0; i < n1; i++){
        l[i] = arr[i];
    }
    for(j = 0; j < n2; j++){
        r[j] = arr[mid+j];
    }
    printf("\nValues given to first temporary subarray: ");
    chprintarr(l, n1);
    printf("\nValues given to second temporary subarray: ");
    chprintarr(r, n2);
    for(i = 0; i < n1; i++){
        for(j = 0; j < n1-1; j++){
            if(l[j] > l[j+1]){
                chswap(&l[j],&l[j+1]);
                printf("\n");
                chprintarr(l, n1);
            }
        }
    }
    for(i = 0; i < n2; i++){
        for(j = 0; j < n2-1; j++){
            if(r[j] > r[j+1]){
                chswap(&r[j],&r[j+1]);
                printf("\n");
                chprintarr(r, n2);
            }
        }
    }
    printf("\nSorted first temporary subarray: ");
    chprintarr(l, n1);
    printf("\nSorted second temporary subarray: ");
    chprintarr(r, n2);
    printf("\n");
    i = 0;
    j = 0;
    k = 0;
    while(i < n1 && j < n2){
        if(l[i] <= r[j]){
            arr[k] = l[i];
            i++;
        }
        else{
            arr[k] = r[j];
            j++;
        }
        k++;
        printf("\n");
        chprintarr(arr, k);
        printf("\n");
    }
    while(i < n1){
        arr[k] = l[i];
        i++;
        k++;
        printf("\n");
        chprintarr(arr, k);
        printf("\n");
    }
    while(j < n2){
        arr[k] = r[j];
        j++;
        k++;
        printf("\n");
        chprintarr(arr, k);
        printf("\n");
    }
}

void chinssort(unsigned char arr[], int size){
    for(int i = 0; i < size; i++){
        unsigned char place = arr[i];
        int j = i - 1;
        while(place < arr[j] && j >= 0){
            arr[j+1] = arr[j];
            j--;
            arr[j+1] = place;
            chprintarr(arr, size);
            printf("\n");
        }
    }
}

void print_char_in_dec_oct_hex(unsigned char arr[], int size){
    printf("\n");
    printf("Decimal array: ");
    for(int i = 0; i < size; i++){
        printf("  %d.%d", i+1, arr[i]);
    }
    printf("\n");
    printf("Octal array: ");
    for(int i = 0; i < size; i++){
        printf("  %d.%o", i+1, arr[i]);
    }
    printf("\n");
    printf("Hexadecimal array: ");
    for(int i = 0; i < size; i++){
        printf("  %d.%x", i+1, arr[i]);
    }
}

void char_in_dec_oct_hex(){
    unsigned char arr[10];
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Choose up to 10 characters or symbols and see their decimal, octal and hexadecimal values\n");
    printf("Numbers are not accepted\n");
    printf("Choices");
    for(int i = 0; i < size; i++){
        printf("\n%d. Character:", i+1);
        scanf(" %c", &arr[i]);
    }
    printf("\nCharacter array: ");
    chprintarr(arr, size);
    print_char_in_dec_oct_hex(arr, size);
}

void unsintinput(){
    long long unsigned int arr[10];
    int size = sizeof(arr)/sizeof(arr[0]);
    int mid = size/2;
    char choice;
    printf("Select 10 integer numbers (max size: 18 quintillion).\nNegative numbers are not supported\n");
    printf("18 quintillion = 18,446,744,073,709,551,615\n");
    printf("Choices\n");
    for(int i = 0; i < size; i++){
        printf("\nNumber %d:", i+1);
        scanf(" %llu", &arr[i]);
    }
    printf("Array: ");
    unsintprintarr(arr, size);
    printf("\n");
    printf("Now choose your sort technique.\n");

    while(TRUE){
        printf("\nB or b for bubble sort, S or s for selection sort, M or m for merge sort, I or i for insertion sort.\n");
        printf("E or e to exit the program.\n");
        printf("A or a to do it again (uses recursion).\n");
        printf("Choice:");
        scanf(" %c", &choice);

        switch(choice){

            case 'B':
            case 'b':
            unsintbubsort(arr, size);
            printf("Sorted Array:  ");
            unsintprintarr(arr, size);
            break;

            case 'S':
            case 's':
            unsintselsort(arr, size);
            printf("Sorted Array:  ");
            unsintprintarr(arr, size);
            break;

            case 'M':
            case 'm':
            unsintmersort(arr, mid, size);
            printf("\nSorted Array:  ");
            unsintprintarr(arr, size);
            break;

            case 'I':
            case 'i':
            unsintinssort(arr, size);
            printf("Sorted array:  ");
            unsintprintarr(arr, size);
            break;

            case 'E':
            case 'e':
            exit(0);
            break;

            case 'A':
            case 'a':
            unsintinput();
            break;

            default:
            printf("\nWrong choice, try again.\n");
        }
    }
}

void dblinput(){
    double arr[10];
    int size = sizeof(arr)/sizeof(arr[0]);
    int mid = size/2;
    char choice;
    printf("Select 10 floating-point numbers (max size: 16 decimal places)\n");
    printf("Choices");
    for(int i = 0; i < size; i++){
        printf("\nNumber %d:", i+1);
        scanf(" %lf", &arr[i]);
    }
    printf("\nArray: ");
    dblprintarr(arr, size);
    printf("\nNow choose your sort technique.\n");

    while(TRUE){
        printf("\nB or b for bubble sort, S or s for selection sort, M or m for merge sort, I or i for insertion sort.\n");
        printf("E or e to exit the program.\n");
        printf("A or a to do it again(uses recursion).\n");
        printf("Choice:");
        scanf(" %c", &choice);
        
        switch(choice){

            case 'B':
            case 'b':
            dblbubsort(arr, size);
            printf("Sorted Array:  ");
            dblprintarr(arr, size);
            break;

            case 'S':
            case 's':
            dblselsort(arr, size);
            printf("Sorted Array:  ");
            dblprintarr(arr, size);
            break;

            case 'M':
            case 'm':
            dblmersort(arr, mid, size);
            printf("\nSorted Array:  ");
            dblprintarr(arr, size);
            break;

            case 'I':
            case 'i':
            dblinssort(arr, size);
            printf("Sorted array:  ");
            dblprintarr(arr, size);
            break;

            case 'E':
            case 'e':
            exit(0);
            break;

            case 'A':
            case 'a':
            dblinput();
            break;

            default:
            printf("\nWrong choice. Try again.\n");
        }
    } 
}

void charinput(){
    unsigned char arr[10];
    int size = sizeof(arr)/sizeof(arr[0]);
    int mid = size/2;
    char choice;
    printf("Enter 10 characters to sort them.\n");
    printf("Choices");
    for(int i = 0; i < size; i++){
        printf("\n%d. Character:", i+1);
        scanf(" %c", &arr[i]);
    }
    printf("Array: ");
    chprintarr(arr, size);
    printf("\n");
    printf("Now choose your sort technique\n");

    while(TRUE){
        printf("\nB or b for bubble sort, S or s for selection sort, M or m for merge sort, I or i for insertion sort.\n");
        printf("E or e to exit the program.\n");
        printf("A or a to do it again(uses recursion).\n");
        printf("Choice:");
        scanf(" %c", &choice);

        switch(choice){

            case 'B':
            case 'b':
            chbubsort(arr, size);
            printf("Sorted Array:  ");
            chprintarr(arr, size);
            break;

            case 'S':
            case 's':
            chselsort(arr, size);
            printf("Sorted Array:  ");
            chprintarr(arr, size);
            break;

            case 'M':
            case 'm':
            chmersort(arr, mid, size);
            printf("\nSorted Array:  ");
            chprintarr(arr, size);
            break;

            case 'I':
            case 'i':
            chinssort(arr, size);
            printf("Sorted array:  ");
            chprintarr(arr, size);
            break;

            case 'E':
            case 'e':
            exit(0);
            break;

            case 'A':
            case 'a':
            charinput();
            break;

            default:
            printf("\nWrong choice. Try again.\n");
        }
    }
}