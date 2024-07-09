#include <stdio.h>

#define MAXLINE 100
int getlines(char line[], int lim);//A funtion for getting lines
void copy(char to[], char from[]);//A function for copying a string into another string
//not considering newline to be a part of the line whereas in book they have

int main(){
    int len, max;
    char line[MAXLINE];
    char max_len[MAXLINE];
    max = 0;
    
    /*    Working
    Loops through till there are lines to be read and if it encounters a line longer than the previous ones it stores it into the string max_len*/
    while((len = getlines(line, MAXLINE)) > 0){
        if(len > max){
            max = len;
            copy(max_len, line);
        }
    }

    if(max > 0){
        printf("%s", max_len);
    }
}

/*     Working
Takes a string and a number specifying the size of the string*/
/*And stores the input into the string till it encounters an EOF or newline character*/
/*Also returns the length of the string*/
int getlines(char line[], int lim){
    int i, c;

    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++){
        line[i] = c;
    }
    line[i] = '\0';

    return i;
}

/*    Working
Takes two strings the copies from the string from to the string to*/
void copy(char to[], char from[]){
    int i;
    i = 0;

    while((to[i] = from[i]) != '\0')
        i++;
    to[i] = '\0';
}