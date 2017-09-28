/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:07:05 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/28 15:18:19 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game.h"
#include "push_swap.h"

# define FIRE(instruction) fire_instruction(game, instruction, 1)

static void	push_smaller_integer_to_b(t_game *game, uint16_t len, int from_sort_b)
{
	int		median;
	int		count;
	int		nb_rotate;

	median = get_tab_median(game->a.list, len);
	nb_rotate = 0;
	count = 0;
	while (count < len / 2 && nb_rotate < game->a.len)
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
	while (from_sort_b && nb_rotate)
	{
		FIRE(RRA);
		nb_rotate--;
	}
}

static void	sort_b_by_pushing_to_a(t_game *game, uint16_t len)
{
	int		count;
	int		median;
	int		nb_rotate;

	nb_rotate = 0;
	median = get_tab_median(game->b.list, len + len % 2);
	count = 0;
	FT_DEBUG("LEN = %i", len);
	if (len == 1)
	{
		FIRE(PA);
	}
	else
	{
		while (count < len / 2 + len % 2&& nb_rotate < game->b.len)
		{
			if (game->b.list[0] >= median)
			{
				FIRE(PA);

				++count;
			}
			else
			{
				FIRE(RB);
				++nb_rotate;
			}
		}
		while (nb_rotate)
		{
			FIRE(RRB);
			--nb_rotate;
		}
		FT_DEBUG("BEFORE : : size: %i, len: %i - count: %i - nb_rotate: %i", game->b.len, len, count, nb_rotate);
		resolve_game(game, count, 1);
		FT_DEBUG("AFTER : : size: %i, len: %i - count: %i - nb_rotate: %i", game->b.len, len, count, nb_rotate);
		// if (len / 2 == game->b.len)
		{
			sort_b_by_pushing_to_a(game, len - count);
		}
	}

}

void		resolve_game(t_game *game, uint16_t len, int from_sort_b)
{
	if (is_game_finished(*game))
		return ;
	if (len == 2 && game->a.list[0] > game->a.list[1])
		FIRE(SA);
	else if (len > 2)
	{
		print_piles(*game);
		// if (game->a.len == 3) {
		// 	FT_DEBUG("3 items");
		// 	sort_three_items(game);
		// }
		// else
		push_smaller_integer_to_b(game, len, from_sort_b);
		resolve_game(game, len / 2  + len % 2, from_sort_b);
		FT_DEBUG("Depil : %i -> %i", len, len/2);
		print_piles(*game);
		sort_b_by_pushing_to_a(game, len / 2);
		FT_DEBUG("-------------------");
	}
}
