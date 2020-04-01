#include "palindrome.h"
/**
 * is_palindrome - checks whether or not an unsigned integer is a
 * palindrome
 * @n: number to be checked
 * Return: 1 if n is a palindrome, 0 if it isn't.
 */
int is_palindrome(unsigned long n)
{
	unsigned long rem, num, rev = 0;
	num = n;

	while (n > 0)
	{
		rem = n % 10;
		rev = rev * 10 + rem;
		n = n / 10;
	}
	if (rev == num)
		return (1);
	else
		return (0);
}
