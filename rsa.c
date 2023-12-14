#include <stdio.h>
#include <stdlib.h>

int is_prime(int num)
{
	int i;

	if (num < 2)
	{
		return 0;
	}

	for (i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
		{
			return 0;  
		}
	}

	return 1;
}

void factorize_prime(int n)
{
	int i;

	printf("%d=", n);

	if (is_prime(n))
	{
		printf("%d*1\n", n);
		return;
	}

	for (i = 2; i <= n; i++)
	{
		if (n % i == 0 && is_prime(i))
		{
			printf("%d", i);
			n /= i;

			if (n > 1)
			{
				printf("*");
			}

			while (n % i == 0)
			{
				printf("%d", i);
				n /= i;

				if (n > 1)
				{
					printf("*");
				}
			}
		}
	}

	printf("\n");
}

int main(int argc, char *argv[])
{
	int number;

	if (argc != 2)
	{
		printf("Usage: %s <number>\n", argv[0]);
		return 1;
	}

	number = atoi(argv[1]);

	factorize_prime(number);

	return 0;
}
