/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:27:14 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/01/15 17:39:55 by jmigoya-         ###   ########.fr       */
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
