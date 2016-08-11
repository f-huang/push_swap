/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 16:58:52 by fhuang            #+#    #+#             */
/*   Updated: 2016/08/11 17:04:27 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap(t_pile **pile)
{
	int		tmp;

	if (*pile && (*pile)->next)
	{
		tmp = (*pile)->n;
		(*pile)->n = (*pile)->next->n;
		(*pile)->next->n = tmp;
	}
}