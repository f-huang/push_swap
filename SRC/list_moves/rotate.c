/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 17:04:43 by fhuang            #+#    #+#             */
/*   Updated: 2016/08/11 19:24:31 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rotate(t_pile **pile)
{
	int		tmp;
	t_pile	*byebye;

	if (*pile)
	{
		tmp = (*pile)->n;
		byebye = *pile;
		if ((*pile)->next)
		{
			*pile = (*pile)->next;
			(*pile)->prev = NULL;
		}
		free(byebye);
		byebye = NULL;
		push_back(pile, tmp);
	}
}
