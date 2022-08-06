#include <stdio.h> 
void swap(int* a, int* b){ 
    int temp = *a; 
    *a = *b; 
    *b = temp;
}
void printArray(int arr[], int size){ 
    int i; 
    for (i = 0; i < size; i++) 
    printf(" %d", *(arr+i)); 
} 
/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int partition (int arr[], int low, int high){ 
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
    for (int j = low; j < high; j++){ 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) { 
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]);
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int arr[], int low, int high){ 
    if (low < high) { 
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
}  
void main(){
    int arr[] = {6, 1, 7, 10, 4, 2, 5, 3, 9, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted array:\n");
    printArray(arr, size);
    quickSort(arr, 0, size - 1);
    printf("\nSorted array:\n");
    printArray(arr, size);
}