/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:19:54 by preed             #+#    #+#             */
/*   Updated: 2022/03/19 20:44:53 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (make_stack_a(argc - 1, ++argv, pp_node_a, p_argc) || argc == 1)
		return (1);
	print_lst(pp_node_a);
	sort(pp_node_a, pp_node_b, *p_argc);
	int_lstclear(pp_node_a);
	int_lstclear(pp_node_b);
	return (0);
}
