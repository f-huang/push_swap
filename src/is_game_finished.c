/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_game_finished.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:17:23 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/22 00:31:36 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	is_pile_empty(t_pile pile)
{
	return (!pile.list || pile.len == 0);
}

int			is_game_finished(t_game game)
{
	if (!is_pile_empty(game.b))
		return (ERROR);
	return (is_pile_sorted(game.a));
}
