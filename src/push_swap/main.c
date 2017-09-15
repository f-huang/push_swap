/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:09:00 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/15 14:48:43 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "push_swap.h"
#include "libft.h"

extern int total;
int		main(int ac, char **av)
{
	t_piles	piles;

	if (ac == 1 || !(av = check_parameters(av, &piles.len)))
	{
		!av ? ft_putstr_fd(ERROR_STRING, 2) : 0;
		return (1);
	}
	init_piles(&piles, av);
	init_sorted_pile(&piles.sorted_pile, piles.pile_a, piles.len);
	if (piles.pile_a && piles.pile_b && piles.sorted_pile)
	{
		ft_putendlcol("_________START_________", RED);
		print_piles(&piles);
		ft_putendlcol("_______________________", RED);
		resolve_game(&piles, piles.len, 0);
	}
	FT_DEBUG("TOTAL = %i", total);
	print_piles(&piles);
	destroy_piles(&piles);
	ft_tabfree(&av);
	return (0);
}
