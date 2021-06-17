#include "palindrome.h"




/**
 * itoa - convert number to string
 *
 * @val: number to convert
 * @base: base of the conversion
 *
 * Return: converted num as a string
 */
char *itoa(int val, int base)
{
	static char buf[32] = {0};

	int i = 30;

	for (; val && i ; --i, val /= base)

		buf[i] = "0123456789abcdef"[val % base];

	return (&buf[i + 1]);

}




/**
 * is_palindrome - checks if a number is a palindrome
 *
 * @n: number to check
 *
 * Return: 1 if palindrome 0 if not
 */
int is_palindrome(unsigned long n)
{
	char *s = itoa(n, 10);
	size_t i, j;

	for (i = 0, j = strlen(s) - 1; i < strlen(s); i++, j--)
	{
		if (s[i] != s[j])
			return (0);
	}
return (1);
}
