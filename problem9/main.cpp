#include <stdio.h>

int main(int argc, char* argv[])
{
	for (unsigned int a = 1; a < 1000; ++a)
	{
		unsigned int reminder = 1000 - a;
		for (unsigned int b = 1; b < reminder / 2; ++b)
		{
			unsigned int c = reminder - b;
			if (a * a + b * b == c * c)
			{
				printf("answer: a: %u, b: %u, c: %u, abc = %u\n", a, b, c, a * b * c);
				return 0;
			}
		}
	}
	return 0;
}
