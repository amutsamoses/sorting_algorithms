#include "sort.h"

/**
 * shell_sort -  function to sorts an array of integers in
 * ascending order using the Shell sort algorithm,
 * using the Knuth sequence
 *
 * @array: reference pointer to array
 * @size: gets size of the array
 **/

void shell_sort(int *array, size_t size)
{
	size_t kunth[1000], k = 0, j = 0, i;
	int n, m;

	if (!array)
		return;
	while (j * 3 + 1 < size)
	{
		kunth[k] = j * 3 + 1;
		j = kunth[k++];
	}
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < size; j++)
		{
			if ((j + kunth[k - i - 1]) > size - 1)
				break;
			m = j;
			while (array[m] > array[m + kunth[k - i - 1]])
			{
				n = array[m];
				array[m] =  array[m + kunth[k - i - 1]];
				array[m + kunth[k - i - 1]] = n;
				m = m - kunth[k - i - 1];
				if (m < 0)
					break;
			}
		}
		print_array(array, size);
	}
}
