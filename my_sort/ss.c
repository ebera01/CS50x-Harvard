#include <cs50.h>
#include <stdio.h>

void printer(int array[], int size);

int main(void)
{
    int array[] = {4, 5, 8, 2, 3, 6, 12, 10, 9, 16, 1, 0};
    int size = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_index])
            {
                min_index = j;
            }
        }
        int temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
    }
    printer(array, size);

    return 0;
}

void printer(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
