/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migmanu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:42:56 by migmanu           #+#    #+#             */
/*   Updated: 2024/01/24 16:33:11 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"
#include <semaphore.h>

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		printf("error in time external function!\n");
		return (0);
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
	sem_wait(philo->data->print);
	if (CLR != NULL)
	{
		printf("%s%lu | %d %s\n%s", CLR,
			get_time() % 1000000, philo->id, str, DEFAULT);
	}
	else
	{
		printf("%s%lu | %d %s\n%s", DEFAULT,
			get_time() % 1000000, philo->id, str, DEFAULT);
	}
	sem_post(philo->data->print);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
