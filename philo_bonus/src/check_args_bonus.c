/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:37:56 by migmanu           #+#    #+#             */
/*   Updated: 2024/01/10 19:07:52 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"

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

static int	check_values(char *argv[])
{
	int	i;

	i = 1;
	while (i < 4)
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
	if (argc < 5 || argc > 6)
	{
		printf("Inputed %d arguments. Must use 4 or 5\n", argc - 1);
		exit(ERROR);
	}
	if (check_str(argc, argv) != 0)
	{
		exit(ERROR);
	}
	if (check_values(argv) != 0)
	{
		exit(ERROR);
	}
	if (ft_atoi(argv[1]) > 200)
	{
		printf("%sMaximum number of philosophers suggested is 200.\
		\n%sProgram will start shortly...\n",
			RED, DEFAULT);
		ft_usleep(10000);
	}
	return (0);
}
