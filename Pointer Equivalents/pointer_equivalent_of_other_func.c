#include <stdio.h>
#include <ctype.h>

#define ALLOCSIZE 10 //Buffer size that will be used to dynamically allocate memory
#define S_SIZE 10 //the size of the first array for strcpy function so that it isnt overflowed
#define LINE_SIZE 10 //THe size of the line array in which lines from the input are stored.

static char allocbuf[ALLOCSIZE]; //A string for dynamically allocating memory.
static char* allocpoint = allocbuf; //Points to the first free index in the allocbuff. 
char line[LINE_SIZE]; //For storing lines from the input.

/*                                Functions                                        */
char *alloc (int n);
void strcpy1 (char *s, char *t);
int allocfree (char *s);
int strcmp (char *s, char *t);
void strcat (char *s, char *t);
int strend (char *s, char *t);
int getline (char *s, int size);
int *binarysearch (int *a, int *b, int num);
void reverse (char *s);
void itoa (char *s, int num);
void strncpy (char *s, char *t, int n);
void strncat (char *s, char *t, int n);
int strncmp (char *s, char *t, int n);

/*          Working
Takes in an integer n and checks if there is enough space in the allocbuf for n characters and if there is returns the pointer to the first free index and updates the global var allocpoint to point to the next free location after n places. And in this way allocates memory.*/
char *alloc (int n) {
    if (allocbuf + ALLOCSIZE - allocpoint >= n) {
        allocpoint += n;
        return allocpoint - n;
    }
    return NULL;//A replacement for 0
}

/*       Working
Takes in a pointer and checks that the pointer to any address in the string allocbuf and if it does updates the global pointer to point to that address. In this way, it frees up the buffer after that index.*/
int allocfree (char *s) {
    if (s >= allocbuf && s < allocbuf + ALLOCSIZE)
        allocpoint = s;
}

/*    working
Takes two pointers to strings and copies the second string into the first.
The first string must be big enough to accomodate the second.*/
void strcpy1 (char *s, char *t) {
    while (*s++ = *t++)
        ;
}

/*     Working
Returns negative, zero or positive if s is lexicographically less than, equal to or greater than t.
takes two pointers to two strings and loops till it encounters the first character of t that is not equal to the corresponding character in s. then checks if the pointer to s is pointing to the end of the string. If so returns 0, to show that the two strings are the same. Else subtracts the first unmatching char of s from t.*/
int strcmp (char *s, char *t) {
    for ( ; *s == *t; s++, t++)
        if (*s == '\0') 
            return 0;
    return *s - *t;
}

/*      Working
Copies the string t into s. Loops through s till the pointer to s points to its end and then starts copying t into s as long as there is still space in s(S_SIZE)*/
void strcat (char *s, char *t) {
    char *init = s;

    while (*s++) 
        ;
    for (s -= 1; s - init < S_SIZE - 1; s++, t++)
        if(!(*s = *t))
            break;
    *s = '\0';
}

/*     Working
Takes two pointers to two strings and loops through the first array and checks if the second string occcurs at the end of the first string. If yes, then returns 1. Else returns 0.*/
int strend (char *s, char *t) {
    char *init = t;

    while (*s) {
        if (*s == *t) {
            while (*++s == *++t && *t != '\0')
                ;
            if (*t == '\0' && *s == '\0')
                return 1;
            else 
                t = init;
        }
        s++;
    }

    return 0;
}

/*     Working 
Takes a pointer to a string and its size and takes characters from the input and stores it into the string untill it encounters an end of file char, or a newline char or line size exceeds the size of the string.*/
int getline (char *s, int size) {
    char *end = s + size;
    int c;

    while ((c = getchar()) != EOF && end - s > 2 && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = '\n';
    *s++ = '\0';

    if (end - s == size - 2)
        return 0;
    return 1;    
}

/*     Working
Takes two pointers, one that points to the start of an array and the other that points to a location right after the last index of the array and takes an int. It searches for the integer in the sorted array(ascending order) uses the passed pointers. Using the two pointers it figures out the address of the centermost index of the array(mid). And checks if the num is less than or greater than the value at that index and based on this evaluation changes the rightmost or leftmost pointer. In this way in reduces the searching interval till it finds the location of the passed int in which case returns the pointer to that location or if the int is not in the array then returns 0.*/
int *binarysearch (int *a, int *b, int num) {
    int *mid = (b - a) / 2 + a;

    while (b-a > 1) {
        if (*mid > num) {
            b = mid;
            mid = (b - a) / 2 + a;
        }
        else if (*mid  < num) {
            a = mid;
            mid = (b - a) / 2 + a;
        }
        else 
            return mid;
    }
    if (*a == num)
       return a;
    return NULL;
}

/*    Working
Takes a pointer to a string and stores it in another pointer and loops till the passed pointer points to the end of the string and then using both these locations reverses the string.*/
void reverse (char *s) {
    char *first_ind = s;
    char temp;
    while (*++s)
        ;
    s--;
    
    while (s > first_ind) {
        temp = *s;
        *s-- = *first_ind;
        *first_ind++ = temp;
    }
}

/*     Working
takes in a number and a pointer to a string and stores the passed number in the string. But since the order of operations is such that the number in the string is in opposite order so calls reverse at the end to reverse the string.*/
void itoa (char *s, int num) {
    int sign = 0;
    char *first_ind = s;

    if (num < 0) {
        num *= -1;
        sign = 1;
    }

    while (num) {
        *s++ = (num % 10) + '0';
        num /= 10;
    }
    if (sign) 
        *s++ = '-';
    *s = '\0';
    
    reverse(first_ind);
}

/*   Working
same as strcpy but only copies t into s upto n characters.*/
void strncpy (char *s, char *t, int n) {
    while (n-- && *t)
        *s++ = *t++;
    *s = '\0';
}

/*    Working
same as strcat but only concatnates t with s upto n characters. And those n characters include the characters already present in s.*/
void strncat (char *s, char *t, int n) {

    while (n-- && *s++)
        ;
    if (n >= 0) {
        s--;
        n++;
        while (n--  && (*s++ = *t++))
            ;
        *s = '\0';
    }
}

/*    Working
Same as strncmp but only compares the first n characters of both the strings.*/
int strncmp (char *s, char *t, int n) {
    for ( ;n && *s == *t; s++, t++, n--)
        if (*s == '\0')
            return 0;
    if (n == 0)
        return 0;
    return  *s - *t;
}