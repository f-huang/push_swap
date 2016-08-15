/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 15:26:14 by fhuang            #+#    #+#             */
/*   Updated: 2016/08/15 16:31:04 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			checker(t_game *game)
{
	char	*line;

	while ((line = read_stdin()) != NULL)
	{
		follow_instruc(game, line);
		ft_strdel(&line);
	}
	is_game_finished(game) == 1 ? ft_putendl("OK") : ft_putendl("KO");
}
