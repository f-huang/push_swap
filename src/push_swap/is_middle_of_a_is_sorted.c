/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_middle_of_a_is_sorted.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 16:54:13 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/29 16:55:00 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	is_middle_of_a_is_sorted(t_game *game, int nb_rotate)
{
	int i;
	int sorted;

	if (game->a.len > 1 && game->a.list[0] > game->a.list[1])
	{
		i = 2;
		sorted = 1;
		swap(&game->a);
		while (sorted && i < game->a.len - nb_rotate - 3)
		{
			if (game->a.list[i] > game->a.list[i + 1])
				sorted = 0;
			++i;
		}
		swap(&game->a);
		if (sorted)
			fire_instruction(game, SA, 1);
	}
}
