#include <cs50.h>
#include <stdio.h>

int validity(long l)
{
    int summation = 0;
    int counter = 1;
    while (l > 0)
    {
        int sum_term = 0;
        int last_digit = l % 10;
        l = l / 10;
        if (counter % 2 == 0)
        {
            sum_term = last_digit * 2;
            if (sum_term >= 10)
            {
                sum_term = (sum_term % 10) + 1;
            }
        }
        else
        {
            sum_term = last_digit;
        }
        summation += sum_term;
        counter++;
    }
    if (summation % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int first_digits(long l)
{
    while (l >= 100)
    {
        l = l / 10;
    }
    return l;
}

int digit_counter(long l)
{
    int counter = 0;
    while (l > 0)
    {
        l = l /10;
        counter ++;
    }
    return counter;
}

int main(void)
{
    long l = get_long("Number: ");
    if (validity(l))
    {
        if (first_digits(l) == 34 || first_digits(l) == 37)
        {
            if (digit_counter(l) == 15)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (first_digits(l) / 10 == 4)
        {
            if (digit_counter(l) == 13 || digit_counter(l) == 16)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (first_digits(l) == 51 || first_digits(l) == 52 || first_digits(l) == 53 || first_digits(l) == 54 || first_digits(l) == 55)
        {
            if (digit_counter(l) == 16)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
