#include <cstdio>
#include <memory.h>
void Print(unsigned int* data, unsigned int cnt)
{
	bool leading_zero = true;
	for (unsigned int i = 0; i < cnt; ++i)
	{
		if (leading_zero && data[i] != 0)
			leading_zero = false;

		if (!leading_zero)
			printf("%u ", data[i]);
	}
	printf("\n");
}

void LongMultiply2(unsigned int* lhs, unsigned int lhs_cnt,
				  unsigned int* rhs, unsigned int rhs_cnt,
				  unsigned int* answer)
{
	for (unsigned int i = 0; i < lhs_cnt; ++i)
	{
		unsigned int carry = 0;
		for (unsigned int j = 0; j < rhs_cnt; ++j)
		{
			answer[i + j] += carry + lhs[i] * rhs[j];
			carry = answer[i + j] / 10;
			answer[i + j] %= 10;
		}
		answer[i + rhs_cnt] += carry;
		Print(answer, lhs_cnt + rhs_cnt);
	}

	Print(answer, lhs_cnt+rhs_cnt);

	printf("\n");
}

void LongMultiply(unsigned int* lhs, unsigned int lhs_cnt,
				  unsigned int* rhs, unsigned int rhs_cnt,
				  unsigned int* answer)
{
	for (unsigned int i = 0; i < lhs_cnt; ++i)
	{
		for (unsigned int j = 0; j < rhs_cnt; ++j)
		{
			unsigned int tmp = lhs[i] * rhs[j];
			printf("%u, %u, -> %u\n", lhs[i], rhs[j],  tmp);
			answer[i + j] += tmp % 10;
			answer[i + j + 1] += tmp / 10;
			printf("a[%u] = %u, a[%u] = %u\n", i + j, answer[i + j], i + j + 1, answer[i + j + 1]);
		}
		Print(answer, lhs_cnt + rhs_cnt);
	}

	Print(answer, lhs_cnt+rhs_cnt);

	for (int i = 0; i < lhs_cnt + rhs_cnt; ++i)
	{
		if (answer[i] >= 10)
		{
			unsigned tmp = answer[i];
			answer[i] = tmp % 10;
			answer[i + 1]  += tmp / 10;
		}
	}

	Print(answer, lhs_cnt+rhs_cnt);
	printf("\n");
}

int main(int argc, char* argv[])
{
	unsigned int lhs[] = {1, 2, 3, 4};
	unsigned int rhs[] = {4, 5, 6};

	unsigned int answer[sizeof(lhs)/sizeof(lhs[0]) + sizeof(rhs)/sizeof(rhs[0])];

	memset(answer, 0, sizeof(answer));

	LongMultiply2(lhs, sizeof(lhs)/sizeof(lhs[0]), rhs, sizeof(rhs)/sizeof(rhs[0]), answer);
	
	return 0;
}

