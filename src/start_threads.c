/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:09:39 by migmanu           #+#    #+#             */
/*   Updated: 2023/11/05 17:42:32 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	check_starved(t_philos *philo)
{
	size_t	curr_time;

	curr_time = get_time();
	if (curr_time - philo->last_meal > philo->die_time)
	{
		*(philo->dead) = 1;
		printf("%lu | philo nbr %d died! \n",
			get_time(), philo->id);
	}
}

void	*philo_routine(void *ptr)
{
	t_philos	*philo;

	philo = (t_philos *)ptr;
	if (philo->id % 2 == 0)
		ft_usleep(1); // TODO: check!
	while (*(philo->dead) != 1)
	{
		check_starved(philo);
		if (*(philo->dead) == 1)
			return (ptr);
		eat(philo);
		p_sleep(*philo);
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
