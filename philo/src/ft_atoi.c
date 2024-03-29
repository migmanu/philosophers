/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmigoya- <jmigoya-@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:31:23 by jmigoya-          #+#    #+#             */
/*   Updated: 2024/01/06 19:01:21 by jmigoya-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

// returns: 1 if is digit, 2 if is '-', 3 if is space, else 0
int	type_check(char c)
{
	int	a;

	a = c;
	if ((a >= 9 && a <= 13) || a == 32)
		return (3);
	if (a == 45)
		return (2);
	if (a >= 48 && a <= 57)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (type_check(str[i]) == 3)
		i++;
	if (str[i] == '+' && type_check(str[i + 1]) == 1)
		i++;
	if (type_check(str[i]) == 2)
	{
		sign *= -1;
		i++;
	}
	while (type_check(str[i]) == 1)
		result = (result * 10) + (str[i++] - '0');
	return (result * sign);
}
