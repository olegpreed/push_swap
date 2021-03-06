/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 20:39:42 by preed             #+#    #+#             */
/*   Updated: 2022/03/07 18:35:30 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*a;

	if (!*lst)
	{
		*lst = new;
		new->next = 0;
		return ;
	}
	if (new == 0 || !lst)
		return ;
	a = ft_lstlast(*lst);
	a->next = (struct s_list *)new;
}
// Adds the element ’new’ at the end of the list.