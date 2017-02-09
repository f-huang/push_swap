/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:08:41 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/09 14:04:15 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	push_to(int **src, int **dst, int *len_src, int *len_dst)
{
	int		i;

	if (!src || !dst || *len_src <= 0)
		return ;
	++(*len_dst);
	i = *len_dst - 1;
	while (i > 0)
	{
		(*dst)[i] = (*dst)[i - 1];
		--i;
	}
	(*dst)[0] = (*src)[0];
	i = 0;
	while (i < *len_src - 1)
	{
		(*src)[i] = (*src)[i + 1];
		++i;
	}
	--(*len_src);
}
