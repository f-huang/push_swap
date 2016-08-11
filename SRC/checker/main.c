/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 14:43:15 by fhuang            #+#    #+#             */
/*   Updated: 2016/08/11 22:25:46 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define INT_MAX 2147483647
#define INT_MIN -2147483648

static int	check_param(char **av)
{
	int		i;
	int		j;
	long	uin;

	i = 1;
	while (av[i])
	{
		if (ft_isstrdigit(av[i]) == 1)
			return (1);
		if (INT_MAX < (uin = (long)ft_atoi(av[i]))\
			|| INT_MIN > uin)
{		printf("UIN : %li\n", (long)ft_atoi(av[i]));
			return (1);
}
		printf("UIN : %li\n", (long)ft_atoi(av[i]));
		j = i;
		while (av[++j])
			if (ft_strcmp(av[i], av[j]) == 0)
				return (1);
		i++;
	}
	return (0);
}

static void	init_game(t_game *game, int ac, char **av)
{
	game->pile_a = NULL;
	game->pile_b = NULL;
	while (ac != 1 && av[--ac])
		push_front(&game->pile_a, ft_atoi(av[ac]));
}

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
		checker(&game);
	}
	return (0);
}
