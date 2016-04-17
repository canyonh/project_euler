#include <stdio.h>

int main(int argc, char* argv[])
{
	const unsigned int max = 1000;
	unsigned int answer = 0;
	for (unsigned int i = 1; i < max; ++i)
	{
		unsigned multiple_of_three = i * 3;
		if (multiple_of_three < max)
		{
			answer += multiple_of_three;
			unsigned multiple_of_five = i * 5;
			
			if (multiple_of_five < max)
			{
				answer += multiple_of_five;
				unsigned multiple_of_both = multiple_of_three * 5;
				if (multiple_of_both < max)
					answer -= multiple_of_both;
			}
		}
		else
		{
			break;
		}
	}	
	printf("answer = %u\n", answer);
	return 0;
}
