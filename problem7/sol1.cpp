#include <vector>
#include <math.h>
#include "../util.h"

int main()
{
	unsigned int max = 10001;
	std::vector<unsigned int> primes(1, 2);

	unsigned int i = 3;
	unsigned int primes_cnt;

	uint64_t start = GetRelativeWaitTime();

	while ((primes_cnt = primes.size()) < max)
	{
		unsigned int bound = (unsigned int) sqrt(i); 
		
		bool is_composite = false;
		for (size_t j = 0; j < primes_cnt; ++j)
		{
			unsigned int prime = primes[j];
			if (prime > bound)
				break;

			if (i % prime == 0)
			{
				is_composite = true;
				break;
			}
		}

		if (!is_composite)
			primes.push_back(i);

		i += 2;
	}

	uint64_t end = GetRelativeWaitTime();
	printf("time: %llu, answer: %u\n", end - start, primes.back());
	return 0;
}	
