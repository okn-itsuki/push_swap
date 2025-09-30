# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/22 20:49:29 by iokuno            #+#    #+#              #
#    Updated: 2025/09/29 21:17:04 by iokuno           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
RM			= rm -fr

COMMON_CFLAGS = \
				-g \
				-Wall -Wextra -Werror \
				-I./libft/ft_printf/inc \
				-I./libft/mylib/inc

CFLAGS		= $(COMMON_CFLAGS) -I./inc

BONUS_CFLAGS = $(COMMON_CFLAGS) -I./inc_bonus

LIBFT_DIR	= libft
LIBFT_LIB	= $(LIBFT_DIR)/libft.a

SRCDIR		= src
OBJDIR		= obj

SRCFILE		= main.c \
		sort/push.c \
		sort/rev_rotate.c \
		sort/rotate.c \
		sort/swap.c \
		stack_op/case_five.c \
		stack_op/case_three.c \
		stack_op/case_two.c \
		stack_op/general_sort.c \
		utility/assign_index.c \
		utility/atoi_check.c \
		utility/free_stack.c \
		utility/handle_error.c \
		utility/init_stack.c \
		utility/is_sorted.c \
		utility/stack_size.c

SRCS		= $(addprefix $(SRCDIR)/, $(SRCFILE))
OBJS		= $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJDIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all