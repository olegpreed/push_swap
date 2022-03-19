/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:56:25 by oleg              #+#    #+#             */
/*   Updated: 2022/03/18 16:36:25 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	b_make_stack_a(int argc, char **argv, t_stack **pp_node, int *p_argc)
{
	if (argc == 1)
	{
		if (!argv[0][0])
			return (1);
		if (string_to_args(argv[0], argc, pp_node, p_argc))
		{
			write(1, "Error\n", 6);
			return (1);
		}
	}
	if (argc > 1)
	{
		if (push_args(argv, argc, pp_node))
		{
			write(1, "Error\n", 6);
			return (1);
		}
		*p_argc = argc;
	}
	get_index(pp_node);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	**pp_node_a;
	t_stack	*p_node_a;
	t_stack	**pp_node_b;
	t_stack	*p_node_b;
	int		*p_argc;

	p_argc = &argc;
	p_node_a = NULL;
	p_node_b = NULL;
	pp_node_a = &p_node_a;
	pp_node_b = &p_node_b;
	if (b_make_stack_a(argc - 1, ++argv, pp_node_a, p_argc) || argc == 1)
		return (1);
	get_commands(pp_node_a, pp_node_b, *p_argc);
	int_lstclear(pp_node_a);
	int_lstclear(pp_node_b);
	return (0);
	return (0);
}
