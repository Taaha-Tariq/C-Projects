#include <stdio.h>
#include <ctype.h>

#define COM_TEST(x) (x > -1) ? buffer[x--] : getchar()//Comparison test for getch to see if there is any character in the buffer. If there is, that character is fetched. Else uses getchar to get another character from the input stream.
#define BUF_SIZE 10  //The size of the buffer which stores the extra characters that have been read from the input.
#define ARR_SIZE 10  //The array in which the floating point numbersfrom the array will be stored.

char buffer[BUF_SIZE]; //Buffer
int bufp = -1; //Buffer index
void ungetch (int c); //Function for pushing the extra characters that are read onto the buffer.
int getch (void);//Function for returning the characters on the buffer if there are any. If not then uses getchar to get characters from the input stream.
int getfloat (float *);//Gets characters from the input and stores them in a floating point numbers array.

int main () {
    float arr[ARR_SIZE];

    for (int n = 0; n < ARR_SIZE && getfloat(&arr[n]) != EOF; n++)
        ;
    for (int i = 0; i < ARR_SIZE; i++) 
        printf("%0.4f   ", arr[i]);
}

/*     Working
Uses getch to get characters from the buffer if there are any or from the input. Uses isspace to skip any preceding white space and if the first non blank character it encounters is a char that is not a sign, dot, or a digit it returns zero and pushes that char onto the buffer. And If the first non blank character it encounters is either '-' or '+', it stores the value in the sign variable, and if the '-' or '+' is not followed by a number or a dot then the sign is pushed onto the buffer and is returned.
If it encounters a number than it stores the floating point number from the input onto the passed address. */
int getfloat (float *pm) {
    int c, sign, pow;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);
        return 0;
    } 

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') 
        c = getch();
    if (!isdigit(c) && c != '.') {
        if (sign > 0 && c != EOF) 
            ungetch('+');
        else if (sign < 0 && c != EOF)
            ungetch('-');
        return c;
    }

    for (*pm = 0.0; isdigit(c); c = getch())
        *pm = *pm * 10.0 + (c - '0');
    
    if (c == '.') {
        c = getch();
        for (pow = 1; isdigit(c); c = getch()) {
            *pm = *pm * 10.0 + (c - '0');
            pow *= 10;
        }
    *pm /= pow;
    }
    *pm *= sign;

    if (c != EOF) {
        ungetch(c);
    }
    return c;
}

/*     Working
takes an int as an argument and using the global index bufp pushes it onto the buffer. But does make sure that there is enough space in the buffer.*/
void ungetch (int c) {
    if (bufp < BUF_SIZE - 1) 
        buffer[++bufp] = c;
    else 
        printf("Error buffer size exceeded!");
}

/*    Working 
checks if there is any character on the buffer using the global index. If yes, then returns the last character that was pushed onto the buffer. Else gets another character from the input using getchar().*/
int getch (void) {
    return COM_TEST(bufp);
}