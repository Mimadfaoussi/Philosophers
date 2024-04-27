/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaoussi <mfaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:07:06 by mfaoussi          #+#    #+#             */
/*   Updated: 2024/04/26 21:13:10 by mfaoussi         ###   ########.fr       */
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


typedef struct s_args
{
	int					total_meals;
	int					nb_philos;
	u_int64_t			time_to_eat;
	u_int64_t			time_to_sleep;
	u_int64_t			time_to_die;
}				t_args;


typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	int					is_eating;
	int					nb_meals;
	int					*dead;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	u_int64_t			start_time;
	u_int64_t			last_eating;
	pthread_mutex_t		*print_mutex;
	pthread_mutex_t		*eat_mutex;
	pthread_mutex_t		*dead_mutex;
	t_args				*args;
}					t_philo;

typedef struct s_data
{
	int					dead;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		eat_mutex;
	pthread_mutex_t		dead_mutex;
	pthread_mutex_t		*forks;
	t_philo				*philo;
}					t_data;


/** HELPER  functions */

int			ft_atoi(const char *str);

/*** checking input ***/

int			check_input(int argc, char **argv);

/*** init ***/

void		init_data(t_data *data, t_philo *philo, pthread_mutex_t *forks);
void		init_forks(pthread_mutex_t *forks, char **argv);
void		destroy_data(t_data *data, pthread_mutex_t *forks, char **argv);
void		init_philo(t_philo *philo, char **argv, t_data *data, t_args *args);
void		init_args(t_args *args, char **argv);
u_int64_t	get_precise_time(void);
void		start_threads(t_philo *philo, t_data *data);
void	ft_usleep(u_int64_t	time_to_wait);


#endif