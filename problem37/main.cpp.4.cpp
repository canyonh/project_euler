#include <cstdio>
#include <vector>
#include <cmath>

int Power10(int pow)
{
	int val = 1;
	for (int i = 0; i < pow; ++i)
	{
		val *= 10;
	}
	return val;
}

bool IsPrime(int num)
{
	int sqrt_num = sqrt(num);

	if (num < 2)
		return false;

	if (num == 2)
		return true;

	if (num % 2 == 0) 
		return false;

	for (int i = 3; i <= sqrt_num; i += 2)
	{
		if (num % i == 0)
			return false;
	}

	return true;
}

bool Test(int num)
{
	printf("testing %d\n", num);
	int now = num;
	int digit_cnt = 0;

	while (now > 0)
	{
		printf("%d\n", now);
		if (!IsPrime(now))
			return false;
		now /= 10;
		++digit_cnt;
	}

	//reverse digit
	now = num;
	while (now > 0)
	{
		printf("%d\n", now);
		if (!IsPrime(now))
			return false;

		now %= Power10(digit_cnt - 1);
		--digit_cnt;
	}
	printf("found %d\n", num);
	return true;
}

std::vector<int> Calculate(int max_cnt)
{
	std::vector<int> double_sided;
	double_sided.push_back(2);
	double_sided.push_back(3);
	double_sided.push_back(5);
	double_sided.push_back(7);

	std::vector<int> possible_digits;
	possible_digits.push_back(1);
	possible_digits.push_back(3);
	possible_digits.push_back(7);
	possible_digits.push_back(9);

	int i;
	for (int i = 0; i < double_sided.size(); ++i)
	{
		printf("i[%d] = %d\n", i, double_sided[i]);
		for (int j = 0; j < possible_digits.size(); ++j)
		{
			int to_test = double_sided[i];
			to_test = to_test * 10 + possible_digits[j];
			printf("testing %d\n", to_test);
			if (Test(to_test))
			{
				double_sided.push_back(to_test);
				if (double_sided.size() > max_cnt)
				{
					return double_sided;
				}
			}
		}
	}
	return double_sided;
}

int main(int argc, char* argv[])
{
	//IsPrime(3797);
	//Test(73);

	int sum = 0;
	std::vector<int> answer = Calculate(15);
	for (int i = 0; i < answer.size(); ++i)
	{
		if (answer[i] >= 10)
		{
			printf("%d ", answer[i]);
			sum += answer[i];
		}
	}

	printf("\n sum = %d\n", sum);
	return 0;
}
