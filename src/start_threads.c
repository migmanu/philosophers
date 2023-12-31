/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:09:39 by migmanu           #+#    #+#             */
/*   Updated: 2024/01/04 19:36:37 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"
#include <pthread.h>

void	check_starved(t_philos *philo)
{
	size_t	curr_time;

	curr_time = get_time();
	printf("check_starved. last meal %lu, now %lu\n", philo->last_meal, curr_time);
	if (curr_time - philo->last_meal > philo->die_time)
	{
		*(philo->dead) = 1;
		printf(RED);
		printf("%lu | %d died! \n",
			get_time(), philo->id);
		printf(DEFAULT);
	}
}

void	*philo_routine(void *ptr)
{
	t_philos	*philo;

	philo = (t_philos *)ptr;
	if (philo->id % 2 == 0)
		ft_usleep(1); // TODO: check!
	printf("philo gonna start meals %d, times to eat %d\n", philo->meals, philo->nbr_times_to_eat);
	while (*(philo->dead) != 1 && philo->meals < philo->nbr_times_to_eat)
	{
		printf("philo gonna start meals %d, times to eat %d\n", philo->meals, philo->nbr_times_to_eat);
		check_starved(philo);
		if (*(philo->dead) == 1)
			return (ptr);
		eat(philo);
		p_sleep(*philo);
		check_starved(philo);
		if (*(philo->dead) == 1)
			return (ptr);
		think(*philo);
	}
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
	pthread_create(&(data->philos[200].thread), NULL, &monitor_routine,
		&(data->philos[200])); // TODO: error handling
	i = 0;
	while (i < data->nbr_philos)
	{
		if (pthread_join(data->philos[i++].thread, NULL) != 0)
			printf("thread create error!\n"); // TODO: error handling
	}
	pthread_join(data->philos[200].thread, NULL); // TODO: error handling
}
