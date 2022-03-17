/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:56:25 by oleg              #+#    #+#             */
/*   Updated: 2022/03/17 21:18:14 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
	get_commands(pp_node_a, pp_node_b, *p_argc);
	int_lstclear(pp_node_a);
	int_lstclear(pp_node_b);
	return (0);
	return (0);
}
