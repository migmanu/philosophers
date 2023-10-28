/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:37:56 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/28 20:40:38 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static int	check_str(int argc, char *argv[])
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

static int	check_values(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < (argc - 1))
	{
		if (ft_atoi(argv[i]) < 1)
		{
			printf("Only number of times philosophers eat can be 0!\n");
			return (ERROR);
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
	if (check_values(argc, argv) != 0)
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
