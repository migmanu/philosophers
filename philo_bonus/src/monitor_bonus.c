/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:27:14 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/01/22 12:53:33 by jmigoya-         ###   ########.fr       */
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

int	check_and_wait(t_philos *philo, long time)
{

	ft_usleep(time);
	if (philo->dead == 1)
		return (1);
	/*
	size_t	now;
	now = get_time();
	pthread_mutex_lock(&(philo->dead_check));
	if (philo->dead == 1)
	{
		print_message(philo, "died!", RED);
		kill_all(philo->data, philo->id);
		free(philo->data->philos);
		free(philo->data->pids);
		exit(EXIT_FAILURE);
		return (1);
	}
	pthread_mutex_unlock(&(philo->dead_check));
	else if (time != 0 && (now + time) - philo->last_meal >= philo->die_time)
	{
		ft_usleep(time);
		print_message(philo, "died while waiting!", RED);
		kill_all(philo->data, philo->id);
		free(philo->data->philos);
		free(philo->data->pids);
		exit(EXIT_FAILURE);
		return (1);
	}
	else if (time != 0)
		ft_usleep(time);
	*/
	return (0);
}
