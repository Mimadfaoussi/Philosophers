#include "main.h"

int	mails = 0;
pthread_mutex_t	mutex;

void	*routine()
{
	for (int i = 0; i < 1000000; i++)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
}

int main(void)
{
	pthread_t 	p1;
	pthread_t	p2;

	pthread_mutex_init(&mutex, NULL);
	if (pthread_create(&p1, NULL, &routine, NULL) != 0)
		return (1);
	if (pthread_create(&p2, NULL, &routine, NULL) != 0)
		return (1);
	if (pthread_join(p1, NULL) != 0)
		return (1);
	if (pthread_join(p2, NULL) != 0)
		return (1);
	pthread_mutex_destroy(&mutex);
	printf("nb of mails %d",mails);
}
