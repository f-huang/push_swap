/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fire_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 00:18:07 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/05 13:56:00 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game.h"

static void	handle_instruction(t_game *game, enum e_instruction instruction)
{
	if (instruction == SA)
		swap(&game->a);
	else if (instruction == SB)
		swap(&game->b);
	else if (instruction == SS)
		swap_both_piles(&game->a, &game->b);
	else if (instruction == RA)
		rotate(&game->a);
	else if (instruction == RB)
		rotate(&game->b);
	else if (instruction == RR)
		rotate_both_piles(&game->a, &game->b);
	else if (instruction == RRA)
		reverse_rotate(&game->a);
	else if (instruction == RRB)
		reverse_rotate(&game->b);
	else if (instruction == RRB)
		reverse_rotate_both_piles(&game->a, &game->b);
	else if (instruction == PA)
		push_to(&game->b, &game->a);
	else if (instruction == PB)
		push_to(&game->a, &game->b);
}

void		fire_instruction(
			t_game *game, enum e_instruction instruction, int print)
{
	handle_instruction(game, instruction);
	if (print)
		ft_putendl(get_instruction_name(instruction));
	if (game->option & OPTION_V || game->option & OPTION_C)
		print_piles(*game);
	game->total_operations++;
}
