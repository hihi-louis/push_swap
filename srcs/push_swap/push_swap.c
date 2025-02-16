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

int parse_arguments(int argc, char ***argv, char ***split_args)
{
    if (argc == 1)
        return (0);
    if (argc == 2 && !(*argv)[1][0])
    {
        ft_printf("Error\n");
        return (1);
    }
    if (argc == 2)
    {
        *split_args = push_swap_split((*argv)[1], ' ');
        if (!*split_args || !(*split_args)[0])
        {
            ft_printf("Error\n");
            ft_free_double_p((void **)*split_args);
            return (1);
        }
        *argv = *split_args;
    }
    else
        (*argv)++;
    return (0);
}

int main(int argc, char **argv)
{
    t_stack_node *a = NULL;
    t_stack_node *b = NULL;
    char **split_args = NULL;

    if (parse_arguments(argc, &argv, &split_args))
        return (1);

    init_stack_a(&a, argv);
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
    ft_free_double_p((void **)split_args);
    return (0);
}
