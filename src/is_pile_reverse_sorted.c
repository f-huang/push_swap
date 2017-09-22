/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pile_reverse_sorted.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:33:04 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/22 00:32:19 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	is_pile_reverse_ssorted(t_pile pile)
{
	int		i;

	i = 0;
	while (i < pile.len - 1)
	{
		if (pile.list[i] < pile.list[i + 1])
			return (ERROR) ;
		++i;
	}
	return (GOOD);
}

int			is_pile_reverse_sorted(t_pile pile)
{
	if (pile.len == 0 || pile.len == 1)
		return (GOOD);
	if (!is_pile_reverse_ssorted(pile))
		return (ERROR);
	return (GOOD);
}
