/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_smaller_number_at_the_start.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 13:30:42 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/15 14:28:53 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "push_swap.h"

#include "libft.h"
int	are_smaller_number_at_the_start(int *pile, uint16_t len, int median)
{
	int		count;
	int		i;
	int		size;

	count = 0;
	i = 0;
	size = len / 2;
	while (i < size)
	{
		if (median > pile[i])
			++count;
		++i;
	}
	return (count >= size / 2 + size % 2 ? 1 : 0);
}
