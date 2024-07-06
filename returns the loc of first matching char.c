#include <stdio.h>

int any(char s[], char t[]);//Returns the index of the first char in string s that matches any char from string t

int main(){
    char name[] = "";
    char vowels[] = "";

    printf("%d", any(name, vowels));
}

int any(char s[], char t[]){
    int i, k, found;

    for(i = found = 0; s[i] != '\0'; i++){
        for(k = 0; t[k] != '\0'; k++){
            if(s[i] == t[k])
                found++;
        }
        if(found)
            return i;
    }
    return -1;
}