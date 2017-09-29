/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_if_needed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 14:49:57 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/29 18:26:05 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "push_swap.h"

static int	need_to_swap_a(t_game *game, int nb_rotate)
{
	int		i;
	int		swap_a;

	if (game->a.len > 1 && game->a.list[0] > game->a.list[1])
	{
		swap_a = 1;
		i = 2;
		while (swap_a && i < game->b.len)
		{
			if (game->a.list[1] < game->b.list[i])
				swap_a = 0;
			++i;
		}
		if (swap_a)
			return (1);
		i = 0;
		while (swap_a && i < game->b.len)
		{
			if (game->a.list[0] < game->b.list[i])
				return (0);
			++i;
		}
		is_middle_of_a_is_sorted(game, nb_rotate);
	}
	return (0);
}

static int	need_to_swap_b(t_pile b)
{
	int		i;

	if (b.len > 1 && b.list[0] < b.list[1])
	{
		i = 2;
		while (i < b.len)
		{
			if (b.list[0] < b.list[i])
				return (0);
			++i;
		}
		return (1);
	}
	return (0);
}

void		swap_if_needed(t_game *game, int nb_rotate)
{
	int		swap_a;
	int		swap_b;

	swap_a = need_to_swap_a(game, nb_rotate);
	swap_b = need_to_swap_b(game->b);
	if (swap_a && swap_b)
		fire_instruction(game, SS, 1);
	else if (swap_a)
		fire_instruction(game, SA, 1);
	else if (swap_b)
		fire_instruction(game, SB, 1);
}
