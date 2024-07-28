#include <stdio.h>
#include <string.h>

void reverse (char s[], int, int);//A function to reverse a string based on recursion.

int main () {
    char s[] = "hello i ma sad";
    reverse (s, -1, strlen(s));
    printf("%s", s);
}

/*    Working
Takes a string and two indices, the left index should be one less than the starting index of the string (-1) and the right index should be equal to the size of the string because it performs the test and increments or decrements the indices before switching the values at those indices so if 0 and strlen(s) - 1 are passed it will not swap the first and the last value of the string.*/
void reverse (char s[], int left, int right) {
    int temp;

    if (left < right) 
        reverse (s, ++left, --right);

    temp = s[left];
    s[left] = s[right];
    s[right] = temp;
}