#include <stdio.h>

#define SIZE 16//Determines the size of the array. As of now the number is represented as a sixteen bit number
int result[SIZE];//An array to store the number in bits
void decimal_to_binary(int* decimal, int result[]);//takes in an array and a pointer and stores the number in bits in the array

int main(){
    int decimal;
    printf("Enter the decimal number to be converted:\n");
    scanf("%d", &decimal);
    decimal_to_binary(&decimal, result);
    printf("The number in binary is: ");
    for(int i = sizeof(result) / sizeof(int) - 1; i >= 0; i--){
        printf("%d", result[i]);
    }
}

/*     Working
Takes in a pointer to the int to be converted and stores the bits in an array in the reverse order*/
/*Loops till the decimal number is greater than zero and at each iteration divides the decimal number by two and takes its mod by 2 and stores the remainder in the array*/
void decimal_to_binary(int* decimal, int result[]){
    int k = 0;

    while(*decimal > 0){
        if(*decimal % 2 == 0){
        result[k++] = 0;
        *decimal = *decimal / 2;
            if(k > SIZE - 1){
                break;
            }
            else{
            }
        }
        else{
            result[k++] = 1;
            *decimal = *decimal / 2;
            if(k > SIZE - 1){
                break;
            }
            else {

            }
        }
    }
}