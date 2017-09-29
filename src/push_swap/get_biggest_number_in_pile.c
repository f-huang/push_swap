/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_biggest_number_in_pile.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 16:27:16 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/29 16:27:30 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	get_biggest_number_in_pile(t_pile pile)
{
	int		i;
	int		ret;

	i = 0;
	ret = pile.list[0];
	while (i < pile.len)
	{
		if (pile.list[i] > ret)
			ret = pile.list[i];
		++i;
	}
	return (i);
}
