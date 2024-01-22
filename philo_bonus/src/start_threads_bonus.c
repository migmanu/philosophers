/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:09:39 by migmanu           #+#    #+#             */
/*   Updated: 2024/01/22 14:26:46 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"
#include <pthread.h>

void	one_philo(t_data *data)
{
	print_message(&(data->philos[0]), "took one fork", NULL);
	ft_usleep(data->philos[0].die_time);
	print_message(&(data->philos[0]), "died!", RED);
	free(data->pids);
	data->pids = NULL;
	free(data->philos);
	data->philos = NULL;
}

void	*philo_routine(t_philos *philo)
{
	if (pthread_create(&(philo->monitor), NULL, &monitor_routine, philo) != 0)
	{
		print_message(philo, "pthread error", RED);
		return (NULL);
	}
	while (1)
	{
		if (philo->id % 2 == 0)
		{
			ft_usleep(1);
		}
		eat(philo);
		p_sleep(philo);
		think(philo);
	}
	if (pthread_join(philo->monitor, NULL) != 0)
	{
		print_message(philo, "pthread error", RED);
		return (NULL);
	}
	free(philo->data->pids);
	philo->data->pids = NULL;
	free(philo->data->philos);
	philo->data->philos = NULL;
	return (philo);
}

int	start_philos(t_data *data)
{
	int			i;

	i = 0;
	while (i < data->nbr_philos)
	{
		data->pids[i] = fork();
		data->philos[i].pid = data->pids[i];
		if (data->pids[i] == 0)
			philo_routine(&(data->philos[i]));
		i++;
	}
	i = 0;
	while (i < data->nbr_philos)
	{
		waitpid(data->pids[i], 0, 0);
		i++;
	}
	free(data->philos);
	data->philos = NULL;
	free(data->pids);
	data->pids = NULL;
	return (0);
}
