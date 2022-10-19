#include "menger.h"
#include <stdio.h>
#include <math.h>


/**
 * Uno - Lorem ipsum dolor sit amet
 *
 * @l: Lorem ipsum dolor sit amet
 * @d: Lorem ipsum dolor sit amet
 *
 * Return: Uno or zero
 */

int Uno(int l, int d)
{
	while (l != 0 && d != 0)
	{
		if (l % 3 == 1 && d % 3 == 1)
			return (0);

		l /= 3, d /= 3;
	}
	return (1);
}

/**
 * menger - Lorem ipsum dolor sit amet
 *
 * @level: Lorem ipsum dolor sit amet
 *
 * Return: empty
 */
void menger(int level)
{
	int m, l, limit;

	if (level < 0)
		return;

	for (m = 0, limit = pow(3, level); m < limit; m++)
	{
		for (l = 0; l < limit; l++)
		{
			Uno(m, l) == 1 ? printf("%c", '#') : printf("%c", ' ');
		}
		printf("\n");
	}
}
