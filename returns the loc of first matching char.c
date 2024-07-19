#include <stdio.h>

int any(char s[], char t[]);//Returns the index of the first char in string s that matches any char from string t

int main(){
    char name[] = "";
    char vowels[] = "";

    printf("%d", any(name, vowels));
}

/*     Working
Loops through the first string and for each character of the first string goes into a second loop that loops through the second string checking each character of the second string against that character of the first string and the first character of the first string that matches any character of the second string, its index is returned. If not one of the character matches, then -1 is returned.*/
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