/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleg <oleg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:14:52 by oleg              #+#    #+#             */
/*   Updated: 2022/03/19 16:35:48 by oleg             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_pointers(t_stack *p_node, t_stack **pp_node)
{
	if (p_node)
		free(p_node);
	int_lstclear(pp_node);
}

int	push_args(char **argv, int argc, t_stack **pp_node)
{
	int				j;
	long long int	c;
	t_stack			*p_node;

	j = 0;
	if (check_doubles(argv, argc))
		return (1);
	while (j < argc)
	{
		if (check_num(argv[j]))
		{
			int_lstclear(pp_node);
			return (1);
		}
		c = ft_atoi(argv[j++]);
		p_node = int_lstnew(c);
		if (!p_node || (c > 2147483647 || c < -2147483648))
		{
			free_pointers(p_node, pp_node);
			return (1);
		}
		int_lstadd_back(pp_node, p_node);
	}
	return (0);
}

int	string_to_args(char *string, int argc, t_stack **pp_node, int *p_argc)
{
	int		i;
	int		j;
	char	num[100];
	char	**argv;

	ft_memset(num, 0, 100);
	i = 0;
	j = 0;
	if (check_num(string))
		return (1);
	argc = count_argc(string);
	*p_argc = argc;
	if (!argc)
		return (1);
	argv = ft_split(string, ' ');
	if (argv == 0)
		return (1);
	i = push_args(argv, argc, pp_node);
	while (argv[j])
		free(argv[j++]);
	free(argv);
	if (i)
		return (1);
	return (0);
}

int	make_stack_a(int argc, char **argv, t_stack **pp_node, int *p_argc)
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
	if (!get_index(pp_node))
	{
		int_lstclear(pp_node);
		return (1);
	}
	return (0);
}
