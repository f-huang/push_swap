/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 15:28:29 by fhuang            #+#    #+#             */
/*   Updated: 2016/08/12 15:38:59 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int ac, char **av)
{
	t_game		game;

	if (ac > 1)
	{
		if (check_param(av))
		{
			ft_putendl_fd("Error", 2);
			return (1);
		}
		init_game(&game, ac, av);
		push_swap(&game);
	}
	return (0);
}
