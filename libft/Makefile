# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/28 22:30:37 by iokuno            #+#    #+#              #
#    Updated: 2025/09/22 21:15:18 by iokuno           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     := libft.a
AR       := ar
ARFLAGS  := rcs
RANLIB   := ranlib
MAKEFLAGS += --no-print-directory

MYLIB_DIR     := mylib
MYLIB_LIB     := $(MYLIB_DIR)/mylib.a

FT_PRINTF_DIR := ft_printf
FT_PRINTF_LIB := $(FT_PRINTF_DIR)/ft_printf.a

SUBDIRS := $(MYLIB_DIR) $(FT_PRINTF_DIR)
SUBLIBS := $(MYLIB_LIB) $(FT_PRINTF_LIB)

.PHONY: all libs clean fclean re

all: $(NAME)

libs: $(SUBLIBS)

$(MYLIB_LIB):
	$(MAKE) -C $(MYLIB_DIR)

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(NAME): libs
	@rm -f $@
	@{ \
		echo "create $@"; \
		echo "addlib $(MYLIB_LIB)"; \
		echo "addlib $(FT_PRINTF_LIB)"; \
		echo "save"; \
		echo "end"; \
	} > .ar.mri
	@$(AR) -M < .ar.mri
	@rm -f .ar.mri
	@$(RANLIB) $@
	@echo "==> built $@ from: $(notdir $(SUBLIBS))"

clean:
	@for d in $(SUBDIRS); do $(MAKE) -C $$d clean; done

fclean:
	@for d in $(SUBDIRS); do $(MAKE) -C $$d fclean; done
	@rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
