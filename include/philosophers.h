/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:22:44 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/29 18:24:30 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <bits/pthreadtypes.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>

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
}	t_philos;

typedef struct s_data
{
	t_philos		philos[200];
	pthread_mutex_t	forks[200];
	int				nbr_philos;
	size_t			die_time;
	size_t			eat_time;
	size_t			sleep_time;
	int				nbr_times_to_eat;
	int				dead;
}	t_data;

// check_args.c
int		check_args(int argc, char *argv[]);
// ft_atoi.c
int		ft_atoi(const char *str);
int		type_check(char c);
// initiate_data.c
void	initiate_data(t_data *data, char *argv[]);
#endif
