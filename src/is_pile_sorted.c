/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pile_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:33:04 by fhuang            #+#    #+#             */
/*   Updated: 2017/03/25 17:58:11 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	is_pile_ssorted(int *pile, uint16_t len)
{
	int		i;

	i = 0;
	while (i < len - 1)
	{
		if (pile[i] > pile[i + 1])
			return (ERROR) ;
		++i;
	}
	return (GOOD);
}

int			is_pile_sorted(int *pile, uint16_t len)
{
	if (len == 0 || len == 1)
		return (GOOD);
	if (!is_pile_ssorted(pile, len))// && !is_pile_revsorted(pile, len))
		return (ERROR);
	return (GOOD);
}
