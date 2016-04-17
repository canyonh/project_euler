#include <cassert>
#include <cstdio>
#include <set>
#include <vector>

const int fact[] = 
{
	9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1,
	8 * 7 * 6 * 5 * 4 * 3 * 2 * 1,
	7 * 6 * 5 * 4 * 3 * 2 * 1,
	6 * 5 * 4 * 3 * 2 * 1,
	5 * 4 * 3 * 2 * 1,
	4 * 3 * 2 * 1,
	3 * 2 * 1,
	2 * 1,
	1,
	1
};

void LexiOrder(int digit_cnt, int permu, int *result)
{
	std::vector<int> digits_left;
	for (int i = 0; i < digit_cnt; ++i)
		digits_left.push_back(i);

	int permu_left = permu;

	for (int i = 0; i < digit_cnt; ++i)
	{
		int iter_cnt = fact[i];

		int digit = 0;
		digit = permu_left / iter_cnt;
		permu_left = permu_left % iter_cnt;
		result[i] = digits_left[digit];
		digits_left.erase(digits_left.begin() + digit);

		printf("permu_left: %d, iter_cnt: %d, quotient:%d, digit:%d\n", permu_left, iter_cnt, digit, result[i]);
	}
	//assert(digits_left.size() == 1);
	//result[digit_cnt - 1] = digits_left[0];
}

int main(int argc, char*argv[])
{
	const int kDigits = 10;
	int array[kDigits];
	LexiOrder(kDigits, 999999, array);

	for (size_t i = 0; i < kDigits; ++i)
		printf("%d \n", array[i]);
	return 0;
}

