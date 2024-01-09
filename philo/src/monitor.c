/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:27:14 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/01/09 17:24:38 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	check_full(t_data *data)
{
	int	i;

	i = 0;
	if (data->nbr_times_to_eat == -1)
		return ;
	while (i < data->nbr_philos)
	{
		if (data->philos[i].meals < data->nbr_times_to_eat)
			return ;
		i++;
	}
	data->dead = 1;
	printf(YELLOW);
	printf("all philosophers ate!\n");
	printf(DEFAULT);
}

void	*monitor_routine(void *ptr)
{
	size_t	curr_time;
	t_data	*data;
	int		i;

	data = (t_data *)ptr;
	i = 1;
	while (data->dead != 1)
	{
		check_full(data);
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
