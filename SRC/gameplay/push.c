/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 19:32:58 by fhuang            #+#    #+#             */
/*   Updated: 2016/08/11 19:56:27 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push(t_pile **dest, t_pile **src)
{
	int		tmp;
	t_pile	*byebye;

	if (*src)
	{
		tmp = (*src)->n;
		byebye = *src;
		*src = (*src)->next;
		if (*src)
			(*src)->prev = NULL;
		free(byebye);
		byebye = NULL;
		push_front(dest, tmp);
	}
}
