/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:02:29 by trietpham         #+#    #+#             */
/*   Updated: 2025/02/19 19:46:47 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	parse_arguments(int argc, char ***argv, char ***split_args)
{
	if (argc == 1)
		return (0);
	if (argc == 2 && !(*argv)[1][0])
	{
		ft_printf("Error\n");
		return (1);
	}
	if (argc == 2)
	{
		*split_args = push_swap_split((*argv)[1], ' ');
		if (!*split_args || !(*split_args)[0])
		{
			ft_printf("Error\n");
			if (*split_args)
				ft_free_double_p((void **)*split_args);
			return (1);
		}
		*argv = *split_args;
	}
	else
		(*argv)++;
	return (0);
}

static void	sort_and_cleanup(t_stack_node **a, t_stack_node **b,
						char **split_args, bool allocated)
{
	if (!stack_sorted((*a)))
	{
		if (stack_len((*a)) == 2)
			sa(a, false);
		else if (stack_len((*a)) == 3)
			sort_three(a);
		else
			sort_stack(a, b);
	}
	free_stack(a);
	if (allocated)
		ft_free_double_p((void **)split_args);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**split_args;
	bool			allocated;

	split_args = NULL;
	allocated = false;
	a = NULL;
	b = NULL;
	if (parse_arguments(argc, &argv, &split_args))
		return (1);
	if (split_args)
		allocated = true;
	init_stack_a(&a, argv, allocated);
	sort_and_cleanup(&a, &b, split_args, allocated);
	return (0);
}
