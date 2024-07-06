#include <stdio.h>

void arraysort(int s[]);//A basic sort
int binarysearch(int x, int s[]);//Takes an array and an integer to look for in the array
#define MAX_LEN 10

int main(){
    int arr[MAX_LEN] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    arraysort(arr);
    printf("%d", binarysearch(9, arr));
}

/*     Working
Checks each index of the array against other indices to sort it in ascending order*/
void arraysort(int s[]){
    int i, j, temp;

    for(i = 0; i < MAX_LEN - 1; i++){
        for(j = i + 1; j < MAX_LEN; j++){
            if(s[i] > s[j]){
                temp = s[j];
                s[j] = s[i];
                s[i] = temp;
            }
        }
    }
}

/*   Working
Works only on arrays that are sorted in ascending order*/
/*Uses three int and loops till low is less than or equal to high.*/
/*The high value initially points to the last index of the array and the low to the zero-th index of the array and the mid to the middle index*/
/*then it compares the value at the mid index with the passed integer and based on if it is greater than or less than the value at the mid index it changes the high or the low value and after each iteration closes the gap between subsequent high and low values until eventually the number is found and it returns its index. Else if it isnt found the function returns -1*/
/*Little different because it tests only one condition inside the loop*/
int binarysearch(int x, int s[]){
    int mid, low, high;

    high = MAX_LEN - 1;
    low = 0;
    while(low <= high && s[mid] != x){
        mid = (low + high) / 2;
        if(s[mid] > x){
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    if(s[mid] == x){
        return mid;
    }
    else {
        return -1;
    }
}