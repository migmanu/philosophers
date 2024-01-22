/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:27:14 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/01/22 16:44:44 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

// checks if philo is full. If full sets full to -1 to now count twice
int	check_full(t_data *data, int i, int *d)
{
	if (data->nbr_times_to_eat == -1)
	{
		data->philos[i].full = 0;
		return (0);
	}
	if (data->philos[i].full == 1)
	{
		*d = *d + 1;
		data->philos[i].full = -1;
	}
	if (*d >= data->nbr_philos)
	{
		print_message(&(data->philos[i]), "all philos are full!", YELLOW);
		pthread_mutex_lock(&(data->dead_check));
		data->dead = 1;
		pthread_mutex_unlock(&(data->dead_check));
		return (1);
	}
	return (0);
}

int	check_time(t_data *data, int i)
{
	if (data->philos[i].full == 0 
		&& get_time() - data->philos[i].last_meal > data->philos[i].die_time)
	{
		print_message(&(data->philos[i]), "died!", RED);
		pthread_mutex_lock(&(data->dead_check));
		data->dead = 1;
		pthread_mutex_unlock(&(data->dead_check));
		return (1);
	}
	return (0);
}

void	*monitor_routine(void *ptr)
{
	t_data	*data;
	int		i;
	int		d;

	data = (t_data *)ptr;
	d = 0;
	i = 0;
	while (1)
	{
		pthread_mutex_lock(&(data->philos[i].eating));
		if (check_time(data, i) == 1 || check_full(data, i, &d) == 1)
		{
			pthread_mutex_unlock(&(data->philos[i].eating));
			return (NULL);
		}
		pthread_mutex_unlock(&(data->philos[i].eating));
		i++;
		if (i == data->nbr_philos)
			i = 0;
	}
	return (ptr);
}
