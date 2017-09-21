/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:07:05 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/21 22:37:55 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "push_swap.h"
#include "libft.h"

int	total = 0;

static void	push_smaller_integer_to_b(t_piles *piles, uint16_t len)
{
	int		median;
	int		count;
	int		nb_rotate;

	median = get_tab_median(piles->pile_a, len);
	nb_rotate = 0;
	count = 0;
	while (count < len / 2)
	{
		if (piles->pile_a[0] < median)
		{
			push_to(&piles->pile_a, &piles->pile_b, &piles->len_a, &piles->len_b);
			total++;
			count++;
		}
		else
		{
			rotate(&piles->pile_a, piles->len_a);
			total++;
			nb_rotate++;
		}
	}
	while (nb_rotate)
	{
		total++;
		reverse_rotate(&piles->pile_a, piles->len_a);
		nb_rotate--;
	}
}

static void	sort_b_by_pushing_to_a(t_piles *piles, uint16_t len)
{
	int		count;
	int		median;
	int		*tmp_pile;

	if (!(tmp_pile = ft_intabndup(piles->pile_b, 0, len)))
		return ;

	median = get_tab_median(tmp_pile, len);
	count = 0;
	while (count < len)
	{
		push_to(&piles->pile_b, &piles->pile_a, &piles->len_b, &piles->len_a);
		if (len > 1) {
			int swap_a = piles->pile_a[0] > piles->pile_a[1];
			int swap_b = piles->pile_b[0] < piles->pile_b[1];
			++total;
			if (swap_a && swap_b)
				swap_both_piles(piles);
			else if (swap_a)
				swap(&piles->pile_a, piles->len_a);
			else if (swap_b)
				swap(&piles->pile_b, piles->len_b);
			else
				--total;
		}
		total++;
		count++;
	}
	if (!is_pile_sorted(piles->pile_a, piles->len_a))
	{
		resolve_game(piles, len);
	}
	ft_memdel((void*)&tmp_pile);

}

void		resolve_game(t_piles *piles, uint16_t len)
{
	if (is_game_finished(*piles))
		return ;
	if (len == 2 && piles->pile_a[0] > piles->pile_a[1])
	{
		total++;
		swap(&piles->pile_a, piles->len_a);
	}
	else if (len > 2)
	{
		print_piles(piles);
		push_smaller_integer_to_b(piles, len);
		resolve_game(piles, len / 2 + len % 2);
		FT_DEBUG("Depil : %i -> %i", len, len/2);
		print_piles(piles);
		FT_DEBUG("-------------------");
		sort_b_by_pushing_to_a(piles, len / 2);
	}
}
