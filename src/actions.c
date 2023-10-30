/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:36:27 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/30 20:44:47 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	think(t_philos philo)
{
	printf("Philosopher %d is thinking\n", philo.id);
}

void	p_sleep(t_philos philo)
{
	printf("Philosopher %d is gonna mimir for\n", philo.id);
	ft_usleep(philo.sleep_time);
}

void	eat(t_philos *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		printf("philo nbr %d locked their left fork\n", philo->id);
		pthread_mutex_lock(philo->r_fork);
		printf("philo nbr %d locked their right fork\n", philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		printf("philo nbr %d locked their right fork\n", philo->id);
		pthread_mutex_lock(philo->l_fork);
		printf("philo nbr %d locked their left fork\n", philo->id);
	}
	pthread_mutex_lock(philo->eating);
	printf("philo nbr %d is gonna eat\n", philo->id);
	ft_usleep(philo->eat_time);
	pthread_mutex_unlock(philo->eating);
	pthread_mutex_unlock(philo->l_fork);
	printf("philo nbr %d unlocked their left fork\n", philo->id);
	pthread_mutex_unlock(philo->r_fork);
	printf("philo nbr %d unlocked their right fork\n", philo->id);
}
