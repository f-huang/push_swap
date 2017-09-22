/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fire_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 00:18:07 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/23 00:33:34 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game.h"

void	fire_instruction(t_game *game, enum instruction instruction, int print)
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
	if (print)
		ft_putendl(instruction_names[instruction]);
	game->total_operations++;
}
