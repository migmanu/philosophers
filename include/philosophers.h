/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:22:44 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/27 20:10:30 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <string.h>

# define ERROR -1
# define FAILURE 1
# define SUCCESS 0

typedef struct s_philos
{
	pthread_t		thread;
	int				id;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_philos;

typedef struct s_data
{
	int		nbr_philos;
	int		nbr_times_to_eat;
	int		*dead;
	size_t	die_time;
	size_t	eat_time;
	size_t	sleep_time;
}	t_data;

/****************	00_check_args	****************/
// check_args.c
int	check_args(int argc, char *argv[]);
/****************	10_utils	****************/
// ft_atoi.c
int	ft_atoi(const char *str);
int	type_check(char c);
#endif
