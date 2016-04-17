#include <cstdio>
#include <set>
#include <cassert>
#include <cmath>

const int max = 1000000;
std::set<int> primes;

void Sieve()
{
	int total[max];
	memset(total, 0, sizeof(total));

	int bound = sqrt(max);
	for (int i = 2; i <= bound;  ++i)
	{
		if (total[i] == 1)
			continue;

		for (int j = i * i; j <= max; j += i)
			total[j] = 1;
	}

	for (int i = 2; i < max; ++i)
	{
		if (total[i] == 0)
		{
			//printf("%d ", i);
			// don't need to test the msd
			int now = i / 10;

			// check if each digit can be divided by 0
			bool skip = false;
			while (now > 0)
			{
				if (now % 2 == 0)
				{
					skip = true;
					break;
				}
				now /= 10;
			}

			if (!skip)
				primes.insert(i);
		}
	}
}

void Filter()
{
	std::set<int> answer;
	int cnt = primes.size();
	for (auto i = primes.begin(); i != primes.end(); ++i)
	{
		assert(*i >= 2);

		int digits = 0;
		{
			int now = *i;
			while (now > 0)
			{
				now /= 10;
				++digits;
			}
		}

		// no permutation needed if digit count is less than 2
		if (digits >= 2)
		{
			bool match = true;
			int permu_now = *i;

			for (int j = 0; j < digits - 1; ++j)
			{
				int msd = permu_now % 10;

				if (msd == 0)
					break;

				permu_now /= 10;

				for (int k = 0; k < digits - 1; ++k)
					msd *= 10;

				permu_now += msd;
				if (primes.find(permu_now) == primes.end())
				{
					match = false;
					break;
				}
			}
			if (match)
				answer.insert(permu_now);
		}
		else
		{
			answer.insert(*i);
		}
	}
	printf("answer: %d\n", (int)answer.size());
}

int main(int argc, char* argv[])
{
	Sieve();
	Filter();
	return 0;
}

