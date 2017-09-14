/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_piles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:48:12 by fhuang            #+#    #+#             */
/*   Updated: 2017/09/14 18:33:21 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"

void	destroy_piles(t_piles *piles)
{
	if (piles->sorted_pile)
		ft_memdel((void*)&piles->sorted_pile);
	if (piles->pile_a)
		ft_memdel((void*)&piles->pile_a);
	if (piles->pile_b)
		ft_memdel((void*)&piles->pile_b);
	if (piles)
		ft_bzero(piles, sizeof(piles));
	piles = NULL;
}
