#include <stdio.h>

void printer(int array[], int size);

int main(void)
{
    int array[] = {4, 5, 8, 2, 3, 6, 12, 10, 9, 16, 15, 21, 0, 23, 1, 14, 18, 24};
    merge_sort(array);
