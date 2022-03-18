/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:23:51 by oleg              #+#    #+#             */
/*   Updated: 2022/03/18 16:36:12 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	execute_command(char *command, t_stack **pp_node_a, t_stack **pp_node_b)
{
	if (!ft_strncmp(command, "sa\n", 4))
		b_swap_a(pp_node_a);
	else if (!ft_strncmp(command, "sb\n", 4))
		b_swap_b(pp_node_b);
	else if (!ft_strncmp(command, "ss\n", 3))
		b_swap_ab(pp_node_a, pp_node_b);
	else if (!ft_strncmp(command, "pa\n", 3))
		b_push_a(pp_node_a, pp_node_b);
	else if (!ft_strncmp(command, "pb\n", 3))
		b_push_b(pp_node_a, pp_node_b);
	else if (!ft_strncmp(command, "ra\n", 3))
		b_rotate_a(pp_node_a);
	else if (!ft_strncmp(command, "rb\n", 3))
		b_rotate_b(pp_node_b);
	else if (!ft_strncmp(command, "rr\n", 3))
		b_rotate_ab(pp_node_a, pp_node_b);
	else if (!ft_strncmp(command, "rra\n", 4))
		b_reverse_rotate_a(pp_node_a);
	else if (!ft_strncmp(command, "rrb\n", 4))
		b_reverse_rotate_b(pp_node_b);
	else if (!ft_strncmp(command, "rrr\n", 4))
		b_reverse_rotate_ab(pp_node_a, pp_node_b);
	else
		write(1, "Error\n", 6);
}

int	get_commands(t_stack **pp_node_a, t_stack **pp_node_b, int argc)
{
	char	command[4];

	(void)argc;
	ft_memset(command, '\0', 4);
	while (read(0, command, 4))
	{
		execute_command(command, pp_node_a, pp_node_b);
		ft_memset(command, '\0', 4);
	}
	if (!get_index(pp_node_a) && !(*pp_node_b))
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	return (0);
}
