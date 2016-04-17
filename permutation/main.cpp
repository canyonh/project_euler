#include <cstdio>
#include <algorithm>

void Callback(int *src, size_t length)
{
	for (size_t i = 0; i < length; ++i)
		printf("%d", src[i]);
	
	printf("\n");
}

void Permu(int *src, size_t start, size_t end)
{
	if (start == end)
	{
		Callback(src, end + 1);
		return;
	}

	for (size_t i = start; i <= end; ++i)
	{
		std::swap(src[start], src[i]);
		Permu(src, start + 1, end);
		std::swap(src[start], src[i]);
	}
}



int main(int argc, char* argv[])
{
	int val[] = {1, 2, 3};
	Permu(val, 0, sizeof(val) / sizeof(val[0]) - 1);
	return 0;
}
