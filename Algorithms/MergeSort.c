#include <stdio.h>
int swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}
void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf(" %d", *(arr+i));
    }
}
void mergesort(int *arr, int mid, int right){
    int i,j,k;
    int n1 = mid;
    int n2 = right - mid;
    int l[n1],r[n2];
    for(i = 0; i < n1; i++){
        l[i] = arr[i];
    }
    for(i = 0; i < n1; i++){
        for(j = i+1; j < n1; j++){
            if(l[i] > l[j]){
                swap(&l[i],&l[j]);
            }
        }
    }
    for(j = 0; j < n2; j++){
        r[j] = arr[mid+j];
    }
    for(i = 0; i < n2; i++){
        for(j = i+1; j < n2; j++){
            if(r[i] > r[j]){
                swap(&r[i],&r[j]);
            }
        }
    }
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
    }
    while(i < n1){
        arr[k] = l[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = r[j];
        j++;
        k++;
    }
    /*printf("\n");
    printArray(l, n1);
    printf("\n");
    printArray(r, n2);*/
}
void main(){
    int arr[] = {4,5,2,8,3,1,7,6};
    int right = sizeof(arr)/sizeof(arr[0]);
    int mid = right / 2;
    printf("Unsorted array: ");
    printArray(arr,right);
    mergesort(arr, mid, right);
    printf("\nSorted array: ");
    printArray(arr, right);
}