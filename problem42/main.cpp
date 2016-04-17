#include <cstdio>
#include <vector>
#include <cassert>
#include <unordered_set>

#include "../util.h"

void ReadData(const char* file_name_in, std::vector<char>& buffer_in)
{
	FILE* file = fopen(file_name_in, "r");
	assert(file != nullptr);

	int error;
	error = fseek(file, 0, SEEK_END);
	assert(error == 0);

	long size = ftell(file);
	assert(size > 0);

	error = fseek(file, 0, SEEK_SET);
	assert(error == 0);

	buffer_in.resize(size + 1);
	error = fread(&buffer_in[0], 1, size, file);
	assert(size > 0);

	buffer_in[size] = '\0';

	fclose(file);
}

int BreakWords(char* src, std::vector<char*>& strings)
{
	char* start = src + 1;
	char* end = start;
	int max_length = 0;
	while (true)
	{
		if (*end == '\"')
		{
			*end = '\0';
	 		strings.push_back(start);
			printf("%s\n", start);
			int length = strlen(start);
			max_length = max_length > length ? max_length : length;
			if (*(end + 1) == '\0')
				break;

			end += 3;
			start = end;
		}
		else
		{
			++end;
		}
	}
	return max_length;
}

void GenerateTriangleNumbers(std::unordered_set<int>& set_in, int max_in)
{
	int n = 1;
	int result = 1;
	while (result <= max_in)
	{
		set_in.insert(result);
		++n;
		result = n * (n + 1) / 2;
	}
}

int Calculate(const std::vector<char*>& words, const std::unordered_set<int>& triangle_numbers)
{
	size_t count = words.size();

	int answer = 0;
	for (size_t i = 0; i < count; ++i)
	{
		char* now = words[i];
		int score = 0;
		while (*now != '\0')
		{
			score += *now - 'A' + 1;
			++now;
		}
		if (triangle_numbers.find(score) != triangle_numbers.end())
			++answer;
	}
	return answer;
}


int main(int argc, char* argv[])
{
	std::vector<char> file;
	std::unordered_set<int> triangle_numbers;
	ReadData("p042_words.txt", file);

	printf("%s", &file[0]);

	std::vector<char*> strings;
	int max_length = BreakWords(&file[0], strings);
	printf("word cnt: %d, max_length: %d\n", (int)strings.size(), max_length);

	uint64_t start = GetRelativeWaitTime();
	GenerateTriangleNumbers(triangle_numbers, max_length * 26);

	int answer = Calculate(strings, triangle_numbers);

	printf("answer: %d, time: %llu\n", answer, GetRelativeWaitTime() - start);
	return 0;
}
