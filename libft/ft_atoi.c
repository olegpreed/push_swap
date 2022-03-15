/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:01:10 by preed             #+#    #+#             */
/*   Updated: 2022/03/15 17:47:45 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	ft_putnbr(const char *str, int i)
{
	long long int	num;

	num = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		num = 10 * num + (str[i] - 48);
		i++;
	}
	return (num);
}

long long int	ft_atoi(const char *str)
{
	int				i;
	long long int	e;
	long long int	k;

	i = 0;
	e = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		e *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	else if (str[i] < 47 || str[i] > 58)
		return (0);
	k = ft_putnbr(str, i);
	if (k == -2 && e == -1)
		return (0);
	else if (k == -2 && e == 1)
		return (-1);
	return (k * e);
}
// turns a string into an int
// INT_MAX < number <= LLONG_MAX 	overflow
// LLONG_MAX < number				-1
// number < LLONG_MIN				0
