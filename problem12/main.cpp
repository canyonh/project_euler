#include <cstdio>
#include <cmath>

uint64_t DivisorCnt(uint64_t num_in)
{
	uint64_t num = num_in;
	uint64_t divisor_cnt = 1; // 1

	while (num_in % 2 == 0)
	{
		++divisor_cnt;
		num_in /= 2;
	}

	for (uint64_t i = 3; i < sqrt(num); i += 2)
	{
		uint64_t divisor_tmp = 0;
		while (num_in % i == 0)
		{
			++divisor_tmp;
			num_in /= i;
		}
		if (divisor_tmp > 0)
			divisor_cnt *= (divisor_tmp + 1);
	}
	return divisor_cnt;
}

int main(int argc, char*argv[])
{
	uint64_t i = 1;
	uint64_t divisor_cnt;
	uint64_t sum;
	do 
	{
		sum = i * (i+1) / 2;
		divisor_cnt = DivisorCnt(sum);
		printf("i = %llu, sum: %llu, divisor cnt: %llu\n", i, sum, divisor_cnt);
		++i;
	}
	while (divisor_cnt  < 500);
	printf("answer: %lld\n", sum);	
	return 0;
}
