#include <cstdio>
#include <vector>

int main(int argc, char* argvp[])
{
	const uint64_t dimension = 21;
	uint64_t array[dimension][dimension];

	memset(array, 0, sizeof(array));

	for (size_t i = 0; i < dimension; ++i)
	{
		array[0][i] = 1;
		array[i][0] = 1;
	}

	for (size_t i = 1; i < dimension; ++i)
	{
		for (size_t j = 1; j < dimension; ++j)
		{
			array[i][j] = array[i][j - 1] + array[i - 1][j];
		}
	}

	for (size_t i = 0; i < dimension; ++i)
	{
		for (size_t j = 0; j < dimension; ++j)
		{
			printf("%llu ", array[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("%llu\n", array[dimension - 1][dimension - 1]);
	return 0;
}
