#include <stdio.h>
#include <vector>
#include <cassert>

std::vector<int> primes;

void PrimeSieve(int max, std::vector<int>& primes)
{
	std::vector<int> all(max, 0);

	for (int i = 2; i < max; ++i)
	{
		while (all[i] == 1) // marked
			++i;

		primes.push_back(i);

		int p = 2;
		int now;
		while ((now = p * i) < max)
		{
			all[now] = 1;
			++p;
		}
	}
}

/*
bool IsPrime(int target, int* primes, int cnt)
{
	if (cnt == 0)
		return false;

	int mid = cnt / 2;
	if (primes[mid] == target)
	{
		return true;
	}
	else if (primes[mid] < target)
	{
		int new_cnt = mid;
		if (new_cnt > 0)
			return IsPrime(target, primes, new_cnt);
		else
			return false;
	}
	else
	{
		assert(primes[mid] > target);
		int new_cnt = cnt - (mid + 1);
		if (new_cnt  > 0)
			return IsPrime(target, primes + mid + 1, new_cnt);
		else
			return false;
	}
}
*/
bool IsPrime(int target, int* primes, int cnt)
{
	for (int i = 0; i < cnt; ++i)
	{
		//printf("testing i: %d val: %d target: %d\n", i, primes[i], target);
		if (primes[i] == target)
			return true;
	}

	return false;
}

int Calculate(int a, int b)
{
	if (a + b < 2)
		return 0;

	// 0 and 1 are checked already
	int n = 0;
	bool is_prime = true;
	while (is_prime)
	{
		int fx = n * n + a * n + b;
		is_prime = IsPrime(fx, &primes[0], primes.size());
		if (!is_prime)
			return n;
		
		++n;
	}
	assert(!"unreachable");
	return n;
}


int main(int argc, char* argv[])
{
	const int max = 100000;

	PrimeSieve(max, primes);
	//for (int i = 0; i < primes.size(); ++i)
	//	printf("%d: isprime: %d\n", primes[i], IsPrime(primes[i], &primes[0], primes.size()));

	int num_of_primes = 0;
	int a_at_max = 0;
	int b_at_max = 0;

	for (int i = 0; i < primes.size(); ++i)
	{
		int b = primes[i];
		if (b >= 1000)
			break;

		for (int a = -1000; a <= 1000; ++a)
		{
			if (IsPrime(1 + a + b, &primes[0], primes.size()))
			{
				int result = Calculate(a, b);
//				printf("a: %d, b: %d, n: %d\n", a, b, result);
				if (result > num_of_primes)
				{
					num_of_primes = result;
					a_at_max = a;
					b_at_max = b;
				}
			}
		}
	}
	printf("answer: a:%d, b:%d, n:%d\n", a_at_max, b_at_max, num_of_primes);
	return 0;
}
