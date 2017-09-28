/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:07:05 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/28 18:27:39 by fhuang           ###   ########.fr       */
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
		// ft_putnbrendl(game->a.list[game->a.len - 1]);
		ft_putnbrendl(game->a.list[0]);
		if (game->a.list[0] < median)
		{
			FIRE(PB);
			count++;
		}
		else
		{
			FIRE(RRA);
			nb_rotate++;
		}
	}
	while (from_sort_b && nb_rotate)
	{
		FIRE(RA);
		nb_rotate--;
	}
}

static void	sort_b_by_pushing_to_a(t_game *game, uint16_t len)
{
	int		count;
	int		median;
	int		nb_rotate;

	if (len == 1)
		FIRE(PA);
	else
	{
		nb_rotate = 0;
		median = get_tab_median(game->b.list, len + len % 2);
		count = 0;
		while (count < len / 2 + len % 2 && nb_rotate - count < game->b.len)
		{
			print_piles(*game);
			if (game->b.list[0] >= median && (++count))
				FIRE(PA);
			else if (len == 2 && (++count))
			{
				FIRE(SB);
				FIRE(PA);
			}
			else if (++nb_rotate)
				FIRE(RB);
		}
		while (nb_rotate--)
			FIRE(RRB);
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
		push_smaller_integer_to_b(game, len, from_sort_b);
		resolve_game(game, half + len % 2, from_sort_b);
		sort_b_by_pushing_to_a(game, half);
	}
}
