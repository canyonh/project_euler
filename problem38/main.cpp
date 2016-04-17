#include <cstdio>
#include <vector>

bool IsPandigital(int val_in)
{
	const int k_base = 10;
	std::vector<int> flags(k_base, 0);	
	
	int val = val_in;
	while (val > 0)
	{
		int mod = val % k_base;

		if (mod == 0 || flags[mod] == 1)
			return false;

		flags[mod] = 1;
		val /= k_base;
	}

	for (int i = 1; i < k_base; ++i)
		if (flags[i] == 0)
			return false;

	return true;
}

void Calculate()
{
	int max = 0;
	int panval = 0;
	for (int i = 9000; i <= 9999; ++i)
	{
		int result = i * 100000 + i * 2;
		printf("%d\n", result);
		if (!IsPandigital(result))
			continue;

		if (max <= i)
		{
			max = i;
			panval = result;
		}
	}	
	printf("max = %d, pan val = %d\n", max, panval);
}

int main(int argc, char* argv[])
{
	Calculate();
	return 0;
}
