/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:07:05 by fhuang            #+#    #+#             */
/*   Updated: 2017/03/25 19:08:35 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "push_swap.h"
#include "libft.h"

static void	print_piles(t_piles *piles)
{
	ft_putendlcol("PILE A", GREEN);
	for (int i = 0 ; i < piles->len_a; i++)
	{
		ft_printf("%d ", piles->pile_a[i]);
	}
	ft_putendlcol("\nPILE B", GREEN);
	for (int i = 0 ; i < piles->len_b; i++)
	{
		ft_printf("%d ", piles->pile_b[i]);
	}
	ft_putchar('\n');
}

void		split_a_in_2(t_piles *piles, uint16_t len)
{
	int		median;
	int		i;

	median = get_tab_median(piles->pile_a, len);
	ft_printf("^RED^Median : %i - Len : %i^EOC^\n", median, len);
	i = 0;
	while (i < len)
	{
		if (piles->pile_a[0] < median)
		{
			call_instruction(piles, "pb");
		}
		else //OPTI
			call_instruction(piles, "ra");
		++i;
	}
}

static void push_b_in_a(t_piles *piles, uint16_t len)
{
	int		median;
	int		i;

	median = get_tab_median(piles->pile_b, len);
	ft_printf("^MAGENTA^Median : %i - Len : %i^EOC^\n", median, len);
	i = 0;
	while (i < len)
	{
		call_instruction(piles, "pa");
		++i;
	}
}

void		resolve_game(t_piles *piles, uint16_t len)
{
	if (!piles || !piles->pile_a || !piles->pile_b || !piles->sorted_pile)
		return ;
	if (len == 2)
	{
		if (piles->pile_a[0] > piles->pile_a[1])
			call_instruction(piles, "sa");
		return ;
	}
	ft_printf("^BLUE^Len : %i^EOC^\n", len);
	split_a_in_2(piles, len);
	print_piles(piles);
	resolve_game(piles, len / 2 + len % 2);
	push_b_in_a(piles, len / 2);
	print_piles(piles);
}
