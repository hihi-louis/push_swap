/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trietpham <trietpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:02:26 by trietpham         #+#    #+#             */
/*   Updated: 2025/02/08 16:51:17 by trietpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../library/libft/libft.h"
# include "../library/ft_printf/ft_printf.h"

typedef struct s_stack_node
{
  int         nbr;
  int         index; //The number's position in the stack
  int         push_cost;  //How many commands in total
  bool        above_median;  //Used to calculate `push_cost`
  bool        cheapest;  //The node that is the cheapest to do commands
  struct s_stack_node *target_node; //The target node of a node in the opposite stack
  struct s_stack_node *next;
  struct s_stack_node *prev;
} t_stack_node;

//Handle Error
int error_syntax(char *str);
int error_duplicate(t_stack_node *a, int n);
void  free_stack(t_stack_node **stack);
void  free_error(t_stack_node **a);
//Stack initation
void  init_stack_a(t_stack_node **a, char **argv);
char  **push_swap_split(char *s, char c);

//Node initation
t_stack_node  *get_cheapest(t_stack_node *stack);
void  pre_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name);
void  current_index(t_stack_node *stack);
void set_cheapest(t_stack_node *stack);
void  init_nodes_a(t_stack_node *a, t_stack_node *b);
void  init_node_b(t_stack_node *a, t_stack_node *b);
//Stack utils
int stack_len(t_stack_node *stack);
t_stack_node  *find_last_node(t_stack_node *stack);
bool  stack_sorted(t_stack_node *stack);
t_stack_node  *find_min(t_stack_node *stack);
t_stack_node  *find_max(t_stack_node *stack);
//Commands

void  sa(t_stack_node **a, bool print);
void  sb(t_stack_node **b, bool print);
void  ss(t_stack_node **a, t_stack_node **b, bool print);
void  ra(t_stack_node **a, bool print);
void  rb(t_stack_node **b, bool print);
void  sb(t_stack_node **b, bool print);
void  rr(t_stack_node **a, t_stack_node **b, bool print);
void  rra(t_stack_node **a, bool print);
void  rrb(t_stack_node **b, bool print);
void  rrr(t_stack_node **a, t_stack_node **b, bool print);
void  pa(t_stack_node **a, t_stack_node **b, bool print);
void  pb(t_stack_node **b, t_stack_node **a, bool print);

//Algorithrms
void  sort_three(t_stack_node **a);
void  sort_stack(t_stack_node **a, t_stack_node **b);
#endif