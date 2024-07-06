#include <stdio.h>

#define MAX_LEN 6
int binarysearch(int x, int s[]);//Takes an array and an integer to look for in the array

int main(){
    int arr[MAX_LEN] = {0, 1, 2, 3, 4, 5};
    printf("%d", binarysearch(5, arr));
}

/*   Working
Works only on arrays that are sorted in ascending order*/
/*Uses three int and loops till low is less than or equal to high.*/
/*The high value initially points to the last index of the array and the low to the zero-th index of the array and the mid to the middle index*/
/*then it compares the value at the mid index with the passed integer and based on if it is greater than or less than the value at the mid index it changes the high or the low value and after each iteration closes the gap between subsequent high and low values until eventually the number is found and it returns its index. Else if it isnt found the function returns -1*/
int binarysearch(int x, int s[]){
    int low, mid, high;

    high = MAX_LEN - 1;
    low = 0;
    while(low <= high){
        mid = (high + low) / 2;
        if(s[mid] > x){
            high = mid - 1;
        }
        else if(s[mid] < x){
            low = mid + 1;
        }
        else {
            return mid;
        }
    }
    return -1;
}