/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:36:27 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/30 21:03:04 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	think(t_philos philo)
{
	printf("%lu | philo %d is thinking\n",get_time() ,philo.id);
}

void	p_sleep(t_philos philo)
{
	printf("%lu | philo %d is sleeping\n", get_time() ,philo.id);
	ft_usleep(philo.sleep_time);
}

void	eat(t_philos *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		printf("%lu | philo nbr %d took their left fork\n",
			get_time() , philo->id);
		pthread_mutex_lock(philo->r_fork);
		printf("%lu | philo nbr %d took their right fork\n",
			get_time() , philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		printf("%lu | philo nbr %d took their right fork\n",
			get_time() , philo->id);
		pthread_mutex_lock(philo->l_fork);
		printf("%lu | philo nbr %d took their left fork\n",
			get_time() , philo->id);
	}
	pthread_mutex_lock(philo->eating);
	printf("%lu | philo nbr %d is gonna eat\n", get_time() , philo->id);
	ft_usleep(philo->eat_time);
	pthread_mutex_unlock(philo->eating);
	pthread_mutex_unlock(philo->l_fork);
	printf("%lu | philo nbr %d drop their left fork\n",
		get_time() , philo->id);
	pthread_mutex_unlock(philo->r_fork);
	printf("%lu | philo nbr %d drop their right fork\n",
		get_time() , philo->id);
}
