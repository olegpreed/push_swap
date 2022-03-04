/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:22:30 by preed             #+#    #+#             */
/*   Updated: 2021/10/19 17:13:30 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	k;

	k = (char)c;
	while (*s != k && *s != 0)
		s++;
	if ((k == 0 && *s == 0) || *s != 0)
		return ((char *)s);
	return (0);
}
// finds the first c symbols in string s
// c can be '\0'