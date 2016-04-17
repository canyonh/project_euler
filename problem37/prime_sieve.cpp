#include <cstdio>
#include <vector>
#include <cmath>

void PrimeSieve(int max)
{
	std::vector<int> is_prime(max, 1);

	int square_max = sqrt(max);

	for (int i = 2; i <= square_max; ++i)
	{
		for (int j = i * i; j < max; j += i)
			is_prime[j] = 0;
	}

	for (int i = 2; i < is_prime.size(); ++i)
	{
		if (is_prime[i])
			printf("%d ", i);
	}

	printf("\n");
}

int main(int argc, char* argv[])
{
	PrimeSieve(1000);
	return 0;
}
	
