/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:09:39 by migmanu           #+#    #+#             */
/*   Updated: 2024/01/22 13:03:59 by jmigoya-         ###   ########.fr       */
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
	free(data->philos);
}

void	*monitor_routine(void *ptr)
{
	t_philos	*philo;
	size_t		now;

	philo = (t_philos *)ptr;
	while (1)
	{
		pthread_mutex_lock(&(philo->dead_check));
		now = get_time();
		if (now - philo->last_meal > philo->die_time)
		{
			print_message(philo, "died!", RED);
			kill_all(philo->data, philo->id);
			free(philo->data->philos);
			free(philo->data->pids);
			exit(EXIT_FAILURE);
			philo->dead = 1;
		}
		pthread_mutex_unlock(&(philo->dead_check));
		//printf("%lu | philo %d check done, gonna wait %lu\n", get_time(),
		//	philo->id, philo->die_time);
		ft_usleep(1);
	}
	return (ptr);
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
	free(philo->data->philos);
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
	free(data->pids);
	return (0);
}
