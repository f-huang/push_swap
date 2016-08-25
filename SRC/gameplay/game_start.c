/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 15:34:55 by fhuang            #+#    #+#             */
/*   Updated: 2016/08/25 18:52:39 by fhuang           ###   ########.fr       */
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

int		flags(t_game *game, char *str, t_bool *boo)
{
	int		i;

	i = 1;
	while (str[i])
	{
		if (str[i] == 'v')
			OPT[0] = 1;
		else if (str[i] == 'c')
			OPT[1] = 1;
		else if (i == 1 && str[i] == '-')
			*boo = true;
		else
		{
			if (ft_isdigit(str[i]))
				return ft_isstrdigit(str + i) ? 1 : 0;
			ft_printf("./push_swap: illegal option -- %c\nusage: ./push_swap [-cv] number(s)\n", str[i]);
			exit(EXIT_SUCCESS);
		}
		i++;
	}
	return (0);
}

int		check_param(t_game *game, char **av)
{
	int		i;
	int		j;
	t_bool	boo;

	i = 1;
	boo = false;
	while (av[i])
	{
		if (!boo && av[i][0] == '-' && av[i][1] && ft_isdigit(av[i][1]) == 0)
		{
			if (flags(game, av[i], &boo) == 1)
				return (1);
			NLINK--;
		}
		else if ((ft_isstrdigit(av[i]) && !no_space(av[i])) ||\
			INT_MAX < ft_atol(av[i]) || INT_MIN > ft_atol(av[i]))
			return (1);
		if (av[i][0] != '-')
			boo = true;
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
	PILE_A = NULL;
	PILE_B = NULL;
	if (NLINK == 1 && no_space(av[1]) == 1)
	{
		av++;
		if ((av = ft_strsplit(av[0], ' ')) == NULL)
			exit(EXIT_FAILURE);
		ac = ft_tablen(av);
	}
	while (NLINK-- && ac != 1 && av[--ac])
	{
		push_front(&game->pile_a, ft_atoi(av[ac]));
	}
	if (ac == 2 && no_space(av[1]) == 1 && av != NULL)
		ft_tabfree(av);
}
