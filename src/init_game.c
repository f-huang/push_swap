/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 00:09:08 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/22 21:46:19 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game.h"

void	init_game(t_game *game, char **av, uint16_t max_size)
{
	int		i;

	game->a.list = (int*)ft_memalloc(sizeof(int) * max_size);
	game->a.len = max_size;
	game->b.list = (int*)ft_memalloc(sizeof(int) * max_size);
	game->b.len = 0;
	game->sorted.list = NULL;
	game->sorted.len = 0;
	i = -1;
	while (av[++i])
		game->a.list[i] = ft_atoi(av[i]);
}
