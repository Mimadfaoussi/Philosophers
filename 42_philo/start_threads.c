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

philo_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_mutex)
	if (*(philo->dead) == 1)
	{
		pthread_mutex_unlock(philo->dead_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_mutex);
	return (0);
}

void	_sleep(t_philo *philo)
{
	u_int64_t	time;

	pthread_mutex_lock(philo->print_mutex);
	time = get_precise_time() -  philo->start_time;
	if (philo_dead(philo == 0))
		printf("%lu philo %d is sleeping\n", time, philo->id);
	pthread_mutex_unlock(philo->print_mutex);
	ft_usleep(philo->args->time_to_sleep);
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
