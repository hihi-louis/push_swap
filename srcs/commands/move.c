/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:30:23 by tripham           #+#    #+#             */
/*   Updated: 2025/02/18 19:46:58 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (!cheapest_node)
		return ;
	if (!cheapest_node->target_node)
		return ;
	if ((cheapest_node->above_median)
		&&!(cheapest_node->target_node->above_median))
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	pre_for_push(a, cheapest_node, 'a');
	pre_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a, false);
}

void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	pre_for_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
}
