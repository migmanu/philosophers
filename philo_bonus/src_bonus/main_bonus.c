/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:16:51 by migmanu           #+#    #+#             */
/*   Updated: 2024/01/09 13:06:05 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/philosophers_bonus.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	check_args(argc, argv);
	if (initiate_data(&data, argc, argv) == 1)
		return (1);
	start_threads(&data);
	return (0);
}
