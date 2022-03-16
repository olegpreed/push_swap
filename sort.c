/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:56:59 by preed             #+#    #+#             */
/*   Updated: 2022/03/16 20:45:31 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prepare_b(t_stack **pp_node_a, t_stack **pp_node_b)
{
	int		length;
	int		i;
	int		j;
	int		max;
	t_stack	*copy;

	copy = *pp_node_b;
	length = 0;
	j = 0;
	i = 0;
	max = find_max(copy, &length);
	i = find_max_i(copy, max);
	if (i < length / 2)
	{
		while (j++ < i)
			rotate_b(pp_node_b);
		push_a(pp_node_a, pp_node_b);
	}
	else
	{
		while (i++ < length - 1)
			reverse_rotate_b(pp_node_b);
		reverse_rotate_b(pp_node_b);
		push_a(pp_node_a, pp_node_b);
	}
}

void	sort_many(t_stack **pp_node_a, t_stack **pp_node_b, int argc)
{
	int	i;
	int	mystery_number;

	i = 0;
	mystery_number = 15;
	if (argc > 100)
		mystery_number = 30;
	while (*pp_node_a)
	{
		if ((*pp_node_a)->n <= i)
		{
			push_b(pp_node_a, pp_node_b);
			i++;
		}
		else if ((*pp_node_a)->n <= (i + mystery_number))
		{
			push_b(pp_node_a, pp_node_b);
			rotate_b(pp_node_b);
			i++;
		}
		else
			rotate_a(pp_node_a);
	}
	while (*pp_node_b)
		prepare_b(pp_node_a, pp_node_b);
}

void	sort_three(t_stack **pp_node_a)
{
	int	length;
	int	max;
	int	i_max;

	if ((*pp_node_a)->n < (*pp_node_a)->next->n
		&& (*pp_node_a)->next->n < (*pp_node_a)->next->next->n)
		return ;
	length = 0;
	max = find_max(*pp_node_a, &length);
	i_max = find_max_i(*pp_node_a, max);
	if (i_max == 0)
	{
		rotate_a(pp_node_a);
		if ((*pp_node_a)->n > (*pp_node_a)->next->n)
			swap_a(pp_node_a);
	}
	else if (i_max == 1)
	{
		reverse_rotate_a(pp_node_a);
		if ((*pp_node_a)->n > (*pp_node_a)->next->n)
			swap_a(pp_node_a);
	}
	else if (i_max == 2)
		swap_a(pp_node_a);
}

void	sort_five(t_stack **pp_node_a, t_stack **pp_node_b)
{
	int	length;
	int	i_max;

	length = 0;
	while (length != 4)
	{
		i_max = find_max_i(*pp_node_a, find_max(*pp_node_a, &length));
		if (i_max <= (length - 1) / 2)
			while (i_max--)
				rotate_a(pp_node_a);
		else
			while (i_max++ != length)
				reverse_rotate_a(pp_node_a);
		push_b(pp_node_a, pp_node_b);
		if (length != 4)
			length = 0;
	}
	sort_three(pp_node_a);
	push_a(pp_node_a, pp_node_b);
	rotate_a(pp_node_a);
	push_a(pp_node_a, pp_node_b);
	rotate_a(pp_node_a);
}

void	sort(t_stack **pp_node_a, t_stack **pp_node_b, int argc)
{
	if (argc == 2)
		swap_a(pp_node_a);
	else if (argc == 3)
		sort_three(pp_node_a);
	else if (argc == 5)
		sort_five(pp_node_a, pp_node_b);
	else
		sort_many(pp_node_a, pp_node_b, argc);
	(void)pp_node_b;
}
