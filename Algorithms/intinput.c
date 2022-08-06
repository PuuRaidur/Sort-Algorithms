#include <stdio.h>
#include <stdlib.h>

#include "sorts.h"

void unsintswap(long long unsigned int *x, long long unsigned int *y){
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