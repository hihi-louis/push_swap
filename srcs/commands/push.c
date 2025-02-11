/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trietpham <trietpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 22:19:30 by trietpham         #+#    #+#             */
/*   Updated: 2025/02/08 16:54:37 by trietpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void push(t_stack_node **destination, t_stack_node **source)
{
  t_stack_node  *push_node;

  if (!source || !*source)
    return ;
  
  push_node = *source;
  *source = (*source)->next;
  if (*source)
    (*source)->prev = NULL;
  push_node->prev = NULL;
  if (!destination || !*destination)
  {
    *destination = push_node;
    push_node->next = NULL;
  }
  else
  {
    push_node->next = *destination;
    push_node->next->prev = push_node;
    *destination = push_node;
  } 
}

void  pa(t_stack_node **a, t_stack_node **b, bool print)
{
  push(a, b);
  if (!print)
    ft_printf("pa\n");
}

void  pb(t_stack_node **b, t_stack_node **a, bool print)
{
  push(b, a);
  if (!print)
    ft_printf("pb\n");
}