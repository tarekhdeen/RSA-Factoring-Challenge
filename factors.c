#include <stdio.h>

void factorize(int n)
{
	int factor = 2;

	printf("%d=", n);

	while (n > 1)
	{
		if (n % factor == 0)
		{
			printf("%d", factor);
			n /= factor;

			if (n > 1)
			{
				printf("*");
			}
		}
		else
		{
			factor++;
		}
	}

	printf("\n");
}

int main(int argc, char *argv[])
{
	FILE *file;
	int number;

	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		printf("Error opening the file.\n");
		return (1);
	}

	while (fscanf(file, "%d", &number) == 1)
	{
		factorize(number);
	}

	fclose(file);

	return (0);
}
