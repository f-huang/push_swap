/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 18:53:34 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/28 20:01:02 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	reverse_rotate(t_pile *pile)
{
	int		tmp;
	int		i;

	if (!pile || pile->len < 2)
		return ;
	tmp = pile->list[pile->len - 1];
	i = pile->len - 1;
	while (i - 1 >= 0)
	{
		pile->list[i] = pile->list[i - 1];
		--i;
	}
	pile->list[0] = tmp;
}
