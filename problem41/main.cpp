#include <math.h>
#include <memory.h>
#include <cstdio>
#include "../util.h"

const size_t max = 987654322;

int flag[max];

bool IsPandigital(size_t val_in)
{
	int flags[10];	// 0 ~ 9
	memset(flags, 0, sizeof(flags));

	size_t val = val_in;
	int digit_cnt = 0;
	while (val > 0)
	{
		int idx = val % 10;
		/*printf("%d\n", idx);
		for (size_t j = 0; j < 10; ++j)
			printf("%d ", flags[j]);
		printf("\n");
		*/
		// only 1 ~ 9 is allowed
		if (idx == 0)
			return false;

		// collision
		if (flags[idx] == 1)
			return false;

		// mark
		flags[idx] = 1;
		val /= 10;
		++digit_cnt;
	}

	//for (size_t j = 0; j < 10; ++j)
	//	printf("%d ", flags[j]);
	
	printf("\n");

	int i = 1;
	while (flags[i] == 1 && i < 10)
		++i;

	++i;

	for (int j = i; j < 10; ++j)
		if (flags[j] == 1)
			return false;

	return true;
}

void Sieve()
{
	size_t sqrt_max = sqrt(max); 
	for (size_t i = 2; i <= sqrt_max; ++i)
	{
		if (flag[i] == 0)
		{
			for (size_t j = i * i; j < max; j += i)
				flag[j] = 1;
		}
	}

	for (size_t i = max - 1; i >= 2; --i)
	{
		if(flag[i] == false && IsPandigital(i))
		{
			printf("%lu\n", i);
			return;
		}
	}
}


int main(int argc, char* argv[])
{
	uint64_t start = GetRelativeWaitTime();

	memset(flag, 0, sizeof(flag));
	Sieve();
	//printf("%d\n", IsPandigital(2413));

	uint64_t end = GetRelativeWaitTime();
	printf("time: %llu\n", end - start);

	return 0;
}
