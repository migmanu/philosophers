/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:09:39 by migmanu           #+#    #+#             */
/*   Updated: 2024/01/05 19:58:21 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*philo_routine(void *ptr)
{
	t_philos	*philo;

	philo = (t_philos *)ptr;
	while (*(philo->dead) != 1 && philo->meals < philo->nbr_times_to_eat)
	{
		if (*(philo->dead) != 1)
			eat(philo);
		if (*(philo->dead) != 1)
			p_sleep(philo);
		if (*(philo->dead) != 1)
			think(philo);
		if (*(philo->dead) == 1)
			return (ptr);
		ft_usleep(1);
	}
	return (ptr);
}

void	start_threads(t_data *data)
{
	int			i;
	pthread_t	monitor;

	i = 0;
	while (i < data->nbr_philos)
	{
		if (pthread_create(&(data->philos[i].thread), NULL,
				&philo_routine,
				&(data->philos[i])) != 0)
		{
			printf("thread create error!\n"); // TODO: error handling
		}
		i++;
	}
	if (pthread_create(&monitor, NULL, monitor_routine, data) != 0)
	{
			printf("thread create error!\n"); // TODO: error handling
	}
	i = 0;
	while (i < data->nbr_philos)
	{
		if (pthread_join(data->philos[i++].thread, NULL) != 0)
			printf("thread create error!\n"); // TODO: error handling
	}
}
