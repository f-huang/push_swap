/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 18:44:06 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/22 23:58:14 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	rotate(t_pile *pile)
{
	int		tmp;
	int		i;

	if (!pile || pile->len < 2)
		return ;
	tmp = pile->list[0];
	i = 0;
	while (i < pile->len - 1)
	{
		pile->list[i] = pile->list[i + 1];
		++i;
	}
	pile->list[i] = tmp;
}
