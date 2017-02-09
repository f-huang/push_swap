/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pile_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:33:04 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/09 17:34:43 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	is_pile_sorted(int *pile, int len)
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
