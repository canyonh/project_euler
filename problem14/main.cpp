#include <cstdio>

uint64_t Calculate(uint64_t start)
{
	uint64_t n = start;
	uint64_t length = 0;

	while (n != 1)
	{
		if (n % 2 == 0)
			n /= 2;
		else
			n = 3 * n + 1;
		++length;
	}
	return length;
}

int main(int argc, char* argv[])
{
	uint64_t answer = 0;
	uint64_t occurred_at = 0;
	for (uint64_t i = 1; i <= 1000000; ++i)
	{
		uint64_t tmp = Calculate(i);
		printf("%llu: %llu\n", i, tmp);
		if (tmp > answer)
		{
			answer = tmp;
			occurred_at = i;
		}
	}
	printf("%llu@%llu\n", answer, occurred_at);
	return 0;
}
