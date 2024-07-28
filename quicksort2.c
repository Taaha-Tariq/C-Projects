#include <stdio.h>

void swap (int v[], int left, int right);//Function for swapping the values in the passed array at the passed indices
void quicksort (int v[], int left, int right); //A function for sorting the array but the pivot will always be the right index.

int main () {
    int arr[] = {4, 6, 9, 3, 1, 2, 7, 8};
    quicksort(arr, 0, sizeof(arr)/sizeof(int) - 1);
    for(int i = 0; i < sizeof(arr)/sizeof(int); i++)
        printf("%d ", arr[i]);
}

/*     Working
A recursive sorting algorithm.
it takes two indices and an array and initially the two indices point to the start(left) and the end of the array(right). It considers the last index(right) to be the pivot and using an int j which is initialized to the left index loops through the array till it reaches the pivot and when it is initialized another int i is initialized to point to a value one less than j and whenever j points to a value smaller than the pivot, i is incremented and the value at j is swapped with the value at i and in this way the final resting place of the pivot is found after the complete iteration of the loop. after which the function recusively calls itself twice and passing the same array but the indices are changed the first call is passed the indices 0 and i - 1(the position one less than the pivot's end point) and the second call is passed the indices i + 1 and size of array - 1 and this continues untill the the left index becomes equal to or greater than right index.*/
void quicksort (int v[], int left, int right) {
    int i, j;
    
    if (left >= right) 
        return;
    
    for (j = left, i = j - 1; j <= right; j++) 
        if (v[j] < v[right]) 
            swap (v, ++i, j);
    
    swap (v, ++i, right);
    quicksort (v, left, i - 1);
    quicksort (v, i + 1, right);
}

/*    Working
takes an array and two indices and swaps the values at those two indices*/
void swap (int v[], int left, int right) {
    int temp;

    temp = v[left];
    v[left] = v[right];
    v[right] = temp;
}