/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:27:14 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/01/06 18:34:00 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*monitor_routine(void *ptr)
{
	size_t	curr_time;
	t_data	*data;
	int		i;

	data = (t_data *)ptr;
	i = 1;
	while (data->dead != 1)
	{
		pthread_mutex_lock(&(data->philos[i].eating));
		curr_time = get_time();
		if (curr_time - data->philos[i].last_meal > data->philos[i].die_time)
		{
			data->dead = 1;
			print_message(&(data->philos[i]), "died!", RED);
			ft_usleep(10);
			pthread_mutex_unlock(&(data->philos[i]).eating);
			return (NULL);
		}
		pthread_mutex_unlock(&(data->philos[i].eating));
		i++;
		if (i == data->nbr_philos)
			i = 1;
	}
	return (ptr);
}
