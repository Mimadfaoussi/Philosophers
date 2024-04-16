#include "main.h"

int	mails = 0;

void	*routine()
{
	for(int i=0; i < 1000; i++)
		mails++;
}

// encountring the race problem trying to increment same variable at the same time
int main(int argc, char **argv)
{
	pthread_t	t1, t2; // to store information about the thread using the api 
	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return (1);
	pthread_create(&t2, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("mails : %d\n",mails);
	return (0);
}
