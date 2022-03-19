/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:17:12 by oleg              #+#    #+#             */
/*   Updated: 2022/03/19 20:58:31 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"

int		get_commands(t_stack **pp_node_a, t_stack **pp_node_b, int argc);
void	b_swap_a(t_stack **pp_node_a);
void	b_swap_b(t_stack **pp_node_b);
void	b_swap_ab(t_stack **pp_node_a, t_stack **pp_node_b);
void	b_push_a(t_stack **pp_node_a, t_stack **pp_node_b);
void	b_push_b(t_stack **pp_node_a, t_stack **pp_node_b);
void	b_rotate_a(t_stack **pp_node_a);
void	b_rotate_b(t_stack **pp_node_b);
void	b_rotate_ab(t_stack **pp_node_a, t_stack **pp_node_b);
void	b_reverse_rotate_a(t_stack **pp_node_a);
void	b_reverse_rotate_b(t_stack **pp_node_b);
void	b_reverse_rotate_ab(t_stack **pp_node_a, t_stack **pp_node_b);

#endif