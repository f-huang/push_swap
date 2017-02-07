# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/07 15:45:39 by fhuang            #+#    #+#              #
#    Updated: 2017/02/07 20:05:14 by fhuang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== Editable =====
PROG1	:=	checker
# ====================

# ===== Standard =====
CC		:=	clang -pipe
CFLAGS	:=	-Wall -Wextra -Werror -g3
SRCDIR	:=	src/
OBJDIR	:=	obj/
BINDIR	:=	bin/
INCDIR	:=	include/
LIBDIR	:=	libft/
DIRBUILTINS	:= obj/builtins/
SRC		:=
OBJ		:=	$(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)
INC		:=	-I./$(INCDIR) -I./$(LIBDIR)$(INCDIR)
LIBPATH	:=	-L./$(LIBDIR)lib -lft
CACHEF	:=	.cache_exists
HISTORY	:=	~/.42sh_history
42SHRC	:=	~/.42shrc
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
OBJDIRCHKER	:= $(OBJDIR)$(PROG1)/
BINCHKER	:=	$(PROG1)
SRCCHKER	:=	$(DIRCHKER)main.c
OBJCHKER	:=	$(SRCCHKER:$(DIRCHKER)%.c=$(OBJDIRCHKER)%.o)
# ================

.PHONY: all libft checker norme clean fclean re
.SILENT:

all: libft checker

$(OBJDIR)%.o: $(SRCDIR)%.c $(CACHEF)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)
	printf $(GREEN)"|"$(EOC)

$(CACHEF):
	test -d $(OBJDIR) || mkdir $(OBJDIR)
	test -d $(OBJDIRCHKER) || mkdir $(OBJDIRCHKER)
	test -d $(CACHEF) || touch $(CACHEF)

%.c:
	printf $(RED)"Missing file : $@\n"$(EOC)

libft:
	make -C $(LIBDIR)

checker: $(OBJCHKER)
	$(CC) $(CFLAGS) -o $(BINCHKER) $(OBJCHKER) $(LIBPATH) $(LIB) $(INC)
	printf $(GREEN)" $@ compiled!\n"$(EOC)

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
	printf $(RED)"$(PROG1) removed\n"$(EOC)

re: fclean all
