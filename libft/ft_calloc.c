/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:38:05 by preed             #+#    #+#             */
/*   Updated: 2021/10/19 18:58:43 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;

	a = (char *)malloc(size * count);
	if (a == 0)
		return (0);
	ft_bzero(a, size * count);
	return (a);
}
// allocates memory in heap and zeroes it out
