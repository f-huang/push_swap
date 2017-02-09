/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 12:10:39 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/09 17:33:35 by fhuang           ###   ########.fr       */
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

typedef struct	s_piles
{
	int			len;
	int			len_a;
	int			*pile_a;
	int			len_b;
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
	void		(*f)(int **pile, int len);
}				t_instruction2;

typedef struct	s_instruction3
{
	const char	*str;
	void		(*f)(int **src, int **dst, int *len_src, int *len_dst);
}				t_instruction3;

char**			check_parameters(char **av, int *len);

int				call_instruction(t_piles *piles, const char *str);

int				is_pile_sorted(int *pile, int len);
int				is_game_finished(t_piles piles);

void			init_piles(t_piles *piles, char **av);
void			destroy_piles(t_piles *piles);

/*
**	INSTRUCTIONS
*/

void			push_to(int **src, int **dst, int *len_src, int *len_dst);
void			swap(int **pile, int len);
void			rotate(int **pile, int len);
void			reverse_rotate(int **pile, int len);
void			swap_both_piles(t_piles *piles);
void			rotate_both_piles(t_piles *piles);
void			reverse_rotate_both_piles(t_piles *piles);

#endif
