/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:17:21 by preed             #+#    #+#             */
/*   Updated: 2022/03/15 17:38:16 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	w;

	i = 0;
	j = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)hay);
	while (hay[i])
	{
		w = i;
		while (needle[j] == hay[i] && needle[j] != 0 && i < len)
		{
			i++;
			j++;
		}
		if (needle[j] == 0)
			return ((char *)(hay + w));
		j = 0;
		i = w++;
		i++;
	}
	return (0);
}
// finds a needle in a hay 
// (searches not more than len bytes)
