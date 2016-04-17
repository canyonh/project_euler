#include <cstdio>
#include <memory.h>
void Print(unsigned int* data, unsigned int cnt)
{
	bool leading_zero = true;
	for (int i = cnt - 1; i >= 0; --i)
	{
		if (leading_zero && data[i] != 0)
			leading_zero = false;

		if (!leading_zero)
			printf("%u", data[i]);
	}
	printf("\n");
}

void LongMultiply2(unsigned int* lhs, unsigned int lhs_cnt,
				  unsigned int* rhs, unsigned int rhs_cnt,
				  unsigned int* answer)
{
	printf("lhs:");
	Print(lhs, lhs_cnt);
	printf("\n");
	printf("rhs:");
	Print(rhs, rhs_cnt);
	printf("\n");
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
		//Print(answer, lhs_cnt + rhs_cnt);
	}

	//Print(answer, lhs_cnt+rhs_cnt);

	//printf("\n");
}

void LongMultiply(unsigned int* lhs, unsigned int lhs_cnt,
				  unsigned int* rhs, unsigned int rhs_cnt,
				  unsigned int* answer)
{
	printf("lhs:");
	Print(lhs, lhs_cnt);
	printf("\n");
	printf("rhs:");
	Print(rhs, rhs_cnt);
	printf("\n");
	for (unsigned int i = 0; i < lhs_cnt; ++i)
	{
		for (unsigned int j = 0; j < rhs_cnt; ++j)
		{
			unsigned int tmp = lhs[i] * rhs[j];
			//printf("%u, %u, -> %u\n", lhs[i], rhs[j],  tmp);
			answer[i + j] += tmp % 10;
			answer[i + j + 1] += tmp / 10;
			//printf("a[%u] = %u, a[%u] = %u\n", i + j, answer[i + j], i + j + 1, answer[i + j + 1]);
		}
		//Print(answer, lhs_cnt + rhs_cnt);
	}

	//Print(answer, lhs_cnt+rhs_cnt);

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

void Problem()
{
	const unsigned int length = 200;
	unsigned int buffer1[length];
	memset(buffer1, 0, length * sizeof(unsigned int));

	unsigned int buffer2[length];
	memset(buffer2, 0, length * sizeof(unsigned int));

	unsigned int input[3];

	unsigned int* input2 = buffer1;
	unsigned int* output = buffer2;

	input2[0] = 1;

	for (size_t i = 2; i <= 100; ++i)
	{
		int tmp = i;
		input[0] = tmp % 10;
		tmp /=10;
		input[1] = tmp % 10;
		tmp /= 10;
		input[2] = tmp % 10;

		LongMultiply2(input2, length, input, 3, output);
		//printf("%lu! = ", i);
		//Print(output, length);
		//printf("\n");
		if (i != 100)
		{
			unsigned int *tmp = input2;
			input2 = output;
			output = tmp;
			memset(output, 0, length * sizeof(unsigned int));
		}
	}
	printf("answer:\n");
	Print(output, length);
	printf("\n");
	unsigned int sum = 0;
	for (size_t i = 0; i < length; ++i)
		sum += output[i];

	printf("answer: %u\n", sum);

}


int main(int argc, char*argv[])
{
	Problem();
	return 0;
}
