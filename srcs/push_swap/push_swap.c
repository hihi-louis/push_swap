/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trietpham <trietpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:02:29 by trietpham         #+#    #+#             */
/*   Updated: 2025/02/09 17:26:07 by trietpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int is_numeric(char *str)
{
    int i = 0;

    if (!str || !*str) // Check for empty string
        return (0);

    if (str[i] == '+' || str[i] == '-') // Allow leading sign
        i++;

    if (!str[i]) // Ensure at least one digit follows sign
        return (0);

    while (str[i])
    {
        if (!(str[i] >= '0' && str[i] <= '9')) // Reject non-numeric characters
            return (0);
        i++;
    }
    return (1);
}

static int  validate_args(char **argv)
{
    int i = 1;

    while (argv[i])
    {
        if (!is_numeric(argv[i])) // Check if the argument is a valid number
        {
            write(2, "Error\n", 6); // Print error message to stderr
            return (0);
        }
        i++;
    }
    return (1);
}

int main(int argc, char **argv)
{
    t_stack_node  *a;
    t_stack_node  *b;

    a = NULL;
    b = NULL;

    if (argc == 1 || (argc == 2 && (!argv[1][0] || error_syntax(argv[1]))))
    {
        write(2, "Error\n", 6);
        return (1);
    }

    if (argc == 2)
        argv = push_swap_split(argv[1], ' ');

    if (!validate_args(argv)) // Validate that all arguments are numbers
        return (1);

    init_stack_a(&a, argv + 1);

    if (!stack_sorted(a))
    {
        if (stack_len(a) == 2)
            sa(&a, false);
        else if (stack_len(a) == 3)
            sort_three(&a);
        else 
            sort_stack(&a, &b);
    }

    free_stack(&a);
    return (0);
}

// int main(int argc, char **argv)
// {
//   t_stack_node  *a;
//   t_stack_node  *b;

//   a = NULL;
//   b = NULL;
//   if (argc == 1 || (argc == 2 && !argv[1][0]))
//   {
//     ft_printf("Error\n");
//     return (1);
//   }
//   else if(argc == 2)
//     argv = push_swap_split(argv[1], ' ');
//   init_stack_a(&a, argv + 1);
//   if (!stack_sorted(a))
//   {
//     if (stack_len(a) == 2)
//       sa(&a, false);
//     else if (stack_len(a) == 3)
//       sort_three(&a);
//     else 
//       sort_stack(&a, &b);
//   }
//   free_stack(&a);
//   return (0);
// }