#include "palindrome.h"

unsigned long *max_mult_ten(unsigned long n)
{
	unsigned long num = n;
	unsigned long max = 1;
	unsigned long *ret = &max;
	while (num / max > 0) {
		max = max * 10;
	}
	max = max / 10;
	return (ret);
}

/**
 * is_palindrome - checks whether or not an unsigned integer is a
 * palindrome
 * @n: number to be checked
 * Return: 1 if n is a palindrome, 0 if it isn't.
 */
int is_palindrome(unsigned long n)
{
	unsigned long max, f, l;
	while (n) {
		max = *(max_mult_ten(n));
		f = n / max;
		l = n % 10;
		if (l == f)
			n = (n % max) / 10;
		else
			return (0);
	}
	return (1);
}
