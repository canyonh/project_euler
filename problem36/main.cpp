#include <stdio.h>

int masks[20];

bool Base2Check(int val)
{
	// 1000000 is at most 20 digits
	int i = 0;
	for (i = 19; i >= 0; --i)
	{
		if ((val & masks[i]) != 0)
			break;
	}

	for (int j = 0; j < i / 2 + 1; ++j)
	{
		if (((val & masks[j]) != 0) != ((val & masks[i - j]) != 0))
		{
			return false;
		}
	}	  
	return true;
}

void PrepareMask()
{
	for (int i = 0; i < 20; ++i)
		masks[i] = 1 << i;
}


void Loop()
{
	int to_check;
	int sum = 0;
	int cnt = 0;
	for (int i = 1; i <= 9; i += 2)
	{
		//i
		to_check = i;
		++cnt;
		if (Base2Check(to_check))
		{
			sum += to_check;
			printf("%d ", to_check);
		}

		//ii
		to_check = 10 * i + i;
		++cnt;
		if (Base2Check(to_check))
		{
			sum += to_check;
			printf("%d ", to_check);
		}

		for (int j = 0; j <= 9; ++j)
		{
			//i j i
			to_check = 100 * i + 10* j + i;
			++cnt;
			if (Base2Check(to_check))
			{
				sum += to_check;
				printf("%d ", to_check);
			}

			//i j j i	
			to_check = 1000 * i + 100 * j + 10 * j + i;
			++cnt;
			if (Base2Check(to_check))
			{
				sum += to_check;
				printf("%d ", to_check);
			}

			for (int k = 0; k <= 9; ++k)
			{
				// i j k j i
				to_check = 10000 * i + 1000 * j + 100 * k + 10 * j + i;
				++cnt;
				if (Base2Check(to_check))
				{
					sum += to_check;
					printf("%d ", to_check);
				}

				// i j k k j i
				to_check = 100000 * i + 10000 * j + +1000 * k + 100 * k + 10 * j + i;
				++cnt;
				if (Base2Check(to_check))
				{
					sum += to_check;
					printf("%d ", to_check);
				}
			}
		}
	}
	printf("\nsum = %d, cnt= %d\n", sum, cnt);
}

int main(int argc, char* argv[])
{
	PrepareMask();
	Loop();
	return 0;
}
