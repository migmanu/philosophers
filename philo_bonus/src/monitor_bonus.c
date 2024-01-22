/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:27:14 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/01/22 14:48:28 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"
#include <pthread.h>

void	kill_all(t_data *data, int caller_id)
{
	int	i;

	i = 0;
	while (i < data->nbr_philos)
	{
		if (i != caller_id)
		{
			kill(data->pids[i], SIGTERM);
		}
		i++;
	}
}

void	*monitor_routine(void *ptr)
{
	t_philos	*philo;
	size_t		now;

	philo = (t_philos *)ptr;
	while (1)
	{
		sem_wait(philo->dead_check);
		now = get_time();
		if (now - philo->last_meal > philo->die_time)
		{
			print_message(philo, "died!", RED);
			kill_all(philo->data, philo->id);
			sem_post(philo->dead_check);
			if (pthread_join(philo->monitor, NULL) != 0)
				print_message(philo, "pthread error", RED);
			free(philo->data->pids);
			philo->data->pids = NULL;
			free(philo->data->philos);
			philo->data->philos = NULL;
			exit(EXIT_FAILURE);
		}
		sem_post(philo->dead_check);
		ft_usleep(1);
	}
	return (ptr);
}
