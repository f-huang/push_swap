/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 12:10:39 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/15 14:42:02 by fhuang           ###   ########.fr       */
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

typedef struct	s_piles
{
	uint16_t	len;
	uint16_t	len_a;
	int			*pile_a;
	uint16_t	len_b;
	int			*pile_b;
	int			*sorted_pile;
}				t_piles;

typedef struct	s_instruction1
{
	const char	*str;
	void		(*f)(t_piles *piles);
}				t_instruction1;

typedef struct	s_instruction2
{
	const char	*str;
	void		(*f)(int **pile, uint16_t len);
}				t_instruction2;

typedef struct	s_instruction3
{
	const char	*str;
	void		(*f)(int **src, int **dst, uint16_t *len_src, uint16_t *len_dst);
}				t_instruction3;

char**			check_parameters(char **av, uint16_t *len);

int				call_instruction(t_piles *piles, const char *str);

int				is_pile_sorted(int *pile, uint16_t len);
int				is_pile_reverse_sorted(int *pile, uint16_t len);
int				is_game_finished(t_piles piles);

void			init_piles(t_piles *piles, char **av);
void			destroy_piles(t_piles *piles);

/*
**	INSTRUCTIONS
*/

void			push_to(int **src, int **dst, uint16_t *len_src, uint16_t *len_dst);
void			swap(int **pile, uint16_t len);
void			rotate(int **pile, uint16_t len);
void			reverse_rotate(int **pile, uint16_t len);
void			swap_both_piles(t_piles *piles);
void			rotate_both_piles(t_piles *piles);
void			reverse_rotate_both_piles(t_piles *piles);

#endif
