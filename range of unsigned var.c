#include <stdio.h>
#include <math.h>

int main(){
    int i, g;   //change the data type
    char* ptr = &i;
    char *ptr2 = &g;
    
    int bits = (ptr - ptr2) * 8;//Subtracting the pointers gives us the size of the var in bytes and by multiplying it by 8 we get the size in bits.

    //Calculates the range using the fact that for n-bits there are 2^n possible combinations and range from 0 to 2^n -1 if it is unsigned.
    double max_unsigned = pow(2, bits) - 1; 
    printf("%.0f", max_unsigned);
}