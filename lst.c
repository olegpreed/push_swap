/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:58:57 by preed             #+#    #+#             */
/*   Updated: 2022/03/12 19:38:55 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_count(t_stack **pp_node)
{
	t_stack	*check;
	int		i;

	i = 1;
	check = *pp_node;
	if (!*pp_node)
		return (0);
	while (check->next)
	{
		i++;
		check = check->next;
	}
	return (i);
}

t_stack	*int_lstnew(int content)
{
	t_stack	*a;

	a = (t_stack *)malloc(sizeof(t_stack));
	if (!a)
		return (0);
	a->content = content;
	a->next = 0;
	return (a);
}

void	int_lstclear(t_stack **lst)
{
	t_stack	*dbl;

	if (!*lst || !lst)
		return ;
	dbl = (*lst)->next;
	while (*lst)
	{
		free(*lst);
		*lst = dbl;
		if (!dbl)
			return ;
		dbl = (*lst)->next;
	}
}

t_stack	*int_lstlast(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	int_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*a;

	if (!*lst)
	{
		*lst = new;
		new->next = 0;
		return ;
	}
	if (new == 0 || !lst)
		return ;
	a = int_lstlast(*lst);
	a->next = (struct s_stack *)new;
}
// creates a structure in heap with content
// and null pointer in next