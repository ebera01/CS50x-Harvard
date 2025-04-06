#include <cs50.h>
#include <stdio.h>

int height;
int main(void)
{
    do
    {
        height = get_int("Height: ");
    }
    while ((height <= 0) || (height > 8));

    for (int i = 0; i < height + 1; i++)
    {

        for (int k = 0; k < height - i; k++)
        {
            if (i != 0)
            {
                printf(" ");
            }
        }

        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        if (i != 0)
        {
            printf("  ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        if (i != 0)
        {
            printf("\n");
        }
    }
}
