/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 15:34:55 by fhuang            #+#    #+#             */
/*   Updated: 2016/08/12 15:36:43 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define INT_MAX 2147483647
#define INT_MIN -2147483648

int		check_param(char **av)
{
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		if (ft_isstrdigit(av[i]) ||\
			INT_MAX < ft_atol(av[i]) || INT_MIN > ft_atol(av[i]))
			return (1);
		j = i;
		while (av[++j])
			if (ft_strcmp(av[i], av[j]) == 0)
				return (1);
		i++;
	}
	return (0);
}

void	init_game(t_game *game, int ac, char **av)
{
	game->pile_a = NULL;
	game->pile_b = NULL;
	while (ac != 1 && av[--ac])
		push_front(&game->pile_a, ft_atoi(av[ac]));
}
