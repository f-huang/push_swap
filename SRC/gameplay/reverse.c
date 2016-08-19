/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 17:11:51 by fhuang            #+#    #+#             */
/*   Updated: 2016/08/18 20:07:43 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		reverse(t_pile **pile)
{
	int		tmp;
	t_pile	*byebye;

	if (*pile && (*pile)->next)
	{
		byebye = *pile;
		while (byebye->next)
			byebye = byebye->next;
		tmp = byebye->n;
		if (byebye->prev)
			byebye->prev->next = NULL;
		free(byebye);
		byebye = NULL;
		push_front(pile, tmp);
	}
}
