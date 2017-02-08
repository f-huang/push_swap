/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:20:27 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/08 12:42:36 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"

int			main(int ac, char **av)
{
	if (ac == 1 || !check_parameters(av))
	{
		ft_putstr_fd(ERROR_STRING, 2);
		return (1);
	}

	return (0);
}
