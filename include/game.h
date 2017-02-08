/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 12:10:39 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/08 19:06:12 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#ifndef GOOD
# define GOOD 1
#endif

#ifndef ERROR
# define ERROR 0
#endif

#ifndef ERROR_STRING
# define ERROR_STRING "Error\n"
#endif

#ifndef NUMBER_INSTRUCTIONS
# define NUMBER_INSTRUCTIONS 11
#endif

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
	const char		*str;
	void		(*f)(t_piles *piles);
}				t_instruction1;

typedef struct	s_instruction2
{
	const char		*str;
	void		(*f)(int **pile, int len);
}				t_instruction2;

int		check_parameters(char **av);
int		call_instruction(t_piles *piles, const char *str);
int		is_game_finished(t_piles piles);

void	init_piles(t_piles *piles, char **av, int ac);
void	destroy_piles(t_piles *piles);

/*
**	INSTRUCTIONS
*/

void	swap(int **pile, int len);
void	rotate(int **pile, int len);
void	reverse_rotate(int **pile, int len);

#endif
