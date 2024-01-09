/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:05:14 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/01/09 21:56:04 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	initiate_philos(t_data *data, char *argv[], int i)
{
	while (++i < data->nbr_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].l_fork = &(data->forks[i]);
		if (i == data->nbr_philos - 1)
			data->philos[i].r_fork = &(data->forks[0]);
		else
			data->philos[i].r_fork = &(data->forks[i + 1]);
		if (pthread_mutex_init(&(data->philos[i].eating), NULL) != 0)
		{
			printf("mutex init error!\n");
			return (1);
		}
		data->philos[i].nbr_times_to_eat = &(data->nbr_times_to_eat);
		data->philos[i].printing = &(data->printing);
		data->philos[i].dead_check = &(data->dead_check);
		data->philos[i].dead = &(data->dead);
		data->philos[i].die_time = ft_atoi(argv[2]);
		data->philos[i].eat_time = ft_atoi(argv[3]);
		data->philos[i].sleep_time = ft_atoi(argv[4]);
		data->philos[i].last_meal = get_time();
	}
	return (0);
}

int	initiate_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philos)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL) != 0)
		{
			printf("mutex init error!\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	initiate_data(t_data *data, int argc, char *argv[])
{
	data->nbr_philos = ft_atoi(argv[1]);
	if (argc == 5)
		data->nbr_times_to_eat = -1;
	else
		data->nbr_times_to_eat = ft_atoi(argv[5]);
	data->dead = 0;
	if (pthread_mutex_init(&(data->printing), NULL) != 0)
	{
		printf("mutex init error!\n");
		return (1);
	}
	if (pthread_mutex_init(&(data->dead_check), NULL) != 0)
	{
		printf("mutex init error!\n");
		return (1);
	}
	data->philos = malloc(sizeof(t_philos) * data->nbr_philos);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nbr_philos);
	if (data->philos == NULL || data->forks == NULL)
		return (1);
	if (initiate_mutex(data) == 1)
		return (1);
	if (initiate_philos(data, argv, -1) == 1)
		return (1);
	return (0);
}
