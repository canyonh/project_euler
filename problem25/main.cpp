#include <cstdio>
#include <algorithm>
#include <cassert>
#include <memory.h>

// constants
int kLength = 1024;

//index 0 is digit 0
int Add(int* lhs, int* rhs, int *result, int cnt = kLength)
{
	int carry = 0;
	int i;
	int digits = 0;
	for (i = 0; i < cnt - 1; ++i)
	{
		carry += lhs[i] + rhs[i];
		result[i] = carry % 10;
		carry /= 10;
		if (result[i] != 0)
			digits = i;
	}
	return digits;
}

void Print(int* num, int cnt = kLength)
{
	bool leading_zero = true;
	for (int i = cnt - 1; i >= 0; --i)
	{
		if (leading_zero && num[i] == 0)
			continue;
		else
			leading_zero = false;

		//printf("%d", num[i]);
	}
	//printf("\n");
}
int Calculate(int max_digits)
{
	int buf1[kLength];
	int buf2[kLength];
	int buf3[kLength];
	memset(buf1, 0, sizeof(buf1));
	buf1[0] = 1;
	memset(buf2, 0, sizeof(buf2));
	buf2[0] = 1;
	memset(buf3, 0, sizeof(buf3));

	int* lhs = buf1;
	int* rhs = buf2;
	int* result = buf3;

	// calculate fib
	int digits = 0;
	int n = 3;
	while (true)
	{
		// lhs : f(n-1) rhs: f(n-2)
		digits = Add(lhs, rhs, result) + 1;

		//printf("n = %d, digits: %d, fn=", n, digits);
		//Print(result);
		//printf("\n");

		if (digits > max_digits)
			return n;

		// result: f(n)
		std::swap(lhs, result);
		std::swap(result, rhs);
		memset(result, 0, sizeof(int) * kLength);
		++n;
	}
}

int main(int argc, char* argv[])
{
	printf("%d\n", Calculate(1000));
	return 0;
}
