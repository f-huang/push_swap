/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_there_numbers_greater_than_median.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 14:59:15 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/29 14:59:26 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	is_there_numbers_greater_than_median(t_pile pile, int median)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < pile.len)
	{
		if (pile.list[i] >= median)
			++count;
		++i;
	}
	return (count);
}
