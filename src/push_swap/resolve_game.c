/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:07:05 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/09 17:36:13 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"

static void	finish_game(t_piles *piles)
{
	while (piles->len_b > 0)
	{
		push_to(&piles->pile_b, &piles->pile_a, &piles->len_b, &piles->len_a);
		ft_putendl("pa");
	}
}

void	resolve_game(t_piles *piles)
{
	int		i;
	_Bool	reverse;

	if (!piles || !piles->pile_a || !piles->pile_b || !piles->sorted_pile)
		return ;
	reverse = false;
	i = 0;
	while (!is_game_finished(*piles))
	{
		if (is_pile_sorted(piles->pile_a, piles->len_a))
		{
			finish_game(piles);
			break ;
		}
		if (piles->pile_a[0] != piles->sorted_pile[i])
		{
			rotate(&piles->pile_a, piles->len_a);
			ft_putendl("ra");
		}
		else
		{
			push_to(&piles->pile_a, &piles->pile_b, &piles->len_a, &piles->len_b);
			ft_putendl("pb");
			++i;
		}
	}
	// ft_putstr(GREEN);
	// for (int i = 0; i < piles->len; i++)
		// ft_putnbrendl(piles->pile_a[i]);
	// ft_putstr(COLOR_RESET);
}
