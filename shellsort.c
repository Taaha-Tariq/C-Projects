#include <stdio.h>

void shellsort(int z[], int n);
/*Takes an array and the memory capacity of the array*/

int main(){
    int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    shellsort(arr, sizeof(arr)/sizeof(arr[0]));
    for(unsigned int i = 0; i < sizeof(arr)/ sizeof(int); i++){
        printf("%d ", arr[i]);
    }
}

/*    Working
The outer loop determines the gap. Initially, the gap is n / 2. The gap reduces by 2 after each iteration till it becomes equal to 0*/
/*The second loop loops from the gap to the last index*/
/*The third loop compares the element separated by gap and since the gap reduces to one eventually the array is sorted*/

void shellsort(int z[], int n){
    int gap, i, j, temp;

    for(gap = n / 2; gap > 0; gap /= 2){
        for(i = gap; i < n; i++){
            for(j = i - gap; j >= 0 && z[j] > z[j+gap]; j -= gap){
                temp = z[j+gap];
                z[j+gap] = z[j];
                z[j] = temp;
            }
        }
    }
}