#include <stdio.h>
#include <string.h>

#define MAX_LEN 100
int getline(char lines[], int n);//A function for getting lines from the input and storing it in a string
int strindex(char lines[], char pattern[]);//A function for determining if the pattern is present in the line. Returns 1 if it is present else -1.
int strindex2(char lines[], char pattern[]);//Same as the above function. The only difference is it returns the index of the first occurence of the pattern in the line

int main(){
    char lines[MAX_LEN];//An array to store lines in
    char pattern[] = "boy";//The pattern which is being looked for in the line
    
    /*    Working
    Loops till there are no more lines and at each iteration checks if the pattern is present in that line. If so, prints the line. Else, iterates to the next line*/
    while(getline(lines, MAX_LEN) > 0) {
        if(strindex2(lines, pattern) != -1){
            printf("%s", lines);
        }
    }

    return 0;
}

/*     Working
takes two strings and loops till the end of the first and checks if the second string is present in the first string. If yes, then returns 1. Else, returns -1.*/
/*At each iteration checks if that letter matches with the first letter of the second string and when it does goes into another loop till the letters in the two strings match and based on the value of j determines what to return.*/
int strindex(char lines[], char pattern[]){
    int i, j;
    
    for(i = j = 0; lines[i] != '\0';){
        if(lines[i++] == pattern[j]){
            for(j = 1; pattern[j] == lines[i]; i++, j++){
                if(j == strlen(pattern) - 1)
                    return 1;
            }
            j = 0;
        }
    }

    return -1;
}

/*     Working
Takes a string and an int which is the size of the string and gets lines from the input and stores them in the string*/
int getline(char lines[], int n) {
    int c, i;
    i = 0;

    while((c = getchar()) != EOF && c != '\n'){
        if(i < n - 1){
            lines[i++] = c;
        }
        else {
            printf("Exceeded the index of the string");
            break;
        }
    }
    if(c == '\n')
        lines[i++] = '\n';

    lines[i] = '\0';
    return i;
}

/*     Working
takes two strings and if the second string matches the first, returns the index of the first occurence of the second string in the first string*/
int strindex2 (char lines[], char pattern[]) {
    int i, j, k;

    for(i = 0; lines[i] != '\0'; i++) {
        for (j = i, k = 0; pattern[k] != '\0' && pattern[k] == lines[j]; j++, k++)
            ;
        if (k > 0 && pattern[k] == '\0')
            return i;
    }

    return -1;
}