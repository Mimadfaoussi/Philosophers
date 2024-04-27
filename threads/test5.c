#include "main.h"

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void    *routine(void *arg)
{
    int *value;
    int result;
    int index = *(int *)arg;
    int i;
    int end;

    result = 0;
    value = malloc(sizeof(int));
    if (index == 0)
    {
        i = 0;
        end = (sizeof(primes) / sizeof(int)) / 2;
    }
    else
    {
        i = (sizeof(primes) / sizeof(int)) / 2;
        end = (sizeof(primes) / sizeof(int));
    }
    while (i < end)
    {
        result = result + primes[i];
        i++;
    }
    *value = result;
    free(arg);
    return (void *)value;
}

int main(int argc, char **argv)
{
    pthread_t   th[2];
    int         i;
    int         *a;
    int         sum;
    int         *value;

    sum = 0;
    i = 0;
    while (i < 2)
    {
        a = malloc(sizeof(int));
        *a = i;
        pthread_create(&th[i], NULL, &routine, a);
        i++;
    } g
    i = 0;
    while (i < 2)
    {
        pthread_join(th[i], (void **)&value);
        sum = sum + *value;
        free(value);
        i++;
    }
    printf("sum is %d\n",sum);

    return (0);
} 