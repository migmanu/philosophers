/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:36:27 by migmanu           #+#    #+#             */
/*   Updated: 2024/01/22 14:50:01 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"

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
	sem_wait(philo->data->forks);
	print_message(philo, "picked first fork", NULL);
	sem_wait(philo->data->forks);
	print_message(philo, "picked second fork", NULL);
}

void	drop_forks(t_philos *philo)
{
	sem_post(philo->data->forks);
	print_message(philo, "dropped first fork", NULL);
	sem_post(philo->data->forks);
	print_message(philo, "dropped second fork", NULL);
}

void	eat(t_philos *philo)
{
	hold_forks(philo);
	if (philo->meals == *(philo->nbr_times_to_eat))
	{
		print_message(philo, "is full", YELLOW);
		drop_forks(philo);
		exit(0);
	}
	sem_wait(philo->dead_check);
	print_message(philo, "is eating", GREEN);
	philo->last_meal = get_time();
	philo->meals++;
	sem_post(philo->dead_check);
	ft_usleep(philo->eat_time);
	print_message(philo, "ate", CYAN);
	drop_forks(philo);
}
