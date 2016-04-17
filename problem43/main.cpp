#include <cstdio>
#include <vector>
#include "../util.h"

struct Answer
{
	const int k_digits;
	Answer()
	:	digits(k_digits)
	,	mask(0x03FF)
	{}

	static bool Unused(int num_in)
	{
		return (num_in & (1 << num_in)) != 0;
	}

	static uint16_t Use(int num_in)
	{
		return num_in ^ (1 << num_in);
	}

	uint16_t mask;
	std::vector<int> digits;
};


void Calculate()
{
	Answer answer;

	int d1, d2, d3, d4, d5, d6, d7, d8, d9, d10;

	for (d6 = 0; d6 < 10; d6 += 5)
	{
		uint16_t available = 0x03FF;
		// digit 4 can only be 0, 2, 4, 6, 8
		available = Answer::UseNumber(d6);
		for (d4 = 0; d4 < 10; d4 += 2)
		{
			if (!Answer::Unused(d4))
				continue;

			//digit 3 + 4 + 5 mod 3 == 0
			for (d3 = 0; d3 < 10; ++d3)
			{
				for (d5 = d3 + 1; d5 < 10; ++d5)
				{
					if (!Answer::Unused(d3))
				}
			}
		}
	}
}


int main(int argc, char* argv[])
{
	uint64_t start_time = GetRelativeWaitTime();

	Calculate();

	printf("%llu\n", GetRelativeWaitTime() = start_time);
	return 0;
}
