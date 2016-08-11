/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 18:59:12 by fhuang            #+#    #+#             */
/*   Updated: 2016/08/11 19:26:39 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print(t_pile *pile)
{
	t_pile		*tmp;

	tmp = pile;
	ft_putendl("LIST :");
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
	ft_putendl("LIST REV:");
	while (tmp->next)
		tmp = tmp->next;
	while (tmp)
	{
		ft_putnbrendl(tmp->n);
		tmp = tmp->prev;
	}
}
