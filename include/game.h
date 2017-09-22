/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 12:10:39 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/23 00:33:41 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# ifndef GOOD
#  define GOOD 1
# endif

# ifndef ERROR
#  define ERROR 0
# endif

# ifndef ERROR_STRING
#  define ERROR_STRING "Error\n"
# endif

# include <inttypes.h>

# define NB_INSTRUCTIONS 11

enum instruction
{
	SA = 0, SB, SS,
	RA, RB, RR,
	RRA, RRB, RRR,
	PA, PB
};

static const char *instruction_names[] =
{
	[SA] = "sa",
	[SB] = "sb",
	[SS] = "ss",
	[RA] = "ra",
	[RB] = "rb",
	[RR] = "rr",
	[RRA] = "rra",
	[RRB] = "rrb",
	[RRR] = "rrr",
	[PA] = "pa",
	[PB] = "pb"
};

typedef struct	s_pile
{
	uint16_t	len;
	int			*list;
}				t_pile;

typedef struct	s_piles
{
	uint16_t	len;
	uint16_t	len_a;
	int			*pile_a;
	uint16_t	len_b;
	int			*pile_b;
	int			*sorted_pile;
}				t_piles;

typedef struct	s_game
{
	t_pile		a;
	t_pile		b;
	t_pile		sorted;
	uint16_t	total_operations;
}				t_game;

char**			check_parameters(char **av, uint16_t *len);

int				is_pile_sorted(t_pile pile);
int				is_pile_reverse_sorted(t_pile pile);
int				is_game_finished(t_game game);
int				is_game_set(t_game game);

void			init_game(t_game *game, char **av, uint16_t max_size);
void			finish_game(t_game *game);

/*
**	INSTRUCTIONS
*/
void			fire_instruction(t_game *game, enum instruction instruction, int print);
int				name_to_instruction(const char *name);

void			push_to(t_pile *src, t_pile *dst);
void			swap(t_pile *pile);
void			rotate(t_pile *pile);
void			reverse_rotate(t_pile *pile);
void			swap_both_piles(t_pile *a, t_pile *b);
void			rotate_both_piles(t_pile *a, t_pile *b);
void			reverse_rotate_both_piles(t_pile *a, t_pile *b);

#endif
