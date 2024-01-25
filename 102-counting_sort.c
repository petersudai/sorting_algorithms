#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order using Counting sort
 * @array: array to be sorted
 * @size: number of elements in the array
 */

void counting_sort(int *array, size_t size)
{
	int *count, *output, max, i;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (i = 1; (size_t)i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;

	for (i = 0; i <= max; i++)
		count[i] = 0;

	for (i = 0; (size_t)i < size; i++)
		count[array[i]]++;

	print_array(count, max + 1);

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(count);
		return;
	}

	for (i = size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	print_array(output, size);

	for (i = 0; (size_t)i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
