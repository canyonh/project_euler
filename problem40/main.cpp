#include <cstdio>
#include <vector>

struct TableEntry
{
	TableEntry(int num_length_in, int table_start_in, int num_count_in)
		:	num_length(num_length_in)
		,	table_start(table_start_in)
		,	num_count(num_count_in)
	{}
	int num_length;
	int table_start;
	int num_count;
};

std::vector<TableEntry> table;

void GenTable(int n)
{
	int i = 0; // iteration
	int total_digits = 0;
	int pow = 1;

	while (total_digits <= n)
	{
		int sub_sum = pow * 9 * (i + 1);
		total_digits += sub_sum;
		table.push_back(TableEntry(i + 1, pow, sub_sum));
		TableEntry& entry = table.back();
		pow *= 10;
		++i;
	}
}

int Power10(int power)
{ 
	int pow = 1;
	for (int i = 0; i < power; ++i)
		pow *= 10;

	return pow;
}

int FindDigits(int n_in)
{
	int n = n_in;
	int i = 0;

	for (; i < table.size(); ++i)
	{
		if (n >= table[i].num_count)
			n -= table[i].num_count;
		else
			break;
	}
	int val = (n - 1) / table[i].num_length + table[i].table_start;
	int digits = table[i].num_length - ((n - 1) % table[i].num_length) - 1;

	int left = val;
	int answer = left % 10;
	for (int j = 0; j < digits; ++j)
	{
		left /= 10;
		answer = left % 10;
	}

	return answer;
}

int main(int argc, char* argv[])
{
	GenTable(1000000);
	int answer = FindDigits(1) * FindDigits(10) * FindDigits(100) * FindDigits(1000) * FindDigits(10000) * FindDigits(100000) * FindDigits(1000000);
	printf("answer: %d\n", answer);
	return 0;
}
