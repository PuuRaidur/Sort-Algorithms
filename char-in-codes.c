#include "sorts.h"

void chprintarr(unsigned char *arr, int size){
    for(int i = 0; i < size; i++){
        printf("  %d.\'%c\'", i+1, arr[i]);
    }
}

void print_char_in_dec_oct_hex_bin(unsigned char arr[], int size){
    int i, j;
    printf("\nNormal array: ");
    for(i = 0; i < size; i++){
        printf(" %d.%c", i, arr[i]);
    }
    printf("\nDecimal array: ");
    for(i = 0; i < size; i++){
        printf(" %d.%d", i, arr[i]);
    }
    printf("\nOctal array: ");
    for(i = 0; i < size; i++){
        printf(" %d.%o", i, arr[i]);
    }
    printf("\nHexadecimal array: ");
    for(i = 0; i < size; i++){
        printf(" %d.%x", i, arr[i]);
    }
    printf("\nBinary array: ");
    for (i = 0; i < size; i++){
        printf(" %d.", i);
        for(j = 0; j < 8;j++){
            printf("%d", !!((arr[i] << j) & 0x80));
        }
    }
}

void char_in_dec_oct_hex_bin(){
    unsigned char arr[10];
    int size = sizeof(arr)/sizeof(arr[0]);
    char ch;
    while(TRUE){
    printf("\nChoose up to 10 characters or symbols and see their decimal, octal and hexadecimal values\n");
    printf("Numbers are not accepted\n");
    printf("Choices:\n");
    for(int i = 0; i < size; i++){
        printf("\n%d. Character:", i+1);
        scanf(" %c", &arr[i]);
    }
    printf("\nCharacter array: ");
    chprintarr(arr, size);
    printf("\nNow choose what you want to do:\n");
    printf("P or p to proceed to see the array in decimal, octal and hexadecimal code.\n");
    printf("E or e to exit the program.\n");
    printf("Any other key to do it again.\n");
    printf("Decision:");
    scanf(" %c", &ch);
    switch(ch){

        case 'P':
        case 'p':print_char_in_dec_oct_hex_bin(arr, size);
        break;

        case 'E':
        case 'e':exit(0);
        break;

        default:printf("\nWe're going to do it again.");
        char_in_dec_oct_hex_bin();
        }
    }
}

void main(){
    char_in_dec_oct_hex_bin();
}