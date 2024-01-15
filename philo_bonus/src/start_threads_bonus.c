/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:09:39 by migmanu           #+#    #+#             */
/*   Updated: 2024/01/15 17:38:41 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"

void	one_philo(t_data *data)
{
	print_message(&(data->philos[0]), "took one fork", NULL);
	ft_usleep(data->philos[0].die_time);
	print_message(&(data->philos[0]), "died!", RED);
	free(data->pids);
	free(data->philos);
}

void	*philo_routine(t_philos *philo)
{
	while (1)
	{
		eat(philo);
		p_sleep(philo);
		think(philo);
	}
	free(philo->data->pids);
	free(philo->data->philos);
	return (philo);
}

int	start_threads(t_data *data)
{
	int			i;

	i = 0;
	while (i < data->nbr_philos)
	{
		data->pids[i] = fork();
		data->philos[i].pid = data->pids[i];
		if (data->pids[i] == 0)
			philo_routine(&(data->philos[i]));
		i++;
	}
	i = 0;
	while (i < data->nbr_philos)
	{
		waitpid(data->pids[i], 0, 0);
		i++;
	}
	free(data->philos);
	free(data->pids);
	return (0);
}
