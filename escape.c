#include <stdio.h>

void escape(char s[], char t[]);//Replaces the newline and tab sequences with their visual rep as it copies the string from t to s
void inverseescape(char s[], char t[]);//Replaces the visual representation of newline and tab sequences into actual sequences as it copies the string from t to s
#define MAX_LEN 50

int main(){
    char tobecopied[MAX_LEN] = "hello\thoware\nhello";
    char tocopyinto[MAX_LEN];
    escape(tocopyinto, tobecopied);
    printf("%s\n", tocopyinto);
}

/*    Working
Loops through an array and when it encounters a newline or a tab character it uses switch to replace it with a backslash and an n or t depending on the input as it copies the array from t to s*/
void escape(char s[], char t[]){
    int i, j;
    i = j = 0;

    while(t[j] != 0){
        switch(t[j]){
            case '\n':
            s[i++] = '\\';
            s[i++] = 'n';
            j++;
            break;
            case '\t':
            s[i++] = '\\';
            s[i++] = 't';
            j++;
            break;
            default:
            s[i++] = t[j++];
        }
    }
    s[i] = '\0';
}

/*      Working
Loops through an array and when it encounters a backslash followed by a t or an n replaces it with the corresponding escape sequence as it copies it from t to s*/
void inverseescape(char s[], char t[]){
    int i, j;
    i = j = 0;

    while(t[j] != 0){
        switch(t[j]){
            case '\\':
            switch(t[++j]){
            case 'n':
            s[i++] = '\n';
            j++;
            break;
            case 't':
            s[i++] = '\t';
            j++;
            break;
            }
            default: 
            s[i++] = t[j++];
            break;
        }
    }
    s[i] = '\0';
}