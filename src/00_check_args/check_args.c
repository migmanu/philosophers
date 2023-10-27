/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:37:56 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/27 19:35:17 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

int	check_str(int argc, char *argv[])
{
	int	i;
	int	c;

	i = 1;
	while (i < argc)
	{
		c = 0;
		while (argv[i][c] != '\0')
		{
			if (type_check(argv[i][c]) != 1)
			{
				printf("%s is a wrong argument. Only use numbers!\n", argv[i]);
				return (ERROR);
			}
			c++;
		}
		i++;
	}
	return (0);
}

int	check_args(int argc, char *argv[])
{
	if (argc < 4 || argc > 5)
	{
		printf("Inputed %d arguments. Must use 3 or 4\n", argc - 1);
		exit(ERROR);
	}
	if (check_str(argc, argv) != 0)
	{
		exit(ERROR);
	}
	if (ft_atoi(argv[1]) > 200)
	{
		printf("Maximum number of philosophers allowed is 200\n");
		exit(ERROR);
	}
	return (0);
}
