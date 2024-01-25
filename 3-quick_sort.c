#include "sort.h"

void swap(int *a, int *b);
int lomuto_partition(int *array, int low, int high, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);

/**
 * swap - swaps 2 elements in an array
 *
 * @a: pointer to first element
 * @b: pointer to second element
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - lomuto partition scheme for Quick sort
 *
 * @array: the array to be partitioned
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: number of elements in the array
 *
 * Return: index of the pivot after partitioning
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_recursive - recursive function for Quick Sort
 *
 * @array: the array to be sorted
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: number of elements in array
 */

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot;

		pivot = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: array to be sorted
 * @size: number of elements in the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

