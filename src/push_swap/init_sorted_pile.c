/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sorted_pile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:21:01 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/09 17:05:07 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_sorted_pile(int **sorted_pile, int *pile_a, int len)
{
	int		i;
	int		tmp;

	if (!sorted_pile)
		return ;
	*sorted_pile = (int*)ft_memdup(pile_a, sizeof(int) * len);
	i = 0;
	while (i < len - 1)
	{
		if ((*sorted_pile)[i] > (*sorted_pile)[i + 1])
		{
			tmp = (*sorted_pile)[i];
			(*sorted_pile)[i] = (*sorted_pile)[i + 1];
			(*sorted_pile)[i + 1] = tmp;
			i = -1;
		}
		++i;
	}
}
