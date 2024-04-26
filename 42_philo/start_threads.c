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

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if ((philo->id % 2) == 0)
		printf("philo with id : %d\n", philo->id);
	else
		printf("bullshit %d\n",philo->id);
	return (NULL);
}

void	start_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->args->nb_philos)
	{
		if (pthread_create(&(philo[i].thread), NULL, &routine, &philo[i]) != 0)
			printf("error\n");
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
