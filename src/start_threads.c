/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:09:39 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/30 18:37:43 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*philo_routine(void *ptr)
{
	t_philos *philo;

	// TODO: check philo life
	philo = (t_philos *)ptr;
	if (philo->id % 2 == 0)
		usleep(100); // TODO: check!
	while (*(philo->dead) != 1)
	{
		pthread_mutex_lock(philo->l_fork);
		printf("philo nbr %d locked their left fork\n", philo->id);
		pthread_mutex_lock(philo->r_fork);
		printf("philo nbr %d locked their right fork\n", philo->id);
		// TODO: lock eating
		eat(*philo);
		pthread_mutex_unlock(philo->l_fork);
		printf("philo nbr %d unlocked their left fork\n", philo->id);
		pthread_mutex_unlock(philo->r_fork);
		printf("philo nbr %d unlocked their right fork\n", philo->id);
		p_sleep(*philo);
		think(*philo);
	}
	printf("while end!\n");
	return (ptr);
}

void	start_threads(t_data *data)
{
	int	i;

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
	i = 0;
	while (i < data->nbr_philos)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
		{
			printf("thread create error!\n"); // TODO: error handling
		}
		i++;
	}
}
