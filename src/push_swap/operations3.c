/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:50:40 by preed             #+#    #+#             */
/*   Updated: 2022/03/18 14:40:53 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_ab(t_stack **pp_node_a, t_stack **pp_node_b)
{
	reverse_rotate_a(pp_node_a);
	reverse_rotate_b(pp_node_b);
	write(1, "rrr\n", 4);
}
