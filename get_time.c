#include "threads/main.h"
// struct timeval {
//     time_t      tv_sec;     // seconds
//     suseconds_t tv_usec;    // microseconds
// };

// int	gettimeofday(struct timeval *tv, struct timezone *tz);

// 1 sec = 1 000 milliseconds 
// 1 sec = 1 000 000 microseconds 


uint64_t	get_precise_time(void)
{
	struct timeval	current_time;
	uint64_t		time;

	if (gettimeofday(&current_time, NULL) != 0)
		return (0);
	time = current_time.tv_sec * (uint64_t)1000 + current_time.tv_usec / 1000;
	return (time);
}

int	main(void)
{
	uint64_t	start_time;
	uint64_t	time_now;
	uint64_t	time;


	start_time = get_precise_time();
	usleep(100000);
	time_now = get_precise_time();
	time = time_now - start_time;
	printf("time in is : %llu\n",time);
	return (0);
}

