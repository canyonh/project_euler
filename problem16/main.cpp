#include <cstdio>
#include <memory.h>
unsigned int input[] = {4, 2, 6, 2, 4, 8, 6, 0, 9, 9, 9, 8, 5, 2, 1, 1};

void Multiply(unsigned int* lhs, size_t lhs_cnt, unsigned int*rhs, size_t rhs_cnt, unsigned int*answer)
{
	for (size_t i = 0; i < lhs_cnt; ++i)
	{
		for (size_t j = 0; j < rhs_cnt; ++j)
		{
			//printf("%lu %lu (%u*%u)-", i, j, rhs[j], lhs[i]);
			unsigned int tmp = rhs[j] * lhs[i];
			answer[i + j] += tmp % 10;
			answer[i + j + 1] += tmp / 10;
			/*for (ssize_t k = lhs_cnt + rhs_cnt - 1; k >= 0; --k)
			{
				printf("%u ", answer[k]);
			}
			printf("\n");
			*/
		}
	}

	for (size_t i = 0; i < lhs_cnt + rhs_cnt - 1; ++i)
	{
		unsigned int tmp = answer[i];
		//printf("tmp: %d\n", tmp);
		if (answer[i] >= 10)
		{
			answer[i] = tmp % 10;
			answer[i + 1] += tmp / 10;
		}
	}
}

void Print(unsigned int *answer, unsigned int total_cnt)
{
	bool valid = false;
	unsigned int final_answer = 0;
	for (ssize_t i = total_cnt - 1; i >= 0; --i)
	{
		if (!valid)
		{
			if (answer[i] != 0)
				valid = true;
		}

		if (valid)
		{
			printf("%u", answer[i]);
			final_answer += answer[i];
		}
	}
	printf("\n\n");
	printf("final answer: %u\n", final_answer);
}
int main(int argc, char* argv[])
{
	ssize_t input_cnt = sizeof(input) / sizeof(input[0]);
	ssize_t total_cnt = 400;

	unsigned int* lhs = new unsigned int[total_cnt];
	memset(lhs, 0, total_cnt * sizeof(unsigned int));

	for (size_t i = 0; i < input_cnt; ++i)
		lhs[i] = input[i];

	unsigned int* answer = new unsigned int[total_cnt];
	unsigned int* input_2 = lhs;
	unsigned int* output = answer;
	memset(answer, 0, total_cnt * sizeof(unsigned int));

	for (size_t i = 0; i < 20; ++i)
	{
		Multiply(input, input_cnt, input_2, total_cnt, output);
		//Print(output, total_cnt);
		if (input_2 == lhs)
		{
			input_2 = answer;
			output = lhs;
		}
		else
		{
			input_2 = lhs;
			output = answer;
		}
			
		if ( i != 19)
			memset(output, 0, total_cnt * sizeof(unsigned int));
	}

	Print(output, total_cnt);
	delete [] answer;
	delete [] lhs;
	return 0;
}
