#include <stdio.h>

int bitcount(unsigned int x);//Takes an unsigned int and counts the number of ones in it

int main(){
    int x = 63;
    printf("%d", bitcount(x));
}

/*     Working
It is based on the fact that x &= x-1 removes the last most one bit from the number */
/*It loops through till the number becomes equal to zero and at each iteration removes the right most one from the number and increments the counter by 1*/
int bitcount(unsigned int x){
    int b;
    b = 0;

    while(x != 0){
        x &= x-1;
        b++;
    }
    return b;
}