/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 13:32:35 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/08 19:06:33 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"

static int	call_instruction2(t_piles *piles, const char *str)
{
	static const t_instruction2	instructions[] = {
		{"sa", swap},
		{"ra", rotate},
		{"rra", reverse_rotate},
		{"sb", swap},
		{"rb", rotate},
		{"rrb", reverse_rotate},
		{NULL, NULL}
	};
	int						**tmp;
	int						len;
	int						i;

	tmp = NULL;
	i = 0;
	while (instructions[i].str)
	{
		if (ft_strequ(str, instructions[i].str))
		{
			len = i >= 0 && i <= 2 ? piles->len_a : piles->len_b;
			tmp = i >= 0 && i <= 2 ? &piles->pile_a : &piles->pile_b;
			instructions[i].f(tmp, len);
			return (GOOD);
		}
		++i;
	}
	return (ERROR);
}
/*
static int	call_instruction1(t_piles *piles, const char *str)
{
	static const t_instruction2	instructions[] = {
		{"pa", push_to_a},
		{"pb", push_to_b},
		{"ss", swap_both_piles},
		{"rr", rotate_both_piles},
		{"rrr", reverse_rotate_both_piles},
		{NULL, NULL}
	};
	int							i;

	i = 0;
	while (instructions[i].str)
	{
		if (ft_strequ(str, instructionsp[i].str))
		{
			instructions[i].f(piles);
			return (GOOD);
		}
		++i;
	}
	return (ERROR);
}
*/
int			call_instruction(t_piles *piles, const char *str)
{
	if (!str)
		return (ERROR);
//	if (!call_instruction1(piles, str) &&
	if (!call_instruction2(piles, str))
		return (ERROR);
	return (GOOD);
}
