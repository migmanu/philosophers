/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:37:26 by migmanu           #+#    #+#             */
/*   Updated: 2023/11/05 19:42:09 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"
#include <limits.h>

void	initiate_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].l_fork = &(data->forks[i]);
		if (i == data->nbr_philos - 1)
		{
			data->philos[i].r_fork = &(data->forks[0]);
		}
		else
		{
			data->philos[i].r_fork = &(data->forks[i + 1]);
		}
		data->philos[i].dead = &(data->dead);
		data->philos[i].die_time = data->die_time;
		data->philos[i].eat_time = data->eat_time;
		data->philos[i].sleep_time = data->sleep_time;
		data->philos[i].nbr_times_to_eat = data->nbr_times_to_eat;
		data->philos[i].eating = &(data->eating);
		data->philos[i].last_meal = get_time();
		i++;
	}
}

void	initiate_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philos)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL) != 0)
		{
			printf("mutex init error!\n"); // TODO: error management
		}
		i++;
	}
}

void	initiate_data(t_data *data, int argc, char *argv[])
{
	printf("initiate_data init\n");
	data->nbr_philos = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	if (pthread_mutex_init(&(data->eating), NULL) != 0)
	{
		printf("mutex init error!\n"); // TODO: error management
	}
	data->nbr_times_to_eat = INT_MAX;
	if (argc == 6)
		data->nbr_times_to_eat = ft_atoi(argv[5]);
	data->dead = 0;
	initiate_mutex(data);
	initiate_philos(data);
}
