/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:33:41 by preed             #+#    #+#             */
/*   Updated: 2022/03/17 22:38:17 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				n;
	int				content;
	struct s_stack	*next;
}	t_stack;

void	free_pointers(t_stack *p_node, t_stack **pp_node);
int		push_args(char **argv, int argc, t_stack **pp_node);
int		string_to_args(char *string, int argc, t_stack **pp_node, int *p_argc);
int		make_stack_a(int argc, char **argv, t_stack **pp_node, int *p_argc);
void	int_lstadd_back(t_stack **lst, t_stack *new);
void	int_lstclear(t_stack **lst);
t_stack	*int_lstnew(int content);
int		lst_count(t_stack **pp_node);
void	swap_a(t_stack **pp_node_a);
void	swap_b(t_stack **pp_node_b);
void	swap_ab(t_stack **pp_node_a, t_stack **pp_node_b);
void	push_a(t_stack **pp_node_a, t_stack **pp_node_b);
void	push_b(t_stack **pp_node_a, t_stack **pp_node_b);
void	rotate_a(t_stack **pp_node_a);
void	rotate_b(t_stack **pp_node_b);
void	rotate_ab(t_stack **pp_node_a, t_stack **pp_node_b);
void	reverse_rotate_a(t_stack **pp_node_a);
void	reverse_rotate_b(t_stack **pp_node_b);
void	reverse_rotate_ab(t_stack **pp_node_a, t_stack **pp_node_b);
int		get_index(t_stack **pp_node);
void	sort(t_stack **pp_node_a, t_stack **pp_node_b, int argc);
void	print_lst(t_stack **pp);
int		check_doubles(char **argv, int argc);
int		check_num(char *string);
int		count_argc(char *string);
int		find_max_i(t_stack *copy, int max);
int		find_max(t_stack *copy, int *p_length);

#endif