#include <stdio.h>
#include <stdbool.h>

/*A function for checking if the passed year is a leap year or not*/
bool Leap_year(int yy){
    if(yy % 4 == 0 && !(yy % 100 == 0))
    {return 1;}
    else{
        if(yy % 100 == 0 && yy % 400 == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
}
int days_in_month[] = {1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/*    It takes a date, month and year from the user and the number of days that the person wishes to add and returns the date, month and year after that many days*/
int main(){
    int dd, mm, yy, days_to_be_added;
    printf("Enter the date:\n");
    scanf("%d", &dd);
    printf("Enter the month:\n");
    scanf("%c");
    scanf("%d", &mm);
    printf("Enter the year:\n");
    scanf("%c");
    scanf("%d", &yy);
    printf("Enter the number of days to be added:\n");
    scanf("%c");
    scanf("%d", &days_to_be_added);

    int boolean = Leap_year(yy);
    
    //checks if the passed year is a leap year if so increases the number of days in february
    if(boolean == 1){
            days_in_month[2] = 29;
        }
    else{

    }
   
    int days_that_can_be_accomodated = days_in_month[mm] - dd;//Calculates the number of days that can be added to the passed month
    int additional_days = days_to_be_added - days_that_can_be_accomodated;//Calculates the number of days that cant be added to the passed month

    if(additional_days <= 0){
        dd += days_to_be_added;
    }
    else{
        if(mm < 12){   
            boolean = Leap_year(yy);
            if(boolean == 1){
               days_in_month[2] = 29;
        }
            else{
               days_in_month[2] = 28;
        }
            mm++;
            while(additional_days > days_in_month[mm]){
                if(mm < 12){
                    boolean = Leap_year(yy);
                    if(boolean == 1){
                        days_in_month[2] = 29;
                    }
                    else{days_in_month[2] = 28;}
                        additional_days = additional_days - days_in_month[mm];
                        mm++;
                        dd = additional_days;
               }
               else{
                    boolean = Leap_year(yy);
                    if(boolean == 1){
                       days_in_month[2] = 29;
                    }
                    else{
                        days_in_month[2] = 28;
                        }
                    additional_days = additional_days - days_in_month[mm];
                    mm = 0;
                    mm++;
                    dd = additional_days; 
                    yy += 1;
                }
            }
        dd = additional_days;
    }
    else{
        yy += 1;
        boolean = Leap_year(yy);
        mm = 0;
        mm++;
        if(boolean == 1){
            days_in_month[2] = 29;
        }
        else{
            days_in_month[2] = 28;
            }
        while(additional_days > days_in_month[mm]){
            if(mm < 12){
                boolean = Leap_year(yy);
                if(boolean == 1){
                    days_in_month[2] = 29;
                }
                else{
                    days_in_month[2] = 28;
                    }
                additional_days = additional_days - days_in_month[mm];
                mm++;
                dd = additional_days;
                }
            else{
                boolean = Leap_year(yy);
                if(boolean == 1){
                    days_in_month[2] = 29;
                }
                else{
                    days_in_month[2] = 28;
                    }
                additional_days = additional_days - days_in_month[mm];
                mm = 0;
                mm++;
                dd = additional_days; 
                yy += 1;
            }
        }
        dd = additional_days;
    }
    }

    printf("/nThe date after %d days would be: ", days_to_be_added);
    
    printf("%d/%d/%d", dd, mm, yy);
    return 0;
}