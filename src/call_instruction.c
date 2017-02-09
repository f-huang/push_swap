/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 13:32:35 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/09 15:10:02 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"

static int	call_instruction3(t_piles *piles, const char *str)
{
	static const t_instruction3	instructions[] = {
		{"pa", push_to},
		{"pb", push_to},
		{NULL, NULL}
	};

	if (ft_strequ(str, instructions[0].str))
		push_to(&piles->pile_b, &piles->pile_a, &piles->len_b, &piles->len_a);
	else if (ft_strequ(str, instructions[1].str))
		push_to(&piles->pile_a, &piles->pile_b, &piles->len_a, &piles->len_b);
	else
		return (ERROR);
	return (GOOD);
}
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

static int	call_instruction1(t_piles *piles, const char *str)
{
	static const t_instruction1	instructions[] = {
		{"ss", swap_both_piles},
		{"rr", rotate_both_piles},
		{"rrr", reverse_rotate_both_piles},
		{NULL, NULL}
	};
	int							i;

	i = 0;
	while (instructions[i].str)
	{
		if (ft_strequ(str, instructions[i].str))
		{
			instructions[i].f(piles);
			return (GOOD);
		}
		++i;
	}
	return (ERROR);
}

static int			print_debug(t_piles *piles, const char *str)
{
	if (!ft_strequ(str, "print"))
		return (ERROR);
	ft_printf("^YELLOW^Pile a **%i**^EOC^\n", piles->len_a);
	if (piles->len_a == 0)
		ft_putendlcol("(null)", RED);
	for (int i = 0; i < piles->len_a; i++)
	{
		ft_printf("[%i] -> ^GREEN^[%i]^EOC^\n", i, piles->pile_a[i]);
	}
	ft_printf("^YELLOW^Pile b **%i**^EOC^\n", piles->len_b);
	if (piles->len_b == 0)
		ft_putendlcol("(null)", RED);
	for (int i = 0; i < piles->len_b; i++)
	{
		ft_printf("[%i] -> ^GREEN^[%i]^EOC^\n", i, piles->pile_b[i]);
	}
	return (GOOD);
}

int			call_instruction(t_piles *piles, const char *str)
{
	if (!str)
		return (ERROR);
	if (!call_instruction1(piles, str) &&
		!call_instruction2(piles, str) &&
		!call_instruction3(piles, str) &&
		!print_debug(piles, str))
	{
		ft_putstr_fd(ERROR_STRING, 2);
		return (ERROR);
	}
	return (GOOD);
}
