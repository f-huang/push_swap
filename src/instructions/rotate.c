/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 18:44:06 by fhuang            #+#    #+#             */
/*   Updated: 2017/03/25 17:57:18 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>

void	rotate(int **pile, uint16_t len)
{
	int		tmp;
	int		i;

	if (!pile || len < 2)
		return ;
	tmp = (*pile)[0];
	i = 0;
	while (i < len - 1)
	{
		(*pile)[i] = (*pile)[i + 1];
		++i;
	}
	(*pile)[i] = tmp;
}
