/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:40:14 by preed             #+#    #+#             */
/*   Updated: 2022/03/16 17:27:20 by preed            ###   ########.fr       */
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

int	count_argc(char *string)
{
	int	i;
	int	argc;

	i = 0;
	argc = 1;
	while (string[i] != '\0')
	{
		if (string[i] == ' ')
		{
			while (string[i] == ' ')
			{	
				if (string[i + 1] == '\0')
					argc--;
				i++;
			}
			argc++;
		}
		i++;
	}
	if (string[0] == ' ')
		argc--;
	return (argc);
}

int	get_index(t_stack **pp_node)
{
	int		i;
	int		j;
	t_stack	*copy1;
	t_stack	*copy2;

	j = 0;
	copy1 = *pp_node;
	copy2 = *pp_node;
	while (copy1)
	{
		i = 0;
		while (copy2)
		{
			if (copy1->content > copy2->content)
				i++;
			copy2 = copy2->next;
		}
		copy1->n = i;
		if (copy1->next)
			if (copy1->next->content < copy1->content)
				j = 1;
		copy1 = copy1->next;
		copy2 = *pp_node;
	}
	return (j);
}

void	print_lst(t_stack **pp)
{
	t_stack	*check;

	check = *pp;
	if (!check)
	{
		printf("stack is empty\n");
		return ;
	}
	while (check->next)
	{
		printf("%d: %d\n", check->n, check->content);
		check = check->next;
	}
	printf("%d: %d\n", check->n, check->content);
}
