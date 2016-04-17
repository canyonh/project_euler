#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#include <memory.h>
#include <cerrno>
#include <vector>

struct Entry
{
	Entry(const char* start_in, size_t length_in, int score_in, uint64_t key_in)
	: start(start_in), length(length_in), score(score_in), key(key_in)
	 {}
	const char* start;
	size_t length;
	unsigned int score;
	uint64_t key;
};

int LoadFile(const char* filename, char** buffer)
{
	FILE *file = fopen("p022_names.txt", "r");
	if (file == NULL)
	{
		fprintf(stderr, "read file failed, %d\n", (int)errno);
		return -1;
	}

	fseek(file, 0L, SEEK_END);
	long size = ftell(file);
	fseek(file, 0L, SEEK_SET);
	*buffer = new char[size + 1];
	memset(*buffer, 0, size + 1);
	size_t size_read = fread(*buffer, sizeof(char), size, file);
	if (size_read != size)
	{
		fprintf(stderr, "size %d expected, got %d\n", (int)size, (int)size_read);
		return -1;
	}
	fclose(file);
	return 0;
}

void Parse(char* buffer_in, std::vector<Entry>& entries_in)
{
	char* start = buffer_in + 1;
	char* end = start;
	size_t max_length = 0;
	while (true)
	{
		while (*end != '\"')
			++end;

		size_t length = end - start;
		unsigned int score = 0;
		uint64_t key = 0;
		for (size_t i = 0; i < length; ++i)
		{
			char c = *(start + i) - 'A' + 1;
			assert(c >= 1 && c <= 26);
			score += c;
			key |= ((uint64_t)c << (64 - (i + 1) * 5));
		}
		max_length = max_length > length ? max_length : length;	
		entries_in.push_back(Entry(start, end - start, score, key));

		*end = '\0';
		if (*(end + 1) == '\0')
			return;

		end += 3;
		start = end;
	}
}

int EntryCompare(const void* lhs, const void* rhs)
{
	const Entry* lhs_entry = reinterpret_cast<const Entry*>(lhs);
	const Entry* rhs_entry = reinterpret_cast<const Entry*>(rhs);

	if (lhs_entry->key > rhs_entry->key)
		return 1;
	else if (lhs_entry->key < rhs_entry->key)
		return -1;
	else
		return 0;
}

void Sort(Entry* begin, unsigned int cnt)
{
	qsort(begin, cnt, sizeof(Entry), EntryCompare);
}

int main(int argc, char* argv[])
{
	char* buffer = NULL;
	if (LoadFile("p022_names.txt", &buffer) != 0)
		return -1;

	std::vector<Entry> entries;
	Parse(buffer, entries);

	Sort(&entries[0], entries.size());

	uint64_t sum = 0;
	for (size_t i = 0; i < entries.size(); ++i)
		sum += (entries[i].score * (i + 1));

	printf("answer: %llu\n", sum);

	if (buffer != NULL)
		delete [] buffer;
	return 0;
}

