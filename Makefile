# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trietpham <trietpham@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/08 11:45:55 by trietpham         #+#    #+#              #
#    Updated: 2025/02/09 12:42:52 by trietpham        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC      := cc
CFLAGS  := -Wall -Wextra -Werror

# Directories
SRCDIR  := srcs
INCDIR  := include
LIBFTDIR   := library/libft
PRINTF_DIR := library/ft_printf

# Source files (ensure proper pathing)
SRCS := $(SRCDIR)/commands/push.c $(SRCDIR)/commands/rev_rotate.c $(SRCDIR)/commands/rotate.c \
        $(SRCDIR)/commands/sort_stacks.c $(SRCDIR)/commands/sort_three.c $(SRCDIR)/commands/swap.c \
        $(SRCDIR)/push_swap/handle_error.c $(SRCDIR)/push_swap/init_a_to_b.c $(SRCDIR)/push_swap/init_b_to_a.c \
        $(SRCDIR)/push_swap/push_swap_split.c $(SRCDIR)/push_swap/push_swap.c $(SRCDIR)/push_swap/stack_init.c \
        $(SRCDIR)/push_swap/stack_utils.c

# Executable name
NAME := push_swap

# Library files
LIBFT  := $(LIBFTDIR)/libft.a
PRINTF := $(PRINTF_DIR)/libftprintf.a

# Default rule
all: $(NAME)

# Compile the executable directly with the libraries
$(NAME): $(SRCS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -I$(INCDIR) $(SRCS) $(LIBFT) $(PRINTF) -o $(NAME)

# Build Libft
$(LIBFT):
	make -C $(LIBFTDIR)

# Build Ft_printf
$(PRINTF):
	make -C $(PRINTF_DIR)

# Cleaning rules
clean:
	make -C $(LIBFTDIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
