/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:20:27 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/08 19:08:48 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"

int			main(int ac, char **av)
{
	int		ret;
	char	*line;
	t_piles	piles;

	if (ac == 1 || !check_parameters(av))
	{
		ft_putstr_fd(ERROR_STRING, 2);
		return (1);
	}
	init_piles(&piles, av, ac);
	line = NULL;
	while ((ret = read_stdin(&line)))
	{
		if (ret == -1)
			return (1);
		if (!call_instruction(&piles, line))
		{
			ft_putstr_fd(ERROR_STRING, 2);
			return (1);
		}
		ft_strdel(&line);
	}
	ft_putendl(is_game_finished(piles) ? "OK" : "KO");
	destroy_piles(&piles);
	return (0);
}
