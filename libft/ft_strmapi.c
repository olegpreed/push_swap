/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:49:54 by preed             #+#    #+#             */
/*   Updated: 2021/10/25 16:02:40 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*e;
	int		l;

	if (!s || !*f)
		return (0);
	l = ft_strlen(s);
	e = (char *)ft_calloc(l + 1, sizeof(char));
	if (e == 0)
		return (0);
	while (l--)
		e[l] = (*f)(l, s[l]);
	return (e);
}
// applies function (*f) to every element of s
// returns the altered string allocated in heap
