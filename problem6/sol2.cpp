#include "../util.h"

int main(int argc, char* argv[])
{
	uint64_t start = GetRelativeWaitTime();

	long square_of_sum = ((100 + 1) * 100 / 2);
	square_of_sum *= square_of_sum;

	long sum_of_square = 100 * (100 + 1) * (2 * 100 + 1) / 6;

	uint64_t end = GetRelativeWaitTime();

	printf("time: %llu, answer: %ld\n", end - start, square_of_sum - sum_of_square);

	return 0;
}
