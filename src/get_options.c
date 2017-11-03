/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 11:34:56 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/03 16:27:13 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game.h"

int		get_options(t_game *game, char **av)
{
	int		j;
	int		i;

	i = 1;
	while (av && av[i])
	{
		if (ft_isstrdigit(av[i]) || av[i][0] != '-' ||\
			(av[i][0] == '-' && !av[i][1]))
			return (i);
		j = 1;
		while (av[i][j])
		{
			if (av[i][j] == 'v')
				game->option |= OPTION_V;
			else
				return (-1);
			j++;
		}
		(i)++;
	}
	return (i);
}
