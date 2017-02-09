/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:07:05 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/09 19:03:19 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"

static void		finish_game(t_piles *piles)
{
	while (piles->len_b > 0)
	{
		push_to(&piles->pile_b, &piles->pile_a, &piles->len_b, &piles->len_a);
		ft_putendl("pa");
	}
}

static _Bool	is_reverse_faster(t_piles piles, int sorted_index)
{
	int		i;

	i = 0;
	while (i < piles.len_a)
	{
		if (piles.pile_a[i] == piles.sorted_pile[sorted_index])
			break ;
		// if (piles.pile_a[i] < piles.pile_a[i + 1])
			// sorted++;
		++i;
	}
	return (i > piles.len_a / 2 ? true : false);
	// return (sorted < piles.len - sorted ? false : true);
}

void			resolve_game(t_piles *piles)
{
	int		i;
	_Bool	reverse;

	if (!piles || !piles->pile_a || !piles->pile_b || !piles->sorted_pile)
		return ;
	i = 0;
	reverse = is_reverse_faster(*piles, i);
	while (!is_game_finished(*piles))
	{
		if (is_pile_sorted(piles->pile_a, piles->len_a))
		{
			finish_game(piles);
			// break ;
		}
		if (piles->pile_a[0] != piles->sorted_pile[i])
		{
			reverse ? reverse_rotate(&piles->pile_a, piles->len_a) :
				rotate(&piles->pile_a, piles->len_a);
			ft_putendl(reverse ? "rra" : "ra");
		}
		else
		{
			push_to(&piles->pile_a, &piles->pile_b, &piles->len_a, &piles->len_b);
			ft_putendl("pb");
			++i;
			reverse = is_reverse_faster(*piles, i);
		}
	}
	// ft_putstr(GREEN);
	// for (int i = 0; i < piles->len_a; i++)
	// 	ft_putnbrendl(piles->pile_a[i]);
	// ft_putstr(COLOR_RESET);
}
