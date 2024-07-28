#include <stdio.h>

void swap (int z[], int, int);//Function for swapping the values in the passed array at the passed indices
void quicksort (int z[], int left, int right);//A function for sorting an array using the middle index as a pivot

int main () {
    int arr[] = {10, 3, 4, 2, 7, 8, 9};
    quicksort(arr, 0, sizeof(arr)/sizeof(int) - 1);
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++)
        printf("%d ", arr[i]);
}

/*      Working
it takes an array and two indices, the right and left ends of the array and determines the middle index(pivot).Then it swaps the value at the middle index with the value at the left index and declares a last(int) to point to the changed index of the pivot and assigns i to point to an index of the array one greater than last and loops till i becomes greater than right. And whenever a value less than the pivot is encountered it is swapped with the values right after pivot using left. And so after the loop, the final position of the pivot is found and pivot is swapped with the value at that index and then the function calls itself twice once with the indices last - 1 and left and once with the indices last + 1 and right.*/
void quicksort (int z[], int left, int right) {
    int i, last;

    if (left >= right) 
        return;
    swap (z, left, (right + left) / 2);
    last = left;

    for (i = left + 1; i <= right; i++)
        if (z[i] < z[left]) 
            swap (z, i, ++left);
    
    swap (z, last, left);
    quicksort (z, left, last - 1);
    quicksort (z, last + 1, right);
}

/*    Working
takes an array and two indices and swaps the values at those two indices*/
void swap (int z[], int left, int right) {
    int temp;

    temp = z[left];
    z[left] = z[right];
    z[right] = temp;
}