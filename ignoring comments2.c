#include <stdio.h>

#define in_comment 1  //The state of being in a comment
#define out_comment 0  //The state of exiting a comment
#define not_a_comment -2  //The state of a false signal of a comment
#define EOFR -3 //The state of encountering an EOF in a comment
int c;

int check_comment(void);//A function to check if the passed input is a comment or not

int main() {
    int to_check, EOFR_in_com; 
    EOFR_in_com = 0;
    
    /*     Working
    when it encounters a / it calls the function check_comment that loops through till the end of the comment and if it wasnt a comment to begin with returns the value of not_a_comment and if the function encounters an EOF it returns the value of EOFR*/
    /*Based on the returned values of the check_comment function the loop prints the input or ignores the comments*/
    while((c = getchar()) != EOF){
        if(c == '/'){
            if((to_check = check_comment()) == not_a_comment && to_check != EOFR){
                putchar('/');
                putchar(c);
                }
            else if(to_check == EOFR)
                EOFR_in_com = 1;
        }
        if(EOFR_in_com == 1)
            break;
        if(to_check == not_a_comment)
        to_check = 0;
        else
            putchar(c);
    }
}

/*     Working
The function takes no argument but uses the global variable c to loop through the input till the end of a comment if it encounters one else returns an integer specifying the different states*/
int check_comment(){
    int state;

    c = getchar();
    if(c == '*'){
        state = in_comment;
        for( ; (c = getchar()) != EOF && state != out_comment; ){
            if(c == '*'){
                c = getchar();
                if(c == '/')
                    state = out_comment;
            }
        }
        if(c == EOF)
            return EOFR;
        }
    else if(c == '/'){
        state = in_comment;
        for( ; (c = getchar()) != EOF && state != out_comment;){
            if(c == '\n')
                state = out_comment;
        }
        if(c == EOF)
            return EOFR;
    }   
    else{
        return not_a_comment;
    }
}