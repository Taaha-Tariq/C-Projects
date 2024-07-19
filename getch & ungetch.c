#include <stdio.h>
#include <string.h>

#define BUFSIZE 100 //The size of the buffer 
#define MAXLEN 1000 //The size of the string for storing inputs

void ungetch(int);//For pushing the extra character that was read onto the buffer 
void ungets(char s[]); //For pushing all the characters stored in an array onto the buffer 
int getch(void); //For reading the characters from the buffer and if there isnt any, then from the input

char buf[BUFSIZE];//The string that stores the extra character that are read on each cycle
int bufp = 0; //The index of the buffer

int main(){
    int i;
    char s[MAXLEN];
    for(i = 0; (s[i] = getch()) != '\n'; i++)
        ;
    s[++i] = '\0';
    printf("%s", buf);
    return 0;
}

/*     Working 
Pushing the character passed as an argument onto the buffer and increments the index by one as long as the index is less than BUFSIZE*/
void ungetch(int a){
    if(bufp >= BUFSIZE){
        printf("Error");
    }
    else{
        buf[bufp++] = a;
    }
}

/*    Working 
Pushes the entire array passed to it onto the buffer*/
void ungets(char s[]){
    int i;

    for(i = 0; i < strlen(s); i--)
        ungetch(s[i]);
}

/*      Working 
Checks the index of the buffer if it is greater than 0 meaning there is a character stored in the buffer than returns that character and after reading all the characters from the buffer calls getchar() to get characters from the input*/
int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}