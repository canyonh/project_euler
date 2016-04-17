#include <cstdio>
#include <vector>

std::vector< std::vector<int> > results;
std::vector<int> tmp;

void combi(int to_choose, int* elements, int cnt, std::vector<int>& sol)
{
	if (to_choose <= 0 || cnt <= 0 || to_choose > cnt)
	{
		results.push_back(sol);
		sol.clear();
		return;
	}

	tmp.push_back(elements[cnt - 1]);
	combi(to_choose - 1, elements, cnt - 1);
   	combi(to_choose, elements, cnt - 1);
}

int main(int argc, char* argv[])
{
	int digits[] = {1, 2, 3, 4};

	tmp.clear();
	combi(3, digits, sizeof(digits) / sizeof (digits[0]));
	for (int i = 0; i < results.size(); ++i)
	{
		for (int j = 0; j < results[i].size(); ++j)
			printf("%d ", results[i][j]);

		printf("\n");
	}
}
	
