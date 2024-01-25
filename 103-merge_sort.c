#include "sort.h"

/**
 * merge_sort - sorts an array of integers in ascending order using Merge sort
 * @array: array to be sorted
 * @size: number of elements in array
 */

void merge_sort(int *array, size_t size)
{
	if (size > 1)
	{
		size_t mid, i, j, k, left_size, right_size;
		int *left, *right;

		mid = size / 2;
		left = array;
		right = array + mid;
		left_size = mid;
		right_size = size - mid;

		merge_sort(left, left_size);
		merge_sort(right, right_size);

		printf("Merging...\n");

		printf("[left]: ");
		print_array(left, left_size);
		printf("[right]: ");
		print_array(right, right_size);

		i = j = k = 0;
		while (i < left_size && j < right_size)
		{
			if (left[i] <= right[j])
			{
				array[k++] = left[i++];
			}
			else
			{
				array[k++] = right[j++];
			}
		}

		while (i < left_size)
		{
			array[k++] = left[i++];
		}
		while (j < right_size)
		{
			array[k++] = right[j++];
		}

		printf("[Done]: ");
		print_array(array, size);
	}
}
