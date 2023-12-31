/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:05:14 by jmigoya-          #+#    #+#             */
/*   Updated: 2023/11/30 21:05:16 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	initiate_philos(t_data *data, int argc, char *argv[], int i)
{
	while (++i < data->nbr_philos)
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
		data->philos[i].nbr_times_to_eat = INT_MAX;
		if (argc == 6)
			data->philos[i].nbr_times_to_eat = ft_atoi(argv[5]);
		data->philos[i].dead = &(data->dead);
		data->philos[i].die_time = ft_atoi(argv[2]);
		data->philos[i].eat_time = ft_atoi(argv[3]);
		data->philos[i].sleep_time = ft_atoi(argv[4]);
		data->philos[i].eating = &(data->eating);
		data->philos[i].last_meal = get_time();
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
	data->nbr_philos = ft_atoi(argv[1]);
	if (pthread_mutex_init(&(data->eating), NULL) != 0)
	{
		printf("mutex init error!\n"); // TODO: error management
	}
	data->dead = 0;
	initiate_mutex(data);
	initiate_philos(data, argc, argv, -1);
}
