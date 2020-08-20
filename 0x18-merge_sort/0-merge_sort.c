#include "sort.h"

/**
 * print_done - prints numbers that were just merged in array
 * @array: array being sorted
 * @l: integer representing the start of the merged numbers
 * @r: integer representing the end of the merged numbers
 */
void print_done(int *array, int l, int r)
{
	int i = 0;

	printf("[Done]: ");

	for (i = l; i < r; i++)
	{
		if (i == r - 1)
			printf("%d\n", array[i]);
		else
			printf("%d, ", array[i]);
	}
}

/**
 * print - prints the numbers that about to be merged
 * @left: array representing the left half of the array being sorted
 * @right: array representing the right half of the array being sorted
 * @left_size: size of the left array;
 * @right_size: size of the right array;
 */
void print(int *left, int *right, int left_size, int right_size)
{
	int i = 0;

	printf("Merging...\n");
	printf("[left]: ");
	for (; i < left_size; i++)
	{
		if (i == left_size - 1)
			printf("%d\n", left[i]);
		else
			printf("%d, ", left[i]);
	}
	printf("[right]: ");
	for (i = 0; i < right_size; i++)
	{
		if (i == right_size - 1)
			printf("%d\n", right[i]);
		else
			printf("%d, ", right[i]);
	}
}

/**
 * merge - merges left and right arrays into one by editing its values
 * @array: array to change while merging left and right
 * @left: leftmost array to merge
 * @right: rightmost  array to merge
 * @left_size: size of the left array;
 * @right_size: size of the right array;
 */
void merge(int *array, int *left, int *right, int left_size, int right_size)
{
	int l, r, i;

	i = 0, l = 0, r = 0;
	print(left, right, left_size, right_size);

	/*
	 * choose the lowest value between left[i] and right[i]
	 * change array[i] with it
	 */
	while (l < left_size && r < right_size)
	{
		if (left[l] < right[r])
		{
			array[i] = left[l];
			l++;
		} else
		{
			array[i] = right[r];
			r++;
		}
		i++;
	}
	/*
	 * eventually either l or r are going to reach the condition while the
	 * other side hasn't reached it yet
	 */
	while (l < left_size)
	{
		array[i] = left[l];
		i++;
		l++;
	}
	while (r < right_size)
	{
		array[i] = right[r];
		i++;
		r++;
	}
	print_done(array, 0, i);
}

/**
 * merge_sort - recursively splits array in two and calls merge() to sort them
 * @array: array to sort
 * @size: size of the array to sort
 */
void merge_sort(int *array, size_t size)
{
	size_t mid, left_size, right_size, i = 0;
	int *left, *right;

	/* base case */
	if (size < 2)
		return;

	mid = size / 2;
	left_size = mid;
	right_size = size - mid;

	left = malloc(left_size * sizeof(int));
	for (i = 0; i < mid; i++)
		left[i] = array[i];

	right = malloc(right_size * sizeof(int));
	for (i = mid; i < size; i++)
		right[i - mid] = array[i];

	/* split then merge */
	merge_sort(left, left_size);
	merge_sort(right, right_size);
	merge(array, left, right, left_size, right_size);
}
