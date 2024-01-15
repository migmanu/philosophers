/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:27:14 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/01/14 17:16:36 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"

/*
int	check_full(t_data *data, int meals)
{
	int	i;

	i = 0;
	if (data->nbr_times_to_eat == -1)
		return (0);
	while (i < data->nbr_philos)
	{
		if (meals < data->nbr_times_to_eat)
		{
			return (0);
		}
		i++;
	}
	print_message(&(data->philos[1]), "all philosophers ate!", YELLOW);
	pthread_mutex_lock(&(data->dead_check));
	data->dead = 1;
	pthread_mutex_unlock(&(data->dead_check));
	return (1);
}

int	check_time(t_data *data, int i)
{
	if (get_time() - data->philos[i].last_meal > data->philos[i].die_time)
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
	int		meals;
	int		i;

	data = (t_data *)ptr;
	i = 0;
	while (1)
	{
		pthread_mutex_lock(&(data->philos[i].eating));
		meals = data->philos[i].meals;
		if (check_time(data, i) == 1 || check_full(data, meals) == 1)
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
*/
