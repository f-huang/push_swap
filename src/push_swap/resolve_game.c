/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:07:05 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/29 15:08:54 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game.h"
#include "push_swap.h"

# define FIRE(instruction) fire_instruction(game, instruction, 1)

static void	is_middle_of_a_is_sorted(t_game *game, int nb_rotate)
{
	int i;
	int sorted;

	if (game->a.len > 1 && game->a.list[0] > game->a.list[1])
	{
		i = 2;
		sorted = 1;
		swap(&game->a);
		while (sorted && i < game->a.len - nb_rotate - 3)
		{
			if (game->a.list[i] > game->a.list[i + 1])
				sorted = 0;
			++i;
		}
		swap(&game->a);
		if (sorted)
			FIRE(SA);
	}

}

static void	push_smaller_integer_to_b(t_game *game, uint16_t len, int from_sort_b)
{
	int		median;
	int		count;
	int		nb_rotate;

	median = get_tab_median(game->a.list, len);
	nb_rotate = 0;
	count = 0;
	while (count < len / 2 && nb_rotate - count < game->a.len)
	{
		if (game->a.list[0] < median)
		{
			FIRE(PB);
			count++;
		}
		else
		{
			FIRE(RA);
			nb_rotate++;
		}
	}
	print_piles(*game);
	FT_DEBUG("len: %i, nb_rotate: %i - count: %i - a.len: %i", len, nb_rotate, count, game->a.len);
	while (from_sort_b && nb_rotate)
	{
		FIRE(RRA);
		is_middle_of_a_is_sorted(game, nb_rotate);
		nb_rotate--;
	}
}

static void	sort_b_by_pushing_to_a(t_game *game, uint16_t len)
{
	int		count;
	int		median;
	int		nb_rotate;
	int		nb_numbers_left;

	if (len == 1)
		FIRE(PA);
	else
	{
		nb_rotate = 0;
		count = 0;
		median = get_tab_median(game->b.list, len + len % 2);
		while ((nb_numbers_left = is_there_numbers_greater_than_median(game->b, median)) && count < len / 2 + len % 2 && nb_rotate - count < game->b.len)
		{
			if (game->b.list[0] >= median && (++count))
			{
				FIRE(PA);
			}
			else if (len == 2 && (++count))
			{
				FIRE(SB);
				FIRE(PA);
			}
			else if (++nb_rotate) {
				FIRE(RB);
			}
			swap_if_needed(game);
		}
		print_piles(*game);
		FT_DEBUG("len: %i, nb_rotate: %i - count: %i - b.len: %i - median: %i", len, nb_rotate, count, game->b.len, median);
		while (game->b.len != nb_rotate && count < game->b.len && nb_rotate--)
			FIRE(RRB);
		if (!is_pile_sorted(game->a))
			resolve_game(game, count, 1);
		sort_b_by_pushing_to_a(game, len - count);
	}
}

void		resolve_game(t_game *game, uint16_t len, int from_sort_b)
{
	int		half;

	if (is_game_finished(*game))
		return ;
	if (len == 2 && game->a.list[0] > game->a.list[1])
		FIRE(SA);
	else if (len > 2)
	{
		half = len / 2;
		print_piles(*game);
		if (!is_pile_sorted(game->a) ||\
			(is_pile_sorted(game->a) && !is_a_correctly_sorted(game)))
		{
			push_smaller_integer_to_b(game, len, from_sort_b);
			resolve_game(game, half + len % 2, from_sort_b);
			sort_b_by_pushing_to_a(game, half);
		}
	}
}
