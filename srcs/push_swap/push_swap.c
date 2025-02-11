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

static void free_split(char **split)
{
    int i = 0;

    if (!split) // Check if split is NULL before attempting to free
        return;
    
    while (split[i]) // Free each allocated string
    {
        free(split[i]);
        i++;
    }
    free(split); // Free the array itself
}

int main(int argc, char **argv)
{
    t_stack_node  *a;
    t_stack_node  *b;
    char **split_args = NULL; // Store split arguments separately

    a = NULL;
    b = NULL;

    // Case where no arguments or only empty input is provided
    if (argc == 1 || (argc == 2 && !argv[1][0])) 
    {
        ft_printf("Error\n");
        return (1);
    }

    // Handle case where input is a single quoted string (e.g., "./push_swap '3 2 1'")
    if (argc == 2)
    {
        split_args = push_swap_split(argv[1], ' ');
        if (!split_args || !split_args[0]) // If splitting failed or returned an empty array
        {
            ft_printf("Error\n");
            free_split(split_args); // Free memory before exiting
            return (1);
        }
        argv = split_args;
    }
    else
    {
        argv++; // Skip program name for normal input
    }

    // Ensure argv contains at least one valid argument
    if (!argv[0])
    {
        ft_printf("Error\n");
        free_split(split_args); // Free memory before exiting
        return (1);
    }

    init_stack_a(&a, argv); // Pass the split arguments to stack initialization

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
    free_split(split_args); // Free allocated memory

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