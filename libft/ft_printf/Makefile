# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/14 00:41:56 by iokuno            #+#    #+#              #
#    Updated: 2025/08/29 04:10:40 by iokuno           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_printf.a

CC		= cc
CFLAGS	= -Wall -Werror -Wextra -Iinc -MMD -MP

AR		= ar rcs
RM		= rm -fr

INC_DIR  := inc
SRC_DIR  := src
OBJ_DIR  := obj

SRCS	= $(SRC_DIR)/ft_printf.c \
		$(SRC_DIR)/printf_put_char.c \
		$(SRC_DIR)/printf_put_fmt.c

OBJS     := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS     := $(OBJS:.o=.d)

all : $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re