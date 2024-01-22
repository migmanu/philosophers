/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:27:45 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/01/22 12:42:36 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	check_args(argc, argv);
	if (initiate_data(&data, argc, argv) == 1)
	{
		return (1);
	}
	if (data.nbr_philos == 1)
	{
		one_philo(&data);
		return (0);
	}
	start_philos(&data);
	return (0);
}
