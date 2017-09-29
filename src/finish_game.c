/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 00:21:09 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/29 14:47:55 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game.h"

void	finish_game(t_game *game)
{
	if (game->a.list)
		ft_memdel((void*)&game->a.list);
	if (game->b.list)
		ft_memdel((void*)&game->b.list);
	if (game)
		ft_bzero(game, sizeof(t_game));
	game = NULL;
}
