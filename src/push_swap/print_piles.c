/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_piles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 15:11:30 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/29 15:11:38 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game.h"

void	print_piles(t_game game)
{
	int	i;

	i = 0;
	ft_putstrcol(" A : ", GREEN);
	while (i < game.a.len)
		ft_printf("%d ", game.a.list[i++]);
	i = 0;
	ft_putstrcol("\n B : ", GREEN);
	while (i < game.b.len)
		ft_printf("%d ", game.b.list[i++]);
	ft_putchar('\n');
}
