#include <stdio.h>
#include <ctype.h>

#define MAXLEN_LINE 150 //The size of the string that stores the input lines
#define MAXLEN_NUM 15 //The maximum size of the number that can be picked from the stored line
#define NUMBER -2 //Is returned when a number is stored from the line string into the NUM string

static char line[MAXLEN_LINE]; //The string for storing the input lines
char NUM[MAXLEN_NUM]; //The string for storing numbers from the line string and pushing them onto the stack
int i, j; //i is the line index when getchars_from_line loops through it, j is the index of the NUM string

/*    Working
Uses the global j index to clear out the NUM string. then using the global index i loops through the stored line.
Skips any preceding white spaces in the stored line.
And when it encounters the first character that is not a blank, checks if that character is dot '.' or a digit if it is goes into a loop to store the number into the NUM string. And when it encounters the end of the number in the stored line, returns NUMBER to let the caller know that number was read from the stored line.
But if the first character that it encounters is not a digit nor a '.' returns its value to the caller.*/
int getchars_from_line (void) {
    int temp;
    for (int clear = 0; clear < j; clear++) 
        NUM[clear] = '\0';

    for (j = 0; isspace(line[i]); i++)
        ;
    
    if (!isdigit(line[i]) && line[i] != '.') {
        if(line[i] == '-') {
            i++;
            if (isdigit(line[i])) 
                NUM[j++] = '-';
            else 
                return '-';
        }
        else {
            if (line[i] == '\n' || line[i] == '\0') {
                i = 0;
                return '\n';
            }
            return line[i++];
        }
    }
    for ( ; isdigit(line[i]); i++)
        NUM[j++] = line[i];
    
    if (line[i] == '.') {
        for(i += 1, NUM[j++] = '.'; isdigit(line[i]); i++)
            NUM[j++] = line[i];
        return NUMBER;
    }
    else 
        return NUMBER;
}

//A function for printing the stored line
void print_line (void) {
    printf("%s\n", line);
}

//A function for printing the stored number
void print_NUM (void) {
    printf("%s\n", NUM);
}

/*     Working
Reads the input and stores them into a string till it encounters an end of file character or a newline character or the input exceeds the size of the string.
Returns zero if the end of file was read to let the caller know to exit the loop. Otherwise, returns 1.*/
int getline (void) {
    int i, c;
    i = 0;

    while (i < (MAXLEN_LINE - 2) && (c = getchar()) != EOF && c != '\n') 
        line[i++] = c;
    
    if(c == MAXLEN_LINE - 2) {
        printf("Exceeded the string length\n");
        line[i++] = '\n';
        line[i] = '\0';
        return 1;
    }
    else if (c == '\n') {
        line[i++] = '\n';
        line[i] = '\0';
        return 1;
    }
    else 
        return 0;
}