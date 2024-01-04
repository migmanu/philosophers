/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:36:27 by migmanu           #+#    #+#             */
/*   Updated: 2023/11/30 19:44:56 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	think(t_philos philo)
{
	printf("%lu | %d is thinking\n", get_time(), philo.id);
}

void	p_sleep(t_philos philo)
{
	printf(BLUE);
	printf("%lu | %d is sleeping\n", get_time(), philo.id);
	printf(DEFAULT);
	ft_usleep(philo.sleep_time);
}

void	hold_forks(t_philos *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		printf("%lu | %d took their left fork\n",
			get_time(), philo->id);
		pthread_mutex_lock(philo->r_fork);
		printf("%lu | %d took their right fork\n",
			get_time(), philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		printf("%lu | %d took their right fork\n",
			get_time(), philo->id);
		pthread_mutex_lock(philo->l_fork);
		printf("%lu | %d took their left fork\n",
			get_time(), philo->id);
	}
}

void	eat(t_philos *philo)
{
	hold_forks(philo);
	pthread_mutex_lock(philo->eating);
	printf(GREEN);
	printf("%lu | %d is eating\n", get_time(), philo->id);
	printf(DEFAULT);
	ft_usleep(philo->eat_time);
	philo->last_meal = get_time();
	philo->meals++;
	pthread_mutex_unlock(philo->eating);
	pthread_mutex_unlock(philo->l_fork);
	printf("%lu | %d drop their left fork\n",
		get_time(), philo->id);
	pthread_mutex_unlock(philo->r_fork);
	printf("%lu | %d drop their right fork\n",
		get_time(), philo->id);
}
