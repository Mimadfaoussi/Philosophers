/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:07:06 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/24 13:52:24 by mfaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdint.h>

typedef struct s_data
{
	int			nb_philos;
	int			nb_meals;
	u_int64_t	time_to_die;
	u_int64_t	time_to_eat;
	u_int64_t	time_to_sleep;
	u_int64_t	time_to_think;


}				t_data;

typedef struct s_philo
{
	int			nb;
	int			meals;
	int			fork;
	int			*right_fork;
	u_int64_t	start_time;
	u_int64_t	eat_time;

}					t_philo;


/** HELPER  functions */

int	ft_atoi(const char *str);
int	check_input(int argc, char **argv);


#endif