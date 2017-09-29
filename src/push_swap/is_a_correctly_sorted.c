/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_correctly_sorted.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 15:02:00 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/29 15:02:42 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		is_a_correctly_sorted(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->b.len)
	{
		if (game->a.list[0] < game->b.list[i])
			return (0);
		++i;
	}
	return (1);
}
