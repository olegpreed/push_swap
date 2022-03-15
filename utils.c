/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:40:14 by preed             #+#    #+#             */
/*   Updated: 2022/03/15 16:45:51 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doubles(char **argv, int argc)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < argc)
	{
		while (j < argc)
			if (!ft_strncmp(argv[i], argv[j++], 11))
				return (1);
		i++;
		j = i + 1;
	}
	return (0);
}

void	get_index(t_stack **pp_node)
{
	int		i;
	t_stack	*copy1;
	t_stack	*copy2;

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
		copy1 = copy1->next;
		copy2 = *pp_node;
	}
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
