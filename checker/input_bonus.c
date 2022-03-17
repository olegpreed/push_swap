/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:23:51 by oleg              #+#    #+#             */
/*   Updated: 2022/03/17 21:09:51 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	execute_command(char *command, t_stack **pp_node_a, t_stack **pp_node_b)
{
	if (!ft_strncmp(command, "sa", 4))
		swap_a(pp_node_a);
	else if (!ft_strncmp(command, "sb", 4))
		swap_b(pp_node_b);
	else if (!ft_strncmp(command, "ss", 4))
		swap_ab(pp_node_a, pp_node_a);
	else if (!ft_strncmp(command, "pa", 4))
		push_a(pp_node_a, pp_node_a);
	else if (!ft_strncmp(command, "pb", 4))
		push_b(pp_node_a, pp_node_a);
	else if (!ft_strncmp(command, "ra", 4))
		rotate_a(pp_node_a);
	else if (!ft_strncmp(command, "rb", 4))
		rotate_b(pp_node_b);
	else if (!ft_strncmp(command, "rr", 4))
		rotate_ab(pp_node_a, pp_node_b);
	else if (!ft_strncmp(command, "rra", 4))
		reverse_rotate_a(pp_node_a);
	else if (!ft_strncmp(command, "rra", 4))
		reverse_rotate_b(pp_node_b);
	else if (!ft_strncmp(command, "rra", 4))
		reverse_rotate_ab(pp_node_a, pp_node_b);
	else
		write(1, "Error\n", 6);
}

int	get_commands(t_stack **pp_node_a, t_stack **pp_node_b, int argc)
{
	char	command[4];

	(void)argc;
	ft_memset(command, '0', 4);
	while (read(0, command, 4))
		execute_command(command, pp_node_a, pp_node_b);
	return (0);
}