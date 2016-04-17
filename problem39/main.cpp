#include <cstdio>
#include <vector>
#include <utility>
#include <map>

const unsigned int max = 1000;
std::vector<std::pair<int, int> > squares;

void Generate()
{
	for (unsigned int i = 1; i <= 1000; ++i)
	{
		unsigned int val = i * i;
		squares.push_back(std::make_pair(i, val));
		printf("%d %d\n", i, val);
	}
	printf("\n");
}

void Calculate()
{
	std::map<int, int> result;

	unsigned int size = squares.size();
	for (int i = 0; i < size; ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			for (int k = 0; k <= j ; ++k)
			{
				int len = squares[i].first + squares[j].first + squares[k].first;
				if (len > 1000)
					continue;


				if (squares[j].second + squares[k].second == squares[i].second)
				{
					auto res = result.insert(std::make_pair(len, 0));
					++res.first->second;
					printf("(%d, %d, %d) : (%d + %d = %d), len = %d\n",
							squares[j].first,
							squares[k].first,
							squares[i].first,
							squares[j].second,
							squares[k].second,
							squares[i].second,
							squares[i].first + squares[j].first + squares[k].first);
				}
			}
		}
	}
	for (auto it = result.begin(); it != result.end(); ++it)
		printf("len: %d: count: %d\n", it->first, it->second);
}



int main(int argc, char* argv[])
{
	Generate();
	Calculate();
	return 0;
}
