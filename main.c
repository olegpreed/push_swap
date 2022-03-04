/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:19:54 by preed             #+#    #+#             */
/*   Updated: 2022/03/04 16:47:15 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_num(char *string)
{
	int	i;

	i = 0;
	if(string[i] == '-' || string[i] == '+')
		i++;
	while(string[i] != '\0')
	{
		if(!ft_isdigit(string[i++]))
			return (1);
	}
	return (0);
}

int	push_args(char **argv, int argc, s_list *first)
{
	int	i;
	int j;
	
	i = 0;
	j = 1;
	while (j < argc)
	{
		if (check_num(argv[j]))
			return (1);
		first->n = ft_atoi(argv[j]);
		
		
		
	}
		
}

int	string_to_args(char *string)
{
	int	i;

	i = 0;
	while(string[i] != '\0')
	{
		if(!ft_isdigit(string[i++]))
			return (0);
	}
	printf("numbers!\n");
	return (1);
}

int	check(int argc, char **argv, s_list *first)
{
	if (argc == 1)
		return (2);
	if (argc == 2)
		if (string_to_args(argv[1]))
			return (1);
	if (argc > 2)
		if (push_args(argv, argc, first))
			return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	s_list *first;

	first = ft_calloc(1, sizeof(s_list));
	check(argc, argv, first);
	if (argc == 2)
		printf("%s, %s\n", argv[0], argv[1]);
	return (0);
}