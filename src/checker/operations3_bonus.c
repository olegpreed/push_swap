/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 20:50:40 by preed             #+#    #+#             */
/*   Updated: 2022/03/20 00:30:15 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	b_reverse_rotate_ab(t_stack **pp_node_a, t_stack **pp_node_b)
{
	b_reverse_rotate_a(pp_node_a);
	b_reverse_rotate_b(pp_node_b);
}
