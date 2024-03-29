/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:22:44 by migmanu           #+#    #+#             */
/*   Updated: 2024/01/24 16:32:57 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>

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

typedef struct s_philos
{
	pthread_t		monitor;
	sem_t			*dead_check;
	int				id;
	pid_t			pid;
	struct s_data	*data;
	int				dead;
	size_t			die_time;
	size_t			eat_time;
	size_t			sleep_time;
	int				*nbr_times_to_eat;
	size_t			last_meal;
	int				meals;
}	t_philos;

typedef struct s_data
{
	t_philos		*philos;
	pid_t			*pids;
	sem_t			*forks;
	sem_t			*print;
	int				nbr_philos;
	int				nbr_times_to_eat;
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
int		initiate_data(t_data *data, int argc, char *argv[]);
// start_threads.c
int		start_philos(t_data *data);
int		check_dead(t_philos *philo);
void	one_philo(t_data *data);
// monitor.c
void	kill_all(t_data *data, int caller_id);
void	*monitor_routine(void *ptr);
// utils.c
size_t	get_time(void);
void	ft_usleep(size_t time);
void	print_message(t_philos *philo, char *str, char *CLR);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
#endif
