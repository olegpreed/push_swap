/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:08:04 by preed             #+#    #+#             */
/*   Updated: 2021/10/19 20:17:58 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*b;

	if (s == 0)
		return (0);
	if (ft_strlen(s) <= (int)start)
	{
		b = (char *)ft_calloc(1, 1);
		return (b);
	}
	if ((unsigned int)ft_strlen(s) - start < len)
		len = (unsigned int)ft_strlen(s) - start;
	b = (char *)ft_calloc(len + 1, sizeof(char));
	if (b == 0)
		return (0);
	ft_strlcpy(b, &s[start], len + 1);
	return (b);
}
// copies to heap (len - 1) bytes of string s, starting from s[start]
// puts '/0' at the end.
// we copy only up to '\0' of the string.
