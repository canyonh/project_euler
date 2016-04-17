#include <cstdio>

int Diagnal(int side)
{
	int sum = 1; // sum of 1
	printf("1 ");
	for (int i = 3; i <= side; i += 2)
	{ 
		int isquare = i * i;
		for (int j = 0; j < 4; ++j)
		{
			int diagnal = isquare - (i - 1) * j;
			printf("%d ", diagnal);
			sum += diagnal;
		}
	}
	printf("\n sum = %d\n", sum);
	return sum;
}

int main(int argc, char* argv[])
{
	Diagnal(1);
	Diagnal(3);
	Diagnal(5);
	Diagnal(7);
	Diagnal(1001);
	return 0;
}
