/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:51:52 by preed             #+#    #+#             */
/*   Updated: 2022/03/17 22:46:10 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	b_swap_a(t_stack **pp_node_a)
{
	t_stack	*p_node_a;
	t_stack	*temp;

	if (lst_count(pp_node_a) == 1 || !lst_count(pp_node_a))
		return ;
	p_node_a = *pp_node_a;
	temp = p_node_a->next->next;
	p_node_a->next->next = p_node_a;
	*pp_node_a = p_node_a->next;
	p_node_a->next = temp;
}

void	b_swap_b(t_stack **pp_node_b)
{
	t_stack	*p_node_b;
	t_stack	*temp;

	if (lst_count(pp_node_b) == 1 || !lst_count(pp_node_b))
		return ;
	p_node_b = *pp_node_b;
	temp = p_node_b->next->next;
	p_node_b->next->next = p_node_b;
	*pp_node_b = p_node_b->next;
	p_node_b->next = temp;
}

void	b_swap_ab(t_stack **pp_node_a, t_stack **pp_node_b)
{
	swap_a(pp_node_a);
	swap_b(pp_node_b);
}

void	b_push_b(t_stack **pp_node_a, t_stack **pp_node_b)
{
	t_stack	*temp_b;

	if (!*pp_node_a)
		return ;
	temp_b = *pp_node_b;
	*pp_node_b = *pp_node_a;
	*pp_node_a = (*pp_node_a)->next;
	(*pp_node_b)->next = temp_b;
}

void	b_push_a(t_stack **pp_node_a, t_stack **pp_node_b)
{
	t_stack	*temp_a;

	if (!*pp_node_b)
		return ;
	temp_a = *pp_node_a;
	*pp_node_a = *pp_node_b;
	*pp_node_b = (*pp_node_b)->next;
	(*pp_node_a)->next = temp_a;
}
