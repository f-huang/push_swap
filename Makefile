# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/11 11:38:13 by fhuang            #+#    #+#              #
#    Updated: 2016/08/25 18:43:48 by fhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker
NAME2 = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC_PATH = ./SRC/gameplay/
SRC_PATH1 = ./SRC/checker/
SRC_PATH2 = ./SRC/push_swap/

SRC_NAME = $(shell ls $(SRC_PATH))
SRC_NAME1 = $(shell ls $(SRC_PATH1))
SRC_NAME2 = $(shell ls $(SRC_PATH2))

SRC = $(addprefix $(SRC_PATH), $(SCR_NAME))
SRC1 = $(addprefix $(SRC_PATH1), $(SCR_NAME1))
SR2 = $(addprefix $(SRC_PATH2), $(SCR_NAME2))

OBJ_PATH = ./OBJ/gameplay/
OBJ_PATH1 = ./OBJ/checker/
OBJ_PATH2 = ./OBJ/push_swap/

OBJ_NAME = $(SRC_NAME:%.c=%.o)
OBJ_NAME1 = $(SRC_NAME1:%.c=%.o)
OBJ_NAME2 = $(SRC_NAME2:%.c=%.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
OBJ1 = $(addprefix $(OBJ_PATH1), $(OBJ_NAME1))
OBJ2 = $(addprefix $(OBJ_PATH2), $(OBJ_NAME2))

HEADER_PATH = -Iinclude/

LIBFT_PATH = -Llibft -Lft_printf

LIBFT = -lft -lftprintf


.PHONY: clean fclean re all

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ) $(OBJ1) $(SRC)
	@echo "----------------------------CHECKER----------------------------"
	@$(MAKE) -C libft
	@$(MAKE) -C ft_printf
	@$(CC) $(LIBFT_PATH) $(LIBFT) $^ -o $@	#$^ for $(OBJ) and $@ for $(NAME)

$(NAME2): $(OBJ) $(OBJ2) $(SRC)
	@echo "----------------------------PUSH_SWAP----------------------------"
	@$(MAKE) -C libft
	@$(MAKE) -C ft_printf
	@$(CC) $(LIBFT_PATH) $(LIBFT) $^ -o $@	#$^ for $(OBJ) and $@ for $(NAME)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@echo "\033[1;32m" "Compiling $< into $@" "\033[0m"
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(HEADER_PATH)  -c $< -o $@
#$(CFLAGS)
$(OBJ_PATH1)%.o : $(SRC_PATH1)%.c
	@echo "\033[1;32m" "Compiling $< into $@" "\033[0m"
	@mkdir -p $(OBJ_PATH1)
	@$(CC) $(HEADER_PATH)  -c $< -o $@

$(OBJ_PATH2)%.o : $(SRC_PATH2)%.c
	@echo "\033[1;32m" "Compiling $< into $@" "\033[0m"
	@mkdir -p $(OBJ_PATH2)
	@$(CC) $(HEADER_PATH)  -c $< -o $@

clean:
	@rm -rf $(OBJ_PATH)
	@rm -rf $(OBJ_PATH1)
	@rm -rf $(OBJ_PATH2)
	@$(MAKE) clean -C libft

fclean: clean
	@rm -f $(NAME1)
	@rm -f $(NAME2)
	@$(MAKE) fclean -C libft
	@$(MAKE) fclean -C ft_printf

re : fclean all
