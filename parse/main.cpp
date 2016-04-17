#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

void Parse(char* src, std::vector<const char*>& result)
{
	char* start = src;
	while (*start != '\0')
	{
		char* now = start;
		while (*now != ' ' && *now != '\0')
			++now;

		*now = '\0';
		result.push_back(start);
		start = now;
	}
}

int main(int argc, char* argv[])
{
	std::vector<const char*> result;

	char sample[] = "abc daslnl 2ddn232 12dm12313nc 2s2w";
	Parse(sample, result);
	std::for_each(std::begin(result), std::end(result), [](const char* str) { printf("%s\n", str); });

	return 0;
}
