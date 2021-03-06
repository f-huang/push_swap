/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tab_median.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 17:41:11 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/28 21:44:27 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"

int		get_tab_median(int *tab, uint16_t len)
{
	int		*tmp;
	int		i;
	int		swap;
	int		median;

	if (!(tmp = ft_intabndup(tab, 0, len)))
		return (tab[0] ? tab[0] : 0);
	i = 0;
	while (i < len - 1)
	{
		if (tmp[i] > tmp[i + 1])
		{
			swap = tmp[i];
			tmp[i] = tmp[i + 1];
			tmp[i + 1] = swap;
			i = -1;
		}
		++i;
	}
	median = tmp[len / 2];
	ft_memdel((void*)&tmp);
	return (median);
}
