/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:07:05 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/14 20:45:13 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "push_swap.h"
#include "libft.h"

static void	push_smaller_integer_to_b(t_piles *piles, uint16_t len)
{
	int		median;
	int		count;

	median = get_tab_median(piles->pile_a, len);
	count = 0;
	while (count < len / 2)
	{
		if (piles->pile_a[0] < median)
		{
			push_to(&piles->pile_a, &piles->pile_b, &piles->len_a, &piles->len_b);
			count++;
		}
		rotate(&piles->pile_a, piles->len_a);
	}
}

static void	sort_b_by_pushing_to_a(t_piles *piles, uint16_t len)
{
	int	count;
	int	median;
	median = get_tab_median(piles->pile_b, piles->len_b);
	print_piles(piles);
	FT_DEBUG("depiling b -> len : %i and median : %i", len, median);

	if (len == 1)
		push_to(&piles->pile_b, &piles->pile_a, &piles->len_b, &piles->len_a);
	else
	{
		// ft_putnbrendl(median);
		count = 0;
		while (count < len)
		{
			if (len <= 4 && piles->pile_b[0] < piles->pile_b[1])
			{
				FT_DEBUG("SWAP");
				swap(&piles->pile_b, piles->len_b);
			}
			if (piles->pile_b[0] > median)
			{
				push_to(&piles->pile_b, &piles->pile_a, &piles->len_b, &piles->len_a);
				reverse_rotate(&piles->pile_b, piles->len_b);
				count++;
			}
			rotate(&piles->pile_b, piles->len_b);
		}
		ft_putendlcol("          ____________        ", YELLOW);
		print_piles(piles);
		ft_putendlcol("+++++++++++++++++++", YELLOW);
	}
}

void		resolve_game(t_piles *piles, uint16_t len)
{
	if (len == 2 && piles->pile_a[0] > piles->pile_a[1])
	{
		FT_DEBUG("resole -> swap");
		swap(&piles->pile_a, piles->len_a);
		print_piles(piles);
	}
	else if (len > 2)
	{
		FT_DEBUG("resole len -> %i and pile sorted -> %s", len, is_pile_sorted(piles->pile_a, piles->len_a) ? "true" : "false");
		if (!is_pile_sorted(piles->pile_a, piles->len_a))
			push_smaller_integer_to_b(piles, len);
		resolve_game(piles, len / 2 + len % 2);
		sort_b_by_pushing_to_a(piles, len / 2);
	}
}
