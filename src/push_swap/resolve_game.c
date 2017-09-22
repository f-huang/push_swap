/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:07:05 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/23 00:38:25 by fhuang           ###   ########.fr       */
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
	while (count < len / 2)
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
	// int		*tmp_pile;

	// if (!(tmp_pile = ft_intabndup(piles->pile_b, 0, len * 2)))
		// return ;

	// median = get_tab_median(tmp_pile, len * 2);
	count = 0;
	while (count < len)
	{
		FIRE(PA);
		if (len > 1) {
			int swap_a = game->a.list[0] > game->a.list[1];
			int swap_b = game->b.list[0] < game->b.list[1];
			if (swap_a && swap_b)
				FIRE(SS);
			else if (swap_a)
				FIRE(SA);
			else if (swap_b)
				FIRE(SB);
		}
		count++;
	}
	if (!is_pile_sorted(game->a))
	{
		resolve_game(game, len, 1);
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
		push_smaller_integer_to_b(game, len, from_sort_b);
		resolve_game(game, len / 2 + len % 2, from_sort_b);
		FT_DEBUG("Depil : %i -> %i", len, len/2);
		print_piles(*game);
		sort_b_by_pushing_to_a(game, len / 2);
		FT_DEBUG("-------------------");
	}

}
