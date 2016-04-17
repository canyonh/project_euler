#include <stdio.h>

int main(int argc, char* argv[])
{
	int result = 0;

	unsigned int prev = 1;
	unsigned int now = 2;
	unsigned int sum = 2;
	while (now <= 4000000)
	{
		unsigned int next = now + prev;
		prev = now;
		now = next;
		if (now % 2 == 0)
			sum += now;
	}

	printf("%d\n", sum);
	return 0;
}
