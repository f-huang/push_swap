/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 16:08:45 by fhuang            #+#    #+#             */
/*   Updated: 2016/08/24 18:04:27 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define PLAY_A(str, action) play_action(game, &PILE_A, str, action)
#define PLAY_B(str, action) play_action(game, &PILE_B, str, action)

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

void		play_action(t_game *game, t_pile **pile, char *action, void (f)(t_pile**))
{
	f(pile);
	if (action != NULL)
	{
		ft_putstr(action);
		OPT[0] ? print_piles(game) : 0;
	}
}

static int		rev_and_rot(t_game *game)
{
	const char	*str[] = {"ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};
	int		tmp;
	t_pile	*last;

	tmp = -1;
	if (is_pile_sorted(PILE_A) == 0)
	{
		last = get_last_link(PILE_B);
		if (PILE_B && PILE_B->next && PILE_B->n < last->n)
		{
			tmp = last->n > last->prev->n ? 4 : 1;
			last->n > last->prev->n ? PLAY_B(NULL, reverse) : PLAY_B(NULL, rotate);
		}
		last = get_last_link(PILE_A);
		if (PILE_A && PILE_A->next && PILE_A->n > last->n)
		{
			if ((tmp == 4 && last->n < last->prev->n) || (tmp == 1 && last->n > last->prev->n))
			 	tmp++;
			else
			{
				tmp != -1 ? ft_putstr(str[tmp]) : 0;
				tmp != -1 && OPT[0]? print_piles(game) : 0;
				tmp = last->n > last->prev->n ? 0 : 3;
			}
			last->n > last->prev->n ? PLAY_A(NULL, rotate) : PLAY_A(NULL, reverse);
		}
		if (tmp >= 0)
		{
			ft_putstr(str[tmp]);
			OPT[0] ? print_piles(game) : 0;
		}
	}
	return (tmp);
}

static int		swaap(t_game *game)
{
	const char	*str[] = {"sa\n", "sb\n", "ss\n"};
	int		tmp;

	tmp = -1;
	if (is_pile_sorted(PILE_A) == 0 && PILE_B && PILE_B->next && PILE_B->n < PILE_B->next->n)
	{
		PLAY_B(NULL, swap);
		tmp = 1;
	}
	if (is_pile_sorted(PILE_A) == 0 && PILE_A->next && PILE_A->n > PILE_A->next->n)
	{
		PLAY_A(NULL, swap);
		tmp = tmp == 1 ? 2 : 0;
	}
	if (tmp >= 0)
	{
		ft_putstr(str[tmp]);
		OPT[0] ? print_piles(game) : 0;
	}
	return (tmp);
}

void		push_swap(t_game *game)
{
	t_pile	*last;

	while (is_game_finished(game) == 0)
	{
		while (is_pile_sorted(PILE_A) == 0)
		{
			if (rev_and_rot(game) == -1 && swaap(game) == -1 && is_pile_sorted(PILE_A) == 0)
			// else if (is_pile_sorted(PILE_A) == 0)
			{
				push(&PILE_B, &PILE_A);
				ft_putstr("pb\n");
				OPT[0] ? print_piles(game) : 0;
			}
		}
		while (PILE_B)
		{
			push(&PILE_A, &PILE_B);
			ft_putstr("pa\n");
			OPT[0] ? print_piles(game) : 0;
			if (PILE_A->next && PILE_A->n > PILE_A->next->n)
				PLAY_A("sa\n", swap);
		}
		// print_piles(game);
	}
}
