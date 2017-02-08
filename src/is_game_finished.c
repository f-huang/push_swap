/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_game_finished.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:17:23 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/08 17:44:12 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	is_pile_empty(int *pile)
{
	return (!pile || !*pile);
}

static int	is_pile_sorted(int *pile, int len)
{
	int		i;

	if (!pile || !*pile)
		return (GOOD);
	i = 0;
	while (i < len - 1)
	{
		if (pile[i] > pile[i + 1])
			return (ERROR);
		++i;
	}
	return (GOOD);
}
int		is_game_finished(t_piles piles)
{
	if (!is_pile_empty(piles.pile_b))
		return (ERROR);
	return (is_pile_sorted(piles.pile_a, piles.len_a));
}
