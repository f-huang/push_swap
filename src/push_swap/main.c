/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:09:00 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/28 11:28:20 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "push_swap.h"
#include "libft.h"

int		main(int ac, char **av)
{
	t_game	game;
	uint16_t	max_size;

	if (ac == 1 || !(av = check_parameters(av, &max_size)))
	{
		!av ? ft_putstr_fd(ERROR_STRING, 2) : 0;
		return (1);
	}
	init_game(&game, av, max_size);
	set_sorted_pile(&game.sorted, game.a, max_size);
	if (is_game_set(game))
	{
		ft_putendlcol("_________START_________", RED);
		print_piles(game);
		ft_putendlcol("_______________________", RED);
		resolve_game(&game, game.a.len, 0);
		print_piles(game);
	}
	FT_DEBUG("[%s] TOTAL = %i",
		is_game_finished(game) ? "OK" : "KO",
		game.total_operations);
	finish_game(&game);
	ft_tabfree(&av);
	return (0);
}
