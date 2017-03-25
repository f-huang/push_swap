/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 18:53:34 by fhuang            #+#    #+#             */
/*   Updated: 2017/03/25 17:57:09 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>

void	reverse_rotate(int **pile, uint16_t len)
{
	int		tmp;
	int		i;

	if (!pile || len < 2)
		return ;
	tmp = (*pile)[len - 1];
	i = len - 1;
	while (i)
	{
		(*pile)[i] = (*pile)[i - 1];
		--i;
	}
	(*pile)[0] = tmp;
}
