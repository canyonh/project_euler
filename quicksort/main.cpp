#include <cstdio>
#include <algorithm>

//unsigned int data[] = {44, 75, 23, 43, 55, 12, 64, 77, 33};
//unsigned int data[] = {44, 75, 23, 43, 55, 12, 77, 64, 33};
unsigned int data[] = {110, 5, 10, 3, 22, 100, 1,23};

void Print(unsigned int* begin, unsigned int cnt)
{
	for (size_t i = 0; i < cnt; ++i)
		printf("%u ", begin[i]);

	printf("\n");
}
void QuickSort(unsigned int* begin, unsigned int cnt)
{
	Print(begin, cnt);
	if (cnt <= 1)
		return;

	unsigned int *last = begin + cnt - 1;

	// pivot is at cnt -1 
	std::swap(*last, *(begin + (cnt / 2)));

	unsigned int pivot = *last;
	unsigned int *left = begin;
	unsigned int *right = last - 1;

	while (left < right)
	{
		while (*left < pivot && left < last) 
			++left;
		
		while (*right >= pivot && right > begin) 
			--right;

		if (left < right)
			std::swap(*left, *right);
	}
	//swap pivot
	if (*last <= *left)
		std::swap(*left, *last);

	QuickSort(begin, left - begin);
	QuickSort(left + 1, last - left);
}

int main(int argc, char* argv[])
{
	const unsigned int count = sizeof(data) / sizeof(data[0]);

	QuickSort(data, count);
	for (size_t i = 0; i < count; ++i)
		printf("%u ", data[i]);

	printf("\n");
	return 0;
}
