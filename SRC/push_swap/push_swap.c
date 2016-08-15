/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 16:08:45 by fhuang            #+#    #+#             */
/*   Updated: 2016/08/15 18:07:53 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_pile_revsorted(t_pile *pile)
{
	t_pile	*link;

	link = pile;
	while (link->next)
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
	while (link->next)
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

	last_link = pile;
	while (last_link->next != NULL)
		last_link = last_link->next;
	return (last_link);
}

void		push_swap(t_game *game)
{
	t_pile	*last_link;

	printf("n link : %i -- average : %i\n", game->n_link, game->average);
	while (is_game_finished(game) == 0)
	{
		last_link = get_last_link(pile);
		if (PILE_A->n < last_link->n)
			push(&PILE_B, &PILE_A);
		else
			rotate(&PILE_A); // rr
		is_swap(game);
		if (is_pile_sorted(PILE_A) && is_pile_revsorted(PILE_B))
			while (PILE_B)
				push(&PILE_A, &PILE_B);
	}
}
