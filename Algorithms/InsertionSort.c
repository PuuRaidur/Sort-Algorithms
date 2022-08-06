#include <stdio.h>
int printArray(int arr[], int size){
    for(int i = 0; i <= size; i++){
        printf(" %d", arr[i]);
    }
}
void insertionSort(int arr[], int size){
    for(int i = 0; i <= size; i++){
        int place = arr[i];
        int j = i - 1;
        while(place < arr[j] && j >= 0){
            arr[j+1] = arr[j];
            j--;
            //new place
            arr[j+1] = place;
        }
        printf("\n",printArray(arr, size));
    }
}
void main(){
    int arr[] = {4, 1, 7, 9, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    size = size - 1;
    //printf("Unsorted array: ");
    //printArray(arr, size);
    insertionSort(arr, size);
    //printf("\nSorted array: ");
    //printArray(arr, size);
    //printf("\n");
}
// copied. not original