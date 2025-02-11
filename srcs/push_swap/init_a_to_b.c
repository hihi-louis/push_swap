/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trietpham <trietpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:53:35 by trietpham         #+#    #+#             */
/*   Updated: 2025/02/08 17:24:52 by trietpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void  current_index(t_stack_node *stack)
{
  int i;
  int median; //To store the position of the median of the stack

  i = 0;
  if (!stack)
    return ;
  median = stack_len(stack) / 2;
  while (stack)
  {
    stack->index = i;
    if (i <= median)
      stack->above_median = true;
    else
      stack->above_median = false;
    stack = stack->next;
    ++i;
  }
}

static void set_target_a(t_stack_node *a, t_stack_node *b)
{
  t_stack_node  *current_b;
  t_stack_node  *target_node;
  long          best_match_index;

  while (a)
  {
    best_match_index = LONG_MIN;
    target_node = NULL;
    current_b = b;
    while (current_b)
    {
      if (current_b->nbr < a->nbr && current_b->nbr > best_match_index)
      {
        best_match_index = current_b->nbr;
        target_node = current_b;
      }
      current_b = current_b->next;
    }
    if (!target_node)
      a->target_node = find_max(b);
    else
      a->target_node = target_node;
    a = a->next;
  }
}

static void cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
  int len_a;
  int len_b;

  if (!a || !b)
    return ;
  len_a = stack_len(a);
  len_b = stack_len(b);

  while (a)
  {
    if (a->above_median)
      a->push_cost = a->index;
    else
      a->push_cost = len_a - a->index;
    if (!a->target_node)
    {
      a = a->next;
      continue;
    }
    if (a->target_node->above_median)
      a->push_cost += a->target_node->index;
    else
      a->push_cost += len_b - a->target_node->index;
    a = a->next;
  }
}

void set_cheapest(t_stack_node *stack)
{
  long  cheapest_value;
  t_stack_node  *cheapest_node;
  t_stack_node  *temp;

  if(!stack)
    return ;
  temp = stack;
  while (temp)
  {
    temp->cheapest =false;
    temp = temp->next;
  }
  cheapest_value = LONG_MAX;
  cheapest_node = NULL;
  while(stack)
  {
    if (stack->push_cost < cheapest_value)
    {
      cheapest_value = stack->push_cost;
      cheapest_node = stack;
    }
    stack = stack->next;
  }
  if (cheapest_node != NULL)
    cheapest_node->cheapest = true;
}
void  init_nodes_a(t_stack_node *a, t_stack_node *b)
{
  current_index(a);
  current_index(b);
  set_target_a(a, b);
  cost_analysis_a(a, b);
  set_cheapest(a);
}