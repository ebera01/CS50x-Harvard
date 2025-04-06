#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[] = {1, 10, 200, 100, 50, 20, 500};
    int len = 7;
    int n = get_int("Number to search: ");
    int flag = 0;
    for (int i = 0; i < len; i++)
    {
        if (numbers[i] == n)
        {
            return 0;
        }

    }
    printf("not found.\n");
}
