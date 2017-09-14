/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:20:27 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/14 18:28:11 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"

int			main(int ac, char **av)
{
	int		ret;
	char	*line;
	t_piles	piles;

	if (ac < 2 || !(av = check_parameters(av, &piles.len)))
	{
		!av ? ft_putstr_fd(ERROR_STRING, 2) : 0;
		return (1);
	}
	init_piles(&piles, av);
	line = NULL;
	while ((ret = read_stdin(&line)))
	{
		if (ret == -1)
			return (1);
		call_instruction(&piles, line);
		ft_strdel(&line);
	}
	ft_putendl(is_game_finished(piles) ? "OK" : "KO");
	destroy_piles(&piles);
	ft_tabfree(&av);
	return (0);
}
