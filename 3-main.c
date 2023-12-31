#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "3-quick_sort.c"
#include "print_array.c"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {5, 10, 100};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    quick_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
