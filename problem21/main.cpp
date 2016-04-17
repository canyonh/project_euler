#include <map>
#include <cstdio>
#include <cassert>
#include <math.h>

unsigned int Calculate(unsigned int num)
{
	unsigned int sum = 1;
	unsigned int max = sqrt(num) + 0.5;
	for (unsigned int i = 2; i <= max; ++i)
	{
		if (num == i * i)
			sum += num/i;
		else
		{
			if (num % i == 0)
			{
				sum += i;
				sum += num / i;
			}
		}
	}
	printf("%u, %u\n", num, sum); 
	return sum;
}

int main(int argc, char* argv[])
{
	const unsigned int max = 20000;
	
	unsigned int answer = 0;
	unsigned int i = 1;

	for (unsigned int i = 1; i <= 10000; ++i) 
	{
		unsigned int sum = Calculate(i);
		if (sum > i && Calculate(sum) == i)
		{
			printf("pair: %u %u\n", i, sum);
			answer += sum;
			answer += i;
		}
	}
	printf("%u\n", answer);
	return 0;
}
