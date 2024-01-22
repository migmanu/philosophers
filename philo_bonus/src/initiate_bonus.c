/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:05:14 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/01/22 12:38:26 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"

int	initiate_philos(t_data *data, char *argv[], int i)
{
	while (++i < data->nbr_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].data = data;
		data->philos[i].dead = 0;
		data->philos[i].die_time = ft_atoi(argv[2]);
		data->philos[i].eat_time = ft_atoi(argv[3]);
		data->philos[i].sleep_time = ft_atoi(argv[4]);
		data->philos[i].last_meal = get_time();
		data->philos[i].nbr_times_to_eat = &(data->nbr_times_to_eat);
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
	data->philos = malloc(sizeof(t_philos) * data->nbr_philos);
	data->pids = malloc(sizeof(pid_t) * data->nbr_philos);
	sem_unlink("forks"); // TODO: error handling
	data->forks = sem_open("forks", O_CREAT, 0600, data->nbr_philos);
	if (data->philos == NULL || data->forks == SEM_FAILED) // separate?
		return (1);
	if (initiate_philos(data, argv, -1) == 1)
		return (1);
	return (0);
}
