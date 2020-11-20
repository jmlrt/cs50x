#include <cs50.h>
#include <stdio.h>

bool check_luhn_algorythm(long number);
int get_first_digits(long number);
int count_digits(long number);

int main(void)
{
    // get the credit card number
    long credit_card_number = get_long("Number: ");

    // check if the card number is valid according to Luhn's algorythm
    bool is_valid = check_luhn_algorythm(credit_card_number);

    if (is_valid != true)
    {
        printf("INVALID\n");
        return 0;
    }

    /*
     * check if  the cradit card number match AMEX, MASTERCARD or VISA
     */

    // get the 2 first digits of the credit card number
    int first_digits = get_first_digits(credit_card_number);

    // count credit card number digits
    int digits = count_digits(credit_card_number);

    if (first_digits == 34 || first_digits == 37)
    {
        if (digits == 15)
        {
            printf("AMEX\n");
            return 0;
        }
    }
    else if (first_digits >= 40 && first_digits <= 49)
    {
        if (digits == 13 || digits == 16)
        {
            printf("VISA\n");
            return 0;
        }
    }
    else if (first_digits >= 51 && first_digits <= 55)
    {
        if (digits == 16)
        {
            printf("MASTERCARD\n");
            return 0;
        }
    }

    // credit card number is invalid if it didn't match AMEX, MASTERCARD or VISA
    printf("INVALID\n");
}

bool check_luhn_algorythm(long number)
{
    long checksum = 0;

    int i = 0;
    do
    {
        // get modulo
        int modulo = number % 10;
        number = number / 10;

        i++;

        // multiply other digit
        if (i % 2 == 0)
        {
            int product = modulo * 2;
            if (product > 9)
            {
                // add product's digit
                int product_first_digit = product / 10;
                int product_second_digit = product % 10;
                modulo = product_first_digit + product_second_digit;
            }
            else
            {
                modulo = product;
            }
        }

        // add digit to checksum
        checksum += modulo;
    }
    while (number > 0);

    return (checksum % 10 == 0) ? true : false;
}

int get_first_digits(long number)
{
    while (number > 100)
    {
        number = number / 10;
    }

    return number;
}

int count_digits(long number)
{
    int i = 0;
    do
    {
        number = number / 10;
        i++;
    }
    while (number > 0);

    return i;
}
