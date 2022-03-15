/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:51:52 by preed             #+#    #+#             */
/*   Updated: 2022/03/14 20:26:27 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **pp_node_a)
{
	t_stack	*p_node_a;
	t_stack	*temp;

	if (lst_count(pp_node_a) == 1 || !lst_count(pp_node_a))
		return ;
	printf("stack size: %d\n", lst_count(pp_node_a));
	p_node_a = *pp_node_a;
	temp = p_node_a->next->next;
	p_node_a->next->next = p_node_a;
	*pp_node_a = p_node_a->next;
	p_node_a->next = temp;
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **pp_node_b)
{
	t_stack	*p_node_b;
	t_stack	*temp;

	if (lst_count(pp_node_b) == 1 || !lst_count(pp_node_b))
		return ;
	printf("stack size: %d\n", lst_count(pp_node_b));
	p_node_b = *pp_node_b;
	temp = p_node_b->next->next;
	p_node_b->next->next = p_node_b;
	*pp_node_b = p_node_b->next;
	p_node_b->next = temp;
	write(1, "sb\n", 3);
}

void	swap_ab(t_stack **pp_node_a, t_stack **pp_node_b)
{
	swap_a(pp_node_a);
	swap_b(pp_node_b);
	write(1, "ss\n", 3);
}

void	push_b(t_stack **pp_node_a, t_stack **pp_node_b)
{
	t_stack	*temp_b;

	if (!*pp_node_a)
		return ;
	temp_b = *pp_node_b;
	*pp_node_b = *pp_node_a;
	*pp_node_a = (*pp_node_a)->next;
	(*pp_node_b)->next = temp_b;
	write(1, "pb\n", 3);
}

void	push_a(t_stack **pp_node_a, t_stack **pp_node_b)
{
	t_stack	*temp_a;

	if (!*pp_node_b)
		return ;
	temp_a = *pp_node_a;
	*pp_node_a = *pp_node_b;
	*pp_node_b = (*pp_node_b)->next;
	(*pp_node_a)->next = temp_a;
	write(1, "pa\n", 3);
}
