/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:09:39 by migmanu           #+#    #+#             */
/*   Updated: 2024/01/09 22:56:53 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	check_dead(t_philos *philo)
{
	pthread_mutex_lock(philo->dead_check);
	if (*(philo->dead) == 1)
	{
		pthread_mutex_unlock(philo->dead_check);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_check);
	return (0);
}

void	*philo_routine(void *ptr)
{
	t_philos	*philo;

	philo = (t_philos *)ptr;
	while (check_dead(philo) != 1)
	{
		eat(philo);
		p_sleep(philo);
		think(philo);
	}
	return (ptr);
}

int	start_threads(t_data *data)
{
	int			i;
	pthread_t	monitor;

	i = 0;
	while (i < data->nbr_philos)
	{
		if (pthread_create(&(data->philos[i].thread), NULL, &philo_routine,
				&(data->philos[i])) != 0)
			return (printf("thread create error!\n"), 1);
		i++;
	}
	if (pthread_create(&monitor, NULL, monitor_routine, data) != 0)
		return (printf("thread create error!\n"), 1);
	i = 0;
	while (i < data->nbr_philos)
	{
		if (pthread_join(data->philos[i++].thread, NULL) != 0)
			return (printf("thread create error!\n"), 1);
	}
	if (pthread_join(monitor, NULL) != 0)
		return (printf("thread create error!\n"), 1);
	free(data->philos);
	free(data->forks);
	return (0);
}
