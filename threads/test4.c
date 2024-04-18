#include "main.h"

/**
* how to get a value back from the thread
**/

void	*roll_dice(void *arg)
{
	int	value = (rand() % 6) + 1;
	int	*result;

	result = malloc(sizeof(int));
	*result = value;
	printf("%p\n",result);
	return (void*) result;
}

int main(void)
{
	pthread_t	th;
	int			*res;

	srand(time(NULL));
	if (pthread_create(&th, NULL, &roll_dice, NULL)!= 0)
		return (1);
	if (pthread_join(th,(void **) &res) != 0)
		return (1);
	printf("result : %p\n",res);
	free(res);
}
