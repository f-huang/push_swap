/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 12:12:51 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/08 13:27:27 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game.h"

int		check_parameters(char **av)
{
	int		i;
	int		j;
	int		tmp;

	i = 1;
	while (av[i])
	{
		if (!ft_isint(av[i]) || !ft_isstrdigit(av[i]))
			return (ERROR);
		j = 1;
		while (av[j])
		{
			tmp = ft_atoi(av[i]);
			if (i != j && tmp == ft_atoi(av[j]))
				return (ERROR);
			++j;
		}
		++i;
	}
	return (GOOD);
}
