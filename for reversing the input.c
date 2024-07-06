#include <stdio.h>

#define MAXLEN 20 //The size if the string for reversing the input
void rev_str(char s[], int);//The function to reverse strings
int len(char s[]);//To return the length of the string

int main(){
    int c, indices; 
    char s[MAXLEN];
    indices = 0;
   
    /*     Working
    Reads an input and stores it in a string until it encouters a newline or terminating character and then reverses the string using the predefined reverse string function and prints it to the terminal*/
    while((c = getchar()) != EOF){
        if(c != '\n' && c != '\0'){
            if(indices < MAXLEN)
                s[indices++] = c;
        }
        else{
            if(c == '\n')
                s[indices++] = '\n';
            s[indices] = '\0';
            rev_str(s, len(s));
            printf("%s", s);
            s[0] = '\0';
            indices = 0;
        }
        if(indices == MAXLEN){
            printf("Exceeded the array length");
            break;
            }
    }
}

/*    Working
Takes in a string and its length and loops till the index reaches the midpoint of the string and reverses the string*/
void rev_str(char s[], int max){
    int i;
    char temp;

    for(i = 0; i < max / 2; i++){
        temp = s[i];
        s[i] = s[max - 1 - i];
        s[max - 1 - i] = temp;
    }
    s[max] = '\n';
    s[max + 1] = '\0';
}

/*    Working 
loops through a string till it encounters the ending '0' and returns the size of the string*/
int len(char s[]){
    int i;

    for(i = 0; s[i] != '\n' && s[i] != '\0'; i++)
        ;
    return i;
}