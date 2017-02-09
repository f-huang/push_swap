/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:09:00 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/09 17:06:34 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "push_swap.h"
#include "libft.h"

int		main(int ac, char **av)
{
	t_piles	piles;

	if (ac == 1 || !(av = check_parameters(av, &piles.len)))
	{
		ft_putstr_fd(ERROR_STRING, 2);
		return (1);
	}
	init_piles(&piles, av);
	init_sorted_pile(&piles.sorted_pile, piles.pile_a, piles.len);
	resolve_game(&piles);
	destroy_piles(&piles);
	ft_tabfree(&av);
	return (0);
}
