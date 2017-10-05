/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_piles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 12:23:35 by fhuang            #+#    #+#             */
/*   Updated: 2017/10/05 13:52:51 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game.h"

static void	print_pile(t_pile pile, int fd)
{
	int		i;

	i = 0;
	while (i < pile.len)
	{
		ft_printf_fd(fd, "%i ", pile.list[i]);
		i++;
	}
	ft_putchar_fd('\n', fd);
}

void		print_piles(t_game game)
{
	ft_putstr_fd("------------------------\n", game.tty_fd);
	ft_printf_fd(game.tty_fd, "^GREEN^A^EOC^ | \033[7m");
	print_pile(game.a, game.tty_fd);
	ft_printf_fd(game.tty_fd, "\033[0m^GREEN^B^EOC^ | \033[7m");
	print_pile(game.b, game.tty_fd);
	ft_putstr_fd("\033[0m------------------------\n", game.tty_fd);
}
