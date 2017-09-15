/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:07:05 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/15 14:01:00 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "push_swap.h"
#include "libft.h"

int	total = 0;

static int	is_there_random_numbers_at_the_end_of_pile(int *pile, uint16_t len)
{
	int		i;

	i = 0;
	while (i < len - 1)
	{
		if (pile[i] > pile[i + 1] && i > 3)
			return (1);
		i++;
	}
	return (0);
}

static void	push_smaller_integer_to_b(t_piles *piles, uint16_t len, int from_sort_b)
{
	int		median;
	int		count;
	int		nb_rotate;
	int		should_rotate;

	median = get_tab_median(piles->pile_a, len);
	should_rotate = !from_sort_b && are_smaller_number_at_the_start(piles->pile_a, piles->len_a, median);
	nb_rotate = 0;
	count = 0;
	FT_DEBUG("should_rotate = %s", should_rotate ? "true" : "false");
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
			// should_rotate ? rotate(&piles->pile_a, piles->len_a) :\
				// reverse_rotate(&piles->pile_a, piles->len_a);
			total++;
			nb_rotate++;
		}
	}
	print_piles(piles);
	FT_DEBUG("%i to rotate -> %i / %i", nb_rotate, from_sort_b, is_there_random_numbers_at_the_end_of_pile(piles->pile_a, piles->len_a));
	// while (is_there_random_numbers_at_the_end_of_pile(piles->pile_a, piles->len_a) && nb_rotate)
	while (from_sort_b && is_there_random_numbers_at_the_end_of_pile(piles->pile_a, piles->len_a) && nb_rotate)
	{
		total++;
		// should_rotate ? reverse_rotate(&piles->pile_a, piles->len_a):\
			// rotate(&piles->pile_a, piles->len_a);
		reverse_rotate(&piles->pile_a, piles->len_a);
		nb_rotate--;
	}
}

static void	sort_b_by_pushing_to_a(t_piles *piles, uint16_t len)
{
	int	count;
	int	median;
	int	*tmp_pile;
	int	count_until_median = 0;
	int		nb_rotate = 0;

	if (!(tmp_pile = ft_intabndup(piles->pile_b, 0, len)))
		return ;

	median = get_tab_median(tmp_pile, len);
	count = 0;
	ft_putnbrendl(median);
	ft_putnbrendl(len / 2 + len % 2);
	while (count < len)
	{
		push_to(&piles->pile_b, &piles->pile_a, &piles->len_b, &piles->len_a);
		total++;
		count++;
	}
	print_piles(piles);
	if (!is_pile_sorted(piles->pile_a, piles->len_a))
	{
		FT_DEBUG("RESOLVE");
		resolve_game(piles, len, 1);
	}
	ft_memdel((void*)&tmp_pile);

}

void		resolve_game(t_piles *piles, uint16_t len, int from_sort_b)
{
	if (is_game_finished(*piles))
		return ;
	if (len == 2 && piles->pile_a[0] > piles->pile_a[1])
	{
		FT_DEBUG("resole -> swap");
		total++;
		swap(&piles->pile_a, piles->len_a);
		print_piles(piles);
	}
	else if (len > 2)
	{
		FT_DEBUG("resole len -> %i and pile sorted -> %s", len, is_pile_sorted(piles->pile_a, piles->len_a) ? "true" : "false");
		push_smaller_integer_to_b(piles, len, from_sort_b);
		print_piles(piles);
		resolve_game(piles, len / 2 + len % 2, from_sort_b);
		FT_DEBUG("Depiling .. len = %i : ", len / 2);
		sort_b_by_pushing_to_a(piles, len / 2);
	}
}
