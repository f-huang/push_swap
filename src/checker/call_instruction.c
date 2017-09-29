/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 13:32:35 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/29 15:12:07 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"

int			call_instruction(t_game *game, const char *str)
{
	int	instruction_index;

	if (!str)
		return (ERROR);
	if ((instruction_index = name_to_instruction(str)) == -1)
	{
		ft_putstr_fd(ERROR_STRING, 2);
		return (ERROR);
	}
	fire_instruction(game, (enum e_instruction)instruction_index, 0);
	return (GOOD);
}
