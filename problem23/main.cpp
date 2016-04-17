#include <cstdio>
#include <math.h>
#include <set>

unsigned int FindSumOfDivisors(unsigned int n)
{
	unsigned int sum = 1;
	//printf("n = %u: 1 ", n);

	unsigned int max = sqrt(n);
	if (n % 2 != 0)
	{
		for (unsigned int i = 3; i < max + 1; i += 2)
		{
			if (n % i == 0)
			{
				unsigned int reminder = n / i;
				sum += i;
				//printf("%u ", i);
				if (i != reminder)
				{
					sum += reminder;
					//printf("%u ", reminder);
				}
			}	
		}
	}
	else
	{
		for (unsigned int i = 2; i < max + 1; ++i)
		{
			if (n % i == 0)
			{
				unsigned int reminder = n / i;
				sum += i;
				//printf("%u ", i);
				if (i != reminder)
				{
					sum += reminder;
					//printf("%u ", reminder);
				}
			}	
		}
	}
//	printf(" sum = %u\n", sum);
	return sum;
}


void FindAbundant(std::set<unsigned int>& abundant)
{
	for (unsigned int i = 12; i <= 28123; ++i)
	{
		unsigned int sum = FindSumOfDivisors(i);
		if (sum > i)
			abundant.insert(i);
	}
}


int main(int argc, char* argv[])
{
	std::set<unsigned int> abundant;
	FindAbundant(abundant);

	/*
	for (auto it = abundant.begin(); it != abundant.end(); ++it)
	{
		printf("%u ", *it);
	}
	printf("size: %lu\n", abundant.size());
	*/
	unsigned int sum = 0;
	for (unsigned int i = 1; i <= 28123; ++i)
	{
		bool found = true;
		for (auto it = abundant.begin(); it != abundant.end(); ++it)
		{
			unsigned int j;
			unsigned int reminder;
			j = *it;
			if (j >= i)
				continue;

			reminder = i - j;
			if (abundant.find(reminder) != abundant.end())
			{
				//printf("(x): %u = (%u + %u)\n", i, j, reminder);
				found = false;
				break;
			}
		}

		if (found)
		{
			sum += i;
			//printf("(o): %u, sum = %u\n", i, sum);
		}
	}

	printf("\nSum = %u\n", sum);
}
