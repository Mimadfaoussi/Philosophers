#include "threads/main.h"

int	fuel = 100;
pthread_mutex_t	mutex_fuel;
pthread_cond_t	cond_mutex_fuel;

void	*fuel_filling(void *arg)
{
	// sleep(1);
	for (int i=0; i < 5; i++)
	{
		pthread_mutex_lock(&mutex_fuel);
		fuel = fuel + 50;
		printf("start filling fuel %d\n",fuel);
		pthread_mutex_unlock(&mutex_fuel);
		pthread_cond_broadcast(&cond_mutex_fuel);
		sleep(1);
	}
	// pthread_cond_signal(&cond_mutex_fuel);
	return (NULL);
}

void	*car(void *arg)
{
	pthread_mutex_lock(&mutex_fuel);
	while (fuel < 40)
	{
		printf("no  fuel\n");
		pthread_cond_wait(&cond_mutex_fuel,&mutex_fuel);
	}
	fuel = fuel - 40;
	printf("got  fuel now left : %d\n",fuel);
	pthread_mutex_unlock(&mutex_fuel);
	return (NULL);
}

int main(int argc, char **argv)
{
	pthread_t	th[10];

	pthread_mutex_init(&mutex_fuel, NULL);
	pthread_cond_init(&cond_mutex_fuel, NULL);
	for(int i = 0; i < 10; i++)
	{
		if (i == 9 || i == 8)
		{
			if (pthread_create(&th[i], NULL, fuel_filling, NULL) != 0)
			{
				printf("failed to create thread\n");
			}
		}
		else
		{
			if (pthread_create(&th[i], NULL, car, NULL) != 0)
			{
				printf("failed to create thread\n");
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		pthread_join(th[i], NULL);
	}
	pthread_mutex_destroy(&mutex_fuel);
	pthread_cond_destroy(&cond_mutex_fuel);
	return (0);
}
