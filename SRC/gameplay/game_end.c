/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 16:27:48 by fhuang            #+#    #+#             */
/*   Updated: 2016/08/19 15:29:10 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_game_finished(t_game *game)
{
	t_pile		*ptr;

	ptr = game->pile_a;
	while (ptr && ptr->next)
	{
		if (game->pile_b != NULL || ptr->n > ptr->next->n)
			return (0);
		ptr = ptr->next;
	}
	return PILE_B == NULL ? 1 : 0;
}
