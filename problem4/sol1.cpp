#include "../util.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
bool IsPalindrome(unsigned int k)
{
	char buf[256];
	memset(buf, 0, sizeof buf);

	snprintf(buf, sizeof(buf), "%u", k);
	unsigned int size = strlen(buf);
	for (unsigned int i = 0; i < size / 2; ++i)
	{
		if (buf[i] != buf[size - i - 1])
			return false;
	}
	return true;
}
int main(int argc, char* argv[])
{
	unsigned int answer = 0;
	uint64_t start = GetRelativeWaitTime();

	for (unsigned int i = 100; i < 1000; ++i)
	{
		for (unsigned int j = 100; j < 1000; ++j)
		{
			unsigned int k = i * j;
			if (IsPalindrome(k) && k > answer)
				answer = k;
		}
	}
	uint64_t end = GetRelativeWaitTime();
	printf("time: %llu, answer: %u\n", end - start, answer);
	return 0;
}
