/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:36:27 by migmanu           #+#    #+#             */
/*   Updated: 2024/01/15 17:13:44 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"

void	kill_all(t_data *data, int caller_id)
{
	int	i;

	i = 0;
	while (i < data->nbr_philos)
	{
		if (i != caller_id)
		{
			kill(data->pids[i], SIGKILL);
		}
		i++;
	}
}

void	check_and_wait(t_philos *philo, long time)
{
	size_t	now;

	now = get_time();
	if (now - philo->last_meal >= philo->die_time)
	{
		print_message(philo, "died!", RED);
		kill_all(philo->data, philo->id);
		exit(EXIT_FAILURE);
	}
	else if (time != 0 && (now + time) - philo->last_meal >= philo->die_time)
	{
		ft_usleep(time);
		print_message(philo, "died while waiting!", RED);
		kill_all(philo->data, philo->id);
		exit(EXIT_FAILURE);
	}
	else if (time != 0)
		ft_usleep(time);
}

void	think(t_philos *philo)
{
	print_message(philo, "is thinking", NULL);
}

void	p_sleep(t_philos *philo)
{
	print_message(philo, "is sleeping", BLUE);
	check_and_wait(philo, philo->sleep_time);
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
	check_and_wait(philo, 0);
	if (philo->id % 2 == 0)
	{
		ft_usleep(1);
	}
	hold_forks(philo);
	check_and_wait(philo, 0);
	if (philo->meals == *(philo->nbr_times_to_eat))
	{
		print_message(philo, "is full", YELLOW);
		drop_forks(philo);
		exit(0);
	}
	print_message(philo, "is eating", GREEN);
	philo->last_meal = get_time();
	philo->meals++;
	check_and_wait(philo, philo->eat_time);
	print_message(philo, "ate", CYAN);
	drop_forks(philo);
}
