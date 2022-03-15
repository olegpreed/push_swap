/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:19:54 by preed             #+#    #+#             */
/*   Updated: 2022/03/15 18:07:24 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_num(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '+' || string[i] == '-')
		{
			if (!ft_isdigit(string[i + 1]))
				return (1);
		}
		else if (!ft_isdigit(string[i]) && string[i] != ' ')
			return (1);
			i++;
	}
	return (0);
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
		c = ft_atoi(argv[j]);
		if (c > 2147483647 || c < -2147483648)
			return (1);
		p_node = int_lstnew(c);
		if (!p_node)
		{
			int_lstclear(pp_node);
			return (1);
		}
		j++;
		int_lstadd_back(pp_node, p_node);
	}
	get_index(pp_node);
	return (0);
}

int	string_to_args(char *string, int argc, t_stack **pp_node)
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
	while (string[i] != '\0')
	{
		if (string[i] == ' ')
		{
			while (string[i] == ' ')
			{	
				if (string[i + 1] == '\0')
					argc--;
				i++;
			}
			argc++;
		}
		i++;
	}
	if (!argc)
		return (1);
	if (string[0] == ' ')
		argc--;
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

int	make_stack_a(int argc, char **argv, t_stack **pp_node)
{
	if (argc == 0)
		return (1);
	if (argc == 1)
	{
		if (!argv[1])
			return (1);
		if (string_to_args(argv[0], argc, pp_node))
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
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	**pp_node_a;
	t_stack	*p_node_a;
	t_stack	**pp_node_b;
	t_stack	*p_node_b;

	p_node_a = NULL;
	p_node_b = NULL;
	pp_node_a = &p_node_a;
	pp_node_b = &p_node_b;
	if (make_stack_a(argc - 1, ++argv, pp_node_a))
		return (1);
	sort(pp_node_a, pp_node_b);
	int_lstclear(pp_node_a);
	int_lstclear(pp_node_b);
	return (0);
}
