#include <stdio.h>

#define MAX_LEN 50 //Size of both the strings
int getlines(char s[], int); // A function for storing lines from the input into a string
int stlen(char s[]); //A function for returning the length of a string.
void copy(char s[], char t[]);//the first is the array to be copied and the second is the array into which it will copy
int i = 0;

int main(){
    char ran[MAX_LEN];
    char cpy[MAX_LEN];
    int c;
    
    /*    Working
    loops till it encounters an EOF.
    And stores lines into a string (ran) using the getline function and when it encounters the newline character, Checks if the line that was just read from the input is longer than the previous longest line stored in cpy. If it is then the line is copied into the cpy string and a new line is read from the input.*/
    while((c = getchar()) != EOF){
        getlines(ran, c);
        if(c == '\n'){
            copy(ran, cpy);
            ran[0] = '\0';
            i = 0;
        }
    }
    printf("%s", cpy);
}

/*    Working
takes two strings s and t and checks if the size of s is bigger than t. If it is copies it into t.*/
void copy(char s[], char t[]){
    int i = 0;
    
    if(stlen(s) > stlen(t)){
        for(; i < stlen(s); i++)
            t[i] = s[i];
        t[i] = '\0';
    }
    t[i] = '\0';
}

/*    Working 
loops through a string till it encounters the '\0' character and returns its size.*/
int stlen(char s[]){
    int i;

    for(i = 0; s[i] != '\0'; i++)
        ;
    return i;
}

/*    Working 
takes in a string and an int and if there is still space in the string and the character is not a newline character then stores the character in the string using a global index for the string.*/
int getlines(char s[], int c){
    
    if(c != '\n' && i < MAX_LEN - 1)
        s[i++] = c;
    else {
        s[i] = '\0';
        return i;
        }
    return 0;
}