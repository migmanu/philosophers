/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:36:27 by migmanu           #+#    #+#             */
/*   Updated: 2024/01/22 16:49:47 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	think(t_philos *philo)
{
	print_message(philo, "is thinking", NULL);
}

void	p_sleep(t_philos *philo)
{
	print_message(philo, "is sleeping", BLUE);
	ft_usleep(philo->sleep_time);
	print_message(philo, "finished sleeping", MAGENTA);
}

void	hold_forks(t_philos *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		print_message(philo, "took their left fork", NULL);
		pthread_mutex_lock(philo->r_fork);
		print_message(philo, "took their right fork", NULL);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		print_message(philo, "took their right fork", NULL);
		pthread_mutex_lock(philo->l_fork);
		print_message(philo, "took their left fork", NULL);
	}
}

void	drop_forks(t_philos *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	print_message(philo, "drop their left fork", NULL);
	pthread_mutex_unlock(philo->r_fork);
	print_message(philo, "drop their right fork", NULL);
}

void	eat(t_philos *philo)
{
	hold_forks(philo);
	pthread_mutex_lock(&(philo->eating));
	print_message(philo, "is eating", GREEN);
	philo->last_meal = get_time();
	philo->meals++;
	if (*(philo->nbr_times_to_eat) != -1)
	{
		if (philo->meals == *(philo->nbr_times_to_eat))
		{
			philo->full = 1;
			pthread_mutex_unlock(&(philo->eating));
			ft_usleep(philo->eat_time);
			drop_forks(philo);
			print_message(philo, "is full", YELLOW);
			return ;
		}
	}
	pthread_mutex_unlock(&(philo->eating));
	ft_usleep(philo->eat_time);
	drop_forks(philo);
	print_message(philo, "ate", CYAN);
}
