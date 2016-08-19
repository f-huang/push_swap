/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 18:59:12 by fhuang            #+#    #+#             */
/*   Updated: 2016/08/19 14:57:12 by fhuang           ###   ########.fr       */
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

void		print_piles(t_game *game)
{
	t_pile		*pa;
	t_pile		*pb;

	pa = PILE_A;
	pb = PILE_B;
	ft_putstrcol("--------PILE_A-------    ", RED);
	ft_putendlcol("--------PILE_B-------", CYAN);
	while (pa || pb)
	{
		if (pa)
		{
			ft_putnbr(pa->n);
			pa = pa->next;
		}
		ft_putstr("                                ");
		if (pb)
		{
			ft_putnbr(pb->n);
			pb = pb->next;
		}
		ft_putstr("\n");
	}
	ft_putstrcol("---------------------    ", RED);
	ft_putendlcol("---------------------", CYAN);
}
