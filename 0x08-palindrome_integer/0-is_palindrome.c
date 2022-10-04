#include "palindrome.h"
#include <stdio.h>

/**
 * rev checks whether or not a given unsigned integer is a palindrome.
 *
 * @n: Val - rev
 * @rev: P - num INFO saved
 *
 * Return: No (0) ret
 */
void reverse(unsigned long n, unsigned long *rev)
{
	if (n > 0)
	{
		*rev = *rev * 10 + (n % 10);
		n /= 10;
		reverse(n, rev);
	}

}

/**
 * is_palindrome - the entry functioon point
 *
 * @n: val to check
 *
 * Return: 0 no palindrome  else 1
 */
int is_palindrome(unsigned long n)
{
	unsigned long rev = 0;

	reverse(n, &rev);

	if (rev == n)
		return (1);

	return (0);
}
