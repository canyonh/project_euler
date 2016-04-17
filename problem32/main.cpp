#include <cstdio>
#include <cmath>
#include <memory.h>
#include <set>

bool Filter(int* input, int cnt, bool perfectly_once = false)
{
	int flag[9];
	memset(flag, 0, sizeof(flag));

	for (int i = 0; i < cnt; ++i)
	{
		int now = input[i];
		while (now > 0)
		{
			int digit = now % 10;
			now /= 10;

			if (digit == 0)
				return false;

			if (flag[digit - 1] == 1)
				return false;
			else
				flag[digit - 1] = 1;
		}
	}

	if (perfectly_once == true)
	{
		for (int i = 0; i < 9; ++i)
			if (flag[i] == false)
				return false;

		return true;
	}
	else
	{
		return true;
	}
}


int main(int argc, char* argv[])
{
	int lhs[3];
	memset(lhs, 0, sizeof(lhs));

	std::set<int> result;

	int sum = 0;
	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 1000; j < 9999; ++j)
		{
			lhs[0] = i;
			lhs[1] = j;

			if (!Filter(lhs, 2))
				continue;

			lhs[2] = i * j;

			if (Filter(lhs, 3, true))
			{
				printf("%d * %d = %d\n", lhs[0], lhs[1], lhs[2]);
				result.insert(lhs[2]);
			}
		}
	}

	for (int i = 10; i <= 99; ++i)
	{
		for (int j = 100; j < 999; ++j)
		{
			lhs[0] = i;
			lhs[1] = j;

			if (!Filter(lhs, 2))
				continue;

			lhs[2] = i * j;

			if (Filter(lhs, 3, true))
			{
				printf("%d * %d = %d\n", lhs[0], lhs[1], lhs[2]);
				result.insert(lhs[2]);
			}
		}
	}

	std::for_each(result.begin(), result.end(), [&sum](const int& n){ sum += n; }); 
	printf("sum = %d\n", sum);
	return 0;
}
