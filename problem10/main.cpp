#include <stdio.h>
#include <vector>
#include <math.h>
#include "../util.h"

int main(int argc, char* argv[])
{
	uint64_t start = GetRelativeWaitTime();
	uint64_t answer = 2;

	std::vector<uint64_t> primes;
	primes.push_back(2);

	uint64_t max = 2000000;

	for (uint64_t i = 3; i < max; i += 2)
	{
		bool is_prime = true;
		uint64_t bound = sqrt(i);
		for (uint64_t j = 0; j < primes.size(); ++j)
		{
			if (primes[j] > bound)
			break;

			if (i % primes[j] == 0)
			{
				is_prime = false;
				break;
			}
		}

		if (is_prime)
		{
			primes.push_back(i);
			answer += i;
		}
	}
	uint64_t end = GetRelativeWaitTime();
	printf("answer is : %llu, time: %llu\n", answer, end - start);
	return 0;
}
