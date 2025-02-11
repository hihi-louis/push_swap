/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trietpham <trietpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:20:36 by trietpham         #+#    #+#             */
/*   Updated: 2025/02/04 22:39:55 by trietpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void append_node(t_stack_node **stack, int n)
{
  t_stack_node  *node;
  t_stack_node  *last_node;

  if (!stack)
    return ;
  node = malloc(sizeof(t_stack_node));
  if (!node)
    return ;
  node->next = NULL;
  node->nbr = n;
  node->cheapest = 0;
  if (!(*stack))
  {
    *stack = node;
    node->prev = NULL;
  }
  else
  {
    last_node = find_last_node(*stack);
    last_node->next = node;
    node->prev = last_node;
  }
}

void  init_stack_a(t_stack_node **a, char **argv)
{
  long  n;
  int i;

  i = 0;
  while (argv[i])
  {
    if (error_syntax(argv[i]))
      free_error(a);
    n = ft_atol(argv[i]);
    if (n > INT_MAX || n < INT_MIN)
      free_error(a);
    if (error_duplicate(*a, (int)n))
      free_error(a);
    append_node(a, (int)n);
    i++;
  }
}
//Define a function that searches for the cheapest node, that is set by boo
t_stack_node  *get_cheapest(t_stack_node *stack)
{
  if (!stack)
    return (NULL);
  while (stack)
  {
    if (stack->cheapest)
      return (stack);
    stack = stack->next;
  }
  return (NULL);
}

//Define a function that moves the required node to the top of the stack
void  pre_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name)
{
  if (!stack || !*stack || !top_node)
    return ;
  while(*stack != top_node) //Check if the required node is not already the first node
  {
    if (stack_name == 'a')
    {
      if (top_node->above_median)
        ra(stack, false);
      else
        rra(stack, false);
    }
    else if (stack_name == 'b')
    {
      if (top_node->above_median)
        rb(stack, false);
      else
        rrb(stack, false);
    }
    if (!(*stack) || *stack == NULL)
            break ;
  }
}