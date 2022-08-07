#include <stdio.h>
#include <stdlib.h>

#include "sorts.h"

void chswap(unsigned char *x, unsigned char *y){
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

void main(){
    charinput();
}