/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:37:56 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/27 18:45:14 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

int	check_args(int argc, char *argv[])
{
	if (argc < 4 || argc > 5)
	{
		printf("Inputed %d arguments. Must use 3 or 4\n", argc);
		exit(ERROR);
	}
	if (ft_atoi(argv[1]) > 200) // use atoi
	{
		printf("Maximum number of philosophers allowed is 200\n");
	}
	return (0);
}
