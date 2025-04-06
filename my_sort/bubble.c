#include <stdio.h>

void printer(int array[], int size);

int main(void)
{
    int array[] = {4, 5, 8, 2, 3, 6, 12, 10, 9, 16, 15, 21, 0, 23, 1, 14, 18, 24};
    int size = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array [j + 1];
                array[j + 1] = temp;
            }
        }
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

