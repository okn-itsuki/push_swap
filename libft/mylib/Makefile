# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/29 04:20:55 by iokuno            #+#    #+#              #
#    Updated: 2025/09/12 15:39:43 by iokuno           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = mylib.a

CC      = cc
CFLAGS  = -Wall -Werror -Wextra -MMD -MP
AR      = ar rcs
RM      = rm -fr

INC_DIR := inc
SRC_DIR := src
OBJ_DIR := obj

SRCFILES := \
    ft_abs.c ft_atof.c ft_atoi.c ft_bzero.c ft_calloc.c \
    ft_free_split.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
    ft_isprime.c ft_isprint.c ft_itoa.c ft_labs.c \
    ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
    ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \
    ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
    ft_realloc.c ft_meta_free.c ft_print_split.c \
    ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
    ft_split.c ft_splitlen.c ft_strchr.c ft_strcmp.c ft_strdup.c \
    ft_strendswith.c ft_striteri.c ft_strjoin.c ft_strjoin_free.c \
    ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strnlen.c ft_strmapi.c \
    ft_strncmp.c ft_strndup.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
    ft_substr.c ft_tolower.c ft_toupper.c ft_wordcount.c \
    ft_find_next_line.c get_next_line.c

SRCS := $(addprefix $(SRC_DIR)/,$(SRCFILES))
OBJS := $(addprefix $(OBJ_DIR)/,$(SRCFILES:.c=.o))
DEPS := $(OBJS:.o=.d)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)
