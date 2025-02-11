/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trietpham <trietpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:39:44 by trietpham         #+#    #+#             */
/*   Updated: 2025/02/09 17:20:35 by trietpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <ctype.h>
int error_syntax(char *str)
{
  if (!str || !*str) // Check for empty string
        return (1);

    // Check if the string contains only whitespace
    if (ft_is_all_white_spaces(str))
        return (1);

    if (*str == '+' || *str == '-') // Allow leading sign
        str++;

    if (!(*str >= '0' && *str <= '9')) // Ensure at least one digit follows sign
        return (1);

    while (*str)
    {
        if (!(*str >= '0' && *str <= '9')) // If any non-digit is found
            return (1);
        str++;
    }
    return (0);
}

int error_duplicate(t_stack_node *a, int n)
{
  if (!a)
    return (0);
  while (a)
  {
    if (a->nbr == n)
      return (1);
    a = a->next;
  }
  return (0);
}

void  free_stack(t_stack_node **stack)
{
  t_stack_node  *tmp;
  t_stack_node  *current;

  if (!stack || !*stack)
    return ;
  current = *stack;
  while (current)
  {
    tmp = current->next;
    current->nbr = 0;
    free(current);
    current = tmp;
  }
  *stack = NULL;
}

void  free_error(t_stack_node **a)
{
  free_stack(a);
  ft_printf("Error\n");
  exit (1);
}