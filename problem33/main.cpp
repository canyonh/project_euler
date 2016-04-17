#include <cstdio>

int numerator = 1;
int denumerator = 1;

void Find()
{
	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 0; j <= 9; ++j)
		{
			for (int k = 1; k <= 9; ++k)
			{
				// todo: check if this is intended
				if (j == k)
					continue;

				if (i > k || j > i)
				{
					if ( (double)(k * 10 + i) / (double)(i * 10 + j) == (double)k / (double)j)
					{
						printf("%d%d/%d%d\n", k, i, i, j);
						numerator *= (k * 10 + i);
						denumerator *=  (i * 10 + j);
					}
				}
				else
				{
					if ( (double)(i * 10 + j) / (double)(k * 10 + i) == (double)j / (double)k)
					{
						printf("%d%d/%d%d\n", i, j, k, i);
						numerator *= (i * 10 + i);
						denumerator *= (k * 10 + i);
					}
				}
			}
		}
	}
}

void Answer(int num_in, int denum_in)
{
	int num = num_in;
	int denum = denum_in;
	int max = num > denum ? num : denum;
	for (int i = 2; i <= max; ++i)
	{
		while (num % i == 0 && denum % i == 0)
		{
			num /= i;
			denum /= i;
			printf("%d, %d/%d\n",i, num, denum);
		}

		if (num < i || denum < i)
			break;
	}
	printf("%d/%d, answer: %d\n",num_in, denum_in, denum);
}

int main(int argc, char* argv[])
{
	Find();
	Answer(numerator, denumerator);
	return 0;
}
