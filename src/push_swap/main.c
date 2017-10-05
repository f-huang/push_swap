/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:09:00 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/05 11:49:55 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "push_swap.h"
#include "libft.h"

int		main(int ac, char **av)
{
	t_game		game;
	int			max_size;

	game.option = 0;
	if (ac == 1 || !(av = check_parameters(&game, av, &max_size)))
	{
		!av ? ft_putstr_fd(ERROR_STRING, 2) : 0;
		return (1);
	}
	init_game(&game, av, max_size);
	if (is_game_set(game))
	{
		resolve_game(&game, game.a.len, 0);
	}
	finish_game(&game);
	ft_tabfree(&av);
	return (0);
}
