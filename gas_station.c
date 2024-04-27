#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int food = 100;

void    *eat_food(void *quantity_eaten)
{
    usleep(250000);
    if (*(int *)quantity_eaten <= food)
    {
        printf("food %d\n",food);
        food = food - (*(int *)quantity_eaten); 
        printf("eaten from food rest : %d\n",food);

    }
    else
        printf("error not enough food \n");
}

void    *cook_food(void *quantity_coocked)
{
    food = food + (*(int *)quantity_coocked);
    printf("cooked food %d\n",food);
}

int main(int argc, char **argv)
{
    pthread_t    eater1;
    pthread_t    eater2;
    pthread_t    cook;
    int          quantity_eaten;
    int         quantity_coocked;

    quantity_coocked = 40;
    quantity_eaten = 20;
    pthread_create(&eater1, NULL, eat_food, (void *)&quantity_eaten);
    pthread_create(&eater2, NULL, eat_food, (void *)&quantity_eaten);
    pthread_create(&cook, NULL, cook_food, (void *)&quantity_coocked);

    pthread_join(eater1, NULL);
    pthread_join(eater2, NULL);
    pthread_join(cook, NULL);

}