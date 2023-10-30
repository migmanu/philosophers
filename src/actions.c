/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:36:27 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/30 18:32:10 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	think(t_philos philo)
{
	printf("Philosopher %d is thinking\n\n\n", philo.id); // TODO: erase newline
}

void	p_sleep(t_philos philo)
{
	printf("Philosopher %d is gonna mimir for\n", philo.id);
	usleep(philo.sleep_time);
}

void	eat(t_philos philo)
{
	printf("philo nbr %d is eating\n", philo.id);
	usleep(philo.eat_time);
}
