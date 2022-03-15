/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:12:49 by preed             #+#    #+#             */
/*   Updated: 2022/03/15 18:28:59 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doubles(char **argv, int argc)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < argc)
	{
		while (j < argc)
			if (!ft_strncmp(argv[i], argv[j++], 11))
				return (1);
		i++;
		j = i + 1;
	}
	return (0);
}

int	check_num(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '+' || string[i] == '-')
		{
			if (!ft_isdigit(string[i + 1]))
				return (1);
		}
		else if (!ft_isdigit(string[i]) && string[i] != ' ')
			return (1);
			i++;
	}
	return (0);
}
