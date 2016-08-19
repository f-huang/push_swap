# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/11 11:38:13 by fhuang            #+#    #+#              #
#    Updated: 2016/08/18 17:38:45 by fhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#NAME = checker

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC_PATH = ./SRC/

SRC_NAME = $(shell ls SRC)

SRC = $(addprefix $(SRC_PATH), $(SCR_NAME))

OBJ_PATH = ./OBJ/

OBJ_NAME = $(SRC_NAME:%.c=%.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

HEADER_PATH = -Iinclude/

LIBFT_PATH = -Llibft

LIBFT = -lft

CHECKER = SRC/checker
GAMEPLAY = SRC/gameplay
PUSH_SWAP = SRC/push_swap

.PHONY: clean fclean re all

all: #$(NAME)

#$(NAME): $(OBJ) $(SRC)
#	@echo "----------------------------MINISHELL----------------------------"
	@$(MAKE) -C libft
	@$(MAKE) -C $(GAMEPLAY)
	@$(MAKE) -C $(CHECKER)
	@$(MAKE) -C $(PUSH_SWAP)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@echo "\033[1;32m" "Compiling $< into $@" "\033[0m"
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(HEADER_PATH)  -c $< -o $@
#$(CFLAGS)
clean:
	@rm -rf $(OBJ_PATH)
	@$(MAKE) clean -C libft
	@$(MAKE) clean -C $(GAMEPLAY)
	@$(MAKE) clean -C $(CHECKER)
	@$(MAKE) clean -C $(PUSH_SWAP)

fclean: clean
	@rm -f $(NAME)

re : fclean all
