#include <stdio.h>
#include <cs50.h>
#include <math.h>

//psuedo code:

// CHECKSUM:
    //MULTIPLY EVERY OTHER DIGIT BY 2
    // ADD THOSE PRODUCTS DIGITS!! TOGETHER
    // DO NOT ADD THE PRODUCTS THEMSELVES
    //ADD SUM TO SUM OF DIGITS THAT WERE NOT MULTIPLIED
    //IF THE TOTALS LAST DIGIT IS 0 = VALID

//CREDIT CARD TYPE
    //AMEX: 15 DIGITS, STARTS WITH 34 OR 37
    //MC: 16 DIGITS, STARTS WITH 51-55
    //VISA: 13 OR 16 DIGITS, STARTS WITH 4



int every_other_digit(long long ccnum);

int multiplyandsum(int last_digit);

int checklastdigit(int sum);

int get_digit_count(long long ccnum);

int get_first_digits(long long ccnum, int digit_count);

//***START CODE***
int main(void){

long long ccnum = 0;

int digit_count = 0;

//get ccnum//

    do{
        ccnum = get_long("Card Number?\n");
    }
    while(ccnum < 0);

// ***CHECKSUM***//

int sum = every_other_digit(ccnum);

int verify_0 = checklastdigit(sum);

//** Verify last digit of sum **//

if(verify_0 != 0){
    printf("INVALID\n");
    return 0;
}
    else{
          digit_count = get_digit_count(ccnum);

    }

// Get first digits for verification//
int first_digits = get_first_digits(ccnum, digit_count);

// Verification of card type criteria //
if(digit_count > 12 && digit_count < 17){
    if((first_digits == 34 || first_digits == 37) && (digit_count == 15)){
        printf("AMEX\n");
    }else{
        if((digit_count == 13 || digit_count == 16) && (first_digits > 50 && first_digits <= 55)){
            printf("MASTERCARD\n");
            }else{
                if(digit_count == 13 || digit_count == 16){
                    first_digits = first_digits / 10;
                    if(first_digits == 4){
                        printf("VISA\n");
                    }else{
                        printf("INVALID\n");
                    }

                }else{
                    printf("INVALID\n");
                }
            }

    }
}
return 0;

}

//Functions//
int every_other_digit(long long ccnum){
    int sum = 0;
    int last_digit = 0;
    bool alternatedigit = false;
    while(ccnum > 0){
        if(alternatedigit == true){
            last_digit = ccnum % 10;
            int product = multiplyandsum(last_digit);
            sum = sum + product;
        }
            else{
                last_digit = ccnum % 10;
                sum = sum + last_digit;
        }

        alternatedigit = !alternatedigit;
        ccnum = ccnum/10;
    }
    return sum;
}

int multiplyandsum(int last_digit){

    int multiply = last_digit * 2;
    int product = 0;
    while(multiply > 0){
        int last_digit_multiply = multiply % 10;
        product = product + last_digit_multiply;
        multiply = multiply / 10;
    }

    return product;
}
int checklastdigit(int sum){
    int verify_0 = 0;
    if (sum > 0){
         verify_0 = sum % 10;
    }
    return verify_0;
}

int get_digit_count(long long ccnum){
    int digit_count = 0;
   for(digit_count = 0; ccnum > 0; digit_count++){
            ccnum = ccnum / 10;
        }
        if(digit_count < 13 || digit_count > 16){
            printf("INVALID\n");
        }
        return digit_count;
}

int get_first_digits(long long ccnum, int digit_count){
    int first_digits = 0;
    if(digit_count > 12 && digit_count < 17){
     while(ccnum > 100){
        ccnum = ccnum / 10;
        }
        first_digits = ccnum;
    }
    return first_digits;
}
