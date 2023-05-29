#include "holberton.h"

/**
 * main - multiplies two positive numbers
 * @argc: Only 2 - error if not
 * @argv: The two numbers to multiply
 * Return: 0 success
 */

int main(int argc, char *argv[])
{
	char **p;
	int i, j, len1, len2, n, aux_len;
	int n1 = 0;

	if (argc != 3)
	{
		_puts("Error");
		exit(98);
	}

	len1 = _strlen(argv[1]);
	len2 = _strlen(argv[2]);

	for (i = 0; i < len1; i++)
	{
		if (_isdigit(argv[1][i]) != 1)
		{
			_puts("Error");
			exit(98);
		}
	}

	for (i = 0; i < len2; i++)
	{
		if (_isdigit(argv[2][i]) != 1)
		{
			_puts("Error");
			exit(98);
		}
	}

	aux_len = len2 + 2;

	p = malloc(sizeof(char *) * aux_len);

	if (p == NULL)
		return ('\0');

	for (i = 0; i < aux_len; i++)
	{
		p[i] = calloc((len1 + len2 + 1), sizeof(char));

		if (p[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(p[j]);
			free(p);
			return ('\0');
		}
	}

	for (i = 0; i < len1 + len2; i++)
	{
		for (j = 0; j < aux_len; j++)
		{
			p[j][i] = '0';
		}
	}

	for (i = 0; i < len2; i++)
	{
		for (j = 0; j < len2 + len1; j++)
		{
			if (j > len1 + len2 - i - 1)
				break;

			if (j < len1)
				n = (((argv[2][len2 - 1 - i] - '0') * (argv[1][len1 - 1 - j] - '0')) + n1);
			else
				n = 0 + n1;

			if (n > 9)
			{
				n1 = n / 10;
				n = n % 10;
			}
			else
				n1 = 0;

			p[i][len1 + len2 - j - 1 - i] = n + '0';
		}
	}

	if (aux_len == 1)
	{
		for (j = 0; j < len1 + len2; j++)
			p[len2 + 1][j] = p[0][j];
	}
	else
	{
		for (i = 0; i < len2; i++)
		{
			p[len2 + 1] = infinite_add(p[i], p[len2], p[len2 + 1], len1 + len2 + 1);
			for (j = 0; j < len1 + len2; j++)
				p[len2][j] = p[len2 + 1][j];
		}
	}

	for (i = 0; i < len1 + len2; i++)
	{
		if (p[len2 + 1][i] == '0')
			j = i;
		else
		{
			j = i;
			break;
		}
	}

	for (; j < len1 + len2; j++)
	{
		_putchar(p[len2 + 1][j]);
	}
	_putchar('\n');

	for (j = 0; j < aux_len; j++)
		free(p[j]);
	free(p);

	return (0);
}

/**
 * _strlen - Calculate length of string
 * @s: Pointer to string
 * Return: Length of string
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
	}
	return (i);
}

/**
 * _puts - Print string
 * @str: Pointer to string
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}

/**
 *  infinite_add - adds two numbers.
 * @n1: number 1
 * @n2: number 2
 * @r: Array return
 * @size_r: max size
 * Return: r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i, j, k, a, l, n;
	int c = 0;

	for (i = 0; n1[i] != '\0'; i++)
	{
	}
	for (j = 0; n2[j] != '\0'; j++)
	{
	}
	for (k = 0; k < i || k < j; k++)
	{
		n = 0;
		if (i > k)
			n = n + n1[i - k - 1] - '0';
		if (j > k)
			n = n + n2[j - k - 1] - '0';
		n = n + c;
		c = 0;
		if (n > 9)
		{
			r[k] = ((n - 10) + '0');
			c = 1;
		}
		else
			r[k] = n + '0';
	}
	if (c == 1)
	{
		r[k] = '1';
		k++;
	}
	for (l = 0; l < k / 2; l++)
	{
		a = r[l];
		r[l] = r[k - l - 1];
		r[k - l - 1] = a;
	}
	r[k] = '\0';
	if (k >= size_r)
		return (0);
	return (r);
}

/**
 * _calloc - allocates memory for an array and fill with zero
 * @nmemb: number of elements of the array
 * @size: size of the elementes in the array
 * Return: Pointer to address of new space
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *p = NULL;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	p = malloc(sizeof(char) * (size * nmemb));

	if (p == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < size * nmemb; i++)
	{
		p[i] = '\0';
	}

	return (p);
}
/**
 * _isdigit - Check for a digit from 0 to 9
 * @c: Digit to check
 * Return: 1 is a digit 0 to 9 - 0 is not
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}
