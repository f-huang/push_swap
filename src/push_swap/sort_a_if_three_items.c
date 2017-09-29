/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_if_three_items.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 17:29:13 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/29 17:36:44 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	sort_a_if_three_items(t_game *game)
{
	if (game->a.len != 3 || is_pile_sorted(game->a))
		return ;
	else if (is_pile_reverse_sorted(game->a))
	{
		fire_instruction(game, SA, 1);
		fire_instruction(game, RRA, 1);
	}
	else if (game->a.list[0] < game->a.list[1])
	{
		fire_instruction(game, RRA, 1);
		if (!is_pile_sorted(game->a) && game->a.list[0] < game->a.list[2])
			fire_instruction(game, SA, 1);
	}
	else
	{
		if (game->a.list[0] < game->a.list[2])
			fire_instruction(game, SA, 1);
		else
			fire_instruction(game, RA, 1);
	}
}
