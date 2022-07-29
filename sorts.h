#include <stdio.h>

// before using this library don't forget to declare variables with the right data types (e.g. long long unsigned int and double)

int unsintswap(long long unsigned int *x, long long unsigned int *y){
    unsigned int result = *x;
    *x = *y;
    *y = result;
}

void unsintprintarr(long long unsigned int arr[], int size){
    for(int i = 0; i < size; i++){
        printf(" %d", arr[i]);
    }
}

void unsintbubsort(long long unsigned int arr[], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - 1; j++){
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

void unsintmersort(long long unsigned int arr[], int size, int mid){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < mid; j++){
            if(arr[j] > arr[j+1]){
                unsintswap(&arr[j], &arr[j+1]);
                unsintprintarr(arr, size);
                printf("\n");
            }
        }
        for(int k = mid; k < size - 1; k++){
            if(arr[k] > arr[k+1]){
                unsintswap(&arr[k], &arr[k+1]);
                unsintprintarr(arr, size);
                printf("\n");
            }
        }
    }
}

void unsintinssort(long long unsigned int arr[], int size){
    for(int i = 0; i <= size; i++){
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

void unsintinput(){
    long long unsigned int arr[10];
    int size = sizeof(arr)/sizeof(arr[0]);
    int mid = size/2;
    char choice;
    printf("Select 10 integer numbers (max size: 18 quintillion).\nNegative numbers are not supported\n");
    printf("18 quintillion = 18,000,000,000,000,000,000\n");
    printf("Choices\n");
    for(int i = 0; i < size; i++){
        printf("\nNumber %d:", i+1);
        scanf(" %d", &arr[i]);
    }
    printf("Array: ");
    unsintprintarr(arr, size);
    printf("\n");
    printf("Now choose your sort technique\n");
    printf("B or b for bubble sort, S or s for selection sort, M or m for merge sort, I or i for insertion sort:\n");
    printf("Choice:");
    scanf(" %c", &choice);

    switch(choice){

        case 'B':
        unsintbubsort(arr, size);
        printf("Sorted Array:  ");
        unsintprintarr(arr, size);
        break;

        case 'b':
        unsintbubsort(arr, size);
        printf("Sorted Array:  ");
        unsintprintarr(arr, size);
        break;

        case 'S':
        unsintselsort(arr, size);
        printf("Sorted Array:  ");
        unsintprintarr(arr, size);
        break;

        case 's':
        unsintselsort(arr, size);
        printf("Sorted Array:  ");
        unsintprintarr(arr, size);
        break;

        case 'M':
        unsintmersort(arr, size, mid);
        printf("Sorted Array:  ");
        unsintprintarr(arr, size);
        break;

        case 'm':
        unsintmersort(arr, size, mid);
        printf("Sorted Array:  ");
        unsintprintarr(arr, size);
        break;

        case 'I':
        unsintinssort(arr, size);
        printf("Sorted array:  ");
        unsintprintarr(arr, size);
        break;

        case 'i':
        unsintinssort(arr, size);
        printf("Sorted array:  ");
        unsintprintarr(arr, size);
        break;

        default:
            while(choice != 'B' && choice && 'b' && choice != 'S' && choice != 's' && choice != 'M' && choice != 'm'){
            printf("\nB or b for bubble sort, S or s for selection sort, M or m for merge sort, I or i for insertion sort.\n");
            printf("Choice:");
            scanf(" %c", &choice);
            if(choice == 'B' || choice == 'b'){
                unsintbubsort(arr, size);
                printf("Sorted Array:  ");
                unsintprintarr(arr, size);
            }
            if(choice == 'S' || choice == 's'){
                unsintselsort(arr, size);
                printf("Sorted Array:  ");
                unsintprintarr(arr, size);
            }
            if(choice == 'M' || choice == 'm'){
                unsintmersort(arr, size, mid);
                printf("Sorted Array:  ");
                unsintprintarr(arr, size);
            }
            if(choice == 'I' || choice == 'i'){
                unsintinssort(arr, size);
                printf("Sorted array:  ");
                unsintprintarr(arr, size);
            }
        }
    }
}

int dblswap(double *x, double *y){
    double result = *x;
    *x = *y;
    *y = result;
}

void dblprintarr(double arr[], int size){
    for(int i = 0; i < size; i++){
        printf(" %.2lf", arr[i]);
    }
}

void dblbubsort(double arr[], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - 1; j++){
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

void dblmersort(double arr[], int size, int mid){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < mid; j++){
            if(arr[j] > arr[j+1]){
                dblswap(&arr[j], &arr[j+1]);
                dblprintarr(arr, size);
                printf("\n");
            }
        }
        for(int k = mid; k < size - 1; k++){
            if(arr[k] > arr[k+1]){
                dblswap(&arr[k], &arr[k+1]);
                dblprintarr(arr, size);
                printf("\n");
            }
        }
    }
}

void dblinssort(double arr[], int size){
    for(int i = 0; i <= size; i++){
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

void dblinput(){
    double arr[10];
    int size = sizeof(arr)/sizeof(arr[0]);
    int mid = size/2;
    char choice;
    printf("Select 10 floating-point numbers (max size: 16 decimal places)\n");
    printf("Choices");
    for(int i = 0; i < size; i++){
        printf("\nNumber %d:", i+1);
        scanf(" %Lf", &arr[i]);
    }
    printf("\nArray: ");
    dblprintarr(arr, size);
    printf("\nNow choose your sort technique\n");
    printf("B or b for bubble sort, S or s for selection sort, M or m for merge sort, I or i for insertion sort.\n");
    printf("Choice:");
    scanf(" %c", &choice);

    switch(choice){

        case 'B':
        dblbubsort(arr, size);
        printf("Sorted Array:  ");
        dblprintarr(arr, size);
        break;

        case 'b':
        dblbubsort(arr, size);
        printf("Sorted Array:  ");
        dblprintarr(arr, size);
        break;

        case 'S':
        dblselsort(arr, size);
        printf("Sorted Array:  ");
        dblprintarr(arr, size);
        break;

        case 's':
        dblselsort(arr, size);
        printf("Sorted Array:  ");
        dblprintarr(arr, size);
        break;

        case 'M':
        dblmersort(arr, size, mid);
        printf("Sorted Array:  ");
        dblprintarr(arr, size);
        break;

        case 'm':
        dblmersort(arr, size, mid);
        printf("Sorted Array:  ");
        dblprintarr(arr, size);
        break;

        case 'I':
        dblinssort(arr, size);
        printf("Sorted array:  ");
        dblprintarr(arr, size);
        break;

        case 'i':
        dblinssort(arr, size);
        printf("Sorted array:  ");
        dblprintarr(arr, size);
        break;

        default:
            while(choice != 'B' && choice != 'b' && choice != 'S' && choice != 's' && choice != 'M' && choice != 'm'){
            printf("\nB or b for bubble sort, S or s for selection sort, M or m for merge sort, I or i for insertion sort:\n");
            scanf(" %c", &choice);
            if(choice == 'B' || choice == 'b'){
                dblbubsort(arr, size);
                printf("Sorted Array:  ");
                dblprintarr(arr, size);
            }
            if(choice == 'S' || choice == 's'){
                dblselsort(arr, size);
                printf("Sorted Array:  ");
                dblprintarr(arr, size);
            }
            if(choice == 'M' || choice == 'm'){
                dblmersort(arr, size, mid);
                printf("Sorted Array:  ");
                dblprintarr(arr, size);
            }
            if(choice == 'I' || choice == 'i'){
                dblinssort(arr, size);
                printf("Sorted array:  ");
                dblprintarr(arr, size);
            }
        }
    }
}

int chswap(unsigned char *x, unsigned char *y){
    unsigned char result = *x;
    *x = *y;
    *y = result;
}

void chprintarr(unsigned char arr[], int size){
    for(int i = 0; i < size; i++){
        printf("  %d.\'%c\'", i+1, arr[i]);
    }
}

void chbubsort(unsigned char arr[], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - 1; j++){
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

void chmersort(unsigned char arr[], int size, int mid){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < mid; j++){
            if(arr[j] > arr[j+1]){
                chswap(&arr[j], &arr[j+1]);
                chprintarr(arr, size);
                printf("\n");
            }
        }
        for(int k = mid; k < size - 1; k++){
            if(arr[k] > arr[k+1]){
                chswap(&arr[k], &arr[k+1]);
                chprintarr(arr, size);
                printf("\n");
            }
        }
    }
}

void chinssort(unsigned char arr[], int size){
    for(int i = 0; i <= size; i++){
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
    printf("B or b for bubble sort, S or s for selection sort, M or m for merge sort, I or i for insertion sort:\n");
    printf("Choice:");
    scanf(" %c", &choice);

    switch(choice){

        case 'B':
        chbubsort(arr, size);
        printf("Sorted Array:  ");
        chprintarr(arr, size);
        break;

        case 'b':
        chbubsort(arr, size);
        printf("Sorted Array:  ");
        chprintarr(arr, size);
        break;

        case 'S':
        chselsort(arr, size);
        printf("Sorted Array:  ");
        chprintarr(arr, size);
        break;

        case 's':
        chselsort(arr, size);
        printf("Sorted Array:  ");
        chprintarr(arr, size);
        break;

        case 'M':
        chmersort(arr, size, mid);
        printf("Sorted Array:  ");
        chprintarr(arr, size);
        break;

        case 'm':
        chmersort(arr, size, mid);
        printf("Sorted Array:  ");
        chprintarr(arr, size);
        break;

        case 'I':
        chinssort(arr, size);
        printf("Sorted array:  ");
        chprintarr(arr, size);
        break;

        case 'i':
        chinssort(arr, size);
        printf("Sorted array:  ");
        chprintarr(arr, size);
        break;

        default:
            while(choice != 'B' && choice && 'b' && choice != 'S' && choice != 's' && choice != 'M' && choice != 'm'){
            printf("\nB or b for bubble sort, S or s for selection sort, M or m for merge sort, I or i for insertion sort.\n");
            printf("Choice:");
            scanf(" %c", &choice);
            if(choice == 'B' || choice == 'b'){
                chbubsort(arr, size);
                printf("Sorted Array:  ");
                chprintarr(arr, size);
            }
            if(choice == 'S' || choice == 's'){
                chselsort(arr, size);
                printf("Sorted Array:  ");
                chprintarr(arr, size);
            }
            if(choice == 'M' || choice == 'm'){
                chmersort(arr, size, mid);
                printf("Sorted Array:  ");
                chprintarr(arr, size);
            }
            if(choice == 'I' || choice == 'i'){
                chinssort(arr, size);
                printf("Sorted array:  ");
                chprintarr(arr, size);
            }
        }
    }
}

void print_char_in_dec(unsigned char arr[], int size){
    for(int i = 0; i < size; i++){
        printf("  %d.%d", i+1, arr[i]);
    }
}

void print_char_in_oct(unsigned char arr[], int size){
    for(int i = 0; i < size; i++){
        printf("  %d.%o", i+1, arr[i]);
    }
}

void print_char_in_hex(unsigned char arr[], int size){
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
    printf("\nDecimal array: ");
    print_char_in_dec(arr, size);
    printf("\nOctal array: ");
    print_char_in_oct(arr, size);
    printf("\nHexadecimal array: ");
    print_char_in_hex(arr, size);
}
/*Do what you want with this code.
It will get updated in the future*/