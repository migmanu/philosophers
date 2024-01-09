/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:27:45 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/01/09 19:29:44 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

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
	start_threads(&data);
	return (0);
}
