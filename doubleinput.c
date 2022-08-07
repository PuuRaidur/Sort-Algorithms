#include <stdio.h>
#include <stdlib.h>

#include "sorts.h"

void dblswap(double *x, double *y){
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

void main(){
    dblinput();
}