#include <stdio.h>

void squeeze(char s[], char t[]);// Remove the characters from string s that matches any of the characters from the string t

int main(){
    char name[] = "Hello i like gaming";
    char vowels[] = "aeiou";

    squeeze(name , vowels);
    printf("%s", name);
}

/*    Working 
Loops through the first string and checks each character of the first string against all the characters of the second string.
If a character matches with any of the characters from the second string, that character is ignored.
And if it doesnt match with any of the characters from string t then it is stored in the string s.*/
void squeeze(char s[], char t[]){
    int i, j, count, k;

    for(i = count = k = 0; s[i] != '\0'; i++){
        for(j = 0; t[j] != '\0'; j++){
            if(s[i] == t[j])
                count++;
        }
        if(count == 0)
            s[k++] = s[i];
        else
            count = 0;   
    }
    s[k] = '\0';
}