/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:22:18 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/26 18:38:09 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_data(t_data *data, t_philo *philo, pthread_mutex_t *forks)
{
	data->dead = 0;
	data->philo = philo;
	data->forks = forks;
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->eat_mutex, NULL);
	pthread_mutex_init(&data->dead_mutex, NULL);
}

void	init_forks(pthread_mutex_t *forks, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_philo(t_philo *philo, char **argv, t_data *data)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philo->id = i + 1;
		philo->is_eating = 0;
		philo->left_fork = data->forks[i];
		if (i == ft_atoi(argv[1]) - 1)
			philo->right_fork = data->forks[0];
		else
			philo->right_fork = data->forks[i + 1];
		philo->start_time = get_precise_time();
		philo->last_eating = get_precise_time();
		philo->print_mutex = data->print_mutex;
		philo->eat_mutex = data->eat_mutex;
		philo->dead_mutex = data->dead_mutex;
		i++;
	}
}

void	init_args(t_args *args, void **argv)
{
	args->nb_meals = 0;
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	args->time_to_die = ft_atoi(argv[2]);
}



void	destroy_data(t_data *data, pthread_mutex_t *forks, char **argv)
{
	int	i;

	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->eat_mutex);
	pthread_mutex_destroy(&data->dead_mutex);
	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

