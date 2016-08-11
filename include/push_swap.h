/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 14:19:13 by fhuang            #+#    #+#             */
/*   Updated: 2016/08/11 20:23:01 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>


#include <stdio.h>

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
}					t_game;

/*
**			LIST_MOVES
*/

void		print(t_pile *pile);
void		printrev(t_pile *pile);
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
