#include <stdio.h>
                           
                                      //Reverse polish calculator
/*It is implemented on a stack. All the numbers and the operators are pushed into the stack. It reads the operator at the top of the stack and performs that operation on the next two numbers and the result is then pushed back into the stack. Then it reads the next operator and performs that operation on the top most two numbers. This process keeps on going till there is only one number left which is the result of the whole calculation. Just changing the value of the symbolic constant at the top allows you to increase the number of operands on which to perform the calculation.*/

#define SOS 10
double array[SOS];   //array on which the stack is implemented
int k;               //to count the index of the stack
void push(double);   //function to insert a number into the stack
double pop(void);    //function to remove a number from the stack
double print(void);  //function to print the last inserted number without removing it
void swap(void);     //function to swap the last two numbers in the stack
void clear(void);    //function to clear out the stack
void calc(void);     //reverse polish calculator
int temp;

int main(){
    push(12);
    push('/');
    push(20);
    push('+');
    push(40);
    push('+');
    push(30);
    push(10);
    push('*');
    calc();
    printf("%f\n", pop());
}

void calc(void){
    for(int i = SOS - 1; i >= 0; i--){
        if(array[i] == '-' || array[i] == '+' || array[i] == '*' || array[i] == '/'){
            int conversion = array[i];
            if(i == k - 1){
            switch(conversion){
                case '*':
                array[--k] = 0;
                push(pop() * pop());
                break;
                case '+':
                array[--k] = 0;
                push(pop() + pop());
                break;
                case '-':
                array[--k] = 0;
                temp = pop();
                push(pop() - temp);
                break;
                case '/':
                array[--k] = 0;
                temp = pop();
                if(temp == 0){
                    printf("The dividend is zero");
                }
                else{
                    push(pop() / temp);
                }
                break;
            }
            }
            if(i == k - 2){
                temp = pop();
                switch(conversion){
                    case '*':
                    array[--k] = 0;
                    push(pop() * temp);
                    break;
                    case '+':
                    array[--k] = 0;
                    push(pop() + temp);
                    break;
                    case '-':
                    array[--k] = 0;
                    push(pop() - temp);
                    break;
                    case '/':
                    array[--k] = 0;
                    if(temp == 0){
                        printf("The dividend is zero");
                    }
                    else{
                        push(pop() / temp);
                    }
                    break;
                }
            }
        }
    }
}

void push(double a){
    if(k >= SOS){
        printf("ERROR OVERFLOW");
    }
    else{
        array[k++] = a;
    }
}

double pop(void){
    if(k <= 0){
        printf("ERROR UNDERFLOW");
        return 0;
    }
    else{
        if(array[--k] != 0){
        double temp = array[k];
        array[k] = 0;
        return temp;
        }
        else{
            k -= 2;
            double temp = array[k];
            array[k] = 0;
            return temp;
        }
    }
}

double print(void){
    if(k <= 0){
        printf("ERROR UNDERFLOW");
        return 0;
    }
    else{
        return array[k - 1];
    }
}

void swap(void){
    if(k <= 1){
        printf("NOT ENOUGH ARGUMENTS");
    }
    else{
        double temp = array[k - 1];
        array[k - 1] = array[k - 2];
        array[k - 2] = temp;
    }
}

void clear(void){
    for(int l = 0; l < k; l++){
        array[l] = 0;
    }
    k = 0;
}
