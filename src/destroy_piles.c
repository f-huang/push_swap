/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_piles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:48:12 by fhuang            #+#    #+#             */
/*   Updated: 2017/02/08 17:51:25 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"

void	destroy_piles(t_piles *piles)
{
	ft_memdel((void*)&piles->sorted_pile);
	ft_memdel((void*)&piles->pile_a);
	ft_memdel((void*)&piles->pile_b);
	ft_bzero(piles, sizeof(piles));
	piles = NULL;
}
