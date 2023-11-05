/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:22:44 by migmanu           #+#    #+#             */
/*   Updated: 2023/11/05 19:37:39 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <pthread.h>

# define ERROR -1
# define FAILURE 1
# define SUCCESS 0

typedef struct s_philos
{
	pthread_t		thread;
	int				id;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*eating;
	size_t			die_time;
	size_t			eat_time;
	size_t			sleep_time;
	size_t			last_meal;
	int				meals;
	int				nbr_times_to_eat;
}	t_philos;

typedef struct s_data
{
	t_philos		philos[200];
	pthread_mutex_t	forks[200];
	pthread_mutex_t	eating;
	int				nbr_philos;
	size_t			die_time;
	size_t			eat_time;
	size_t			sleep_time;
	int				nbr_times_to_eat;
	int				dead;
}	t_data;

// actions.c
void	think(t_philos philo);
void	p_sleep(t_philos philo);
void	eat(t_philos *philo);
// check_args.c
int		check_args(int argc, char *argv[]);
// ft_atoi.c
int		ft_atoi(const char *str);
int		type_check(char c);
// initiate_data.c
void	initiate_data(t_data *data, int argc, char *argv[]);
// start_threads.c
void	start_threads(t_data *data);
// utils.c
size_t	get_time(void);
void	ft_usleep(size_t time);
#endif
