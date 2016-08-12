# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/11 11:38:13 by fhuang            #+#    #+#              #
#    Updated: 2016/08/12 16:54:15 by fhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgame.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC_NAME = add.c game_start.c reverse.c rotate.c print.c push.c swap.c

SRC = $(SCR_NAME)

OBJ_PATH = ./OBJ/

OBJ_NAME = $(SRC_NAME:%.c=%.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

HEADER_PATH = -I ../../include/

LIBFT_PATH = -L ../../libft

LIBFT = -lft


.PHONY: clean fclean re all

all: $(NAME)

$(NAME): $(OBJ) $(SRC)
	@echo "----------------------------LIST_MOVES----------------------------"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
#	@$(CC) $(LIBFT_PATH) $(LIBFT) $^ -o $@	#$^ for $(OBJ) and $@ for $(NAME)

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
