/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:22:44 by migmanu           #+#    #+#             */
/*   Updated: 2023/10/27 18:46:01 by migmanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <string.h>

# define ERROR -1
# define FAILURE 1
# define SUCCESS 0

/****************	00_check_args	****************/
// check_args.c
int	check_args(int argc, char *argv[]);
/****************	10_utils	****************/
// ft_atoi.c
int	ft_atoi(const char *str);
#endif
