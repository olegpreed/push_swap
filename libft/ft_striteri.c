/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:51:25 by preed             #+#    #+#             */
/*   Updated: 2021/10/25 16:05:37 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		l;

	if (!*f)
		return ;
	if (s != 0)
	{
		l = ft_strlen(s);
		while (l--)
			(*f)(l, &s[l]);
	}
}
// applies function (*f) to every element of a string s.
