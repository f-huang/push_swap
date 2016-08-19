/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 16:08:45 by fhuang            #+#    #+#             */
/*   Updated: 2016/08/18 22:50:01 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_pile_revsorted(t_pile *pile)
{
	t_pile	*link;

	link = pile;
	while (link && link->next)
	{
		if (link->n < link->next->n)
			return (0);
		link = link->next;
	}
	return (1);
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

void		is_swap(t_game *game)
{
	t_pile	*link;

	link = PILE_A->next;
	if (link && PILE_A->n > link->n && is_pile_sorted(link) == 1)
		swap(&PILE_A);
	if (PILE_B == NULL)
		return ;
	link = PILE_B->next;
	if (link && PILE_B->n > link->n && is_pile_revsorted(link) == 1)
		swap(&PILE_B);
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

int			areverse(t_game *game, t_pile *last)
{
	int		i;

	i = 0;
	if (last->n < PILE_A->n && last->n < AVRGE)
	{
		reverse(&PILE_A);
		i++;
	}
	last = get_last_link(PILE_B);
	if (PILE_B && PILE_B != last && last->n > PILE_B->n)
	{
		reverse(&PILE_B);
		i = i == 0 ? -1 : 2;
	}
	if (i < 0)
		ft_putstr("rrb\n");
	else if (i == 1)
		ft_putstr("rra\n");
	else if (i == 2)
		ft_putstr("rrr\n");
	return i ? 1 : 0;
}

int			arotate(t_game *game, t_pile *last)
{
	int		i;

	i = 0;
	if (PILE_A->n > last->n && PILE_A->n > AVRGE)
	{
		rotate(&PILE_A);
		i++;
	}
	last = get_last_link(PILE_B);
	if (PILE_B && PILE_B != last && PILE_B->n < last->n)
	{
		rotate(&PILE_B);
		i = i == 0 ? -1 : 2;
	}
	if (i < 0)
		ft_putstr("rb\n");
	else if (i == 1)
		ft_putstr("ra\n");
	else if (i == 2)
		ft_putstr("rr\n");
	return i ? 1 : 0;
}
int			aswap(t_game *game)
{
	int		i;

	i = 0;
	if (PILE_A->next && PILE_A->n > PILE_A->next->n)
	{
		swap(&PILE_A);
		i++;
	}
	if (PILE_B && PILE_B->next && PILE_B->n < PILE_B->next->n)
	{
		swap(&PILE_B);
		i = i == 0 ? -1 : 2;
	}
	if (i < 0)
		ft_putstr("sb\n");
	else if (i == 1)
		ft_putstr("sa\n");
	else if (i == 2)
		ft_putstr("ss\n");
	return i ? 1 : 0;
}

void		push_swap(t_game *game)
{
	t_pile	*last;

	printf("n link : %i -- average : %i\n", game->n_link, game->average);
	while (is_game_finished(game) == 0)
	{
		last = get_last_link(PILE_A);
		if (areverse(game, last) == 0)
			if (arotate(game, last) == 0)
				if (aswap(game) == 0)
				{
					if (is_pile_sorted(PILE_A) && is_pile_revsorted(PILE_B))
					{
						while (PILE_B)
						{
							push(&PILE_A, &PILE_B);
							ft_putstr("pa\n");
						}
					}
					else
					{
						push(&PILE_B, &PILE_A);
						ft_putstr("pb\n");
					}
				}
		ft_putendlcol("--------PILE_A-------", RED);
		print(PILE_A);
		ft_putendlcol("---------------------", RED);
		ft_putendlcol("--------PILE_B-------", CYAN);
		print(PILE_B);
		ft_putendlcol("---------------------", CYAN);
	}
}
