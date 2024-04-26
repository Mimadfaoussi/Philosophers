/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:19:29 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/26 20:43:13 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	printall(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->args->nb_philos)
	{
		printf("philo id : %d\n",philo[i].id);
		printf("philo is_eating : %d\n",philo[i].is_eating);
		printf("philo nb_meals : %d\n",philo[i].nb_meals);
		printf("philo left_fork : %p\n",philo[i].left_fork);
		printf("philo right_fork : %p\n",philo[i].right_fork);
		printf("philo start_time	 : %llu\n",philo[i].start_time);
		printf("---------------------------\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data			data;
	t_philo			philo[200];
	pthread_mutex_t	forks[200];
	t_args			args;

	if (check_input(argc, argv) == 1)
	{
		printf("Input Error\n");
		return (1);
	}
	init_data(&data, philo, forks);
	init_args(&args, argv);
	init_forks(forks, argv);
	init_philo(philo, argv, &data, &args);
	printall(philo);
	start_threads(philo, &data);
	// end_threads();
	destroy_data(&data, forks, argv);
	return (0);
}
