/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 14:19:13 by fhuang            #+#    #+#             */
/*   Updated: 2016/08/24 18:05:56 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>

#include <stdio.h>

#define PILE_A game->pile_a
#define PILE_B game->pile_b
#define OPT game->option
#define LEN game->len

typedef struct		s_pile
{
	int				n;
	struct s_pile	*next;
	struct s_pile	*prev;
}					t_pile;

typedef struct		s_game
{
	t_pile			*pile_a;
	t_pile			*pile_b;
	int				option[2];
	int				len;
}					t_game;

/*
**			GAMEPLAY
*/

int					check_param(t_game *game, char **av);
void				init_game(t_game *game, int ac, char **av);
int					is_game_finished(t_game *game);
void		print(t_pile *pile);
void		printrev(t_pile *pile);
void		print_piles(t_game *game);
void				push(t_pile **dest, t_pile **src);
void				push_back(t_pile **pile, int n);
void				push_front(t_pile **pile, int n);
void				reverse(t_pile **pile);
void				rotate(t_pile **pile);
void				swap(t_pile **pile);

/*
**			CHECKER
*/

void				follow_instruc(t_game *game, char *instruc);
void 				checker(t_game *game);

/*
**			PUSH_SWAP
*/

void 				push_swap(t_game *game);

#endif
