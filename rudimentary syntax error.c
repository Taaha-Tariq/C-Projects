#include <stdio.h>

#define MAX_LEN 10
char stack[MAX_LEN];// The string on which the stack is implemented
int count = -1; //The stack index

void push(char s);
int pop(void);

int main(){
    int c ,i, d;
    i = 0;
    
    /*    Working 
    Reads from the input until it encounters the EOF
    and it can check if the braces, brackets and parenthsis were properly closed 
    for example: if there is a right parenthesis after a right braces then the parenthesis must close first. { () }
    It cant be like { ( } ) 
    To check that the if there are properly closed a stack is used
    plus if the any of the three is not closed (there is no right closing) even then it will give an error.*/
    while((c = getchar()) != EOF){
        if(c == '(' || c == '[' || c == '{')
            push(c);
        if(c == '}' || c == ']' || c == ')'){
            d = pop();
            if(c == d + 1 || c == d + 2)
                ;
            else{
                if(d == '(')
                    printf("\nEXPECTED %c BEFORE ", d + 1);
                else
                    printf("\nEXPECTED %c BEFORE ", d + 2);
            }
        }
        putchar(c);
    }
    
}

/*    Working 
checks if there is still space in the stack if there is then pushes the passed character onto the stack else prints out an error message.*/
void push(char s){
    if(count + 1 < MAX_LEN)
       stack[++count] = s;
    else
        printf("Error! OVERFLOW");
}

/*     Working
Checks to see if there is something in the stack if there is then return its integer value. Else prints an error message and returns -1*/
int pop(void){
    int temp;

    if(count > -1){
        temp = stack[count];
        stack[count--] = '\0';
        return temp;
        }
    else
        printf("Error! UNDERFLOW");

    return -1;  
}