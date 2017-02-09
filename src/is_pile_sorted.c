/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pile_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:33:04 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/09 19:01:06 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	is_pile_ssorted(int *pile, int len)
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

static int	is_pile_revsorted(int *pile, int len)
{
	int		i;

	i = 0;
	while (i < len - 1)
	{
		if (pile[i] < pile[i + 1])
			return (ERROR);
		++i;
	}
	return (GOOD);
}

int			is_pile_sorted(int *pile, int len)
{
	if (len == 0)
		return (GOOD);
	if (!is_pile_ssorted(pile, len) && !is_pile_revsorted(pile, len))
		return (ERROR);
	return (GOOD);
}
