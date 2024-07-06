#include <stdio.h>

#define MAX_LEN 5 //The max size of the array. And the number of factorials to be computed
int factorials(int); //Function for calculating the value of factorials
int summation(int arr[]);  //function for summing up the indices of the array

int main(){
    int array[MAX_LEN];
    
    for(int i = 0; i < MAX_LEN; i++){
        array[i] = factorials(i + 1);
    };
    printf("%d", summation(array));
}

/*    Working
Takes in a number and loops till the number is equal to zero, decrementing it by one at every iteration and stores the value of its subsequent multiplication in a val variable which is returned*/
int factorials(int num){
    int val = 1;

    for(; num > 0; num--){
        val = val * num;
    }
    return val;
}

/*     Working 
loops through an array and adds up all the values at its indices*/
int summation(int arr[]){
    int sum = 0;
    sum = 0;

    for(int i = 0; i < MAX_LEN; i++){
        sum = sum + arr[i];
    }
    return sum;
}