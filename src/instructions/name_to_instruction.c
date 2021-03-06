/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_to_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 00:50:32 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/29 16:02:25 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game.h"

int		name_to_instruction(const char *name)
{
	int	i;

	i = 0;
	while (i < NB_INSTRUCTIONS)
	{
		if (!ft_strcmp(name, get_instruction_name((enum e_instruction)i)))
			return (i);
		++i;
	}
	return (-1);
}
