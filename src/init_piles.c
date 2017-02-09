/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_piles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:26:59 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/09 17:02:03 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"

void	init_piles(t_piles *piles, char **av)
{
	int		i;
	int		j;

	piles->pile_a = (int*)ft_memalloc(sizeof(int) * piles->len);
	piles->pile_b = (int*)ft_memalloc(sizeof(int) * piles->len);
	piles->len_a = piles->len;
	piles->len_b = 0;
	piles->sorted_pile = NULL;
	i = 0;
	j = 0;
	while (av[i])
		piles->pile_a[j++] = ft_atoi(av[i++]);
}
