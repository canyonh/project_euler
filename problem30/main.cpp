#include <cstdio>
#include <vector>

int main(int argc, char* argv[])
{
	/*
	int base = 59049;
	for (int i = 0; i < 10; ++i)
		printf("%d-%d ", i, i * base);
	printf("\n");
	*/

	const int limit = 354294;
	int sum = 0;
	for (int i = 10; i <= limit; ++i) 
	{
		std::vector<int> digits;
		int digit_left = i;
		while (digit_left > 0)
		{
			digits.push_back(digit_left % 10);
			digit_left /= 10;
		}

		int current_sum = 0;
		for (int i = 0; i < digits.size(); ++i)
		{
			current_sum += (digits[i] * digits[i] * digits[i] * digits[i] * digits[i]);
		}

		if (current_sum == i)
		{
			sum += current_sum;
			printf("match: %d\n", i );
		}
	}
	printf("sum is : %d\n", sum);

	return 0;
}
