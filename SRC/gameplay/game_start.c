/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 15:34:55 by fhuang            #+#    #+#             */
/*   Updated: 2016/08/23 19:41:12 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define INT_MAX 2147483647
#define INT_MIN -2147483648

static int	no_space(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int		check_param(char **av)
{
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		if ((ft_isstrdigit(av[i]) && !no_space(av[i])) ||\
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
	int64_t		total;

	game->pile_a = NULL;
	game->pile_b = NULL;
	game->average = 0;
	game->n_link = 0;
	total = 0;
	if (ac == 2 && no_space(av[1]) == 1)
	{
		av++;
		if ((av = ft_strsplit(av[0], ' ')) == NULL)
			exit(EXIT_FAILURE);
		ac = ft_tablen(av);
	}
	while (ac != 1 && av[--ac])
	{
		push_front(&game->pile_a, ft_atoi(av[ac]));
		game->n_link++;
		total += game->pile_a->n;
	}
	if (game->n_link != 0)
		game->average = total / game->n_link;
	if (ac == 2 && no_space(av[1]) == 1 && av != NULL)
		ft_tabfree(av);

}
