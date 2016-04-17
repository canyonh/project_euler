#include <cstdio>

bool IsLeapYear(unsigned int year)
{
	if (year % 4 != 0)
		return false;

	if (year % 400 == 0)
		return true;

	if (year % 100 == 0)
		return false;

	return true;
}

const unsigned int days_of_month_normal[] = {31,  28,  31,  30,  31,  30,  31,  31,  30,  31,  30,  31};
const unsigned int days_of_month_leap_year[] = {31,  28,  31,  30,  31,  30,  31,  31,  30,  31,  30,  31};

int main(int argc, char* argv[])
{
	unsigned int total_sunday = 0;
	unsigned int days_of_week = 0;
	for (unsigned int i = 1900; i <= 2000; ++i)
	{
		for (unsigned int j = 0; j < 12; ++j)
		{
			unsigned int days_of_month = IsLeapYear(i) ? days_of_month_leap_year[j] : days_of_month_normal[j];
			if (i >= 1901 && days_of_week == 6)
				++total_sunday;

			days_of_week += days_of_month;
			days_of_week %= 7;
		}
	}
	printf("total sundays: %u\n", total_sunday);
	return 0;
}
