#include <cstdio>
#include <memory.h>
#include <cassert>

void Compute(int lhs, int rhs, int *result, int* result_cnt)
{
	assert(result_cnt != nullptr);
	assert(result != nullptr);
	assert(*result_cnt > 0);
	assert(rhs > 0);
	assert(lhs > 0);

	int max = *result_cnt;
	int idx = 0;
	int quo = -1;
	int rem = -1;
	do
	{
		if (lhs < rhs)
			lhs *= 10;

		while (lhs < rhs)
		{
			lhs *= 10;
			result[idx++] = 0;
		}

		quo = lhs / rhs;
		rem = lhs % rhs;
		assert(quo < 10);
		result[idx++] = quo;
		lhs = rem;
		if (rem == 0)
			result[idx++] = quo;

		//printf("lhs: %d rhs: %d quo: %d rem: %d, idx: %d\n", lhs, rhs, quo, rem, idx); 
	} while (rem != 0 && idx < max);
	*result_cnt = idx - 1;
	assert(*result_cnt >= 0);
}

int FindMaxRecurrance(int *src, int cnt, int* answer_idx)
{
	int answer_idx_so_far = 0;
	int answer_cnt_so_far = 0;

	for (int i = 0; i < cnt; ++i)
	{
		int anchor = src[i];

		int j = i + 1;

		bool found = false;
		bool match = true;

		while (j < cnt)
		{
			for (;j < cnt; ++j)
			{
				if (src[i] == src[j])
				{
					found = true;
					break;
				}
			}
			//printf("found: %d@%d\n", src[i], j);

			if (!found)
				break; // break outer

			int length = j - i;
			bool match = true;
			for (int k = length; k + i < cnt; ++k)
			{
				if (src[i + (k % length)] != src[i + k])
				{
					match = false;
					break;
				}
			}

			if (match)
			{
//				if (i == 831)
//					printf("matched, i: %d, j: %d,  length: %d\n", i, j, length);
				if (length > answer_cnt_so_far)
				{
					answer_cnt_so_far = length;
					answer_idx_so_far = i;
				}
				break;
			}

			++j;
		}
	}

	printf("longest recurrance seq, cnt: %d seq: ", answer_cnt_so_far);
	for (int i = 0; i < answer_cnt_so_far; ++i)
		//printf("%d", src[answer_idx_so_far + i]);

//	printf("\n");

	if (answer_idx)
		*answer_idx = answer_idx_so_far;
	return answer_cnt_so_far;
}

const int max_len = 2048;
int main(int argc, char* argv[])
{
	int longest_seq_cnt = 0;
	int longest_seq_idx = 0;
	for (int i = 1; i < 1000; ++i)
	{
		if ( i % 2 == 0 || i % 5 == 0)
			continue;

		printf("1/%04d: %f\n", i, 1.0 / (double)i);

		int result[max_len];
		memset(result, 0, sizeof(result));
		int result_cnt = sizeof(result) / sizeof(result[0]);
		Compute(1, i, result, &result_cnt);
		for (int j = 0; j < result_cnt; ++j)
//			printf("%d", result[j]);
//		printf("\n");

		int seq_len = FindMaxRecurrance(result, result_cnt, nullptr);
		if (seq_len > longest_seq_cnt)
		{
			longest_seq_cnt = seq_len;
			longest_seq_idx = i;	
		}
	}

	printf("longest seq: %d at i: %d\n", longest_seq_cnt, longest_seq_idx);

	return 0;
}
