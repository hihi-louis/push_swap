/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:12:12 by trietpham         #+#    #+#             */
/*   Updated: 2025/02/18 15:59:11 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*second_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last_node(*stack);
	second_last = last->prev;
	if (second_last)
		second_last->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_stack_node **a, bool print)
{
	rev_rotate(a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, bool print)
{
	rev_rotate(b);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!print)
		ft_printf("rrr\n");
}
