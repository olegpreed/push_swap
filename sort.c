/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:56:59 by preed             #+#    #+#             */
/*   Updated: 2022/03/14 20:44:22 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_i(t_stack *copy, int max)
{
	int	i;

	i = 0;
	while (copy->n != max)
	{
		i++;
		copy = copy->next;
	}
	return (i);
}

int	find_max(t_stack *copy, int *p_length)
{
	int	max;

	max = -1;
	while (copy)
	{
		if (copy->n > max)
			max = copy->n;
		copy = copy->next;
		(*p_length)++;
	}
	return (max);
}

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

void	final_sort(t_stack **pp_node_a, t_stack **pp_node_b)
{
	while (*pp_node_b)
		prepare_b(pp_node_a, pp_node_b);
}

void	sort(t_stack **pp_node_a, t_stack **pp_node_b)
{
	int	i;
	int	n;

	i = 0;
	n = 5;
	while (*pp_node_a)
	{
		if ((*pp_node_a)->n <= i)
		{
			push_b(pp_node_a, pp_node_b);
			i++;
		}
		else if ((*pp_node_a)->n <= (i + n))
		{
			push_b(pp_node_a, pp_node_b);
			rotate_b(pp_node_b);
			i++;
		}
		else
			rotate_a(pp_node_a);
	}
	final_sort(pp_node_a, pp_node_b);
}
