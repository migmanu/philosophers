/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:36:27 by migmanu           #+#    #+#             */
/*   Updated: 2024/01/09 22:13:31 by jmigoya-         ###   ########.fr       */
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

void	eat(t_philos *philo)
{
	hold_forks(philo);
	if (philo->meals == *(philo->nbr_times_to_eat))
	{
		print_message(philo, "is full", YELLOW);
		return ;
	}
	pthread_mutex_lock(&(philo->eating));
	print_message(philo, "is eating", GREEN);
	philo->last_meal = get_time();
	philo->meals++;
	pthread_mutex_unlock(&(philo->eating));
	ft_usleep(philo->eat_time);
	print_message(philo, "ate", CYAN);
	pthread_mutex_unlock(philo->l_fork);
	print_message(philo, "drop their left fork", NULL);
	pthread_mutex_unlock(philo->r_fork);
	print_message(philo, "drop their right fork", NULL);
}

void	one_philo(t_data *data)
{
	print_message(&(data->philos[0]), "took their right fork", NULL);
	ft_usleep(data->philos[0].die_time);
	print_message(&(data->philos[0]), "died!", RED);
	free(data->philos);
	free(data->forks);
}
