/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trietpham <trietpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:52:31 by trietpham         #+#    #+#             */
/*   Updated: 2025/01/30 18:12:32 by trietpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int stack_len(t_stack_node *stack)
{
  int count;

  if (!stack)
    return (0);
  count = 0;
  while (stack)
  {
    stack = stack->next;
    count++;
  }
  return (count);
}

t_stack_node  *find_last_node(t_stack_node *stack)
{
  if (!stack)
    return (NULL);
  while (stack->next)
    stack = stack->next;
  return (stack);
}

bool  stack_sorted(t_stack_node *stack)
{
  if (!stack)
    return (1);
  while (stack->next)
  {
    if (stack->nbr > stack->next->nbr)
      return (false);
    stack = stack->next;
  }
  return (true);
}

t_stack_node  *find_min(t_stack_node *stack)
{
  long          min;
  t_stack_node  *min_node;

  if (!stack)
    return (NULL);
  min = LONG_MAX;
  while (stack)
  {
    if (stack->nbr < min)
    {
      min = stack->nbr;
      min_node = stack;
    }
    stack = stack->next;
  }
  return (min_node);
}

t_stack_node  *find_max(t_stack_node *stack)
{
  long          max;
  t_stack_node  *max_node;

  while (!stack)
    return (NULL);
  max = LONG_MIN;
  while (stack)
  {
    if (stack->nbr > max)
    {
      max = stack->nbr;
      max_node = stack;
    }
    stack = stack->next;
  }
  return (max_node);
}