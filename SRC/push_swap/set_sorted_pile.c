/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sorted_pile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:21:01 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/22 21:49:07 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"

void	set_sorted_pile(t_pile *sorted, t_pile a, int max_size)
{
	int		i;
	int		tmp;

	if (!sorted)
		return ;
	sorted->list = (int*)ft_memdup(a.list, sizeof(int) * max_size);
	i = 0;
	while (i < max_size - 1)
	{
		if (sorted->list[i] > sorted->list[i + 1])
		{
			tmp = sorted->list[i];
			sorted->list[i] = sorted->list[i + 1];
			sorted->list[i + 1] = tmp;
			i = -1;
		}
		++i;
	}
}
