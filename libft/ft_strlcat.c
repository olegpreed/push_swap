/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:14:50 by preed             #+#    #+#             */
/*   Updated: 2021/10/26 20:05:17 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	h;

	i = 0;
	j = ft_strlen(dst);
	h = j;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (j < (dstsize - 1) && src[i])
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	if (dstsize >= h)
		dst[j] = 0;
	if (dstsize >= h)
		return (h + ft_strlen(src));
	else
		return (dstsize + ft_strlen(src));
}

//	char a[] = "Jennifer ";
//	char b[] = "Affleck";			 │ ······Affleck·Je │
//									 │ nnifer ········· │
//	strlcat(a, b, 17);				 │ ······Affleck·Je │
//									 │ nnifer ········· │
//
//	char a[] = "Jennifer \0Lopez\0";
//	char b[] = "Affleck";			 │ ········Affleck· │
//									 │ Jennifer ·Lopez· │
//	strlcat(a, b, 17);				 │ ········Affleck· │
//									 │ Jennifer Affleck │
