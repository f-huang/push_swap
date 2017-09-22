/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:20:27 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/23 00:40:01 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game.h"
#include "checker.h"

int			main(int ac, char **av)
{
	int			ret;
	char		*line;
	uint16_t	max_size;
	t_game		game;

	if (ac < 2 || !(av = check_parameters(av, &max_size)))
	{
		!av ? ft_putstr_fd(ERROR_STRING, 2) : 0;
		return (1);
	}
	init_game(&game, av, max_size);
	line = NULL;
	while ((ret = read_stdin(&line)))
	{
		if (ret == -1)
			return (1);
		call_instruction(&game, line);
		ft_strdel(&line);
	}
	ft_putendl(is_game_finished(game) ? "OK" : "KO");
	finish_game(&game);
	ft_tabfree(&av);
	return (0);
}
