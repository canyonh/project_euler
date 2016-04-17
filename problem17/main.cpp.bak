#include <cstdio>

const char* digits1[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };
const char* digits2[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
const char* digits3[] = { "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety" };
const char* digits4[] = { "", "hundred" };	

unsigned int size_1[] = { 0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3 };
unsigned int size_2[] = { 3, 6, 6, 8, 8, 7, 7, 10, 8, 8};
unsigned int size_3[] = { 6, 6, 6, 5, 5, 7, 6, 6 };
unsigned int size_4[] = { 0, 7 };

void Print()
{
	for (size_t hundred = 0; hundred < 10; ++hundred)
	{
		size_t hundred_index = hundred == 0 ? 0 : 1;
		// 1 to 10
		for (size_t i = 0; i <= 10; ++i)
			printf("%s %s %s, ", digits1[hundred], digits4[hundred_index], digits1[i]);
		printf("\n");

		// 11 ~ 19
		for (size_t i = 1; i < 10; ++i)
			printf("%s %s %s, ", digits1[hundred], digits4[hundred_index], digits2[i]);

		printf("\n");

		for (size_t j = 0; j <= 7; ++j)
		{
			for (size_t i = 0; i < 10; ++i)
			{
				printf("%s %s %s %s, ", digits1[hundred], digits4[hundred_index], digits3[j], digits1[i]);
			}
			printf("\n");
		}
	}

	printf("one thousand");
}

void Calculate()
{
	unsigned int sum = 0;
	for (size_t hundred = 0; hundred < 10; ++hundred)
	{
		size_t hundred_index = hundred == 0 ? 0 : 1;
		// 1 to 10
		for (size_t i = 0; i <= 10; ++i)
		{
			printf("%s %s %s, ", digits1[hundred], digits4[hundred_index], digits1[i]);
			printf("\n");
			sum += (size_1[hundred] + size_4[hundred_index] + size_1[i]);
		}

		// 11 ~ 19
		for (size_t i = 1; i < 10; ++i)
		{
			printf("%s %s %s, ", digits1[hundred], digits4[hundred_index], digits2[i]);
			sum += (size_1[hundred] + size_4[hundred_index] + size_2[i]);
		}

		printf("\n");

		for (size_t j = 0; j <= 7; ++j)
		{
			for (size_t i = 0; i < 10; ++i)
			{
				printf("%s %s %s %s, ", digits1[hundred], digits4[hundred_index], digits3[j], digits1[i]);
				sum += (size_1[hundred] + size_4[hundred_index] + size_3[j] + size_1[i]);
			}
			printf("\n");
		}
	}

	printf("one thousand");
	sum += 11;
	printf("answer: %u\n", sum);
}

int main(int argc, char* argv[])
{
	Calculate();
	return 0;
}
