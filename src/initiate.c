/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:37:26 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/29 19:16:47 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	initiate_philos(t_data *data)
{
	printf("initiate_philos init, nbr_philos: %d\n", data->nbr_philos);
	int	i;

	i = 0;
	while (i < data->nbr_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].l_fork = &(data->forks[i]);
		if (i == 0)
		{
			data->philos[i].l_fork = &(data->forks[data->nbr_philos - 1]);
		}
		else
		{
			data->philos[i].l_fork = &(data->forks[i - 1]);
		}
		data->philos[i].dead = &(data->dead);
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

void	initiate_data(t_data *data, char *argv[])
{
	printf("initiate_data init\n");
	data->nbr_philos = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	if (argv[4])
		data->nbr_times_to_eat = ft_atoi(argv[4]);
	data->dead = 0;
	initiate_mutex(data);
	initiate_philos(data);
}