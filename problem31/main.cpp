#include <cstdio>

int table[201][201];

int CoinSum(int total, int*s, int s_cnt)
{
	if (s_cnt <= 0 || total <0)
		return 0;

	if (total == 0)
		return 1;
		
	int left = 0;
	if (s_cnt - 1 >= 0 && total - s[s_cnt - 1] >= 0)
		left = table[total - s[s_cnt - 1]][s_cnt] == -1 ? CoinSum(total - s[s_cnt - 1], s, s_cnt) : table[total - s[s_cnt - 1]][s_cnt];
	
	int right = 0;
	if (s_cnt - 1 >= 0)
		right = table[total][s_cnt - 1] == -1 ? CoinSum(total, s, s_cnt - 1) : table[total][s_cnt - 1];

	table[total][s_cnt] = left + right;
	return left + right;
}


int main(int argc, char* argv[])
{
	int s[] = {1, 2, 5, 10, 20, 50, 100, 200};
	for (int i = 0; i < 201; ++i)
		for (int j = 0; j < 201;++j)
			table[i][j] = -1;

	printf("%d\n", CoinSum(200, s, sizeof(s) / sizeof(s[0])));

	return 0;
}
