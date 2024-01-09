/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:16:51 by migmanu           #+#    #+#             */
/*   Updated: 2024/01/06 18:57:20 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	check_args(argc, argv);
	if (initiate_data(&data, argc, argv) == 1)
		return (1);
	start_threads(&data);
	return (0);
}
