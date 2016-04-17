#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <sys/time.h>
#include <mach/mach_time.h>
#include <time.h>

#include <stdio.h>

uint64_t GetRelativeWaitTime()
{
	uint64_t t = mach_absolute_time();
	mach_timebase_info_data_t tb_info;
	mach_timebase_info(&tb_info);
	return t* tb_info.numer / tb_info.denom / 1000000;
}
void micro_sleep(unsigned int duration)
{
	struct timespec remaining = {0, 0};
	struct timespec sleep_time = {(duration/1000), (duration% 1000)*1000000};
	nanosleep(&sleep_time, &remaining);
}

#endif
