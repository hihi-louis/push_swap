/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trietpham <trietpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 22:38:10 by trietpham         #+#    #+#             */
/*   Updated: 2025/02/08 17:01:08 by trietpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void  sort_three(t_stack_node **a)
{
  t_stack_node  *biggest_node;

  // if (!a || !*a || !(*a)->next || !(*a)->next->next)
  //   return;
  biggest_node = find_max(*a);
  
  if (biggest_node == *a)
    ra(a, false);
  else if ((*a)->next == biggest_node)
    rra(a, false);
  if ((*a)->nbr > (*a)->next->nbr)
    sa(a, false);
}