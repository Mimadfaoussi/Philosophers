/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:43:38 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/26 21:13:24 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_mutex);
	if (*(philo->dead) == 1)
	{
		pthread_mutex_unlock(philo->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_mutex);
	return (0);
}

void	ft_print(t_philo *philo, char *text)
{
	u_int64_t	time;

	pthread_mutex_lock(philo->print_mutex);
	time = get_precise_time() -  philo->start_time;
	if (philo_dead(philo) == 0)
		printf("%lu philo %d %s\n", time, philo->id, text);
	pthread_mutex_unlock(philo->print_mutex);
}

void	_sleep(t_philo *philo)
{
	ft_print(philo, "is sleeping");
	ft_usleep(philo->args->time_to_sleep);
}

void	think(t_philo *philo)
{
	ft_print(philo, "is thinking");
}


void	eat(t_philo *philo)
{	
	pthread_mutex_lock(philo->left_fork);
	ft_print(philo, "has take left fork");
	if (philo->args->nb_philos == 1)
	{
		ft_usleep(philo->args->time_to_die);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	pthread_mutex_lock(philo->right_fork);
	ft_print(philo, "has take right fork");
	philo->is_eating = 1;
	pthread_mutex_lock(philo->eat_mutex);
	philo->nb_meals++;
	philo->last_eating = get_precise_time();
	ft_print(philo, "is eating");
	pthread_mutex_unlock(philo->eat_mutex);
	ft_usleep(philo->args->time_to_eat);
	philo->is_eating = 0;
	pthread_mutex_unlock(philo->right_fork);
	// ft_print(philo, "has putted right fork");
	pthread_mutex_unlock(philo->left_fork);
	// ft_print(philo, "has putted left fork");

}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if ((philo->id % 2) == 0)
		ft_usleep(1);
	while (philo_dead(philo) == 0)
	{
		eat(philo);
		_sleep(philo);
		think(philo);
	}
	return (NULL);
}

void	start_threads(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < philo->args->nb_philos)
	{
		if (pthread_create(&(philo[i].thread), NULL, &routine, &philo[i]) != 0)
			printf("error %p\n",data);
		i++;
	}
	i = 0;
	while (i < philo->args->nb_philos)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			printf("error\n");
		i++;
	}
}
