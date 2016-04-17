#include "../util.h"
#include <algorithm>

uint64_t i = 3;

uint64_t AttemptDivide(uint64_t n)
{
	for (; i <  n / 2; i += 2)
	{
		if (n % i == 0)
		{
			while (n % i == 0)
				n /=  i;

			return AttemptDivide(n);
		}
	}
	return n;
}

int main(int argc, char* argv[])
{
	uint64_t question = 600851475143;

	uint64_t answer = 0;

	while (question % 2 == 0)
	{
		question /= 2;
		answer = 2;
	}

	answer = AttemptDivide(question);
	printf("answer: %llu\n", answer);
	return 0;
}

