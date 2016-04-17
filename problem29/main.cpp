#include <cstdio>
#include <vector>
#include <set>
#include <cassert>

void PrimeSieve(int max, std::vector<int>& primes)
{
	std::vector<int> marked(max, 0);

	for (int i = 2; i < max; ++i)
	{
		if (marked[i] == 0)
			primes.push_back(i);

		int multiplier = 2;
		int now = i;
		while ( (now = i * multiplier) < max)
		{
			marked[now] = 1;
			++multiplier;
		}
	}
}

void PrimeFactorize(int question, const std::vector<int> primes, std::vector<int>& result)
{
	if (question < 2)
		return;

	int primes_cnt = primes.size();
	int left = question;
	for (int i = 0; i < primes_cnt && left != 0; ++i)
	{
		int power = 0;
		while (left % primes[i] == 0)
		{
			++power;
			left /= primes[i];
		}

		if (power != 0)
		{
			result.push_back(primes[i]);
			result.push_back(power);
		}
	}
}

int main(int argc, char* argv[])
{
	const unsigned max = 100;

	std::vector<int> primes;
	PrimeSieve(max, primes);

	std::set<std::vector<int>> result;

	for (int i = 2; i <= 100; ++i)
	{
		std::vector<int> factored;
		PrimeFactorize(i, primes, factored);
		for (int j = 2; j <= 100; ++j)
		{
			std::vector<int> powered(factored);
			for (int k = 1; k < powered.size(); k += 2)
				powered[k] *= j;

			result.insert(powered);
		}
	}

	printf("answer: %d\n", (int)result.size());
	return 0;
}
