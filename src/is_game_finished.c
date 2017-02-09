/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_game_finished.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:17:23 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/09 18:58:32 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	is_pile_empty(int *pile, int len)
{
	return (!pile || len == 0);
}

int			is_game_finished(t_piles piles)
{
	if (!is_pile_empty(piles.pile_b, piles.len_b))
		return (ERROR);
	return (is_pile_sorted(piles.pile_a, piles.len_a));
}
