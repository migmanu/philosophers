/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:22:44 by migmanu           #+#    #+#             */
/*   Updated: 2024/01/06 18:31:39 by jmigoya-         ###   ########.fr       */
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

# define DEFAULT "\001\033[0;39m\002"
# define GRAY "\001\033[1;90m\002"
# define BLACK "\001\033[0;30m\002"
# define RED "\001\033[1;91m\002"
# define GREEN "\001\033[1;92m\002"
# define YELLOW "\001\033[1;93m\002"
# define BLUE "\001\033[1;94m\002"
# define MAGENTA "\001\033[1;95m\002"
# define CYAN "\001\033[1;96m\002"
# define WHITE "\001\033[1;97m\002"

enum	e_returns
{
	ERROR = -1,
	SUCCESS,
	FAILURE,
};

typedef struct s_philos
{
	pthread_t		thread;
	int				id;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*printing;
	pthread_mutex_t	eating;
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
	pthread_mutex_t	printing;
	int				nbr_philos;
	int				dead;
}	t_data;

// actions.c
void	think(t_philos *philo);
void	p_sleep(t_philos *philo);
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
// monitor.c
void	*monitor_routine(void *ptr);
void	check_starved(t_philos *philo);
// utils.c
size_t	get_time(void);
void	ft_usleep(size_t time);
void	print_message(t_philos *philo, char *str, char *CLR);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
#endif
