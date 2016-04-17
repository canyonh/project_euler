#include <cstdio>

const char* digits1[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };
const char* digits2[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
const char* digits3[] = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
const char* digits4[] = { "", "hundred" };	

unsigned int size_1[] = { 0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3 };
unsigned int size_2[] = { 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
unsigned int size_3[] = { 6, 6, 5, 5, 5, 7, 6, 6 };
unsigned int size_4[] = { 0, 7 };

void Calculate()
{
	unsigned int sum = 0;
	for (size_t hundred = 0; hundred < 10; ++hundred)
	{
		size_t hundred_index = hundred == 0 ? 0 : 1;
		// 1 to 10
		for (size_t i = 0; i <= 10; ++i)
		{
			int and_size = (hundred > 0 && i != 0) ? 3 : 0;
			int tmp = (size_1[hundred] + size_4[hundred_index] + size_1[i] + and_size);
			sum += tmp;
			printf("%s %s %s %s - %d, %d\n", digits1[hundred], digits4[hundred_index], (and_size > 0 ? "and" : ""), digits1[i], tmp, sum);
		}

		// 11 ~ 19
		for (size_t i = 1; i < 10; ++i)
		{
			if (hundred == 0)
			{
				int tmp = (size_1[hundred] + size_4[hundred_index] + size_2[i]);
				sum += tmp;
				printf("%s %s %s - %d, %d\n", digits1[hundred], digits4[hundred_index], digits2[i], tmp, sum);
			}
			else
			{
				int tmp = (size_1[hundred] + size_4[hundred_index] + size_2[i] + 3);
				sum += tmp;
				printf("%s %s AND %s - %d, %d\n", digits1[hundred], digits4[hundred_index], digits2[i], tmp, sum);
			}
		}

		for (size_t j = 0; j <= 7; ++j)
		{
			for (size_t i = 0; i < 10; ++i)
			{
				if (hundred == 0)
				{
					int tmp = (size_1[hundred] + size_4[hundred_index] + size_3[j] + size_1[i]);
					sum += tmp;
					printf("%s %s %s %s - %d, %d\n", digits1[hundred], digits4[hundred_index], digits3[j], digits1[i], tmp, sum);
				}
				else
				{
					int tmp = (size_1[hundred] + size_4[hundred_index] + size_3[j] + size_1[i] + 3);
					sum += tmp;
					printf("%s %s and %s %s - %d, %d\n", digits1[hundred], digits4[hundred_index], digits3[j], digits1[i], tmp, sum);
				}
			}
		}
	}

	printf("one thousand\n");
	sum += 11;
	printf("answer: %u\n", sum);
}

int main(int argc, char* argv[])
{
	Calculate();
	return 0;
}
