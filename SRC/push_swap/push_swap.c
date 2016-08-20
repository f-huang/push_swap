/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 16:08:45 by fhuang            #+#    #+#             */
/*   Updated: 2016/08/21 00:37:35 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (PILE_A && PILE_A != last && last->n < PILE_A->n && last->n < AVRGE)
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
	if (PILE_A && PILE_A != last && PILE_A->n > last->n && PILE_A->n > AVRGE)
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
	if (PILE_A && PILE_A->next && PILE_A->n > PILE_A->next->n)
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

void		push_swap(t_game *game)
{
	t_pile	*last;
	int		ret;

	printf("n link : %i -- average : %i\n", game->n_link, game->average);
	while (is_game_finished(game) == 0)
	{
		// if (is_pile_sorted(PILE_A) && (ret = is_pile_revsorted(PILE_B)))
		// {
		// 	while (is_pile_sorted(PILE_A))
		// 	{
		// 		push(&PILE_A, &PILE_B);
		// 		ft_putstr("pa\n");
		// 		ret--;
		// 	}
		// }
		// else if (areverse(game, last) == 0)
		// 	if (arotate(game, last) == 0)
		// 		if (aswap(game) == 0)
		// 		{
		// 			if (list_len(PILE_B) < NLINK / 2)
		// 			{
		// 				push(&PILE_B, &PILE_A);
		// 				ft_putstr("pb\n");
		// 			}
		// 		}
		int	i;
		while (is_pile_sorted(PILE_A) == 0)
		{
			i = 0;
			last = get_last_link(PILE_B);
			if (is_pile_sorted(PILE_A) == 0 && PILE_B && PILE_B != last && PILE_B->n > last->n)
			{
				rotate(&PILE_B);
				ft_putstr("rb\n");
				i++;
			}
			last = get_last_link(PILE_A);
			if (is_pile_sorted(PILE_A) == 0 && PILE_A && PILE_A != last && PILE_A->n < last->n)
			{
				rotate(&PILE_A);
				ft_putstr("ra\n");
				i++;
			}
			if (is_pile_sorted(PILE_A) == 0 && PILE_A && PILE_A != last && PILE_A->n > last->n)
			{
				reverse(&PILE_A);
				ft_putstr("rra\n");
				i++;
			}
			last = get_last_link(PILE_B);
			if (is_pile_sorted(PILE_A) == 0 && PILE_B && PILE_B != last && PILE_B->n < last->n)
			{
				reverse(&PILE_B);
				ft_putstr("rrb\n");
				i++;
			}
			if (is_pile_sorted(PILE_A) == 0 && PILE_B && PILE_B->next && PILE_B->n < PILE_B->next->n)
			{
				swap(&PILE_B);
				ft_putstr("sb\n");
				i++;
			}
			if (is_pile_sorted(PILE_A) == 0 && PILE_A->next && PILE_A->n > PILE_A->next->n)
			{
				swap(&PILE_A);
				ft_putstr("sa\n");
				i++;
			}
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
			{
				swap(&PILE_A);
				ft_putstr("sa\n");
			}
		}

		// print_piles(game);
	}
}
