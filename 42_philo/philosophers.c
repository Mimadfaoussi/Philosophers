/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:19:29 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/26 17:01:55 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data			data;
	t_philo			philo[200];
	pthread_mutex_t	forks[200];

	if (check_input(argc, argv) == 1)
	{
		printf("Input Error\n");
		return (1);
	}
	init_data(&data, philo);
	init_forks(forks, argv);
	// init_philo(philo, argv, &data);
	// start_threads();
	// end_threads();
	destroy_data(&data, forks, argv);
	return (0);
}
