/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_piles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:26:59 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/08 17:42:38 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"

void	init_piles(t_piles *piles, char **av, int ac)
{
	int		i;
	int		j;

	ft_bzero(piles, sizeof(t_piles));
	piles->pile_a = (int*)ft_memalloc(sizeof(int) * ac);
	piles->pile_b = (int*)ft_memalloc(sizeof(int) * ac);
	piles->sorted_pile = (int*)ft_memalloc(sizeof(int) * ac);
	piles->len = ac - 1;
	piles->len_a = piles->len;
	i = 1;
	j = 0;
	while (av[i])
		piles->pile_a[j++] = ft_atoi(av[i++]);
}
