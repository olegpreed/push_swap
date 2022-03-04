/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:01:07 by preed             #+#    #+#             */
/*   Updated: 2021/10/19 19:51:11 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;

	if (s1 == 0 || s2 == 0)
		return (0);
	a = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (a == 0)
		return (0);
	ft_strlcpy(a, s1, ft_strlen(s1) + 1);
	ft_strlcat(a, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (a);
}
// joins together s1 and s2 and copies the result to the heap
