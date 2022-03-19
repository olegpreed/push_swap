/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:05:46 by preed             #+#    #+#             */
/*   Updated: 2022/03/17 22:46:36 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **pp_node_a)
{
	t_stack	*temp_a;
	t_stack	*iter;

	if (!*pp_node_a || !(*pp_node_a)->next)
		return ;
	iter = *pp_node_a;
	temp_a = *pp_node_a;
	*pp_node_a = (*pp_node_a)->next;
	while (iter->next)
		iter = iter->next;
	iter->next = temp_a;
	temp_a->next = NULL;
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack **pp_node_b)
{
	t_stack	*temp_b;
	t_stack	*iter;

	if (!*pp_node_b || !(*pp_node_b)->next)
		return ;
	iter = *pp_node_b;
	temp_b = *pp_node_b;
	*pp_node_b = (*pp_node_b)->next;
	while (iter->next)
		iter = iter->next;
	iter->next = temp_b;
	temp_b->next = NULL;
	write(1, "rb\n", 3);
}

void	rotate_ab(t_stack **pp_node_a, t_stack **pp_node_b)
{
	rotate_a(pp_node_a);
	rotate_b(pp_node_b);
	write(1, "rr\n", 3);
}

void	reverse_rotate_a(t_stack **pp_node_a)
{
	t_stack	*temp_a;
	t_stack	*new_last;
	t_stack	*iter;

	if (!*pp_node_a || !(*pp_node_a)->next)
		return ;
	temp_a = *pp_node_a;
	iter = *pp_node_a;
	while (iter->next->next)
		iter = iter->next;
	new_last = iter;
	iter = iter->next;
	*pp_node_a = iter;
	iter->next = temp_a;
	new_last->next = NULL;
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack **pp_node_b)
{
	t_stack	*temp_b;
	t_stack	*new_last;
	t_stack	*iter;

	if (!*pp_node_b || !(*pp_node_b)->next)
		return ;
	temp_b = *pp_node_b;
	iter = *pp_node_b;
	while (iter->next->next)
		iter = iter->next;
	new_last = iter;
	iter = iter->next;
	*pp_node_b = iter;
	iter->next = temp_b;
	new_last->next = NULL;
	write(1, "rrb\n", 4);
}
