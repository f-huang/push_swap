/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 15:26:14 by fhuang            #+#    #+#             */
/*   Updated: 2016/08/11 21:38:17 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		is_valid(t_game *game)
{
	t_pile		*ptr;

	ptr = game->pile_a;
	while (ptr->next)
	{
		if (game->pile_b != NULL || ptr->n > ptr->next->n)
		{
			ft_putendl("KO");
			return ;
		}
		ptr = ptr->next;
	}
	ft_putendl("OK");
	return ;
}

void			checker(t_game *game)
{
	char	*line;

	while ((line = read_stdin()) != NULL)
	{
		follow_instruc(game, line);
		ft_strdel(&line);
	}
	is_valid(game);
}
