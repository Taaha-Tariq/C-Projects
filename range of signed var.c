#include <stdio.h>
#include <math.h>

int main(){
    int i, g; // Two contiguous variables
    char *ptr = &i; //pointer to the first variable
    char *ptr2 = &g; //pointer to the second variable
    int bits = (ptr - ptr2) * 8; //Subtracting the two pointers give us the size of the var in bytes and by multiplying it by 8, we get the size in bits.

    double max = pow(2, bits);

    //calculates the range of the var using the fact that for n-bits 2^n combinations are possible and values from zero to -(2^n / 2) to (2^n / 2) - 1 if it is signed.
    double max_signed = (max / 2) - 1;
    printf("The Range is form -%.0f to %.0f", max_signed + 1, max_signed);
}