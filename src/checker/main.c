/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:20:27 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/05 14:34:01 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game.h"
#include "checker.h"

static int	quit(t_game *game, char ***av)
{
	finish_game(game);
	ft_tabfree(av);
	return (0);
}

int			main(int ac, char **av)
{
	t_game		game;
	int			ret;
	char		*line;

	game.option = 0;
	if (ac < 2 || !(av = check_parameters(&game, av, &ret)))
	{
		!av ? ft_putstr_fd(ERROR_STRING, 2) : 0;
		return (1);
	}
	init_game(&game, av, ret);
	if (is_game_set(game) && !(line = NULL))
	{
		while ((ret = read_stdin(&line)))
		{
			if (ret == -1)
				return (1);
			call_instruction(&game, line);
			line ? ft_strdel(&line) : 0;
		}
		ft_putendl(is_game_finished(game) ? "OK" : "KO");
	}
	return (quit(&game, &av));
}
