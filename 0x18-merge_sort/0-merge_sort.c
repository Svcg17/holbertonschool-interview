#include "sort.h"

void merge(int* array, int *left, int *right, int left_size, int right_size) {
    int l, r, i;

    printf("Merging...\n");
    printf("[left]: ");
    for (i = 0; i < left_size; i++)
    {
        if (i == left_size - 1)
            printf("%d\n ", left[i]);
        else
            printf("%d, ", left[i]);
    }
    printf("[right]: ");
    for (i = 0; i < right_size; i++)
        printf("%d" , right[i]);
    printf("\n");
    i = 0, l = 0, r = 0;
    while (l < left_size && r < right_size) {
        if (left[l] < right[r]) {
            array[i] = left[l];
            l++;
        } else {
            array[i] = right[r];
            r++;
        }
        i++;
    }
    while (l < left_size) {
        array[i] = left[l];
        i++;
        l++;
    }
    while(r < right_size) {
        array[i] = right[r];
        i++;
        r++;
    }
}

void merge_sort(int *array, size_t size) {
    size_t mid, left_size, right_size, i = 0;
    int *left, *right;

    if (size < 2) return; // base case

    mid = size / 2;
    left_size = mid;
    right_size = size - mid;

    left = malloc(left_size * sizeof(int));
    for (i = 0; i < mid; i++)
        left[i] = array[i];

    right = malloc(right_size * sizeof(int));
    for (i = mid; i < size; i++)
        right[i - mid] = array[i];

  
    merge_sort(left, left_size);
    merge_sort(right, right_size);
    merge(array, left, right, left_size, right_size);
}
