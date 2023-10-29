/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:36:27 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/29 19:08:48 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	think(int	id)
{
	printf("Philosopher %d is thinking\n", id);
}

void	p_sleep(t_data data, int id)
{
	printf("Philosopher %d is gonna mimir\n", id);
	usleep(data.sleep_time);
}
