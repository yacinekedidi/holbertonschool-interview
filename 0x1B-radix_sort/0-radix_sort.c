#include "sort.h"


/**
 * get_digit_count - calculates the number of digits on a number
 *
 * @x: the number
 *
 * Return: digit count on a number
 */
int get_digit_count(int x)
{
	unsigned int count = 0;

	while (x)
	{
		x /= 10;
		count++;
	}
	return (count);
}

/**
 * _pow - computes the power of a number
 *
 * @x: base value
 * @y: power value
 *
 * Return: the power raised to the base number
 */
int _pow(int x, int y)
{
	int res = 1;

	while (y--)
		res *= x;
	return (res);
}

/**
 * get_digit_at - calculates the digit at a given spot
 *
 * @n: the number
 * @spot: the digit spot
 *
 * Return: a digit on a specific spot in a given number
 */
int get_digit_at(int n, int spot)
{
	return (((n / (int) _pow(10, spot)) % 100) % 10);
}

/**
 * get_max_digit - calculates the biggest
 * digit count on an array
 *
 * @array: pointer to the address of the first element in an array
 * @size: the size of the array
 *
 * Return: the max digit count on a number in an array
 */
int get_max_digit(int *array, size_t size)
{
	unsigned int max = 0, count;

	for (unsigned int i = 0; i < size; i++)
	{
		count = get_digit_count(array[i]);
		if (count > max)
			max = count;
	}
	return (max);
}


/**
 * radix_sort - sorts an array of integers in ascending order
 * using the Radix sort algorithm
 *
 * @array: pointer to the address of the first element in an array
 * @size: the size of the array
 *
 * Return: sorted array
 */
void radix_sort(int *array, size_t size)
{
	int current_digit = 0, max_digit, *bucket = NULL;
	unsigned int i = 0;

	if (size < 2)
		return;
	bucket = malloc(sizeof(int) * size);
	if (!bucket)
		return;
	max_digit = get_max_digit(array, size);
	int current_digit_value;

	while (max_digit > current_digit)
	{
		for (i = 0; i < size; i++)
		{
			unsigned int j = 0;
			unsigned int k = 0;

			current_digit_value = get_digit_at(array[i], current_digit);
			if (i == 0)
				bucket[i] = array[i];
			else
			{
				for (; j < i; j++)
					if (current_digit_value < get_digit_at(bucket[j], current_digit))
						break;
				if (j != i)
					for (k = i ; k > j; k--)
						bucket[k] = bucket[k - 1];
				bucket[j] = array[i];
			}
		}
		for (i = 0;  i < size; i++)
			array[i] = bucket[i];
		print_array(array, size);
		current_digit++;
	}
	free(bucket);
}
