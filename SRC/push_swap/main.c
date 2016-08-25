/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 15:28:29 by fhuang            #+#    #+#             */
/*   Updated: 2016/08/25 17:48:36 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int ac, char **av)
{
	t_game		game;

	if (ac > 1)
	{
		game.len = ac - 1;
		ft_memset(game.option, 0, sizeof(int) *  2);
		if (check_param(&game, av))
		{
			ft_putendl_fd("Error", 2);
			return (1);
		}
		init_game(&game, ac, av);
		push_swap(&game);
	}
	return (0);
}
