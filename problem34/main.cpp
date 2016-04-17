#include <stdio.h>

int factorial[9]; // only 1 ~ 9 is used

void CalcFact()
{
	factorial[0] = 1;
	for (int i = 1; i <= 9; ++i)
		factorial[i] = factorial[i - 1] * i;
}

void GetCurious()
{
	int sum = 0;
	for (int i = 10; i < 99999; ++i)
	{
		int tmp = i;
		int tmp_sum = 0;
		while (tmp > 0)
		{
			int digit = tmp % 10;
			tmp /= 10;
			tmp_sum += factorial[digit];
		}
		if (tmp_sum == i)
		{
			printf("%d\n", i);
			sum += tmp_sum;
		}	
	}
	printf("sum = %d\n", sum);
}

int main(int argc, char* argv[])
{
	CalcFact();
	for (int i = 1; i <= 9; ++i)
		printf("%d\n", factorial[i]);

	GetCurious();

	return 0;
}
