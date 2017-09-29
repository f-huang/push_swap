/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_to_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 00:50:32 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/29 15:22:34 by fhuang           ###   ########.fr       */
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
		if (!ft_strcmp(name, g_instruction_names[i]))
			return (i);
		++i;
	}
	return (-1);
}
