/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:37:26 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/29 17:38:00 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	initiate_philos(t_data *data)
{

}

void	initiate_data(t_data *data, char *argv[])
{

	data->nbr_philos = ft_atoi(argv[1]);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	if (argv[4])
		data->nbr_times_to_eat = ft_atoi(argv[4]);
	data->dead = 0;
}
