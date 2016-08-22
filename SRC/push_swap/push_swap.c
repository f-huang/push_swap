/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 16:08:45 by fhuang            #+#    #+#             */
/*   Updated: 2016/08/22 15:51:35 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define PLAY_A(str, action) PLAY_A(str, action)
#define PLAY_B(str, action) PLAY_B(str, action)

int			is_pile_revsorted(t_pile *pile)
{
	t_pile	*link;
	int		n;

	n = 0;
	link = pile;
	while (link && link->next)
	{
		n++;
		if (link->n < link->next->n)
			return (n);
		link = link->next;
	}
	return (n);
}

int			is_pile_sorted(t_pile *pile)
{
	t_pile	*link;

	link = pile;
	while (link && link->next)
	{
		if (link->n > link->next->n)
			return (0);
		link = link->next;
	}
	return (1);
}

t_pile		*get_last_link(t_pile *pile)
{
	t_pile 	*last_link;

	if (pile == NULL)
		return (NULL);
	last_link = pile;
	while (last_link->next != NULL)
		last_link = last_link->next;
	return (last_link);
}

int			list_len(t_pile *pile)
{
	int		n;
	t_pile	*tmp;

	tmp = pile;
	n = 0;
	while (tmp)
	{
		tmp = tmp->next;
		n++;
	}
	return (n);
}

void		play_action(t_pile **pile, char *action, void (f)(t_pile**))
{
	f(pile);
	if (action != NULL)
		ft_putstr(action);
}

void		push_swap(t_game *game)
{
	t_pile	*last;

	while (is_game_finished(game) == 0)
	{
		while (is_pile_sorted(PILE_A) == 0)
		{
			last = get_last_link(PILE_B);
			if (is_pile_sorted(PILE_A) == 0 && PILE_B && PILE_B != last && PILE_B->n < last->n)
			{
				last->n > last->prev->n ? PLAY_B("rrb\n", reverse) : PLAY_B("rb\n", rotate);
			}
			last = get_last_link(PILE_A);
			if (is_pile_sorted(PILE_A) == 0 && PILE_A && PILE_A != last && PILE_A->n > last->n)
			{
				if (last->n > last->prev->n)
					PLAY_A("ra\n", rotate);
				else
					PLAY_A("rra\n", reverse);
			}
			last = get_last_link(PILE_B);
			if (is_pile_sorted(PILE_A) == 0 && PILE_B && PILE_B->next && PILE_B->n < PILE_B->next->n)
				PLAY_B("sb\n", swap);
			if (is_pile_sorted(PILE_A) == 0 && PILE_A->next && PILE_A->n > PILE_A->next->n)
				PLAY_A("sa\n", swap);
			else if (is_pile_sorted(PILE_A) == 0)
			{
				push(&PILE_B, &PILE_A);
				ft_putstr("pb\n");
			}
		}
		while (PILE_B)
		{
			push(&PILE_A, &PILE_B);
			ft_putstr("pa\n");
			if (PILE_A->next && PILE_A->n > PILE_A->next->n)
				PLAY_A("sa\n", swap);
		}
		// print_piles(game);
	}
}
