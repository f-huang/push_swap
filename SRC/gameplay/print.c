/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 18:59:12 by fhuang            #+#    #+#             */
/*   Updated: 2016/08/18 18:19:11 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print(t_pile *pile)
{
	t_pile		*tmp;

	tmp = pile;
	while (tmp)
	{
		ft_putnbrendl(tmp->n);
		tmp = tmp->next;
	}
}

void		printrev(t_pile *pile)
{
	t_pile		*tmp;

	tmp = pile;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp)
	{
		ft_putnbrendl(tmp->n);
		tmp = tmp->prev;
	}
}
