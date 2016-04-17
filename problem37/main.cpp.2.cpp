#include <cstdio>
#include <vector>
#include <cmath>

bool IsPrime(int num)
{
	int sqrt_num = sqrt(num);

	if (num % 2 == 0) 
		return false;

	for (int i = 3; i <= sqrt_num; i += 2)
	{
		if (num % i == 0)
			return false;
	}

	return true;
}

int WhatPowOf10(int val)
{
	int tmp = val;
	int pow = 0;
	while (tmp > 0)
	{
		tmp /= 10;
		++pow;
	}
	return pow;
}


int RaisePower(int power)
{
	int result = 1;
	for (int i = 0; i < power; ++i)
	{
		result *= 10;
	}
	return result;
}


bool Test(int num)
{
	//printf("testing %d\n", num);
	int now = num;
	int digit_cnt = 0;

	while (now > 0)
	{
		//printf("%d\n", now);
		if (!IsPrime(now))
			return false;
		now /= 10;
		++digit_cnt;
	}

	//reverse digit
	now = num;
	while (now > 0)
	{
		//printf("%d\n", now);
		if (!IsPrime(now))
			return false;

		now %= RaisePower(digit_cnt - 1);
		--digit_cnt;
	}
	printf("found %d\n", num);
	return true;
}

void Calculate(int max_cnt)
{
	std::vector<int> answer;
	answer.push_back(37);
	answer.push_back(73);

	int counter = 0;
	int sum = 0;
	int to_test;
	int power = 100;

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
		power = RaisePower(WhatPowOf10(counter) + 1);
	}


	for (int i = 0; i < answer.size(); ++i)
		printf("%d ", answer[i]);

	printf("\n sum = %d\n", sum);
}

int main(int argc, char* argv[])
{
	//IsPrime(3797);
	//Test(3797);

	Calculate(11);
	return 0;
}
