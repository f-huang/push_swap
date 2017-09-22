# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/07 15:45:39 by fhuang            #+#    #+#              #
#    Updated: 2017/09/23 00:23:18 by fhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== Editable =====
PROG1	:=	checker
PROG2	:=	push_swap
# ====================

# ===== Standard =====
CC		:=	clang -pipe
CFLAGS	:=	-Wall -Wextra -Werror -g3
SRCDIR	:=	src/
OBJDIR	:=	obj/
BINDIR	:=	bin/
INCDIR	:=	include/
LIBDIR	:=	libft/
INSTRUCTDIR	:=	instructions/
SRC		:=	$(SRCDIR)$(INSTRUCTDIR)push_to.c		\
			$(SRCDIR)$(INSTRUCTDIR)fire_instruction.c	\
			$(SRCDIR)$(INSTRUCTDIR)name_to_instruction.c	\
			$(SRCDIR)$(INSTRUCTDIR)reverse_rotate.c	\
			$(SRCDIR)$(INSTRUCTDIR)reverse_rotate_both_piles.c\
			$(SRCDIR)$(INSTRUCTDIR)rotate.c			\
			$(SRCDIR)$(INSTRUCTDIR)rotate_both_piles.c\
			$(SRCDIR)$(INSTRUCTDIR)swap.c			\
			$(SRCDIR)$(INSTRUCTDIR)swap_both_piles.c\
			$(SRCDIR)check_parameters.c				\
			$(SRCDIR)finish_game.c				\
			$(SRCDIR)init_game.c					\
			$(SRCDIR)is_game_finished.c				\
			$(SRCDIR)is_game_set.c				\
			$(SRCDIR)is_pile_reverse_sorted.c		\
			$(SRCDIR)is_pile_sorted.c
OBJ		:=	$(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)
INC		:=	-I./$(INCDIR) -I./$(LIBDIR)$(INCDIR)
LIBPATH	:=	-L./$(LIBDIR)lib -lft -lftprintf
CACHEF	:=	.cache_exists
# ====================

# ====== Colors ======
CLEAR		= "\033[2K"
UP			= "\033[A"
EOC			= "\033[0;0m"
BLACK		= "\033[0;30m"
RED			= "\033[0;31m"
GREEN		= "\033[0;32m"
YELLOW		= "\033[0;33m"
BLUE		= "\033[0;34m"
PURPLE		= "\033[0;35m"
CYAN		= "\033[0;36m"
WHITE		= "\033[0;37m"
# ====================

# ===== checker =====
DIRCHKER	:=	$(SRCDIR)$(PROG1)/
OBJDIRCHKER	:=	$(OBJDIR)$(PROG1)/
BINCHKER	:=	$(PROG1)
SRCCHKER	:=	$(DIRCHKER)main.c	\
				$(DIRCHKER)call_instruction.c
OBJCHKER	:=	$(SRCCHKER:$(DIRCHKER)%.c=$(OBJDIRCHKER)%.o)
# ===================

# ===== checker =====
DIRPSWAP	:=	$(SRCDIR)$(PROG2)/
OBJDIRPSWAP	:=	$(OBJDIR)$(PROG2)/
BINPSWAP	:=	$(PROG2)
SRCPSWAP	:=	$(DIRPSWAP)main.c				\
				$(DIRPSWAP)are_smaller_number_at_the_start.c\
				$(DIRPSWAP)set_sorted_pile.c	\
				$(DIRPSWAP)sort_three_items.c		\
				$(DIRPSWAP)resolve_game.c		\
				$(DIRPSWAP)get_tab_median.c		\
				$(DIRPSWAP)print_piles.c
OBJPSWAP	:=	$(SRCPSWAP:$(DIRPSWAP)%.c=$(OBJDIRPSWAP)%.o)
# ===================


.PHONY: all libft push_swap checker norme clean fclean re
.SILENT:

all: libft push_swap checker
	echo ""

$(OBJDIR)%.o: $(SRCDIR)%.c $(CACHEF)
	#CFLAGS
	$(CC) -c $< -o $@ $(INC)
	printf $(GREEN)"|"$(EOC)

$(CACHEF):
	test -d $(OBJDIR) || mkdir $(OBJDIR)
	test -d $(OBJDIR)$(INSTRUCTDIR) || mkdir $(OBJDIR)$(INSTRUCTDIR)
	test -d $(OBJDIRCHKER) || mkdir $(OBJDIRCHKER)
	test -d $(OBJDIRPSWAP) || mkdir $(OBJDIRPSWAP)
	test -d $(CACHEF) || touch $(CACHEF)

%.c:
	printf $(RED)"Missing file : $@\n"$(EOC)

libft:
	make -C $(LIBDIR)

checker: $(OBJ) $(OBJCHKER)
	$(CC) $(CFLAGS) -o $(BINCHKER) $(OBJ) $(OBJCHKER) $(LIBPATH) $(LIB) $(INC)

push_swap: $(OBJ) $(OBJPSWAP)
	$(CC) $(CFLAGS) -o $(BINPSWAP) $(OBJ) $(OBJPSWAP) $(LIBPATH) $(LIB) $(INC)

norme:
	norminette $(SRCDIR) $(INCDIR) | grep -v Norme -B1 || true
	norminette $(LIBFT)$(SRCDIR) $(LIBFT)$(INCDIR) | grep -v Norme -B1 || true

clean:
	make -C $(LIBDIR) clean
	rm -rf $(OBJDIR) $(CACHEF)
	printf $(YELLOW)"All objects removed\n"$(EOC)

fclean: clean
	make -C $(LIBDIR) fclean
	rm -f $(PROG1)
	rm -f $(PROG2)
	printf $(RED)"$(PROG1) removed\n"$(EOC)
	printf $(RED)"$(PROG2) removed\n"$(EOC)

re: fclean all
