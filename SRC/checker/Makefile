# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/11 11:38:13 by fhuang            #+#    #+#              #
#    Updated: 2016/08/11 20:38:05 by fhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC_NAME = checker.c follow_instruc.c main.c

SRC = $(SCR_NAME)

OBJ_PATH = ./OBJ/

OBJ_NAME = $(SRC_NAME:%.c=%.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

HEADER_PATH = -I ../../include/

LIBFT_PATH = -L ../../libft

LIBFT = -lft

LIST_PATH = ../list_moves/liblist.a

.PHONY: clean fclean re all

all: $(NAME)

$(NAME): $(OBJ) $(SRC)
	@echo "----------------------------CHECKER----------------------------"
	@$(CC) $(LIST_PATH) $(LIBFT_PATH) $(LIBFT) $^ -o $@	#$^ for $(OBJ) and $@ for $(NAME)

$(OBJ_PATH)%.o : %.c
	@echo "\033[1;32m" "Compiling $< into $@" "\033[0m"
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(HEADER_PATH)  -c $< -o $@
#$(CFLAGS)
clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -f $(NAME)

re : fclean all
