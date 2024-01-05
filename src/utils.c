/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:42:56 by migmanu           #+#    #+#             */
/*   Updated: 2024/01/05 19:55:33 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		printf("error in time!\n"); // TODO: handle error
	}
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_usleep(size_t time)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < time)
	{
		usleep(500);
	}
	return ;
}

void	print_message(t_philos *philo, char *str, char *CLR)
{
	pthread_mutex_lock(philo->printing);
	if (CLR != NULL)
		printf("%s", CLR);
	printf("%lu | %d %s\n", get_time(), philo->id, str);
	printf(DEFAULT);
	ft_usleep(1);
	pthread_mutex_unlock(philo->printing);
}
