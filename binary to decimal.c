#include <stdio.h>
#include <math.h>

int binary_to_decimal(int* binary);//Function to convert binary numbers to decimal using a pointer

int main(){
    int binary;
    printf("Enter the binary number to be converted:\n");
    scanf("%d", &binary);
    printf("The binary number in decimal form is: %d", binary_to_decimal(&binary));
    return 0;
}

/*    Working
It takes a pointer to a binary number stored in an integer*/
/*While the binary number is greater than 0 it runs a loop and at each iteration checks if the numbers mod 10 is zero, if it is then it doesnt alter the result but deivides the number by 10 and increses the index*/
/*But if the mod 10 is not zero meaning that there is one at the last digit it subtracts the number by 1 and then divide it by 10. At the same time it adds the weight of that one to the result using the pow function from math.h library and increases the index*/
int binary_to_decimal(int *binary){
    int result = 0;
    int k = 0;

    while(*binary > 0){
        if(*binary % 10 == 0){
        *binary = *binary / 10;
        k++;
        }
        else{
            *binary = *binary - 1;
            *binary = *binary / 10;
            result = result + pow(2, k);
            k++;
        }
    }
    return result;
}