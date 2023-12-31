#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/*#include "2-selection_sort.c"
#include "print_list.c"
#include "print_array.c"
#include "1-insertion_sort_list.c"
#include "0-bubble_sort.c"*/

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    selection_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
