/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:07:05 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/15 16:30:44 by fhuang           ###   ########.fr       */
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
	static int	first_time = 1;

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
			// if (first_time)
			// {
			// 	FT_DEBUG("Are smaller etc. -> %i", are_smaller_number_at_the_start(piles->pile_a, len, median));
			// 	are_smaller_number_at_the_start(piles->pile_a, len, median) ?\
			// 		rotate(&piles->pile_a, piles->len_a) :\
			// 		reverse_rotate(&piles->pile_a, piles->len_a);
			// 	first_time = 0;
			// }
			// else
				rotate(&piles->pile_a, piles->len_a);
			total++;
			nb_rotate++;
		}
	}
	while (from_sort_b && is_there_random_numbers_at_the_end_of_pile(piles->pile_a, piles->len_a) && nb_rotate && piles->len_a)
	{
		total++;
		reverse_rotate(&piles->pile_a, piles->len_a);
		nb_rotate--;
	}
}

static int	are_bigger_numbers_presents(int *pile, uint16_t len, int comparator)
{
	int		i = 0;

	while (i < len)
	{
		if (pile[i] > comparator)
			return (1);
		++i;
	}
	return (0);
}

static void	sort_b_by_pushing_to_a(t_piles *piles, uint16_t len)
{
	int	count;
	int	median;
	int	*tmp_pile;
	int	count_until_median = 0;
	int		nb_rotate = 0;

	if (!(tmp_pile = ft_intabndup(piles->pile_b, 0, len * 2)))
		return ;

	median = get_tab_median(tmp_pile, len * 2);
	count = 0;
	FT_DEBUG("MEDIAN = %i", median);
	while (count < len || are_bigger_numbers_presents(piles->pile_b, piles->len_b, median))
	{
		if (piles->len_b > 1 && piles->pile_b[0] < piles->pile_b[1])
		{
			ft_putendlcol("swap", MAGENTA);
			swap(&piles->pile_b, piles->len_b);
			++total;
			print_piles(piles);
		}
		if (piles->pile_b[0] >= median || len >= piles->len_b)
		{
			push_to(&piles->pile_b, &piles->pile_a, &piles->len_b, &piles->len_a);
			total++;
			count++;
		}
		else
		{
			ft_putendl("rotate");
			rotate(&piles->pile_b, piles->len_b);
			nb_rotate++;
			total++;
		}
	}
	while (nb_rotate && piles->len_b)
	{
		reverse_rotate(&piles->pile_b, piles->len_b);
		total++;
		nb_rotate--;
	}
	print_piles(piles);
	ft_memdel((void*)&tmp_pile);
	if (!is_pile_sorted(piles->pile_a, piles->len_a))
	{
		resolve_game(piles, len, 1);
	}

}

void		resolve_game(t_piles *piles, uint16_t len, int from_sort_b)
{
	if (is_game_finished(*piles))
		return ;
	if (piles->len_a == 3)
	{
		ft_putendlcol("sort_three_items()", RED);
		sort_three_items(&piles->pile_a, piles->len_a);
		print_piles(piles);
	}
	if (is_pile_sorted(piles->pile_a, piles->len_a) &&\
		is_pile_reverse_sorted(piles->pile_b, piles->len_b) &&
		piles->len_b > 0 && piles->pile_a[0] > piles->pile_b[0])
	{
		while (piles->len_b)
		{
			push_to(&piles->pile_b, &piles->pile_a, &piles->len_b, &piles->len_a);
			total++;
		}
		return ;
	}
	if (len <= 3 && piles->pile_a[0] > piles->pile_a[1])
	{
		ft_putendlcol("swap", RED);
		if (piles->len_b > 2 && piles->pile_b[0] < piles->pile_b[1])
			swap_both_piles(piles);
		else
			swap(&piles->pile_a, piles->len_a);
		total++;
		print_piles(piles);
	}
	else if (len > 2)
	{
		FT_DEBUG("Resolving game - len : %i", len);
		if (!is_pile_sorted(piles->pile_a, piles->len_a))
		{
			push_smaller_integer_to_b(piles, len, from_sort_b);
			print_piles(piles);
			resolve_game(piles, len / 2 + len % 2, from_sort_b);
		}
		if (!is_game_finished(*piles))
		{
			FT_DEBUG("Depiling - len : %i", len / 2);
			sort_b_by_pushing_to_a(piles, len / 2);
		}
	}

}
