#include "../util.h"
#include <set>

uint64_t answer = 0;

std::set<uint64_t> primes;
bool IsPrime(uint64_t n)
{
	if (n == 2) return true;

	if (primes.find(n) != primes.end())
		return true;

	for (uint64_t i = 3; i < n / 2; i += 2)
	{
		if (n % i == 0)
			return false;
	}

	primes.insert(n);
	return true;
}

void factor(uint64_t n)
{
	printf("factor: %llu\n", n);
	if (n <= 2)
		return;

	for (uint64_t i = 3; i < n / 2; i += 2)
	{
		if (n % i == 0)
		{
			if (IsPrime(i))
			{
				if (answer < i) answer = i;
			}
			if (IsPrime(n / i))
			{
				if (answer < (n / i)) answer = n / i;
			}
			factor(n / i);
			factor(i);
			return;
		}
	}
}

int main(int argc, char* argv[])
{
	uint64_t start = GetRelativeWaitTime();

	uint64_t question = 600851475143;

	factor(question);

	uint64_t end = GetRelativeWaitTime();
	printf("time: %llu, answer: %llu\n", end - start, answer);
	return 0;
}
