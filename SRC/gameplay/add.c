/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 16:51:12 by fhuang            #+#    #+#             */
/*   Updated: 2016/08/11 19:24:08 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_front(t_pile **pile, int n)
{
	t_pile		*new;

	if ((new = (t_pile*)ft_memalloc(sizeof(t_pile))) == NULL)
		exit(EXIT_FAILURE);
	new->n = n;
	if (*pile == NULL)
		*pile = new;
	else
	{
		new->next = *pile;
		(*pile)->prev = new;
		*pile = new;
	}
}

void		push_back(t_pile **pile, int n)
{
	t_pile		*new;
	t_pile		*ptr;

	if ((new = (t_pile*)ft_memalloc(sizeof(t_pile))) == NULL)
		exit(EXIT_FAILURE);
	new->n = n;
	if (*pile == NULL)
		*pile = new;
	else
	{
		ptr = *pile;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
		new->prev = ptr;
	}
}
