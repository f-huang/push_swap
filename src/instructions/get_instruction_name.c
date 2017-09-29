/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction_name.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 15:54:47 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/29 16:01:51 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

const char	*get_instruction_name(enum e_instruction instruction)
{
	static const char	*instruction_names[] =
	{
		[SA] = "sa",
		[SB] = "sb",
		[SS] = "ss",
		[RA] = "ra",
		[RB] = "rb",
		[RR] = "rr",
		[RRA] = "rra",
		[RRB] = "rrb",
		[RRR] = "rrr",
		[PA] = "pa",
		[PB] = "pb"
	};
	return (instruction_names[instruction]);
}
