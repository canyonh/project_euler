#include <cstdio>
#include <vector>
#include <cmath>

void PrimeSieve(uint64_t max, std::vector< std::vector<uint64_t> >& primes)
{
	std::vector<int> is_prime(max, 1);

	uint64_t square_max = sqrt(max);

	for (uint64_t i = 2; i <= square_max; ++i)
	{
		for (uint64_t j = i * i; j < max; j += i)
			is_prime[j] = 0;
	}

	uint64_t digit_limit = 10;
	std::vector<uint64_t> primes_current;
	for (uint64_t i = 2; i < max; ++i)
	{
		if (is_prime[i])
		{
			if (i >= digit_limit)
			{
				primes.push_back(std::move(primes_current));
				primes_current.clear();
				primes_current.push_back(i);
				digit_limit *= 10;
			}
			else
			{
				primes_current.push_back(i);
			}
		}
	}
	primes.push_back(std::move(primes_current));
}

bool IsPrime(uint64_t num)
{
	uint64_t sqrt_num = sqrt(num);

	if (num == 2)
		return true;

	if (num % 2 == 0) 
		return false;

	for (uint64_t i = 3; i <= sqrt_num; i += 2)
	{
		if (num % i == 0)
			return false;
	}

	return true;
}

uint64_t WhatPowOf10(uint64_t val)
{
	uint64_t tmp = val;
	uint64_t pow = 0;
	while (tmp > 0)
	{
		tmp /= 10;
		++pow;
	}
	return pow;
}

uint64_t Power10(uint64_t power)
{
	uint64_t result = 1;
	for (uint64_t i = 0; i < power; ++i)
	{
		result *= 10;
	}
	return result;
}


bool Test(uint64_t num)
{
	//printf("testing %llu\n", num);
	uint64_t now = num;
	uint64_t digit_cnt = 0;

	while (now > 0)
	{
		//pruint64_tf("%llu\n", now);
		if (!IsPrime(now))
			return false;
		now /= 10;
		++digit_cnt;
	}

	//reverse digit
	now = num;
	while (now > 0)
	{
		//pruint64_tf("%llu\n", now);
		if (!IsPrime(now))
			return false;

		now %= Power10(digit_cnt - 1);
		--digit_cnt;
	}
	printf("found %llu\n", num);
	return true;
}

std::vector<uint64_t> Calculate(uint64_t max_cnt)
{
	int outer_digits[] = {2, 3, 5, 7};
	int inner_digits[] = {1, 3, 7, 9};

	std::vector<uint64_t> answer;
	uint64_t counter = 0;
	while (answer.size() < max_cnt)
	{
		uint64_t inner = 0;
		
		uint64_t tmp = counter;
		uint64_t pow = 10;
		while (tmp > 0)
		{
			inner += inner_digits[tmp % 4] * pow;
			tmp /= 4;
			pow *= 10;
		}

		for (int lsd_idx = 0; lsd_idx < 4; ++lsd_idx)
		{
			for (int msd_idx = 0; msd_idx < 4; ++msd_idx)
			{
				uint64_t val = inner;
				val += outer_digits[lsd_idx];
				val += outer_digits[msd_idx] * pow;
				if (Test(val))
					answer.push_back(val);
			}
		}

		++counter;
	}
	return answer;
}

/*
void Calculate(uint64_t max_cnt)
{
	std::vector<uint64_t> answer;
	answer.push_back(37);
	answer.push_back(73);

	uint64_t counter = 0;
	uint64_t sum = 0;
	uint64_t to_test;
	uint64_t power = 100;

	while (answer.size() < max_cnt)
	{
		to_test = 3 * power + counter * 10 + 3;
		if (Test(to_test))
		{
			answer.push_back(to_test);
			sum += to_test;
		}

		to_test = 3 * power + counter * 10 + 7;
		if (Test(to_test))
		{
			answer.push_back(to_test);
			sum += to_test;
		}

		to_test = 7 * power + counter * 10 + 3;
		if (Test(to_test))
		{
			answer.push_back(to_test);
			sum += to_test;
		}

		to_test = 7 * power + counter * 10 + 7;
		if (Test(to_test))
		{
			answer.push_back(to_test);
			sum += to_test;
		}

		++counter;
		power = Power10(WhatPowOf10(counter) + 1);
	}


}
*/

void TestSieve()
{
	std::vector< std::vector<uint64_t> > primes;
	PrimeSieve(10000000, primes);
	printf("primes size: %lu\n", primes.size());
	for (uint64_t i = 0; i < primes.size(); ++i)
	{
		printf("%llu: ", i);
		for (uint64_t j = 0; j < primes[i].size(); ++j)
		{
			printf("%llu ", primes[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char* argv[])
{
	//IsPrime(3797);
	//Test(3797);

	uint64_t sum = 0;
	std::vector<uint64_t> answer = Calculate(11);
	for (uint64_t i = 0; i < answer.size(); ++i)
	{
		printf("%llu ", answer[i]);
		sum += answer[i];
	}

	printf("\n sum = %llu\n", sum);
	//TestSieve();
	return 0;
}
