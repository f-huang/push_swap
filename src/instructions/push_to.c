/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:08:41 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/23 00:30:21 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	push_to(t_pile *src, t_pile *dst)
{
	int		i;

	if (!src || !dst || src->len <= 0)
		return ;
	++dst->len;
	i = dst->len - 1;
	while (i > 0)
	{
		dst->list[i] = dst->list[i - 1];
		--i;
	}
	dst->list[0] = src->list[0];
	i = 0;
	while (i < src->len - 1)
	{
		src->list[i] = src->list[i + 1];
		++i;
	}
	--src->len;
}
